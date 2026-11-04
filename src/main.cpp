#include "game.hpp"
#include "pixel_scaler.hpp"
#include "credit_design.hpp"

static int key(SDL_Keycode k){
 switch(k){case SDLK_UP:return -1;case SDLK_DOWN:return -2;case SDLK_LEFT:return -3;case SDLK_RIGHT:return -4;case SDLK_RETURN:case SDLK_SPACE:return -5;case SDLK_z:return -6;case SDLK_x:case SDLK_ESCAPE:return -7;case SDLK_c:return 48;case SDLK_a:return 55;case SDLK_s:return 57;case SDLK_BACKSPACE:return -8;default:if(k>=SDLK_0&&k<=SDLK_9)return (int)k;return 0;}
}
static int pad(Uint8 b,bool gameplay){switch(b){case SDL_CONTROLLER_BUTTON_DPAD_UP:return -1;case SDL_CONTROLLER_BUTTON_DPAD_DOWN:return -2;case SDL_CONTROLLER_BUTTON_DPAD_LEFT:return -3;case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:return -4;case SDL_CONTROLLER_BUTTON_A:return gameplay?-1:-5;case SDL_CONTROLLER_BUTTON_B:return -8;case SDL_CONTROLLER_BUTTON_X:return -5;case SDL_CONTROLLER_BUTTON_Y:return 57;case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:return -6;case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:return 48;case SDL_CONTROLLER_BUTTON_START:return -7;case SDL_CONTROLLER_BUTTON_BACK:return -8;default:return 0;}}
static void pressed(GameScreen&g,int k){
 if(k==-6&&g.screen==10&&(g.state==1||g.state==20)){
  if(g.state==20){g.state=1;g.game_on=true;g.p_mode=100;g.repaint();}
  else{g.game_on=false;g.state=20;g.gg.setColor(0);g.gg.fillRect(0,293,240,30);g.draw_img(String("m_resume"),g.btn_r_x,g.btn_y,24);g.draw_img(String("pause"),120,200,3);g.repaint();}
  return;
 }
 if(k==-7&&g.screen==10){
  fprintf(stdout,"Options: opening gameplay menu (state=%d auto_move=%d pose=%d)\n",g.state,g.auto_move,g.h_mo);
  if(g.state==20)g.state=1;
  g.load_img(400);g.m_mode=1;g.game_on=false;g.ani_step=-1;g.p_mode=100;g.screen=100;g.repaint();return;
 }
 if(k==-5&&g.screen==123)k=-6;g.keyPressed(k);
}
static int controller_key(Uint8 button,bool gameplay,bool native_ps5){
 if(button==SDL_CONTROLLER_BUTTON_LEFTSHOULDER)return 0;
 if(button==SDL_CONTROLLER_BUTTON_B)return gameplay?55:-8;
 // Pacbrew 0.37 maps physical Options (mask 0x8/raw 4) to BACK,
 // and the touchpad (mask 0x100000/raw 6) to START.
 if(native_ps5){if(button==SDL_CONTROLLER_BUTTON_BACK)return -7;if(button==SDL_CONTROLLER_BUTTON_START||button==SDL_CONTROLLER_BUTTON_TOUCHPAD)return gameplay?-6:0;}
 return pad(button,gameplay);
}
#ifdef FW_PS5
constexpr bool native_ps5_controls=true;
#else
constexpr bool native_ps5_controls=false;
#endif
static int frame_delay(const GameScreen&g){
 if(!g.game_on)return 100;
 if(g.screen==10){static const int speed_ms[]={85,67,55,41,27};return speed_ms[std::clamp(g.h_speed,1,5)-1];}
 if(g.screen==1)return 80;
 if(g.screen==200||g.screen==110||g.screen==115)return 55;
 return 33;
}
static void apply_held_horizontal(GameScreen&g,int direction){
 if(g.screen!=10||!g.game_on||g.state!=1||g.auto_move!=0)return;
 if(direction)g.keyPressed(direction<0?-3:-4);
 else{g.tmp_move=0;if(g.h_dir==2||g.h_dir==4)g.h_dir=0;}
}
static int held_horizontal(){
 const Uint8*keys=SDL_GetKeyboardState(nullptr);bool left=keys[SDL_SCANCODE_LEFT],right=keys[SDL_SCANCODE_RIGHT];
 if(controller){left=left||SDL_GameControllerGetButton(controller,SDL_CONTROLLER_BUTTON_DPAD_LEFT)||SDL_GameControllerGetAxis(controller,SDL_CONTROLLER_AXIS_LEFTX)<-16000;right=right||SDL_GameControllerGetButton(controller,SDL_CONTROLLER_BUTTON_DPAD_RIGHT)||SDL_GameControllerGetAxis(controller,SDL_CONTROLLER_AXIS_LEFTX)>16000;}
 return int(right)-int(left);
}
static void present_frame(SDL_Renderer*r,SDL_Texture*t,const GameScreen&g){
 static std::vector<uint32_t> enlarged;
 enlarge_pixel_art((const uint32_t*)g.canvas.im.p->pixels,240,320,g.canvas.im.p->pitch/4,enlarged);
 SDL_UpdateTexture(t,nullptr,enlarged.data(),480*4);
 SDL_SetRenderDrawColor(r,0,0,0,255);SDL_RenderClear(r);
 const SDL_Rect picture{555,0,810,1080};
 SDL_RenderCopy(r,t,nullptr,&picture);
 if(g.screen==1||g.screen==123||g.screen==2){
  static SDL_Texture*credit=nullptr;
  if(!credit){Image text=make_credit_design();credit=SDL_CreateTextureFromSurface(r,text.p.get());if(credit)SDL_SetTextureScaleMode(credit,SDL_ScaleModeLinear);}
  if(credit){
   if(g.screen==1){const SDL_Rect box{555,996,810,84};SDL_RenderCopy(r,credit,nullptr,&box);}
   else{
    const int left_width=(g.screen==2&&g.menu_mode==1)?g.imgOp.getWidth():g.imgPlay.getWidth();
    const int right_width=g.screen==123?g.imgOp.getWidth():g.imgOk.getWidth();
    const int left=555+((10+left_width)*810+239)/240;
    const int right=555+(230-right_width)*810/240;
    const SDL_Rect source{210,0,390,84},box{left,1004,std::max(1,right-left),70};
    SDL_RenderCopy(r,credit,&source,&box);
   }
  }
 }
 SDL_RenderPresent(r);
}
static void directory(const std::string&p){
#ifdef _WIN32
 _mkdir(p.c_str());
#else
 mkdir(p.c_str(),0755);
#endif
}
int main(int argc,char**argv){
 SDL_SetMainReady();bool test=false;for(int i=1;i<argc;i++){if(!strcmp(argv[i],"--self-test"))test=true;else if(!strcmp(argv[i],"--assets")&&i+1<argc)asset_dir=argv[++i];else if(!strcmp(argv[i],"--save")&&i+1<argc)save_dir=argv[++i];}
#ifdef FW_PS5
 asset_dir="/app0/assets";save_dir="/data/ForgottenWarrior";
#endif
 directory(save_dir);freopen((save_dir+"/native-game.log").c_str(),"a",stdout);freopen((save_dir+"/native-game.log").c_str(),"a",stderr);setvbuf(stdout,nullptr,_IONBF,0);setvbuf(stderr,nullptr,_IONBF,0);
 fprintf(stdout,"Forgotten Warrior native folder 1.1 circle HP potion starting\n");
 if(test){SDL_setenv("SDL_VIDEODRIVER","dummy",1);SDL_setenv("SDL_AUDIODRIVER","dummy",1);}
 if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER|SDL_INIT_AUDIO|SDL_INIT_TIMER)){fprintf(stderr,"SDL: %s\n",SDL_GetError());return 1;}
 SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
 SDL_Window*w=SDL_CreateWindow("Forgotten Warrior - Native PS5",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1920,1080,SDL_WINDOW_SHOWN);
 SDL_Renderer*r=w?SDL_CreateRenderer(w,-1,SDL_RENDERER_SOFTWARE):nullptr;
 if(!r){fprintf(stderr,"Video: %s\n",SDL_GetError());SDL_Quit();return 1;}
 fprintf(stdout,"SDL video=%s audio=%s controllers=%d\n",SDL_GetCurrentVideoDriver(),SDL_GetCurrentAudioDriver(),SDL_NumJoysticks());
 SDL_RenderSetLogicalSize(r,1920,1080);SDL_Texture*texture=SDL_CreateTexture(r,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STREAMING,480,640);
 SDL_SetTextureScaleMode(texture,SDL_ScaleModeLinear);
 int output_w=0,output_h=0;SDL_GetRendererOutputSize(r,&output_w,&output_h);fprintf(stdout,"Output=%dx%d; game viewport=810x1080; original aspect=3:4; edge-aware 2x + linear scaling\n",output_w,output_h);
 for(int i=0;i<SDL_NumJoysticks();i++)if(SDL_IsGameController(i)){controller=SDL_GameControllerOpen(i);if(controller)break;}
 synth=tsf_load_filename((asset_dir+"/soundfont.sf2").c_str());if(synth){tsf_set_output(synth,TSF_STEREO_INTERLEAVED,44100,0);SDL_AudioSpec want{},have{};want.freq=44100;want.format=AUDIO_F32SYS;want.channels=2;want.samples=1024;want.callback=audio_callback;audio_device=SDL_OpenAudioDevice(nullptr,0,&want,&have,0);if(audio_device)SDL_PauseAudioDevice(audio_device,0);}
 int result=0;
 try{
 Default app;Display display;GameScreen game(app,display);game.canvas=Image::createImage(240,320).getGraphics();game.gg=game.canvas;
 if(test){
  if(controller_key(SDL_CONTROLLER_BUTTON_BACK,true,true)!=-7||controller_key(SDL_CONTROLLER_BUTTON_START,true,true)!=-6||controller_key(SDL_CONTROLLER_BUTTON_TOUCHPAD,true,true)!=-6||controller_key(SDL_CONTROLLER_BUTTON_START,false,true)!=0||controller_key(SDL_CONTROLLER_BUTTON_B,true,true)!=55||controller_key(SDL_CONTROLLER_BUTTON_B,false,true)!=-8)throw std::runtime_error("PS5 physical Options/touchpad/potion mapping regression");
  const uint32_t corner[]={0xffffffff,0xffffffff,0,0xffffffff,0,0,0,0,0};std::vector<uint32_t>scaled;enlarge_pixel_art(corner,3,3,3,scaled);if(scaled[14]!=0xffffffff||scaled[15]!=0||scaled[20]!=0||scaled[21]!=0)throw std::runtime_error("Pixel-art edge scaling regression");
  if(pad(SDL_CONTROLLER_BUTTON_A,true)!=-1||pad(SDL_CONTROLLER_BUTTON_A,false)!=-5||pad(SDL_CONTROLLER_BUTTON_X,true)!=-5||pad(SDL_CONTROLLER_BUTTON_START,true)!=-7||pad(SDL_CONTROLLER_BUTTON_B,true)==-7)throw std::runtime_error("Controller mapping regression");
  for(int i=0;i<80;i++)game.tick();SDL_SaveBMP(game.canvas.im.p.get(),"intro.bmp");
  const int intro_screen=game.screen;game.screen=1;present_frame(r,texture,game);SDL_Surface*title=SDL_CreateRGBSurfaceWithFormat(0,1920,1080,32,SDL_PIXELFORMAT_RGBA32);if(!title||SDL_RenderReadPixels(r,nullptr,SDL_PIXELFORMAT_RGBA32,title->pixels,title->pitch))throw std::runtime_error("Credit capture failed");SDL_SaveBMP(title,"title-credit.bmp");
  for(int state:{123,2}){game.screen=state;game.ani_step=10;game.menu_mode=1;if(state==2)game.load_img(2);game.paint(game.canvas);present_frame(r,texture,game);if(SDL_RenderReadPixels(r,nullptr,SDL_PIXELFORMAT_RGBA32,title->pixels,title->pitch))throw std::runtime_error("Menu footer capture failed");SDL_SaveBMP(title,("footer-spacing-"+std::to_string(state)+".bmp").c_str());}game.screen=intro_screen;SDL_FreeSurface(title);
  game.screen=-2;for(int page=0;page<5;page++){game.b_step=page;game.paint(game.canvas);SDL_SaveBMP(game.canvas.im.p.get(),("help-ps5-"+std::to_string(page)+".bmp").c_str());}
  game.screen=-3;game.p_mode=0;game.keyPressed(pad(SDL_CONTROLLER_BUTTON_X,false));if(game.screen!=-3)throw std::runtime_error("Square incorrectly exits settings");game.keyPressed(pad(SDL_CONTROLLER_BUTTON_B,false));if(game.screen!=2)throw std::runtime_error("Circle failed to return to main menu");
  game.screen=-3;game.p_mode=100;game.keyPressed(pad(SDL_CONTROLLER_BUTTON_B,false));if(game.screen!=10)throw std::runtime_error("Circle failed to return to gameplay");
  game.m_mode=3;game.init_game();for(int i=0;i<25;i++)game.tick();
  for(int dir:{-1,1}){
   game.m_mode=3;game.init_game();for(int i=0;i<25;i++)game.tick();game.sn_m[3]=0;game.h_x=dir>0?6:20;
   apply_held_horizontal(game,dir);game.tick();const int jump_x=game.h_x;pressed(game,-1);
   for(int i=0;i<14;i++){if(i==2)game.keyReleased(-1);apply_held_horizontal(game,dir);game.tick();}
   if(game.screen!=10||game.h_dir!=(dir>0?4:2)||(game.h_x-jump_x)*dir<10)throw std::runtime_error("Held movement interrupted by jump/release");
   apply_held_horizontal(game,0);if(game.h_dir!=0||game.tmp_move!=0)throw std::runtime_error("Horizontal movement continued after release");
  }
  game.m_mode=3;game.init_game();for(int i=0;i<25;i++)game.tick();
  game.h_hp=game.h_max_hp-50;game.pt[0]=1;const int hp_before=game.h_hp;pressed(game,controller_key(SDL_CONTROLLER_BUTTON_B,true,true));if(game.h_hp<=hp_before||game.pt[0]!=0)throw std::runtime_error("Circle HP potion failed");game.screen=100;game.m_mode=1;pressed(game,controller_key(SDL_CONTROLLER_BUTTON_B,false,true));if(game.screen!=10)throw std::runtime_error("Circle menu back failed");game.m_mode=3;game.init_game();for(int i=0;i<25;i++)game.tick();
  const int pause_x=game.h_x;pressed(game,controller_key(SDL_CONTROLLER_BUTTON_START,true,true));if(game.game_on||game.state!=20)throw std::runtime_error("Touchpad pause failed");for(int i=0;i<5;i++)game.tick();if(game.h_x!=pause_x)throw std::runtime_error("Gameplay advanced while paused");pressed(game,controller_key(SDL_CONTROLLER_BUTTON_START,true,true));if(!game.game_on||game.state!=1)throw std::runtime_error("Touchpad resume failed");
  game.auto_move=1;game.key_pp=true;game.h_mo=8;pressed(game,pad(SDL_CONTROLLER_BUTTON_START,true));if(game.screen!=100||game.game_on)throw std::runtime_error("Options failed while moving");pressed(game,pad(SDL_CONTROLLER_BUTTON_B,false));if(game.screen!=10)throw std::runtime_error("Options menu back failed");
  game.auto_move=0;game.state=20;game.game_on=false;pressed(game,pad(SDL_CONTROLLER_BUTTON_START,true));if(game.screen!=100||game.state!=1)throw std::runtime_error("Options failed while paused");pressed(game,pad(SDL_CONTROLLER_BUTTON_B,false));
  game.m_mode=3;game.init_game();for(int i=0;i<25;i++)game.tick();
  if(game.stage!=1||game.h_max_hp!=130||game.map.length()!=8)throw std::runtime_error("Initial game state mismatch");
  game.paint(game.canvas);SDL_SaveBMP(game.canvas.im.p.get(),"gameplay.bmp");
  present_frame(r,texture,game);
  if(output_w!=1920||output_h!=1080)throw std::runtime_error("1080p output size mismatch");
  SDL_Surface*display=SDL_CreateRGBSurfaceWithFormat(0,1920,1080,32,SDL_PIXELFORMAT_RGBA32);
  if(!display||SDL_RenderReadPixels(r,nullptr,SDL_PIXELFORMAT_RGBA32,display->pixels,display->pitch))throw std::runtime_error("1080p capture failed");
  SDL_SaveBMP(display,"display-1080p.bmp");SDL_FreeSurface(display);
  const int initial_x=game.h_x;game.keyPressed(-4);for(int i=0;i<5;i++)game.tick();game.keyReleased(-4);
  if(game.h_x<=initial_x)throw std::runtime_error("Right input did not move hero");
  game.keyPressed(-5);for(int i=0;i<20;i++)game.tick();game.keyReleased(-5);
  game.addStage(String("test"),0);int loaded=0;if(!load_value(String("test"),loaded)||loaded!=game.h_hp*1000+game.mp)throw std::runtime_error("Save roundtrip failed");
  remove((save_dir+"/test.sav").c_str());
  for(int chapter=0;chapter<3;chapter++){game.chap=chapter;game.m_mode=100;game.init_game();game.paint(game.canvas);for(int stage=1;stage<=21;stage++){game.stage=stage;game.init_en();game.init_ob();game.make_buf(8,8);game.paint(game.canvas);}}
  game.m_mode=3;game.init_game();for(int i=0;i<25;i++)game.tick();game.game_speed=23;
  Uint64 started=SDL_GetTicks64(),due=started;int updates=0;
  while(SDL_GetTicks64()-started<1000){if(SDL_GetTicks64()>=due){game.tick();updates++;due=SDL_GetTicks64()+frame_delay(game);}SDL_Delay(1);}
  if(updates<15||updates>20||game.screen!=10)throw std::runtime_error("Normal-speed real-time cadence regression");
  fprintf(stdout,"PASS: intro, gameplay, movement, combat update, save roundtrip, 63 stage/chapter renders; normal cadence %d updates/second (legacy saved delay=23ms)\n",updates);
 }else{
  Uint64 next=0;int axis_x=0,axis_y=0,last_screen=-99999;bool options_was_down=false;
  while(!quitting){bool options_event=false;SDL_Event e;while(SDL_PollEvent(&e)){
   if(e.type==SDL_QUIT)quitting=true;
   else if(e.type==SDL_KEYDOWN&&!e.key.repeat){int k=key(e.key.keysym.sym);if(k)pressed(game,k);}
   else if(e.type==SDL_KEYUP){int k=key(e.key.keysym.sym);if(k)game.keyReleased(k);}
   else if(e.type==SDL_CONTROLLERBUTTONDOWN){int k=controller_key(e.cbutton.button,game.screen==10,native_ps5_controls);if(k==-7)options_event=true;if(k)pressed(game,k);}
   else if(e.type==SDL_CONTROLLERBUTTONUP){int k=controller_key(e.cbutton.button,game.screen==10,native_ps5_controls);if(k)game.keyReleased(k);}
   else if(e.type==SDL_CONTROLLERDEVICEADDED&&!controller)controller=SDL_GameControllerOpen(e.cdevice.which);
   else if(e.type==SDL_CONTROLLERDEVICEREMOVED&&controller&&SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller))==e.cdevice.which){SDL_GameControllerClose(controller);controller=nullptr;game.showshow(1);}
   else if(e.type==SDL_WINDOWEVENT&&e.window.event==SDL_WINDOWEVENT_FOCUS_LOST)game.showshow(1);
   else if(e.type==SDL_WINDOWEVENT&&e.window.event==SDL_WINDOWEVENT_FOCUS_GAINED)game.showNotify();
   else if(e.type==SDL_CONTROLLERAXISMOTION&&(e.caxis.axis==SDL_CONTROLLER_AXIS_LEFTX||e.caxis.axis==SDL_CONTROLLER_AXIS_LEFTY)){
    int value=e.caxis.value<-16000?-1:e.caxis.value>16000?1:0;int&old=e.caxis.axis==SDL_CONTROLLER_AXIS_LEFTX?axis_x:axis_y;
    if(value!=old){if(old)game.keyReleased(e.caxis.axis==SDL_CONTROLLER_AXIS_LEFTX?(old<0?-3:-4):(old<0?-1:-2));if(value)game.keyPressed(e.caxis.axis==SDL_CONTROLLER_AXIS_LEFTX?(value<0?-3:-4):(value<0?-1:-2));old=value;}
   }
  }
  bool options_down=controller&&SDL_GameControllerGetButton(controller,SDL_CONTROLLER_BUTTON_START);
#ifdef FW_PS5
  options_down=controller&&SDL_JoystickGetButton(SDL_GameControllerGetJoystick(controller),4);
#endif
  if(options_down&&!options_was_down&&!options_event)pressed(game,-7);
  options_was_down=options_down;
  Uint64 now=SDL_GetTicks64();if(now>=next){apply_held_horizontal(game,held_horizontal());game.tick();next=SDL_GetTicks64()+frame_delay(game);}
  present_frame(r,texture,game);SDL_Delay(4);
  if(last_screen!=game.screen){last_screen=game.screen;fprintf(stdout,"Screen=%d chapter=%d stage=%d\n",game.screen,game.chap,game.stage);
#ifdef FW_PS5
   SDL_SaveBMP(game.canvas.im.p.get(),(save_dir+"/last-screen.bmp").c_str());
#endif
  }
  }
 }
 }catch(const std::exception&e){fprintf(stderr,"Game error: %s\n",e.what());result=2;}
 if(audio_device)SDL_CloseAudioDevice(audio_device);if(midi)tml_free(midi);if(synth)tsf_close(synth);if(controller)SDL_GameControllerClose(controller);SDL_DestroyTexture(texture);SDL_DestroyRenderer(r);SDL_DestroyWindow(w);SDL_Quit();return result;
}
