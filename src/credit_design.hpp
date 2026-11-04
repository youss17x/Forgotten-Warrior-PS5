/*
 * PS5 port contributions and enhancements: Youss Riaal, 2026.
 * SPDX-License-Identifier: GPL-3.0-only
 * Applies to original port contributions only; see COPYRIGHT.md and NOTICE.md.
 * Preserve existing upstream notices. No relicensing of original game content.
 */
#pragma once
#include "platform.hpp"
#include "credit_font.hpp"
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

inline void credit_text(Image&im,const char*text,float size,int baseline,float tracking,int top,int bottom){
 stbtt_fontinfo font;stbtt_InitFont(&font,credit_font,0);float scale=stbtt_ScaleForPixelHeight(&font,size),width=0;
 for(const char*p=text;*p;p++){int advance;stbtt_GetCodepointHMetrics(&font,*p,&advance,nullptr);width+=advance*scale+tracking;}width-=tracking;
 float x=(im.getWidth()-width)/2;
 for(const char*p=text;*p;p++){int w,h,dx,dy,advance;unsigned char*bitmap=stbtt_GetCodepointBitmap(&font,scale,scale,*p,&w,&h,&dx,&dy);stbtt_GetCodepointHMetrics(&font,*p,&advance,nullptr);
  for(int j=0;j<h;j++)for(int i=0;i<w;i++){int xx=int(x)+dx+i,yy=baseline+dy+j;if(xx<0||yy<0||xx>=im.getWidth()||yy>=im.getHeight())continue;unsigned char*pixel=(unsigned char*)im.p->pixels+yy*im.p->pitch+xx*4;int a=bitmap[j*w+i];for(int c=0;c<3;c++){int shift=(2-c)*8;int color=(((top>>shift)&255)*(h-j)+((bottom>>shift)&255)*j)/std::max(1,h);pixel[c]=(pixel[c]*(255-a)+color*a)/255;}pixel[3]=255;}
  stbtt_FreeBitmap(bitmap,nullptr);x+=advance*scale+tracking;
 }
}
inline Image make_credit_design(){
 Image im=Image::createImage(810,84);Graphics g=im.getGraphics();
 for(int y=0;y<84;y++){g.setColor(11+y/20,16+y/14,30+y/6);g.fillRect(0,y,810,1);}
 for(int x=0;x<810;x++){int strength=255-abs(x-405)*190/405;g.setColor(190*strength/255,150*strength/255,77*strength/255);g.fillRect(x,0,1,2);g.fillRect(x,82,1,1);}
 g.setColor(0x594a35);g.fillRect(74,43,155,1);g.fillRect(581,43,155,1);
 g.setColor(0xc5a368);for(int d=-5;d<=5;d++){int half=5-abs(d);g.fillRect(58-half,43+d,1+2*half,1);g.fillRect(752-half,43+d,1+2*half,1);}
 credit_text(im,"REMASTERED BY",14,24,3.2f,0xd0c5ad,0x9b927f);
 credit_text(im,"YOUSS RIAAL",35,66,3.5f,0xffebad,0xbf893f);
 return im;
}
