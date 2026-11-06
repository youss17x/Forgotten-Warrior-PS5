/*
 * PS5 port contributions and enhancements: Youss Riaal, 2026.
 * SPDX-License-Identifier: GPL-3.0-only
 * Applies to original port contributions only; see COPYRIGHT.md and NOTICE.md.
 *
 * The release does not include any original game files. On start-up the game
 * looks for them in <save_dir>/data. If they are missing it extracts them from
 * a .jar of the original game that the user placed in <save_dir>, and if there
 * is none it shows setup instructions until the files are in place.
 */
#pragma once
#include "platform.hpp"
#include "asset_manifest.hpp"
#include <dirent.h>

inline std::string user_data_dir(){return save_dir+"/data";}

inline bool file_exists(const std::string&p){FILE*f=fopen(p.c_str(),"rb");if(!f)return false;fclose(f);return true;}

inline int missing_game_files(const std::string&dir,std::string*first=nullptr){
    int missing=0;
    for(const char*name:original_game_files)if(!file_exists(dir+"/"+name)){if(!missing&&first)*first=name;missing++;}
    return missing;
}

inline bool wanted_game_file(const std::string&name){
    for(const char*n:original_game_files)if(name==n)return true;
    return false;
}

inline uint32_t rd16(const unsigned char*p){return p[0]|(p[1]<<8);}
inline uint32_t rd32(const unsigned char*p){return p[0]|(p[1]<<8)|(p[2]<<16)|(uint32_t(p[3])<<24);}

// Extracts the original game files from a .jar (a ZIP archive). Only names listed
// in original_game_files are written, flattened into out_dir. Returns the count.
inline int extract_game_jar(const std::string&jar,const std::string&out_dir){
    FILE*f=fopen(jar.c_str(),"rb");if(!f)return 0;
    fseek(f,0,SEEK_END);long size=ftell(f);fseek(f,0,SEEK_SET);
    if(size<22||size>256L*1024*1024){fclose(f);return 0;}
    std::vector<unsigned char>z(size);bool ok=fread(z.data(),1,size,f)==(size_t)size;fclose(f);if(!ok)return 0;
    long eocd=-1;for(long i=size-22;i>=0&&i>=size-22-65535;i--)if(rd32(&z[i])==0x06054b50){eocd=i;break;}
    if(eocd<0)return 0;
    uint32_t count=rd16(&z[eocd+10]),cd=rd32(&z[eocd+16]);int written=0;
    for(uint32_t n=0,p=cd;n<count;n++){
        if(p+46>(uint32_t)size||rd32(&z[p])!=0x02014b50)break;
        uint32_t method=rd16(&z[p+10]),csize=rd32(&z[p+20]),usize=rd32(&z[p+24]),nlen=rd16(&z[p+28]),xlen=rd16(&z[p+30]),clen=rd16(&z[p+32]),local=rd32(&z[p+42]);
        if(p+46+nlen>(uint32_t)size)break;
        std::string name((const char*)&z[p+46],nlen);p+=46+nlen+xlen+clen;
        auto slash=name.find_last_of('/');std::string base=slash==std::string::npos?name:name.substr(slash+1);
        if(base.empty()||!wanted_game_file(base))continue;
        if(local+30>(uint32_t)size||rd32(&z[local])!=0x04034b50)continue;
        uint32_t data=local+30+rd16(&z[local+26])+rd16(&z[local+28]);
        if(data+csize>(uint32_t)size||usize>64u*1024*1024)continue;
        std::vector<char>out;
        if(method==0){out.assign((const char*)&z[data],(const char*)&z[data]+csize);}
        else if(method==8){out.resize(usize?usize:1);int got=stbi_zlib_decode_noheader_buffer(out.data(),(int)out.size(),(const char*)&z[data],(int)csize);if(got<0||(uint32_t)got!=usize)continue;out.resize(got);}
        else continue;
        const std::string path=out_dir+"/"+base,tmp=path+".new";FILE*o=fopen(tmp.c_str(),"wb");if(!o)continue;
        bool good=fwrite(out.data(),1,out.size(),o)==out.size();good=fclose(o)==0&&good;
        if(good){remove(path.c_str());rename(tmp.c_str(),path.c_str());written++;}else remove(tmp.c_str());
    }
    return written;
}

