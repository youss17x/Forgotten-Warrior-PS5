/*
 * PS5 port contributions and enhancements: Youss Riaal, 2026.
 * SPDX-License-Identifier: GPL-3.0-only
 * Applies to original port contributions only; see COPYRIGHT.md and NOTICE.md.
 * Preserve existing upstream notices. No relicensing of original game content.
 */
#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>
#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>
#endif
using byte=int8_t;
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "stb_image.h"
#define STB_EASY_FONT_IMPLEMENTATION
#include "stb_easy_font.h"
#define TSF_IMPLEMENTATION
#include "tsf.h"
#define TML_IMPLEMENTATION
#include "tml.h"

inline std::string asset_dir="assets",save_dir="save";
inline bool quitting=false;
inline SDL_GameController* controller=nullptr;
template<class T> struct JArray {
    std::shared_ptr<std::vector<T>> p;
    JArray()=default; JArray(std::nullptr_t){}
    explicit JArray(int n):p(std::make_shared<std::vector<T>>(std::max(0,n))){}
    T& operator[](int n){if(!p || n<0 || n>=(int)p->size())throw std::out_of_range("Java array index "+std::to_string(n));return (*p)[n];}
    const T& operator[](int n) const {if(!p || n<0 || n>=(int)p->size())throw std::out_of_range("Java array index");return (*p)[n];}
    int length() const{return p?(int)p->size():0;}
    JArray& operator=(std::nullptr_t){p.reset();return *this;}
    bool operator==(std::nullptr_t)const{return !p;}
    bool operator!=(std::nullptr_t)const{return !!p;}
};
inline JArray<JArray<int8_t>> matrix(int n,int m){JArray<JArray<int8_t>> a(n);for(int i=0;i<n;i++)a[i]=JArray<int8_t>(m);return a;}
struct String {
    std::string s; bool present=false;
    String()=default;String(std::nullptr_t){};String(const char* v):s(v?v:""),present(v!=nullptr){}
    String(std::string v):s(std::move(v)),present(true){}
    String(JArray<int8_t> a):present(true){for(int i=0;i<a.length();i++)s+=char(a[i]);}
    int length()const{return (int)s.size();}
    JArray<char> toCharArray()const{JArray<char>a(length());for(int i=0;i<length();i++)a[i]=s[i];return a;}
    String substring(int a,int b)const{return s.substr(a,b-a);} String substring(int a)const{return s.substr(a);}
    int indexOf(String v,int from=0)const{auto n=s.find(v.s,from);return n==std::string::npos?-1:(int)n;}
    bool operator==(const String& o)const{return present==o.present&&s==o.s;}
    bool operator!=(const String& o)const{return !(*this==o);}
    bool operator==(std::nullptr_t)const{return !present;} bool operator!=(std::nullptr_t)const{return present;}
    String& operator=(std::nullptr_t){s.clear();present=false;return *this;}
    friend String operator+(String a,const String& b){return a.s+b.s;}
    friend String operator+(String a,int b){return a.s+std::to_string(b);}
    friend String operator+(int a,String b){return std::to_string(a)+b.s;}
    static String valueOf(int n){return std::to_string(n);}static String valueOf(char c){return std::string(1,c);}
};
struct Integer{static String toString(int n){return std::to_string(n);}static int parseInt(String s){return std::stoi(s.s);}};
struct Default {bool start_app=false;void destroyApp(bool){} void notifyDestroyed(){quitting=true;}};
struct Display{};struct Runtime{};struct RecordStore{RecordStore&operator=(std::nullptr_t){return *this;}};
struct Random {uint64_t seed=0x1234abcd330eULL;int nextInt(){seed=(seed*0x5deece66dULL+11)&((1ULL<<48)-1);return (int)(seed>>16);}};
inline JArray<int8_t> read_asset(String name,int n){
    JArray<int8_t>a(n);std::string file=name.s;while(!file.empty()&&file[0]=='/')file.erase(0,1);
    FILE*f=fopen((asset_dir+"/"+file).c_str(),"rb");if(f){fread(a.p->data(),1,n,f);fclose(f);}else fprintf(stderr,"Missing asset: %s\n",file.c_str());return a;
}
inline void save_value(String name,int value){
    const auto file=save_dir+"/"+name.s+".sav",tmp=file+".new";FILE*f=fopen(tmp.c_str(),"wb");
    if(!f)return;unsigned char b[]={static_cast<unsigned char>(value>>24),static_cast<unsigned char>(value>>16),static_cast<unsigned char>(value>>8),static_cast<unsigned char>(value)};
    bool ok=fwrite(b,1,4,f)==4;ok=fclose(f)==0&&ok;if(ok){
#ifdef _WIN32
    remove(file.c_str());
#endif
    rename(tmp.c_str(),file.c_str());}
}
inline bool load_value(String name,int&value){FILE*f=fopen((save_dir+"/"+name.s+".sav").c_str(),"rb");if(!f)return false;unsigned char b[4];bool ok=fread(b,1,4,f)==4;fclose(f);if(ok)value=int((uint32_t(b[0])<<24)|(uint32_t(b[1])<<16)|(uint32_t(b[2])<<8)|b[3]);return ok;}
struct Graphics;
struct Image {
    std::shared_ptr<SDL_Surface> p;
    Image()=default;Image(std::nullptr_t){};explicit Image(SDL_Surface*s):p(s,SDL_FreeSurface){}
    Image&operator=(std::nullptr_t){p.reset();return *this;}bool operator==(std::nullptr_t)const{return !p;}bool operator!=(std::nullptr_t)const{return !!p;}
    static Image createImage(int w,int h){auto*s=SDL_CreateRGBSurfaceWithFormat(0,w,h,32,SDL_PIXELFORMAT_RGBA32);if(!s)throw std::runtime_error(SDL_GetError());SDL_FillRect(s,nullptr,SDL_MapRGBA(s->format,255,255,255,255));return Image(s);}
    static Image createImage(String name){
        auto path=asset_dir+name.s;int w,h,c;unsigned char*b=stbi_load(path.c_str(),&w,&h,&c,4);
        if(!b)throw std::runtime_error("Image: "+path);
        Image im=createImage(w,h);for(int y=0;y<h;y++)memcpy((char*)im.p->pixels+y*im.p->pitch,b+y*w*4,w*4);stbi_image_free(b);SDL_SetSurfaceBlendMode(im.p.get(),SDL_BLENDMODE_BLEND);return im;
    }
    int getWidth()const{return p?p->w:0;}int getHeight()const{return p?p->h:0;}Graphics getGraphics()const;
};
struct Graphics {
    Image im; uint32_t rgb=0;
    Graphics()=default;Graphics(std::nullptr_t){};explicit Graphics(Image i):im(i){}
    void setColor(int c){rgb=c;}
    void setColor(int r,int g,int b){rgb=(r<<16)|(g<<8)|b;}
    uint32_t color()const{return SDL_MapRGBA(im.p->format,(rgb>>16)&255,(rgb>>8)&255,rgb&255,255);}
    void fillRect(int x,int y,int w,int h){if(!im.p||w<=0||h<=0)return;SDL_Rect r{x,y,w,h};SDL_FillRect(im.p.get(),&r,color());}
    void drawRect(int x,int y,int w,int h){fillRect(x,y,w+1,1);fillRect(x,y+h,w+1,1);fillRect(x,y,1,h+1);fillRect(x+w,y,1,h+1);}
    void drawImage(Image i,int x,int y,int anchor){if(!i.p||!im.p)return;if(anchor&1)x-=i.p->w/2;else if(anchor&8)x-=i.p->w;if(anchor&2)y-=i.p->h/2;else if(anchor&32)y-=i.p->h;SDL_Rect r{x,y,i.p->w,i.p->h};SDL_BlitSurface(i.p.get(),nullptr,im.p.get(),&r);}
    void drawString(String text,int x,int y,int anchor){
        std::vector<char>t(text.s.begin(),text.s.end());t.push_back(0);int w=stb_easy_font_width(t.data());if(anchor&1)x-=w/2;else if(anchor&8)x-=w;if(anchor&2)y-=6;else if(anchor&32)y-=12;
        struct V{float x,y,z;unsigned char c[4];};std::vector<V>v(text.length()*64+16);int q=stb_easy_font_print(0,0,t.data(),nullptr,v.data(),(int)(v.size()*sizeof(V)));
        for(int i=0;i<q;i++){int x1=(int)v[i*4].x,y1=(int)v[i*4].y,x2=(int)v[i*4+2].x,y2=(int)v[i*4+2].y;fillRect(x+x1,y+y1,std::max(1,x2-x1),std::max(1,y2-y1));}
    }
};
inline Graphics Image::getGraphics()const{return Graphics(*this);}
inline tsf* synth=nullptr;inline tml_message* midi=nullptr;inline tml_message* next_midi=nullptr;inline double midi_ms=0;inline SDL_AudioDeviceID audio_device=0;
inline void audio_callback(void*,Uint8*stream,int bytes){
    float*out=(float*)stream;int frames=bytes/(sizeof(float)*2);memset(stream,0,bytes);if(!synth)return;
    while(frames>0){int count=std::min(frames,64);while(next_midi&&next_midi->time<=midi_ms){auto*m=next_midi;
        if(m->type==TML_PROGRAM_CHANGE)tsf_channel_set_presetnumber(synth,m->channel,m->program,m->channel==9);
        else if(m->type==TML_NOTE_ON)tsf_channel_note_on(synth,m->channel,m->key,m->velocity/127.f);
        else if(m->type==TML_NOTE_OFF)tsf_channel_note_off(synth,m->channel,m->key);
        else if(m->type==TML_PITCH_BEND)tsf_channel_set_pitchwheel(synth,m->channel,m->pitch_bend);
        else if(m->type==TML_CONTROL_CHANGE)tsf_channel_midi_control(synth,m->channel,m->control,m->control_value);
        next_midi=m->next;
    }tsf_render_float(synth,out,count,0);midi_ms+=count*1000.0/44100.0;out+=count*2;frames-=count;}
}
inline void play_midi(int n){if(!audio_device||!synth)return;static const int ids[]={0,1,3,4,5,6,7};if(n<0||n>6)return;SDL_LockAudioDevice(audio_device);tsf_reset(synth);if(midi)tml_free(midi);midi=tml_load_filename((asset_dir+"/"+std::to_string(ids[n])+".mid").c_str());next_midi=midi;midi_ms=0;SDL_UnlockAudioDevice(audio_device);}
struct AudioClip{bool operator!=(std::nullptr_t)const{return true;}AudioClip&operator=(std::nullptr_t){return *this;}void stop(){if(audio_device){SDL_LockAudioDevice(audio_device);next_midi=nullptr;if(synth)tsf_reset(synth);SDL_UnlockAudioDevice(audio_device);}}};
inline void rumble(int ms){if(controller)SDL_GameControllerRumble(controller,16000,24000,(Uint32)ms);}
