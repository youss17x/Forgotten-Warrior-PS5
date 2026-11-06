/* PS5 presentation contributions: Youss Riaal, 2026.
 * SPDX-License-Identifier: GPL-3.0-only
 * Original contributions only; see COPYRIGHT.md and NOTICE.md. */
#pragma once
// A cropped, uniformly sampled 16:9 view of the scenery supplies soft ambient
// color. Only the background is blurred; the original center remains intact.
inline void draw_side_background(SDL_Renderer*r,const GameScreen&g){
 if(!presentation_settings.ambient)return;
 constexpr int w=96,h=54;static SDL_Texture*texture=nullptr;
 static Uint64 updated=0;static SDL_Surface*last_source=nullptr;static int last_screen=-999,last_style=-1;
 SDL_Surface*source=((g.screen==10||g.screen==20)&&g.imgBuf.p)?g.imgBuf.p.get():g.canvas.im.p.get();
 if(!source)return;
 if(!texture){texture=SDL_CreateTexture(r,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STREAMING,w,h);if(!texture)return;SDL_SetTextureScaleMode(texture,SDL_ScaleModeLinear);}
 const Uint64 now=SDL_GetTicks64();
 const int style=presentation_settings.blur*10+presentation_settings.brightness;
 if(now-updated>=250||last_source!=source||last_screen!=g.screen||last_style!=style){
  const int radius=2+presentation_settings.blur*3,span=radius*2+1;
  struct Pixel{int r,g,b;};static Pixel pixels[w*h],horizontal[w*h];static uint32_t rgba[w*h];
  const int crop_w=source->w,crop_h=crop_w*9/16,crop_y=std::max(0,(std::min(source->h,256)-crop_h)/2);
  for(int y=0;y<h;y++)for(int x=0;x<w;x++){
   const int sx=std::min(source->w-1,(x*crop_w+crop_w/2)/w),sy=std::min(source->h-1,crop_y+(y*crop_h+crop_h/2)/h);
   const uint32_t value=*(const uint32_t*)((const char*)source->pixels+sy*source->pitch+sx*4);Uint8 red,green,blue,alpha;SDL_GetRGBA(value,source->format,&red,&green,&blue,&alpha);pixels[y*w+x]={red,green,blue};
  }
  // Separable blur costs only a few thousand samples, updated four times/sec.
  for(int y=0;y<h;y++)for(int x=0;x<w;x++){Pixel sum{};for(int k=-radius;k<=radius;k++){const Pixel p=pixels[y*w+std::clamp(x+k,0,w-1)];sum.r+=p.r;sum.g+=p.g;sum.b+=p.b;}horizontal[y*w+x]={sum.r/span,sum.g/span,sum.b/span};}
  SDL_PixelFormat*format=SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32);
  if(!format)return;
  for(int y=0;y<h;y++)for(int x=0;x<w;x++){Pixel sum{};for(int k=-radius;k<=radius;k++){const Pixel p=horizontal[std::clamp(y+k,0,h-1)*w+x];sum.r+=p.r;sum.g+=p.g;sum.b+=p.b;}rgba[y*w+x]=SDL_MapRGBA(format,sum.r/span,sum.g/span,sum.b/span,255);}
  SDL_FreeFormat(format);SDL_UpdateTexture(texture,nullptr,rgba,w*4);updated=now;last_source=source;last_screen=g.screen;last_style=style;
 }
 const SDL_Rect full{0,0,1920,1080};SDL_RenderCopy(r,texture,nullptr,&full);
 SDL_SetRenderDrawBlendMode(r,SDL_BLENDMODE_BLEND);SDL_SetRenderDrawColor(r,5,8,18,(Uint8)(200-presentation_settings.brightness*40));
 const SDL_Rect left{0,0,555,1080},right{1365,0,555,1080};SDL_RenderFillRect(r,&left);SDL_RenderFillRect(r,&right);
 // Slightly deepen the ambient panel edges immediately beside the game.
 for(int x=0;x<48;x++){SDL_SetRenderDrawColor(r,0,0,0,(Uint8)(x*2));SDL_Rect l{507+x,0,1,1080},rr{1412-x,0,1,1080};SDL_RenderFillRect(r,&l);SDL_RenderFillRect(r,&rr);}
 SDL_SetRenderDrawBlendMode(r,SDL_BLENDMODE_NONE);
}