inline std::vector<std::string> find_jars(const std::string&dir){
    std::vector<std::string>jars;
    if(DIR*d=opendir(dir.c_str())){
        while(auto*e=readdir(d)){std::string n=e->d_name;if(n.size()>4){std::string ext=n.substr(n.size()-4);for(auto&c:ext)if(c>='A'&&c<='Z')c=char(c-'A'+'a');if(ext==".jar")jars.push_back(dir+"/"+n);}}
        closedir(d);std::sort(jars.begin(),jars.end());
        fprintf(stdout,"Found %d .jar file(s) in %s\n",(int)jars.size(),dir.c_str());
    }else fprintf(stdout,"Cannot list %s; trying fixed .jar names\n",dir.c_str());
    // Fixed names, in case listing the folder is not available on the console.
    for(const char*n:{"game.jar","Game.jar","ForgottenWarrior.jar","Forgotten-Warrior.jar","Forgotten Warrior.jar","Forgotten-Warrior_J2ME_EN_v291.jar"}){
        const std::string path=dir+"/"+n;if(std::find(jars.begin(),jars.end(),path)==jars.end()&&file_exists(path))jars.push_back(path);
    }
    return jars;
}

// Points asset_dir at the user's data folder. Returns the number of files still missing.
inline int prepare_user_data(std::string*first_missing=nullptr){
    const std::string dir=user_data_dir();
#ifdef _WIN32
    _mkdir(dir.c_str());
#else
    mkdir(dir.c_str(),0755);
#endif
    asset_dir=dir;
    int missing=missing_game_files(dir);
    if(missing){
        for(const auto&jar:find_jars(save_dir)){
            int n=extract_game_jar(jar,dir);if(!n)fprintf(stdout,"Could not extract game files from %s\n",jar.c_str());
            fprintf(stdout,"Extracted %d game files from %s\n",n,jar.c_str());
            missing=missing_game_files(dir);if(!missing)break;
        }
    }
    missing=missing_game_files(dir,first_missing);
    if(missing)fprintf(stdout,"Original game files missing: %d (first: %s)\n",missing,first_missing?first_missing->c_str():"?");
    return missing;
}

inline void draw_setup_screen(SDL_Renderer*r,int missing,const std::string&first){
    Image canvas=Image::createImage(640,360);Graphics g=canvas.getGraphics();
    g.setColor(0x101018);g.fillRect(0,0,640,360);
    g.setColor(0xffd060);g.drawString(String("FORGOTTEN WARRIOR REMASTERED - SETUP"),320,28,1);
    g.setColor(0xffffff);
    const std::string lines[]={
        "This port does not include the original game's artwork, maps or audio.",
        "Please add them from your own copy of the original J2ME game:",
        "",
        "Option 1: copy the game's .jar file to",
        "          "+save_dir+"/",
        "          (any name ending in .jar; if it is not found, rename it game.jar)",
        "          The game extracts the files it needs automatically.",
        "",
        "Option 2: extract the .jar yourself and copy its files into",
        "          "+user_data_dir()+"/",
        "",
        "Then press CROSS to check again.",
    };
    int y=64;for(const auto&l:lines){g.drawString(String(l),40,y,0);y+=18;}
    g.setColor(0xff8080);g.drawString(String("Missing files: "+std::to_string(missing)+" of "+std::to_string((int)(sizeof(original_game_files)/sizeof(*original_game_files)))+"  (first: "+first+")"),40,y+14,0);
    SDL_Texture*t=SDL_CreateTextureFromSurface(r,canvas.p.get());
    SDL_SetRenderDrawColor(r,0,0,0,255);SDL_RenderClear(r);
    if(t){SDL_RenderCopy(r,t,nullptr,nullptr);SDL_DestroyTexture(t);}
    SDL_RenderPresent(r);
}

// Blocks on the setup screen until every original game file is present.
// Returns false if the user quits instead.
inline bool ensure_user_data(SDL_Renderer*r){
    std::string first;int missing=prepare_user_data(&first);
    while(missing){
        draw_setup_screen(r,missing,first);
        SDL_Event e;bool retry=false;
        while(SDL_WaitEventTimeout(&e,500)){
            if(e.type==SDL_QUIT)return false;
            if(e.type==SDL_CONTROLLERDEVICEADDED&&!controller)controller=SDL_GameControllerOpen(e.cdevice.which);
            if((e.type==SDL_CONTROLLERBUTTONDOWN&&e.cbutton.button==SDL_CONTROLLER_BUTTON_A)||(e.type==SDL_KEYDOWN&&(e.key.keysym.sym==SDLK_RETURN||e.key.keysym.sym==SDLK_SPACE)))retry=true;
        }
        if(retry){first.clear();missing=prepare_user_data(&first);}
    }
    return true;
}
