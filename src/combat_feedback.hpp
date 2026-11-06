/* PS5 presentation contributions: Youss Riaal, 2026.
 * SPDX-License-Identifier: GPL-3.0-only; see COPYRIGHT.md and NOTICE.md. */
#pragma once
struct CombatSnapshot{int screen,stage,chapter,hp;bool playing;std::vector<int>enemy_hp;};
inline CombatSnapshot combat_snapshot(const GameScreen&g){CombatSnapshot s{g.screen,g.stage,g.chap,g.h_hp,g.game_on,{}};for(int i=0;i<g.e_hp.length();i++)s.enemy_hp.push_back(g.e_hp[i]);return s;}
inline int combat_feedback_event(const CombatSnapshot&before,const GameScreen&g){
 if(g.vib!=1||!before.playing||before.screen!=10||g.screen!=10||g.stage!=before.stage||g.chap!=before.chapter||g.state==20)return 0;
 if(g.h_hp<before.hp)return 2;
 for(int i=0;i<(int)before.enemy_hp.size()&&i<g.e_hp.length();i++)if(before.enemy_hp[i]>0&&g.e_hp[i]<before.enemy_hp[i])return 1;
 return 0;
}
inline void tick_with_feedback(GameScreen&g){
 const auto before=combat_snapshot(g);g.tick();const int event=combat_feedback_event(before,g);
 if(event&&controller){static Uint64 last=0;const Uint64 now=SDL_GetTicks64();if(now-last>=120){SDL_GameControllerRumble(controller,event==2?8000:4000,event==2?4000:7000,event==2?85:40);last=now;}}
}
