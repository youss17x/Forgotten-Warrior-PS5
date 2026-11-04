/*
 * PS5 port contributions and enhancements: Youss Riaal, 2026.
 * SPDX-License-Identifier: GPL-3.0-only
 * Applies to original port contributions only; see COPYRIGHT.md and NOTICE.md.
 * Preserve existing upstream notices. No relicensing of original game content.
 */
#pragma once
#include "platform.hpp"

// Code-drawn DualSense glyphs stay crisp at the game's native pixel resolution.
inline void help_line(Graphics&g,int x,int y,int x2,int y2){int dx=abs(x2-x),sx=x<x2?1:-1,dy=-abs(y2-y),sy=y<y2?1:-1,e=dx+dy;for(;;){g.fillRect(x,y,1,1);if(x==x2&&y==y2)break;int e2=e*2;if(e2>=dy){e+=dy;x+=sx;}if(e2<=dx){e+=dx;y+=sy;}}}
inline void help_button(Graphics g,const char*name,int x,int y){
 g.setColor(0x20232b);for(int j=-10;j<=10;j++)for(int i=-10;i<=10;i++)if(i*i+j*j<=100)g.fillRect(x+i,y+j,1,1);
 g.setColor(0xf4f4f5);
 if(!strcmp(name,"cross")){help_line(g,x-4,y-4,x+4,y+4);help_line(g,x-4,y+4,x+4,y-4);}
 else if(!strcmp(name,"square"))g.drawRect(x-4,y-4,8,8);
 else if(!strcmp(name,"circle")){for(int j=-5;j<=5;j++)for(int i=-5;i<=5;i++){int d=i*i+j*j;if(d>=20&&d<=30)g.fillRect(x+i,y+j,1,1);}}
 else if(!strcmp(name,"triangle")){help_line(g,x,y-5,x-5,y+4);help_line(g,x-5,y+4,x+5,y+4);help_line(g,x+5,y+4,x,y-5);}
 else if(!strcmp(name,"dpad")){g.fillRect(x-2,y-7,5,15);g.fillRect(x-7,y-2,15,5);g.setColor(0x20232b);g.fillRect(x-1,y-1,3,3);}
 else if(!strcmp(name,"up")||!strcmp(name,"down")){int d=!strcmp(name,"up")?-1:1;help_line(g,x,y-5*d,x,y+5*d);help_line(g,x,y+5*d,x-4,y+d);help_line(g,x,y+5*d,x+4,y+d);}
 else {g.drawString(String(name),x,y-5,17);}
}
inline void help_shoulder(Graphics g,const char*name,int x,int y,int width=25){g.setColor(0x20232b);g.fillRect(x-width/2,y-8,width,17);g.setColor(0xf4f4f5);g.drawRect(x-width/2,y-8,width-1,16);g.drawString(String(name),x,y-5,17);}
inline void draw_controller_help(Graphics g,int page){
 const char*title=page==2?"STAIRS":page==3?"CAVE":page==4?"SPECIAL ATTACKS":"CONTROLS";
 g.setColor(0x38220b);g.drawString(String(title),120,101,17);
 auto label=[&](const char*s,int y){g.setColor(0x38220b);g.drawString(String(s),83,y-5,20);};
 if(page==0){
  help_button(g,"dpad",28,125);help_button(g,"LS",55,125);label("LEFT / RIGHT",125);
  help_button(g,"cross",42,150);label("JUMP",150);
  help_button(g,"square",42,175);label("ATTACK",175);
  help_button(g,"cross",28,200);help_button(g,"square",55,200);g.setColor(0x38220b);g.drawString(String("+"),42,195,17);label("FLYING KICK",200);
 }else if(page==1){
  help_button(g,"circle",42,122);label("HP POTION",122);
  help_button(g,"triangle",42,143);label("MP POTION",143);
  help_shoulder(g,"R1",42,164);label("DEATHBLOW",164);
  help_shoulder(g,"TOUCHPAD",42,185,65);label("PAUSE / RESUME",185);
  help_shoulder(g,"OPTIONS",42,206,53);label("OPTIONS",206);
 }else if(page==2){
  help_button(g,"up",42,135);label("CLIMB UP",135);
  help_button(g,"down",42,170);label("CLIMB DOWN",170);
  g.setColor(0x38220b);g.drawString(String("D-PAD / LEFT STICK"),120,198,17);
 }else if(page==3){
  help_button(g,"up",42,131);label("ENTER",131);
  help_button(g,"down",42,161);label("EXIT",161);
  g.setColor(0x38220b);g.drawString(String("WHILE INSIDE A CAVE,"),120,185,17);g.drawString(String("YOU ARE INVINCIBLE"),120,201,17);
 }else if(page==4){
  help_shoulder(g,"R1",42,125);label("USE SPECIAL",125);
  g.setColor(0x38220b);
  g.drawString(String("DEATHBLOW"),20,145,20);g.drawString(String("33% MP"),169,145,20);
  g.drawString(String("FIRESTORM"),20,166,20);g.drawString(String("66% MP"),169,166,20);
  g.drawString(String("THE UNDEAD"),20,187,20);g.drawString(String("99% MP"),169,187,20);
  g.drawString(String("AUTO: CURRENT MP"),120,207,17);
 }
}
