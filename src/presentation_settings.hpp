/* PS5 presentation contributions: Youss Riaal, 2026.
 * SPDX-License-Identifier: GPL-3.0-only; see COPYRIGHT.md and NOTICE.md. */
#pragma once
struct PresentationSettings{int ambient=1,blur=1,brightness=2;};
inline PresentationSettings presentation_settings;
inline void save_presentation_settings(){const auto&p=presentation_settings;save_value(String("display"),p.ambient*100+p.blur*10+p.brightness);}
inline void load_presentation_settings(){int value;if(load_value(String("display"),value)&&value>=0&&value/100<=1&&(value/10)%10<=3&&value%10<=4)presentation_settings={value/100,(value/10)%10,value%10};}
inline void change_presentation_setting(int row,int direction){
 auto&p=presentation_settings;
 if(row==3)p.ambient=1-p.ambient;
 if(row==4)p.blur=std::clamp(p.blur+direction,0,3);
 if(row==5)p.brightness=std::clamp(p.brightness+direction,0,4);
 save_presentation_settings();
}
inline void draw_presentation_settings(Graphics graphics,int selected,int volume,int vibration,int speed){
 graphics.setColor(0x10192c);graphics.fillRect(7,72,226,191);
 graphics.setColor(0xc8a766);graphics.drawRect(7,72,225,190);
 graphics.setColor(0xf5deaa);graphics.drawString(String("SETTINGS"),120,82,17);
 const char*labels[]={"SOUND","VIBRATION","GAME SPEED","SIDE PANELS","BLUR","BRIGHTNESS"};
 const char*blur_names[]={"LOW","MEDIUM","HIGH","MAX"};
 const String values[]={String(volume?"ON":"OFF"),String(vibration?"ON":"OFF"),Integer::toString(speed),String(presentation_settings.ambient?"AMBIENT":"BLACK"),String(blur_names[presentation_settings.blur]),Integer::toString(presentation_settings.brightness+1)};
 for(int row=0;row<6;row++){
  const int y=104+row*19;
  if(row==selected){graphics.setColor(0x34496c);graphics.fillRect(13,y-4,214,19);graphics.setColor(0xf3ce7c);graphics.fillRect(13,y-4,3,19);}
  graphics.setColor(row==selected?0xffe9b6:0xdce5f2);graphics.drawString(String(labels[row]),22,y,20);graphics.drawString(values[row],216,y,24);
 }
 graphics.setColor(0);graphics.fillRect(0,264,240,29);
 graphics.setColor(0xf0e3c4);graphics.drawString(String("UP/DOWN: SELECT"),120,268,17);graphics.drawString(String("LEFT/RIGHT: CHANGE"),120,281,17);
}
