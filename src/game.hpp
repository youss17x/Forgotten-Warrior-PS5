#pragma once
#include "platform.hpp"
#include "controller_help.hpp"
#include "presentation_settings.hpp"
class GameScreen {
public:
    Graphics canvas;

    void repaint() { paint(canvas); }
    void serviceRepaints() {}
    void setFullScreenMode(bool) {}

    Display display{};
    int gg_yy = 11;
    int tile_size_x = 30;
    int tile_size_y = 32;
    int move_gap_x = 10;
    int move_gap_y = 8;
    int h_speed{};
    int game_speed{};
    AudioClip audioClip{};
    int btn_y{};
    int btn_r_x = 235;
    int START_X{};
    int menu_mode{};
    int sadari{};
    bool ing_ss{};
    Default DF{};
    Runtime r{};
    Random rnd{};
    int tmp_move{};
    Graphics gg{};
    RecordStore recordStore{};
    Graphics buf_g{};
    Image imgBuf{};
    bool key_pp{};
    bool game_on{};
    bool t_game_on{};
    int screen{};
    int ani_step{};
    int b_step{};
    int m_mode{};
    int p_mode{};
    int vol{};
    int vib{};
    int state{};
    JArray<int8_t> t_byte{};
    int stage{};
    int chap{};
    int h_x{};
    int h_y{};
    int h_idx{};
    int h_dir{};
    int h_mo{};
    int tmp_mo{};
    int mo_stop{};
    int y_gap{};
    int h_dem{};
    int h_hp{};
    int h_max_hp{};
    int mp{};
    int max_mp{};
    int h_att{};
    int att_d{};
    int w_x{};
    int w_x1{};
    int w_x2{};
    int w_y{};
    int w_y1{};
    int w_y2{};
    int w_dir{};
    int w_rng{};
    int w_dem{};
    int w_att{};
    int gold{};
    int special{};
    int god{};
    int auto_move{};
    String msg{};
    JArray<int> sn_m{};
    JArray<String> strSN{};
    JArray<int> item_p{};
    JArray<int> pt{};
    JArray<int> e_stage{};
    JArray<int> e_x{};
    JArray<int> e_y{};
    JArray<int> e_y_gap{};
    JArray<int> e_k{};
    JArray<int> e_hp{};
    JArray<int> e_max_hp{};
    JArray<int> e_att{};
    JArray<int> e_att_time{};
    JArray<int> e_ai{};
    JArray<int> e_dir{};
    JArray<int> e_ai_time{};
    JArray<int> e_mo{};
    JArray<int> e_idx{};
    JArray<int> e_rng{};
    JArray<int> e_et{};
    JArray<int> e_tt{};
    JArray<int> e_mo_stop{};
    JArray<int> e_w_x{};
    JArray<int> e_w_y{};
    JArray<int> e_w_dir{};
    JArray<int> ai_class{};
    JArray<int> o_x{};
    JArray<int> o_y{};
    JArray<int> o_k{};
    JArray<int> o_st{};
    JArray<JArray<int8_t>> map{};
    Image imgLL{};
    Image imgSlot{};
    Image imgOk{};
    JArray<Image> imgNum{};
    Image imgDD{};
    Image imgPT{};
    Image imgM_back{};
    Image imgM_back2{};
    Image imgCh{};
    Image imgTTT{};
    Image imgTTT2{};
    JArray<Image> imgTile{};
    JArray<Image> imgOB{};
    JArray<Image> imgDe{};
    JArray<Image> imgDDD{};
    Image imgPilll{};
    Image imgAw{};
    Image imgWel{};
    JArray<Image> imgHero{};
    Image imgFF{};
    Image imgPil{};
    Image imgRing{};
    JArray<Image> imgEnemy{};
    Image imgE_box{};
    JArray<Image> imgE{};
    Image imgBim{};
    JArray<Image> imgE_att{};
    JArray<Image> imgDead{};
    Image imgEff{};
    Image imgLogo{};
    Image imgIkey{};
    Image imgGetItem{};
    Image imgConCon{};
    Image imgM_menu{};
    Image imgOn{};
    Image imgOff{};
    Image imgCheck{};
    Image imgSkip{};
    Image imgPlay{};
    Image imgOp{};
    Image imgPause{};

    GameScreen(Default default_, Display display) {
        this->display = display;
        this->h_speed = 3;
        this->game_speed = 55;
        this->audioClip = nullptr;
        this->btn_y = 298;
        this->START_X = 0;
        this->r = Runtime();
        this->rnd = Random();
        this->tmp_move = 0;
        this->recordStore = nullptr;
        this->key_pp = false;
        this->game_on = true;
        this->t_game_on = true;
        this->vol = 1;
        this->stage = 2000;
        this->chap = 0;
        this->h_dir = 0;
        this->max_mp = 100;
        this->w_rng = 1;
        this->sn_m = JArray<int>(4);
        this->item_p = JArray<int>(5);
        this->pt = JArray<int>(2);
        this->e_stage = JArray<int>(12);
        this->e_x = JArray<int>(12);
        this->e_y = JArray<int>(12);
        this->e_y_gap = JArray<int>(12);
        this->e_k = JArray<int>(12);
        this->e_hp = JArray<int>(12);
        this->e_max_hp = JArray<int>(12);
        this->e_att = JArray<int>(12);
        this->e_att_time = JArray<int>(12);
        this->e_ai = JArray<int>(12);
        this->e_dir = JArray<int>(12);
        this->e_ai_time = JArray<int>(12);
        this->e_mo = JArray<int>(12);
        this->e_idx = JArray<int>(12);
        this->e_rng = JArray<int>(12);
        this->e_et = JArray<int>(12);
        this->e_tt = JArray<int>(12);
        this->e_mo_stop = JArray<int>(12);
        this->e_w_x = JArray<int>(12);
        this->e_w_y = JArray<int>(12);
        this->e_w_dir = JArray<int>(12);
        this->ai_class = JArray<int>(12);
        this->imgNum = JArray<Image>(10);
        this->DF = default_;
        
        this->setFullScreenMode(true);
        this->item_p[0] = 120;
        this->item_p[1] = 200;
        this->item_p[2] = 340;
        this->item_p[3] = 35;
        this->item_p[4] = 55;
        this->printStage(String("d"), 3);
        try {
            this->imgPT = Image::createImage((String)String("/ps.png"));
            this->imgE = JArray<Image>(2);
            this->imgConCon = Image::createImage((String)String("/concon.png"));
            this->imgSkip = Image::createImage((String)String("/m_skip.png"));
            int n = 0;
            while (n < 10) {
                if (n < 2) {
                    this->imgE[n] = Image::createImage((String)(String("/logo") + n + String(".png")));
                }
                this->imgNum[n] = Image::createImage((String)(String("/") + n + String(".png")));
                ++n;
            }
            this->imgIkey = Image::createImage((String)String("/ikey.png"));
            this->imgGetItem = Image::createImage((String)String("/getitem.png"));
            this->imgPilll = Image::createImage((String)String("/pil1.png"));
            this->imgRing = Image::createImage((String)String("/fff0.png"));
            this->imgAw = Image::createImage((String)String("/aw.png"));
            this->imgWel = Image::createImage((String)String("/wel.png"));
            this->imgOn = Image::createImage((String)String("/on.png"));
            this->imgOff = Image::createImage((String)String("/off.png"));
            this->imgCh = Image::createImage((String)String("/ch.png"));
            this->imgM_back = Image::createImage((String)String("/m_back.png"));
            this->imgM_back2 = Image::createImage((String)String("/m_back2.png"));
            this->imgOp = Image::createImage((String)String("/b_option.png"));
            this->imgPlay = Image::createImage((String)String("/b_play.png"));
            this->imgPause = Image::createImage((String)String("/b_pause.png"));
            this->imgOk = Image::createImage((String)String("/ok.png"));
            this->imgCheck = Image::createImage((String)String("/arrow.png"));
            this->imgTTT = Image::createImage((String)String("/ttt.png"));
            this->imgTTT2 = Image::createImage((String)String("/ttt2.png"));
            this->imgLogo = Image::createImage((String)String("/logo.png"));
        }
        catch (const std::exception&) {}
    }

    
    void addStage(String string, int n) {
        int value = n==0 ? h_hp*1000+mp : n==1 ? gold*1000+pt[0]*100+pt[1]*10+w_rng : n==2 ? stage*1000+h_x*10+chap : game_speed*1000+h_speed*100+vol*10+vib;
        save_value(string,value);
    }

    
    void printStage(String string, int n) {
        int value=0;
        if (!load_value(string,value)) {
            if(n==0){h_hp=h_max_hp;mp=0;}
            if(n==1){gold=20;pt[0]=1;pt[1]=1;w_rng=1;}
            if(n==2){stage=1;chap=0;h_x=3;h_y=5;}
            if(n==3){h_speed=3;game_speed=55;vol=1;vib=1;}
            return;
        }
        if(n==0){h_hp=value/1000;mp=value%1000;}
        if(n==1){gold=value/1000;pt[0]=value%1000/100;pt[1]=value%100/10;w_rng=value%10;}
        if(n==2){stage=value/1000;h_x=value%1000/10;chap=value%10;h_y=5;}
        if(n==3){game_speed=value/1000;h_speed=value%1000/100;vol=value%100/10;vib=value%10;}
    }

    void load_img(int n) {
        try {
            if (n == 10) {
                this->imgE_box = Image::createImage((String)String("/w_box.png"));
                this->imgBim = Image::createImage((String)String("/bim.png"));
                this->imgE_att = JArray<Image>(2);
                this->imgE = JArray<Image>(4);
                this->imgDead = JArray<Image>(2);
                this->imgEff = Image::createImage((String)String("/eff.png"));
                int n2 = 0;
                while (n2 < 4) {
                    this->imgE[n2] = Image::createImage((String)(String("/w") + n2 + String(".png")));
                    if (n2 < 2) {
                        this->imgE_att[n2] = Image::createImage((String)(String("/e_att") + n2 + String(".png")));
                        this->imgDead[n2] = Image::createImage((String)(String("/dead") + n2 + String(".png")));
                    }
                    ++n2;
                }
            } else if (n == 9) {
                this->imgOB = JArray<Image>(3);
                int n3 = 0;
                while (n3 < 3) {
                    this->imgOB[n3] = Image::createImage((String)(String("/OB") + n3 + String(".png")));
                    ++n3;
                }
            } else if (n == 11) {
                this->imgHero = JArray<Image>(16);
                int n4 = 0;
                while (n4 < 16) {
                    this->imgHero[n4] = Image::createImage((String)(String("/hero") + n4 + String(".png")));
                    ++n4;
                }
            } else if (n == 100) {
                this->imgDD = nullptr;
                this->imgDDD = nullptr;
                if (this->w_rng == 1) {
                    this->imgDDD = JArray<Image>(2);
                    this->imgDDD[0] = Image::createImage((String)String("/ta0.png"));
                    this->imgDDD[1] = Image::createImage((String)String("/ta1.png"));
                    this->imgDD = Image::createImage((String)String("/item1.png"));
                } else {
                    this->imgDD = Image::createImage((String)(String("/item") + (this->w_rng - 2) + String(".png")));
                }
            } else if (n == 12) {
                this->imgTile = JArray<Image>(12);
                this->imgDe = JArray<Image>(2);
                int n5 = 0;
                while (n5 < 12) {
                    this->imgTile[n5] = n5 != 3 && n5 != 11 ? Image::createImage((String)(String("/tile[") + this->chap + String("]") + n5 + String(".png"))) : Image::createImage((String)(String("/tile[0]") + n5 + String(".png")));
                    if (n5 < 2) {
                        this->imgDe[n5] = Image::createImage((String)(String("/de") + n5 + String(".png")));
                    }
                    ++n5;
                }
            } else if (n == 13) {
                this->imgEnemy = JArray<Image>(14);
                int n6 = 0;
                while (n6 < 14) {
                    this->imgEnemy[n6] = n6 < 12 ? (n6 < 6 ? (this->chap == 2 ? Image::createImage((String)(String("/enemy[2]") + (n6 + 6) + String(".png"))) : Image::createImage((String)(String("/enemy[") + this->chap + String("]") + n6 + String(".png")))) : (this->chap == 2 ? Image::createImage((String)(String("/enemy[0]") + n6 + String(".png"))) : Image::createImage((String)(String("/enemy[") + this->chap + String("]") + n6 + String(".png"))))) : Image::createImage((String)(String("/enemy") + n6 + String(".png")));
                    ++n6;
                }
            } else if (n == 20) {
                this->imgPil = Image::createImage((String)(String("/pil") + this->special + String(".png")));
            } else if (n == 15) {
                this->imgOB = JArray<Image>(7);
                int n7 = 0;
                while (n7 < 6) {
                    this->imgOB[n7] = n7 < 2 ? Image::createImage((String)(String("/nina") + n7 + String(".png"))) : (n7 < 4 ? Image::createImage((String)(String("/dog") + (n7 - 2) + String(".png"))) : Image::createImage((String)(String("/dem") + (n7 - 4) + String(".png"))));
                    ++n7;
                }
                this->imgOB[6] = Image::createImage((String)String("/w4.png"));
            } else if (n == 50) {
                this->imgPT = Image::createImage((String)String("/shop.png"));
                this->imgHero = JArray<Image>(5);
                int n8 = 0;
                while (n8 < 5) {
                    this->imgHero[n8] = Image::createImage((String)(String("/item") + n8 + String(".png")));
                    ++n8;
                }
            } else if (n == 2) {
                this->imgLogo = Image::createImage((String)String("/logo.png"));
                if (this->menu_mode == 0) {
                    this->imgLL = Image::createImage((String)String("/mm.png"));
                } else if (this->menu_mode == 1) {
                    this->imgLL = Image::createImage((String)String("/mm1.png"));
                }
            } else if (n == 200) {
                this->imgHero = JArray<Image>(5);
                this->imgEnemy = JArray<Image>(15);
                this->imgE = JArray<Image>(5);
                this->imgE_box = Image::createImage((String)String("/w_box.png"));
                int n9 = 0;
                while (n9 < 5) {
                    this->imgE[n9] = Image::createImage((String)(String("/w") + n9 + String(".png")));
                    if (n9 < 2) {
                        this->imgEnemy[n9] = Image::createImage((String)(String("/nina") + n9 + String(".png")));
                        this->imgEnemy[n9 + 11] = Image::createImage((String)(String("/dem") + n9 + String(".png")));
                        this->imgEnemy[n9 + 13] = Image::createImage((String)(String("/dog") + n9 + String(".png")));
                    }
                    if (n9 < 4) {
                        this->imgEnemy[n9 + 2] = Image::createImage((String)(String("/enemy[0]") + n9 + String(".png")));
                        this->imgEnemy[n9 + 6] = Image::createImage((String)(String("/enemy[0]") + (n9 + 6) + String(".png")));
                        this->imgHero[n9] = Image::createImage((String)(String("/hero") + n9 + String(".png")));
                    } else {
                        this->imgHero[n9] = Image::createImage((String)String("/hero15.png"));
                    }
                    ++n9;
                }
            } else if (n == 400) {
                this->imgPT = Image::createImage((String)String("/s_menu.png"));
            } else if (n == -3) {
                this->imgM_menu = Image::createImage((String)String("/option.png"));
            } else if (n == -4) {
                this->imgM_menu = Image::createImage((String)String("/text10.png"));
            }
        }
        catch (const std::exception&) {
            
        }
        
    }

    void del_img(int n) {
        if (n == 10) {
            this->imgE_box = nullptr;
            this->imgE = nullptr;
            this->imgEff = nullptr;
            this->imgBim = nullptr;
            this->imgE_att = nullptr;
            this->imgDead = nullptr;
        } else if (n == 9) {
            this->imgOB = nullptr;
        } else if (n == 11) {
            this->imgHero = nullptr;
        } else if (n == 100) {
            this->imgDD = nullptr;
            this->imgDDD = nullptr;
        } else if (n == 12) {
            this->imgTile = nullptr;
            this->imgDe = nullptr;
        } else if (n == 13) {
            this->imgEnemy = nullptr;
        } else if (n == 20) {
            this->imgPil = nullptr;
        } else if (n == 15) {
            this->imgOB = nullptr;
        } else if (n == 50) {
            this->imgPT = nullptr;
            this->imgHero = nullptr;
        } else if (n == 2) {
            this->imgLogo = nullptr;
            this->imgLL = nullptr;
        } else if (n == 200) {
            this->imgHero = nullptr;
            this->imgEnemy = nullptr;
            this->imgHero = nullptr;
            this->imgEnemy = nullptr;
            this->imgE = nullptr;
            this->imgE_box = nullptr;
        } else if (n == -100) {
            this->imgM_menu = nullptr;
        } else if (n == 400) {
            this->imgPT = nullptr;
        }
        
    }

    void draw_mback(Graphics graphics) {
        int n = 46;
        graphics.setColor(15442176);
        graphics.drawRect(0, 33 + n, 239, 162);
        graphics.drawRect(2, 35 + n, 235, 158);
        graphics.setColor(16767590);
        graphics.drawRect(1, 34 + n, 237, 160);
        graphics.setColor(10908416);
        graphics.fillRect(3, 36 + n, 234, 157);
        graphics.drawImage(this->imgM_back, 3, 36 + n, 20);
        graphics.drawImage(this->imgM_back2, 3, 187 + n, 20);
        if (this->screen < 0) {
            graphics.setColor(0);
            graphics.fillRect(0, 293, 240, 30);
            help_button(graphics,"circle",188,306);
            graphics.setColor(0xf4f4f5);
            graphics.drawString(String("BACK"),207,301,20);
        }
    }

    void init_game() {
        if (this->m_mode == 3) {
            this->h_max_hp = 130;
            this->h_hp = 130;
            this->mp = 0;
            this->gold = 20;
            this->pt[0] = 1;
            this->pt[1] = 1;
            this->stage = 1;
            this->chap = 0;
            this->h_x = 3;
            this->h_y = 5;
            this->w_rng = 1;
        }
        this->tmp_move = 0;
        this->auto_move = 0;
        this->key_pp = false;
        this->sadari = 0;
        this->ing_ss = false;
        this->att_d = 0;
        this->h_idx = 0;
        this->h_mo = 0;
        this->h_dir = 0;
        this->h_dem = 0;
        this->y_gap = 0;
        this->mo_stop = 0;
        this->h_att = 0;
        this->god = 0;
        this->msg = nullptr;
        this->state = 1;
        this->p_mode = 0;
        this->ani_step = 0;
        this->load_img(9);
        if (this->m_mode != 100) {
            if (this->h_hp < 25) {
                this->h_hp = 30;
            }
            if (this->chap == 0) {
                this->h_max_hp = 130;
            }
            if (this->chap == 1) {
                this->h_max_hp = 95;
            }
            if (this->chap == 2) {
                this->h_max_hp = 80;
            }
            if (this->stage == 1) {
                this->h_hp = this->h_max_hp;
            } else if (this->h_hp > this->h_max_hp) {
                this->h_hp = this->h_max_hp;
            }
            this->load_img(10);
            this->load_img(100);
            this->load_img(11);
            this->load_img(12);
            this->load_img(13);
        } else {
            if (this->chap == 0) {
                this->h_max_hp = 125;
            }
            if (this->chap == 1) {
                this->h_max_hp = 90;
            }
            if (this->chap == 2) {
                this->h_max_hp = 75;
            }
            this->h_hp = this->h_max_hp;
            this->stage = 1;
            this->h_x = 2;
            this->h_y = 5;
            this->addStage(String("a"), 0);
            this->addStage(String("b"), 1);
            this->addStage(String("c"), 2);
        }
        this->w_dem = (this->w_rng - 1) * 5 + 5;
        this->init_en();
        this->init_ob();
        try {
            this->imgBuf = Image::createImage((int)240, (int)256);
            this->buf_g = this->imgBuf.getGraphics();
        }
        catch (const std::exception&) {
            
        }
        this->make_map(8, 8);
        this->make_buf(8, 8);
        this->screen = 10;
        this->game_on = true;
        this->h_idx = 0;
        this->h_mo = 0;
        this->h_dir = 0;
    }

    void load_sn(int n) {
        JArray<int8_t> byArray = this->get_bytes(Integer::toString(this->sn_m[3]) + String(".sn"), 400);
        String string = String(byArray);
        byArray = nullptr;
        JArray<char> cArray = JArray<char>(string.length());
        cArray = string.toCharArray();
        this->strSN = JArray<String>(17);
        int n2 = 0;
        int n3 = 0;
        int n4 = 0;
        while (n4 < string.length()) {
            if (cArray[n4] == '@') {
                this->strSN[n3] = string.substring(n2, n4);
                n2 = n4 + 1;
                ++n3;
            }
            ++n4;
        }
        this->ani_step = Integer::parseInt(this->strSN[0]);
    }

    void init_en() {
        JArray<int8_t> byArray = this->get_bytes(Integer::toString((this->stage - 1) / 3 + 1) + String("[") + this->chap + String("].en"), 60);
        int n = 0;
        while (n < 10) {
            this->e_k[n] = (byArray[n] - 48) * 6 - 6;
            if (this->e_k[n] == 6) {
                this->e_rng[n] = 6;
            } else if (this->e_k[n] == 0) {
                this->e_rng[n] = 15;
            }
            this->ai_class[n] = byArray[n + 12] - 48;
            this->e_stage[n] = byArray[n + 24] - 48;
            this->e_x[n] = byArray[n + 36] - 48;
            this->e_y[n] = byArray[n + 48] - 48;
            this->e_ai_time[n] = 2;
            this->e_att[n] = 0;
            this->e_att_time[n] = 0;
            this->e_ai[n] = 0;
            this->e_dir[n] = 0;
            this->e_y_gap[n] = 0;
            this->e_ai_time[n] = 0;
            this->e_mo[n] = 0;
            this->e_idx[n] = 0;
            this->e_et[n] = 0;
            this->e_tt[n] = 0;
            this->e_mo_stop[n] = 0;
            this->e_w_x[n] = 0;
            this->e_w_y[n] = 0;
            this->e_w_dir[n] = 0;
            this->e_hp[n] = this->e_max_hp[n] = this->chap * 23 + 30 + this->e_k[n];
            ++n;
        }
    }

    void init_ob() {
        JArray<int8_t> byArray = this->get_bytes((this->stage - 1) / 3 + 1 + String("[") + this->chap + String("].ob"), 36);
        this->o_x = JArray<int>(8);
        this->o_y = JArray<int>(8);
        this->o_k = JArray<int>(8);
        this->o_st = JArray<int>(8);
        int n = 0;
        while (n < 8) {
            if (n < 4) {
                this->sn_m[n] = byArray[n + 32] - 48;
            }
            this->o_x[n] = byArray[n] - 48;
            this->o_y[n] = byArray[n + 8] - 48;
            this->o_k[n] = byArray[n + 16] - 48;
            this->o_st[n] = byArray[n + 24] - 48;
            ++n;
        }
    }

    JArray<int8_t> get_bytes(String string, int n) {
        return read_asset(string,n);
    }

    void make_map(int n, int n2) {

        
        String string = nullptr;
        string = this->stage > 100 ? String::valueOf(this->stage) : (this->chap == 2 && (this->stage - 1) / 3 == 1 ? this->stage + 9 + String("[0]") : (this->chap == 2 && (this->stage - 1) / 3 == 3 ? this->stage - 3 + String("[0]") : (this->chap == 2 && (this->stage - 1) / 3 == 4 ? this->stage - 3 + String("[1]") : (this->chap == 2 && (this->stage - 1) / 3 == 6 ? this->stage - 3 + String("[1]") : this->stage + String("[") + this->chap + String("]")))));
        JArray<int8_t> byArray = this->get_bytes(string + String(".map"), 64);
        this->map = matrix(n,n2);
        bool bl = false;
        int n3 = 0;
        int n4 = 0;
        while (n4 < n2 * n) {
            if (n4 != 0 && n4 % n2 == 0) {
                ++n3;
            }
            this->map[n3][n4 % n2] = byArray[n4];
            ++n4;
        }
    }

    void make_buf(int n, int n2) {
        int n3;
        int n4;
        this->buf_g.setColor(8304127);
        this->buf_g.fillRect(0, 0, 240, 256);
        bool bl = false;
        int n5 = 0;
        while (n5 < n) {
            n4 = 0;
            while (n4 < n2) {
                n3 = this->map[n5][n4];
                if (n3 != 65) {
                    if (n3 == 49 && (this->map[n5 - 1][n4] == 54 || this->map[n5 - 1][n4] == 53 || this->map[n5 - 1][n4] == 55)) {
                        this->buf_g.drawImage(this->imgTile[5], n4 * this->tile_size_x + this->START_X, n5 * this->tile_size_y + this->gg_yy, 20);
                    }
                    if (n3 == 53 && n4 != 0 && this->map[n5][n4 - 1] != 65 && this->map[n5][n4 - 1] != 62) {
                        this->buf_g.drawImage(this->imgTile[5], n4 * this->tile_size_x + this->START_X, n5 * this->tile_size_y + this->gg_yy, 20);
                    }
                    if ((n3 == 55 || n3 == 51) && n4 != 7 && this->map[n5][n4 + 1] != 65 && this->map[n5][n4 + 1] != 62) {
                        this->buf_g.drawImage(this->imgTile[5], n4 * this->tile_size_x + this->START_X, n5 * this->tile_size_y + this->gg_yy, 20);
                    }
                    if (n3 > 56 && n3 < 59) {
                        this->buf_g.drawImage(this->imgDe[n3 - 57], n4 * this->tile_size_x + 9 + this->START_X, n5 * this->tile_size_y - 18 + this->gg_yy, 20);
                        n3 = 57;
                    }
                    if (n3 > 59) {
                        n3 -= 2;
                    }
                    this->buf_g.drawImage(this->imgTile[n3 - 49], n4 * this->tile_size_x + this->START_X, n5 * this->tile_size_y + this->gg_yy, 20);
                }
                ++n4;
            }
            ++n5;
        }
        n4 = 0;
        while (n4 < 8) {
            n3 = this->map[0][n4];
            if (n3 != 65 && n3 != 62) {
                if (n3 == 53 && n4 != 0 && this->map[0][n4 - 1] != 65 && this->map[0][n4 - 1] != 62) {
                    this->buf_g.drawImage(this->imgTile[5], n4 * this->tile_size_x + this->START_X, this->gg_yy, 20);
                }
                if ((n3 == 55 || n3 == 51) && n4 != 7 && this->map[0][n4 + 1] != 65 && this->map[0][n4 + 1] != 62) {
                    this->buf_g.drawImage(this->imgTile[5], n4 * this->tile_size_x + this->START_X, this->gg_yy, 20);
                }
                if (n3 > 59) {
                    n3 -= 2;
                }
                this->buf_g.drawImage(this->imgTile[n3 - 49], n4 * this->tile_size_x + this->START_X, this->gg_yy, 36);
            }
            ++n4;
        }
    }

    void make_map2() {
        
        String string = nullptr;
        string = this->stage > 100 ? String::valueOf(this->stage) : (this->chap == 2 && (this->stage - 1) / 3 == 1 ? this->stage + 9 + String("[0]") : (this->chap == 2 && (this->stage - 1) / 3 == 3 ? this->stage - 3 + String("[0]") : (this->chap == 2 && (this->stage - 1) / 3 == 4 ? this->stage - 3 + String("[1]") : (this->chap == 2 && (this->stage - 1) / 3 == 6 ? this->stage - 3 + String("[1]") : this->stage + String("[") + this->chap + String("]")))));
        JArray<int8_t> byArray = this->get_bytes(string + String(".map"), 90);
        this->map = matrix(10,9);
        bool bl = false;
        int n = 0;
        int n2 = 0;
        while (n2 < 90) {
            if (n2 != 0 && n2 % 9 == 0) {
                ++n;
            }
            this->map[n][n2 % 9] = byArray[n2];
            ++n2;
        }
    }

    void make_buf2() {
        this->imgBuf = nullptr;
        
        try {
            this->imgBuf = Image::createImage((int)240, (int)320);
            this->buf_g = this->imgBuf.getGraphics();
        }
        catch (const std::exception&) {
            
        }
        this->buf_g.setColor(8304127);
        this->buf_g.fillRect(0, 0, 240, 200);
        bool bl = false;
        int n = 0;
        while (n < 10) {
            int n2 = 0;
            while (n2 < 9) {
                int n3 = this->map[n][n2];
                if (n3 != 65) {
                    if (n3 == 49 && (this->map[n - 1][n2] == 54 || this->map[n - 1][n2] == 53 || this->map[n - 1][n2] == 55)) {
                        this->buf_g.drawImage(this->imgTile[5], n2 * this->tile_size_x + this->START_X - 11, n * this->tile_size_y, 20);
                    }
                    if (n3 > 56 && n3 < 59) {
                        this->buf_g.drawImage(this->imgDe[n3 - 57], n2 * this->tile_size_x + 4 + this->START_X - 11, n * this->tile_size_y - 15, 20);
                        n3 = 57;
                    }
                    if (n3 > 59) {
                        n3 -= 2;
                    }
                    this->buf_g.drawImage(this->imgTile[n3 - 49], n2 * this->tile_size_x + this->START_X - 11, n * this->tile_size_y, 20);
                }
                ++n2;
            }
            ++n;
        }
    }

    int check_att(int n, int n2, int n3) {
        int n4 = 0;
        while (n4 < 10) {
            if (this->e_stage[n4] == this->stage && this->e_hp[n4] > 0 && this->e_k[n4] != 12 && this->e_dir[n4] > -1 && n > this->e_x[n4] - 3 && n < this->e_x[n4] + 3 && n2 == this->e_y[n4]) {
                if (this->e_x[n4] > 1 && this->e_x[n4] < 23) {
                    int n5 = n4;
                    this->e_x[n5] = this->e_x[n5] + n3;
                }
                this->e_att[n4] = n3 - 2;
                this->e_tt[n4] = -3;
                this->e_y_gap[n4] = -3;
                if (this->h_mo < 13) {
                    int n6 = n4;
                    this->e_hp[n6] = this->e_hp[n6] - this->w_dem;
                } else {
                    int n7 = n4;
                    this->e_hp[n7] = this->e_hp[n7] - 5;
                }
                this->MPlay(3);
                if (this->e_hp[n4] < 1) {
                    this->e_k[n4] = -10;
                }
                return 1;
            }
            ++n4;
        }
        return 0;
    }

    void draw_img(String string, int n, int n2, int n3) {
        try {
            this->gg.drawImage(Image::createImage((String)(String("/") + string + String(".png"))), n, n2, n3);
        }
        catch (const std::exception&) {}
    }

    void draw_stat() {
        this->gg.setColor(0x5E0000);
        this->gg.fillRect(96, 271, 47, 6);
        this->gg.fillRect(176, 271, 56, 6);
        this->gg.setColor(0xFF969F);
        this->gg.fillRect(96, 271, 47 * this->h_hp / this->h_max_hp, 3);
        this->gg.setColor(15138898);
        this->gg.fillRect(96, 274, 47 * this->h_hp / this->h_max_hp, 3);
        this->gg.setColor(7196662);
        this->gg.fillRect(176, 271, 56 * this->mp / this->max_mp, 3);
        this->gg.setColor(33023);
        this->gg.fillRect(176, 274, 56 * this->mp / this->max_mp, 3);
        this->gg.drawImage(this->imgTTT2, 189, 265, 20);
        this->gg.drawImage(this->imgTTT2, 208, 265, 20);
        this->gg.drawImage(this->imgTTT2, 227, 265, 20);
        if (this->mp > 32) {
            this->gg.drawImage(this->imgTTT, 189, 265, 20);
        }
        if (this->mp > 65) {
            this->gg.drawImage(this->imgTTT, 208, 265, 20);
        }
        if (this->mp > 98) {
            this->gg.drawImage(this->imgTTT, 227, 265, 20);
        }
    }

    void draw_int(Graphics graphics, int n, int n2, int n3) {
        int n4 = 0;
        n4 = n / 100 > 0 ? 3 : (n / 10 > 0 ? 2 : 1);
        JArray<int> nArray = JArray<int>(n4);
        if (n4 == 3) {
            nArray[2] = n / 100;
            nArray[1] = n / 10 % 10;
            nArray[0] = n % 10;
        } else if (n4 == 2) {
            nArray[1] = n / 10;
            nArray[0] = n % 10;
        } else if (n4 == 1) {
            nArray[0] = n;
        }
        int n5 = n4;
        while (n5 > 0) {
            if (n < 10) {
                graphics.drawImage(this->imgNum[nArray[n5 - 1]], (n4 - n5) * 6 + n2, n3, 20);
            } else {
                graphics.drawImage(this->imgNum[nArray[n5 - 1]], (n4 - n5) * 6 + n2 - 2, n3, 20);
            }
            --n5;
        }
    }

    void find_hero(int n, int n2, int n3) {
        if (this->e_et[n] != 4 && this->e_k[n] != 12 && this->e_y[n] == this->h_y && this->h_mo != 12 && (this->e_mo[n] == 2 && this->e_x[n] >= this->h_x || this->e_mo[n] == 0 && this->e_x[n] <= this->h_x)) {
            this->e_att[n] = 1;
            this->e_ai_time[n] = 3;
            this->e_att_time[n] = 1;
            this->e_tt[n] = 4;
            this->e_et[n] = 3;
            return;
        }
        this->e_att[n] = 0;
    }

    void nor_ai(int n, int n2, int n3) {
        if (this->ai_class[n] != 0) {
            int n4 = this->get_rnd(3);
            if (n4 == 0) {
                int n5 = this->get_rnd(3);
                if (n5 == 0) {
                    this->e_et[n] = 4;
                    this->e_ai_time[n] = this->e_tt[n] = 30 + this->get_rnd(6);
                } else {
                    this->e_mo_stop[n] = 0;
                    this->e_mo[n] = this->e_x[n] < 7 ? (this->get_rnd(3) == 0 ? 2 : 0) : (this->e_x[n] > 17 ? (this->get_rnd(3) == 0 ? 0 : 2) : (this->get_rnd(2) == 0 ? 2 : 0));
                    int n6 = this->get_rnd2(3);
                    if (n6 == 0) {
                        n6 = 5;
                    }
                    this->e_et[n] = n6;
                    this->e_tt[n] = 5;
                    this->e_ai_time[n] = 20;
                }
                this->e_dir[n] = 0;
            } else {
                if (this->e_x[n] < 7) {
                    if (this->get_rnd(3) == 0) {
                        this->e_dir[n] = 2;
                        this->e_mo[n] = 2;
                    } else {
                        this->e_dir[n] = 4;
                        this->e_mo[n] = 0;
                    }
                } else if (this->e_x[n] > 17) {
                    if (this->get_rnd(3) == 0) {
                        this->e_dir[n] = 4;
                        this->e_mo[n] = 0;
                    } else {
                        this->e_dir[n] = 2;
                        this->e_mo[n] = 2;
                    }
                } else if (this->get_rnd(2) == 0) {
                    this->e_dir[n] = 2;
                    this->e_mo[n] = 2;
                } else {
                    this->e_dir[n] = 4;
                    this->e_mo[n] = 0;
                }
                this->e_ai_time[n] = 5;
            }
        } else if (this->e_dir[n] == 0) {
            this->e_dir[n] = 4;
        }
    }

    int collision(int n) {
        if (this->h_mo != 10) {
            if (this->h_dem == 0 && this->h_x - this->e_x[n] < 2 && this->h_x - this->e_x[n] > -2 && this->h_y == this->e_y[n] && this->y_gap == 0) {
                this->dec_hp(n);
                return 1;
            }
        } else if (this->h_dir == 6) {
            if (this->h_y == this->e_y[n]) {
                if (this->h_dem == 0 && this->h_x - this->e_x[n] < 2 && this->h_x - this->e_x[n] > -2 && this->y_gap > -13) {
                    this->dec_hp(n);
                    return 1;
                }
            } else if (this->h_y - 2 == this->e_y[n] && this->h_dem == 0 && this->h_x - this->e_x[n] < 2 && this->h_x - this->e_x[n] > -2 && this->y_gap < -24) {
                this->dec_hp(n);
                return 1;
            }
        } else if (this->h_dir == 8) {
            if (this->h_y + 2 == this->e_y[n]) {
                if (this->h_dem == 0 && this->h_x - this->e_x[n] < 2 && this->h_x - this->e_x[n] > -2 && this->y_gap > 35) {
                    this->dec_hp(n);
                    return 1;
                }
            } else if (this->h_y == this->e_y[n] && this->h_dem == 0 && this->h_x - this->e_x[n] < 2 && this->h_x - this->e_x[n] > -2 && this->y_gap < 24) {
                this->dec_hp(n);
                return 1;
            }
        }
        return 0;
    }

    void act_en(int n) {
        if (this->e_dir[n] == 2) {
            if (this->e_x[n] < 2) {
                if (this->ai_class[n] == 0) {
                    this->e_dir[n] = 4;
                }
            } else {
                if (this->check_map(this->e_x[n] - 2, this->e_y[n], 2) < 0) {
                    if (this->ai_class[n] == 0) {
                        this->e_dir[n] = 4;
                        return;
                    }
                    if (this->get_rnd(3) == 0 && this->e_y[n] < 5) {
                        this->e_dir[n] = -1;
                    } else {
                        int n2 = n;
                        this->e_ai[n2] = this->e_ai[n2] - 3;
                        this->e_dir[n] = 4;
                        this->e_mo[n] = 0;
                        return;
                    }
                }
                if (this->ai_class[n] == 0 && this->god < 100 && this->collision(n) == 1) {
                    this->e_dir[n] = 4;
                    if (this->h_x > 2) {
                        if (this->h_mo != 10) {
                            this->h_x -= 2;
                        }
                        if (this->check_map(this->h_x - 1, this->h_y, 2) < 0) {
                            this->h_dir = -1;
                            this->h_idx = 0;
                            if (this->h_mo < 6) {
                                this->h_mo += 7;
                            }
                            this->mo_stop = 1;
                        }
                    }
                    if (this->h_dir == 4) {
                        this->h_dir = 0;
                    } else if (this->h_dir > 11 && this->h_dir < 19) {
                        this->h_dir = 10;
                    }
                }
                int n3 = n;
                this->e_x[n3] = this->e_x[n3] - 1;
            }
        } else if (this->e_dir[n] == 4) {
            if (this->e_x[n] > 22) {
                if (this->ai_class[n] == 0) {
                    this->e_dir[n] = 2;
                }
            } else {
                if (this->check_map(this->e_x[n] + 1, this->e_y[n], 2) < 0) {
                    if (this->ai_class[n] == 0) {
                        this->e_dir[n] = 2;
                        return;
                    }
                    if (this->get_rnd(3) == 0 && this->e_y[n] < 5) {
                        this->e_dir[n] = -2;
                    } else {
                        int n4 = n;
                        this->e_ai[n4] = this->e_ai[n4] - 3;
                        this->e_dir[n] = 2;
                        this->e_mo[n] = 2;
                        return;
                    }
                }
                if (this->ai_class[n] == 0 && this->god < 100 && this->collision(n) == 1) {
                    this->e_dir[n] = 2;
                    if (this->h_x < 22) {
                        if (this->h_mo != 10) {
                            this->h_x += 2;
                        }
                        if (this->check_map(this->h_x, this->h_y, 2) < 0) {
                            this->h_dir = -2;
                            this->h_idx = 0;
                            if (this->h_mo < 6) {
                                this->h_mo += 7;
                            }
                            this->mo_stop = 1;
                        }
                    }
                    if (this->h_dir == 2) {
                        this->h_dir = 0;
                    } else if (this->h_dir > 11 && this->h_dir < 19) {
                        this->h_dir = 10;
                    }
                }
                int n5 = n;
                this->e_x[n5] = this->e_x[n5] + 1;
            }
        } else if (this->e_dir[n] < 0) {
            if (this->e_y_gap[n] > 23) {
                this->e_y_gap[n] = 0;
                int n6 = n;
                this->e_y[n6] = this->e_y[n6] + 2;
                if (this->e_y[n] > 5) {
                    this->e_stage[n] = -1;
                    return;
                }
                this->e_att[n] = 1;
                this->e_et[n] = 1;
                this->e_tt[n] = 5;
                if (this->check_map(this->e_x[n] - 1, this->e_y[n], 2) > 0) {
                    this->e_dir[n] = 0;
                } else {
                    this->e_att[n] = 0;
                    int n7 = n;
                    this->e_y_gap[n7] = this->e_y_gap[n7] + 10;
                }
            } else {
                int n8 = n;
                this->e_y_gap[n8] = this->e_y_gap[n8] + 8;
            }
            if (this->e_dir[n] == -1) {
                if (this->e_x[n] > 1) {
                    int n9 = n;
                    this->e_x[n9] = this->e_x[n9] - 1;
                }
            } else if (this->e_dir[n] == -2 && this->e_x[n] < 23) {
                int n10 = n;
                this->e_x[n10] = this->e_x[n10] + 1;
            }
        }
    }

    void att_hero(int n) {
        int n2 = n;
        this->e_att_time[n2] = this->e_att_time[n2] + 1;
        if (this->e_y[n] == this->h_y && this->e_w_dir[n] == 0 && this->h_mo != 12) {
            if (this->e_x[n] >= this->h_x) {
                if (this->e_x[n] - this->h_x < this->e_rng[n]) {
                    this->e_att[n] = 11;
                    this->e_mo[n] = 4;
                    this->e_idx[n] = 1;
                    this->e_mo_stop[n] = 1;
                    this->e_dir[n] = 0;
                    this->e_w_x[n] = this->e_x[n] - 1;
                    this->e_w_y[n] = this->e_y[n];
                    if (this->e_k[n] == 6) {
                        this->e_w_dir[n] = 19;
                    } else if (this->e_k[n] == 0) {
                        this->e_w_dir[n] = 44;
                    }
                } else if (this->e_att[n] == 1 && this->check_map(this->e_x[n] - 2, this->e_y[n], 2) >= 0) {
                    int n3 = n;
                    this->e_x[n3] = this->e_x[n3] - 1;
                    this->e_mo[n] = 2;
                }
            } else if (this->e_x[n] <= this->h_x) {
                if (this->h_x - this->e_x[n] < this->e_rng[n]) {
                    this->e_att[n] = 12;
                    this->e_dir[n] = 0;
                    this->e_mo[n] = 4;
                    this->e_idx[n] = 0;
                    this->e_mo_stop[n] = 1;
                    this->e_w_x[n] = this->e_x[n] + 1;
                    this->e_w_y[n] = this->e_y[n];
                    if (this->e_k[n] == 6) {
                        this->e_w_dir[n] = -19;
                    } else if (this->e_k[n] == 0) {
                        this->e_w_dir[n] = -44;
                    }
                } else if (this->e_att[n] == 1 && this->check_map(this->e_x[n] + 1, this->e_y[n], 2) >= 0) {
                    int n4 = n;
                    this->e_x[n4] = this->e_x[n4] + 1;
                    this->e_mo[n] = 0;
                }
            }
        }
        if (this->e_att_time[n] > 30 && (this->e_y[n] != this->h_y || this->h_mo == 12)) {
            this->e_att_time[n] = 0;
            this->e_att[n] = 0;
            this->e_et[n] = 3;
        }
    }

    void check_h(int n, int n2, int n3, Graphics graphics, int n4) {
        int n5 = 0;
        if (this->h_dem == 0 && n2 == this->h_y && this->h_dir > -1) {
            if (this->h_mo != 10) {
                if (n3 > 0) {
                    if (this->h_x + n3 >= n && this->h_x - n3 - 1 <= n && this->y_gap > -10) {
                        n5 = -2;
                    }
                } else if (this->h_x + n3 <= n && this->h_x - n3 >= n && this->y_gap > -10) {
                    n5 = 2;
                }
            } else if (this->h_dir == 8) {
                if (n3 > 0) {
                    if (this->h_x + n3 >= n && this->h_x - n3 - 1 <= n && this->y_gap < 12) {
                        n5 = -2;
                    }
                } else if (this->h_x + n3 <= n && this->h_x - n3 >= n && this->y_gap < 12) {
                    n5 = 2;
                }
            } else if (n3 > 0) {
                if (this->h_x + n3 >= n && this->h_x - n3 - 1 <= n && this->y_gap > -13) {
                    n5 = -2;
                }
            } else if (this->h_x + n3 <= n && this->h_x - n3 >= n && this->y_gap > -13) {
                n5 = 2;
            }
            if (n5 != 0) {
                this->e_w_x[n4] = -10;
                if (this->god < 100) {
                    this->dec_hp(n4);
                    if (this->h_x > 1 && this->h_x < 23 && (this->h_mo < 6 || this->h_mo > 10)) {
                        this->h_x += n5 >> 1;
                    }
                    if (n3 > 0 && this->check_map(this->h_x - 1, this->h_y, 2) < 0) {
                        this->h_dir = -1;
                        this->h_idx = 0;
                        if (this->h_mo < 6) {
                            this->h_mo += 7;
                        }
                        this->mo_stop = 1;
                    } else if (n3 <= 0 && this->check_map(this->h_x, this->h_y, 2) < 0) {
                        this->h_dir = -2;
                        this->h_idx = 0;
                        if (this->h_mo < 6) {
                            this->h_mo += 7;
                        }
                        this->mo_stop = 1;
                    }
                    if (this->h_dir == 4 || this->h_dir == 2) {
                        this->h_dir = 0;
                    } else if (this->h_dir > 11 && this->h_dir < 19) {
                        this->h_dir = 10;
                    }
                }
            }
        }
    }

    void dec_hp(int n) {
        int n2 = this->e_k[n];
        this->h_hp = n2 == 0 ? (this->h_hp -= 15) : (n2 == 6 ? (this->h_hp -= 20) : (this->h_hp -= 15));
        this->gg.drawImage(this->imgEff, this->h_x * this->move_gap_x + this->START_X, this->h_y * this->tile_size_y + this->y_gap + 2, 33);
        this->h_dem = 6;
        this->draw_stat();
        if (this->h_hp <= 0) {
            this->h_hp = 0;
            this->h_dem = 99;
            this->m_mode = 0;
        }
        this->MPlay(3);
    }

    void draw_pt() {
        this->gg.setColor(0);
        this->gg.fillRect(19, 268, 9, 12);
        this->gg.fillRect(47, 268, 9, 12);
        this->draw_int(this->gg, this->pt[0], 21, 270);
        this->draw_int(this->gg, this->pt[1], 49, 270);
    }

    void draw_ob(Graphics graphics) {
        int n = 0;
        while (n < 8) {
            if (this->stage == this->o_st[n] && this->o_k[n] != 0) {
                graphics.drawImage(this->imgOB[this->o_k[n] - 1], this->o_x[n] * this->move_gap_x, this->o_y[n] * this->tile_size_y + 8 + this->gg_yy, 33);
            }
            ++n;
        }
    }

    void draw_screen(Graphics graphics) {
        graphics.drawImage(this->imgBuf, 0, 0, 20);
        this->draw_ob(graphics);
        if (this->h_dem % 2 == 0) {
            graphics.drawImage(this->imgHero[this->h_idx + this->h_mo], this->h_x * this->move_gap_x + this->START_X, this->h_y * this->tile_size_y + 8 + this->y_gap + this->gg_yy, 33);
        } else if (this->h_dem == 99) {
            graphics.drawImage(this->imgHero[15], this->h_x * this->move_gap_x + this->START_X, this->h_y * this->tile_size_y + 8 + this->y_gap + this->gg_yy, 33);
            ++this->m_mode;
            if (this->m_mode == 10) {
                this->h_dir = 100;
                this->ani_step = 0;
                this->state = -100;
                this->del_img(11);
                this->MPlay(1);
                this->call_vib(1000);
            }
        }
        if (this->mo_stop == 0) {
            if (this->h_idx == 0) {
                this->h_idx = 1;
            } else if (this->h_idx == 1) {
                this->h_idx = 0;
            }
        }
        if (this->god > 99) {
            if (this->w_y2 != -10) {
                graphics.drawImage(this->imgFF, this->h_x * this->move_gap_x + this->START_X, this->h_y * this->tile_size_y - this->w_y2 + this->y_gap - 9 + this->gg_yy, 33);
            }
            if (this->w_y1 != -10) {
                graphics.drawImage(this->imgFF, this->h_x * this->move_gap_x + this->START_X, this->h_y * this->tile_size_y - this->w_y1 + this->y_gap + 1 + this->gg_yy, 33);
            }
            this->w_y2 += 4;
            this->w_y1 += 4;
            if (this->w_y2 == 10) {
                this->w_y2 = -10;
            }
            if (this->w_y1 == 10) {
                this->w_y1 = -10;
            }
            ++this->god;
            if (this->god > 110 && this->god < 200) {
                this->god = 0;
                if (this->special != 0) {
                    this->state = 33;
                } else {
                    this->imgFF = nullptr;
                }
            } else if (this->god > 264) {
                this->god = 0;
                this->imgFF = nullptr;
                
                this->special = 0;
            }
        }
        if (this->h_dem != 0 && this->h_dem < 10) {
            --this->h_dem;
        }
        int n = 0;
        while (n < 10) {
            if (this->e_stage[n] == this->stage && this->e_k[n] > -1 && this->e_y[n] < 7) {
                if (this->e_k[n] != 12) {
                    graphics.drawImage(this->imgEnemy[this->e_k[n] + this->e_mo[n] + this->e_idx[n]], this->e_x[n] * this->move_gap_x + this->START_X, this->e_y[n] * this->tile_size_y + 8 + this->e_y_gap[n] + this->gg_yy, 33);
                } else {
                    graphics.drawImage(this->imgEnemy[this->e_k[n] + this->e_idx[n]], this->e_x[n] * this->move_gap_x + this->START_X, this->e_y[n] * this->tile_size_y + 8 + this->e_y_gap[n] + this->gg_yy, 33);
                }
                if (this->e_tt[n] > 0) {
                    if (this->e_et[n] != 0) {
                        if (this->e_et[n] != 4) {
                            graphics.drawImage(this->imgE_box, this->e_x[n] * this->move_gap_x + 8 + this->START_X, this->e_y[n] * this->tile_size_y - 29 + this->e_y_gap[n] + this->gg_yy, 33);
                            if (this->e_et[n] != 5) {
                                graphics.drawImage(this->imgE[this->e_et[n] - 1], this->e_x[n] * this->move_gap_x + 8 + this->START_X, this->e_y[n] * this->tile_size_y - 35 + this->e_y_gap[n] + this->gg_yy, 33);
                            }
                        } else {
                            graphics.drawImage(this->imgE[this->e_et[n] - 1], this->e_x[n] * this->move_gap_x + 6 + this->START_X, this->e_y[n] * this->tile_size_y - 29 + this->e_tt[n] % 2 * 4 + this->e_y_gap[n] + this->gg_yy, 33);
                        }
                    }
                    int n2 = n;
                    this->e_tt[n2] = this->e_tt[n2] - 1;
                } else if (this->e_tt[n] < 0) {
                    graphics.drawImage(this->imgEff, this->e_x[n] * this->move_gap_x + this->START_X, this->e_y[n] * this->tile_size_y + this->e_y_gap[n] + 3 + this->gg_yy, 33);
                    this->e_tt[n] = 0;
                }
                if (this->e_mo_stop[n] == 0) {
                    if (this->e_idx[n] == 0) {
                        this->e_idx[n] = 1;
                    } else if (this->e_idx[n] == 1) {
                        this->e_idx[n] = 0;
                    }
                }
                if (this->e_w_dir[n] > 20) {
                    int n3 = n;
                    this->e_w_dir[n3] = this->e_w_dir[n3] - 1;
                    if (this->e_w_x[n] > 0) {
                        int n4 = n;
                        this->e_w_x[n4] = this->e_w_x[n4] - 2;
                        graphics.drawImage(this->imgBim, this->e_w_x[n] * this->move_gap_x + this->START_X, this->e_w_y[n] * this->tile_size_y - 10 + this->gg_yy, 33);
                        this->check_h(this->e_w_x[n], this->e_w_y[n], 2, graphics, n);
                    }
                    if (this->e_w_dir[n] < 22) {
                        this->e_w_dir[n] = 0;
                    } else if (this->e_w_dir[n] == 32) {
                        if (this->e_dir[n] > -1) {
                            this->e_att[n] = 1;
                        }
                        this->e_mo[n] = 2;
                        this->e_mo_stop[n] = 0;
                    }
                } else if (this->e_w_dir[n] < -20) {
                    int n5 = n;
                    this->e_w_dir[n5] = this->e_w_dir[n5] + 1;
                    if (this->e_w_x[n] < 23 && this->e_w_x[n] > 0) {
                        int n6 = n;
                        this->e_w_x[n6] = this->e_w_x[n6] + 2;
                        graphics.drawImage(this->imgBim, this->e_w_x[n] * this->move_gap_x + this->START_X, this->e_w_y[n] * this->tile_size_y - 10 + this->gg_yy, 33);
                        this->check_h(this->e_w_x[n], this->e_w_y[n], -2, graphics, n);
                    }
                    if (this->e_w_dir[n] > -22) {
                        this->e_w_dir[n] = 0;
                    } else if (this->e_w_dir[n] == -32) {
                        if (this->e_dir[n] > -1) {
                            this->e_att[n] = 1;
                        }
                        this->e_mo[n] = 0;
                        this->e_mo_stop[n] = 0;
                    }
                } else if (this->e_w_dir[n] < 20 && this->e_w_dir[n] > 0) {
                    int n7 = n;
                    this->e_w_dir[n7] = this->e_w_dir[n7] - 1;
                    if (this->e_w_dir[n] < 3) {
                        this->e_w_dir[n] = 0;
                    } else if (this->e_w_dir[n] == 6) {
                        if (this->e_dir[n] > -1 && this->e_att[n] > -1) {
                            this->e_att[n] = 1;
                        }
                    } else if (this->e_w_dir[n] == 12) {
                        this->e_mo[n] = 2;
                        this->e_mo_stop[n] = 0;
                    } else if (this->e_w_dir[n] > 15) {
                        if (this->e_w_dir[n] == 18) {
                            this->check_h(this->e_w_x[n], this->e_w_y[n], 5, graphics, n);
                        }
                        graphics.drawImage(this->imgE_att[0], this->e_x[n] * this->move_gap_x - 20 + this->START_X, this->e_y[n] * this->tile_size_y + this->e_y_gap[n] - 4 + this->gg_yy, 33);
                    }
                } else if (this->e_w_dir[n] > -20) {
                    int n8 = n;
                    this->e_w_dir[n8] = this->e_w_dir[n8] + 1;
                    if (this->e_w_dir[n] > -3) {
                        this->e_w_dir[n] = 0;
                    } else if (this->e_w_dir[n] == -6) {
                        if (this->e_dir[n] > -1 && this->e_att[n] > -1) {
                            this->e_att[n] = 1;
                        }
                    } else if (this->e_w_dir[n] == -12) {
                        this->e_mo[n] = 0;
                        this->e_mo_stop[n] = 0;
                    } else if (this->e_w_dir[n] < -15) {
                        if (this->e_w_dir[n] == -18) {
                            this->check_h(this->e_w_x[n], this->e_w_y[n], -5, graphics, n);
                        }
                        graphics.drawImage(this->imgE_att[1], this->e_x[n] * this->move_gap_x + 20 + this->START_X, this->e_y[n] * this->tile_size_y + this->e_y_gap[n] - 4 + this->gg_yy, 33);
                    }
                }
                if (this->e_y_gap[n] != 0 && this->e_dir[n] > -1) {
                    int n9 = n;
                    this->e_y_gap[n9] = this->e_y_gap[n9] + 3;
                    if (this->e_att[n] == -1) {
                        if (this->e_x[n] < 23) {
                            int n10 = n;
                            this->e_x[n10] = this->e_x[n10] + 1;
                        }
                    } else if (this->e_x[n] > 1) {
                        int n11 = n;
                        this->e_x[n11] = this->e_x[n11] - 1;
                    }
                    if (this->check_map(this->e_x[n], this->e_y[n], 2) < 0) {
                        this->e_dir[n] = this->e_att[n] == -1 ? -2 : -1;
                        this->e_att[n] = 0;
                        this->e_tt[n] = 0;
                    } else {
                        this->e_tt[n] = 2;
                        this->e_att[n] = -6;
                    }
                    this->e_et[n] = 0;
                }
                if (this->e_dir[n] > -1 && this->e_att[n] > -1) {
                    int n12 = n;
                    this->e_ai[n12] = this->e_ai[n12] + 1;
                    if (this->e_ai[n] >= this->e_ai_time[n] && this->e_att[n] == 0) {
                        this->find_hero(n, 0, 0);
                        if (this->e_att[n] == 0) {
                            this->nor_ai(n, 0, 0);
                            this->e_ai[n] = 0;
                        }
                    }
                }
                if (this->e_att[n] == 0) {
                    this->act_en(n);
                    if (this->e_dir[n] > -1) {
                        this->find_hero(n, 0, 0);
                    }
                } else if (this->e_att[n] > 0) {
                    if (this->e_dir[n] > -1) {
                        this->att_hero(n);
                    }
                } else {
                    int n13 = n;
                    this->e_att[n13] = this->e_att[n13] + 1;
                    graphics.setColor(0xFFFF00);
                    graphics.fillRect(this->e_x[n] * this->move_gap_x - 11 + this->START_X, this->e_y[n] * this->tile_size_y - 45 + this->gg_yy, 23, 5);
                    graphics.setColor(14211584);
                    graphics.fillRect(this->e_x[n] * this->move_gap_x - 11 + this->START_X, this->e_y[n] * this->tile_size_y - 42 + this->gg_yy, 23, 2);
                    graphics.setColor(0xFF0000);
                    graphics.fillRect(this->e_x[n] * this->move_gap_x - 11 + this->START_X, this->e_y[n] * this->tile_size_y - 45 + this->gg_yy, 23 * this->e_hp[n] / this->e_max_hp[n], 5);
                    graphics.setColor(0xD40000);
                    graphics.fillRect(this->e_x[n] * this->move_gap_x - 11 + this->START_X, this->e_y[n] * this->tile_size_y - 42 + this->gg_yy, 23 * this->e_hp[n] / this->e_max_hp[n], 2);
                    graphics.setColor(0);
                    graphics.drawRect(this->e_x[n] * this->move_gap_x - 11 + this->START_X, this->e_y[n] * this->tile_size_y - 45 + this->gg_yy, 23, 5);
                    if (this->e_att[n] == -1) {
                        this->e_att[n] = 1;
                    }
                }
            } else if (this->e_k[n] > -1) {
                if (this->e_att[n] != 0) {
                    if (this->e_y[n] != this->h_y) {
                        this->e_att[n] = 0;
                        this->e_w_dir[n] = 0;
                        this->e_mo[n] = 2;
                    }
                    if (this->e_stage[n] > this->stage) {
                        int n14 = n;
                        this->e_x[n14] = this->e_x[n14] - 1;
                        if (this->e_x[n] < 2) {
                            this->e_x[n] = 23;
                            this->e_w_dir[n] = 0;
                            this->e_att[n] = 0;
                            this->e_mo[n] = 2;
                            this->e_stage[n] = this->stage;
                        }
                    } else {
                        int n15 = n;
                        this->e_x[n15] = this->e_x[n15] + 1;
                        if (this->e_x[n] > 22) {
                            this->e_x[n] = 1;
                            this->e_w_dir[n] = 0;
                            this->e_att[n] = 0;
                            this->e_mo[n] = 0;
                            this->e_stage[n] = this->stage;
                        }
                    }
                }
            } else if (this->e_k[n] < 0 && this->e_stage[n] > 0) {
                int n16 = n;
                this->e_k[n16] = this->e_k[n16] + 1;
                if (this->e_k[n] < -7) {
                    graphics.drawImage(this->imgDead[1], this->e_x[n] * this->move_gap_x + this->START_X, this->e_y[n] * this->tile_size_y + 11 + this->e_y_gap[n] + this->gg_yy, 33);
                } else if (this->e_k[n] > -6) {
                    graphics.drawImage(this->imgDead[0], this->e_x[n] * this->move_gap_x + this->START_X, this->e_y[n] * this->tile_size_y + 11 + this->e_y_gap[n] + this->gg_yy, 33);
                    if (this->e_k[n] == -4) {
                        this->e_stage[n] = -1;
                        this->mp += 7;
                        if (this->mp > this->max_mp) {
                            this->mp = this->max_mp;
                        }
                        this->draw_stat();
                    }
                }
            }
            ++n;
        }
        bool bl = false;
        if (this->w_dir != 0) {
            if (this->w_dir > 0) {
                if (this->w_rng > 1) {
                    if (this->w_dir < 10) {
                        this->w_x += 2;
                        int n17 = this->check_att(this->w_x, this->w_y, 1);
                        if (this->w_dir > this->w_rng || n17 > 0) {
                            this->w_dir = 10;
                            if (this->h_dir != 8 && this->h_dir != 6 && this->h_dir != -2) {
                                this->h_mo = 0;
                            }
                            if (this->h_dir != -2) {
                                this->mo_stop = 0;
                            }
                        }
                    } else {
                        this->w_x -= 2;
                        if (this->w_x <= this->h_x + 2) {
                            this->w_dir = -1;
                        }
                    }
                    ++this->w_dir;
                } else {
                    this->check_att(this->w_x + 1, this->w_y, 1);
                    this->w_dir = 0;
                    if (this->h_dir != 8 && this->h_dir != 6 && this->h_dir != -2) {
                        this->h_mo = 0;
                    }
                    if (this->h_dir != -2) {
                        this->mo_stop = 0;
                    }
                }
            } else if (this->w_rng > 1) {
                if (this->w_dir > -10) {
                    this->w_x -= 2;
                    int n18 = this->check_att(this->w_x, this->w_y, -1);
                    if (-this->w_dir > this->w_rng || n18 > 0) {
                        this->w_dir = -10;
                        if (this->h_dir != 8 && this->h_dir != 6 && this->h_dir != -1) {
                            this->h_mo = 2;
                        }
                        if (this->h_dir != -1) {
                            this->mo_stop = 0;
                        }
                    }
                } else {
                    this->w_x += 2;
                    if (this->w_x >= this->h_x - 2) {
                        this->w_dir = 1;
                    }
                }
                --this->w_dir;
            } else {
                this->check_att(this->w_x - 1, this->w_y, -1);
                this->w_dir = 0;
                if (this->h_dir != 8 && this->h_dir != 6 && this->h_dir != -1) {
                    this->h_mo = 2;
                }
                if (this->h_dir != -1) {
                    this->mo_stop = 0;
                }
            }
            if (this->w_rng > 1) {
                graphics.drawImage(this->imgDD, this->w_x * this->move_gap_x + this->START_X, this->h_y * this->tile_size_y + this->y_gap - 3 + this->gg_yy, 33);
            } else if (this->h_mo == 0) {
                graphics.drawImage(this->imgDDD[0], this->w_x * this->move_gap_x + this->START_X + 9, this->h_y * this->tile_size_y + this->y_gap - 8 + this->gg_yy, 33);
            } else if (this->h_mo == 2) {
                graphics.drawImage(this->imgDDD[1], this->w_x * this->move_gap_x + this->START_X - 9, this->h_y * this->tile_size_y + this->y_gap - 8 + this->gg_yy, 33);
            }
        }
    }

    void paint(Graphics graphics) {
        if (this->screen == 10) {
            if (this->state == 1) {
                this->draw_screen(graphics);
                if (this->p_mode != 2) {
                    this->draw_img(String("ui"), 0, 256, 20);
                    graphics.setColor(0);
                    graphics.fillRect(0, 293, 240, 30);
                    graphics.drawImage(this->imgOp, this->btn_r_x, this->btn_y, 24);
                    graphics.drawImage(this->imgPause, 5, this->btn_y, 20);
                    this->draw_pt();
                    this->draw_stat();
                    if (this->p_mode == 0) {
                        this->state = 0;
                    }
                    this->p_mode = 2;
                    
                }
                if (this->msg != nullptr) {
                    this->gg.setColor(10842880);
                    this->gg.fillRect(0, 219, 240, 37);
                    this->gg.drawImage(this->imgConCon, 0, 219, 20);
                    this->gg.setColor(0xFFFFFF);
                    if (this->msg == String("shop")) {
                        this->gg.drawImage(this->imgIkey, 120, 241, 3);
                    }
                }
            } else if (this->state == 0) {
                ++this->ani_step;
                if (this->ani_step == 3) {
                    this->draw_img(String("go"), 104, 91, 17);
                }
                if (this->ani_step == 7) {
                    this->draw_img(String("go"), 142, 123, 17);
                }
                if (this->ani_step == 11) {
                    this->tmp_move = 0;
                    this->auto_move = 0;
                    this->key_pp = false;
                    this->sadari = 0;
                    this->h_idx = 0;
                    this->h_mo = 0;
                    this->h_dir = 0;
                    this->h_dem = 0;
                    this->y_gap = 0;
                    this->mo_stop = 0;
                    
                    this->state = 1;
                }
            } else if (this->state == 33) {
                this->screen = 20;
                this->w_x = this->w_x1 = this->h_x;
                this->w_y = this->w_y1 = this->h_y;
                this->imgFF = nullptr;
                this->load_img(20);
                this->ani_step = 0;
            } else if (this->state == -100) {
                graphics.setColor(0);
                if (this->ani_step < 5) {
                    graphics.fillRect(0, 0, 240, this->ani_step * 14);
                    graphics.fillRect(0, 256 - this->ani_step * 14, 240, this->ani_step * 14);
                } else if (this->ani_step == 5) {
                    this->draw_img(String("game"), 102, 100, 3);
                } else if (this->ani_step == 10) {
                    this->draw_img(String("over"), 138, 145, 3);
                } else if (this->ani_step == 11) {
                    this->goto_menu();
                    this->m_mode = 1;
                    return;
                }
                ++this->ani_step;
            } else if (this->state == 10) {
                ++this->ani_step;
                if (this->ani_step == 2) {
                    this->game_on = false;
                }
            }
        } else if (this->screen == 20) {
            if (this->special == 1) {
                if (this->h_mo == 2) {
                    this->w_x -= 2;
                    this->w_dir = -1;
                    graphics.drawImage(this->imgPil, this->w_x * this->move_gap_x + this->START_X - 4, this->w_y * this->tile_size_y + this->gg_yy, 33);
                } else {
                    this->w_x += 2;
                    this->w_dir = 1;
                    graphics.drawImage(this->imgPil, this->w_x * this->move_gap_x + this->START_X + 4, this->w_y * this->tile_size_y + this->gg_yy, 33);
                }
            } else if (this->special == 2) {
                this->w_x -= 2;
                this->w_x1 += 2;
                this->w_dir = 0;
                graphics.drawImage(this->imgPil, this->w_x * this->move_gap_x - 5 + this->START_X, this->w_y * this->tile_size_y + this->gg_yy, 33);
                graphics.drawImage(this->imgPil, this->w_x1 * this->move_gap_x + 5 + this->START_X, this->w_y * this->tile_size_y + this->gg_yy, 33);
            }
            if (this->ani_step > 10) {
                int n = 0;
                int n2 = 0;
                while (n2 < 12) {
                    if (this->stage == this->e_stage[n2] && this->e_y[n2] == this->w_y && this->e_k[n2] > -1 && this->e_k[n2] < 12 && this->special < 3) {
                        if ((this->w_dir == -1 || this->w_dir == 0) && this->h_x >= this->e_x[n2]) {
                            n = -1;
                            this->MPlay(3);
                        } else if ((this->w_dir == 1 || this->w_dir == 0) && this->h_x <= this->e_x[n2]) {
                            n = 1;
                            this->MPlay(3);
                        }
                    }
                    if (n != 0) {
                        if (n == 1) {
                            if (this->e_x[n2] < 23) {
                                int n3 = n2;
                                this->e_x[n3] = this->e_x[n3] + n;
                                this->e_y_gap[n2] = -3;
                            }
                        } else if (this->e_x[n2] > 0) {
                            int n4 = n2;
                            this->e_x[n4] = this->e_x[n4] + n;
                            this->e_y_gap[n2] = -3;
                        }
                        this->e_att[n2] = n - 2;
                        this->e_tt[n2] = -1;
                        int n5 = n2;
                        this->e_hp[n5] = this->e_hp[n5] - ((this->special - 1) * 20 + 31);
                        if (this->e_hp[n2] < 1) {
                            this->e_k[n2] = -10;
                        }
                        n = 0;
                    }
                    ++n2;
                }
                this->w_dir = 0;
                this->state = 1;
                this->del_img(20);
                this->draw_stat();
                this->screen = 10;
                this->special = 0;
            }
        } else if (this->screen == 2) {
            graphics.drawImage(this->imgLogo, 0, 0, 20);
            graphics.setColor(0);
            graphics.fillRect(0, 293, 240, 30);
            if (this->ani_step == 1) {
                this->game_on = false;
                ++this->ani_step;
            }
            graphics.setColor(0xCFCFCF);
            if (this->menu_mode == 0) {
                int n = 0;
                while (n < 5) {
                    graphics.fillRect(152, n * 23 + 133, 99, 12);
                    ++n;
                }
                graphics.setColor(0xF9F900);
                graphics.fillRect(152, this->m_mode * 23 + 133, 99, 12);
                graphics.drawImage(this->imgOk, this->btn_r_x, this->btn_y, 24);
                graphics.drawImage(this->imgPlay, 5, this->btn_y, 20);
            } else if (this->menu_mode == 1) {
                int n = 0;
                while (n < 2) {
                    graphics.fillRect(152, n * 23 + 133, 99, 12);
                    ++n;
                }
                graphics.setColor(0xF9F900);
                graphics.fillRect(152, this->m_mode * 23 + 133, 99, 12);
                graphics.drawImage(this->imgOk, this->btn_r_x, this->btn_y, 24);
                graphics.drawImage(this->imgOp, 5, this->btn_y, 20);
            }
            graphics.drawImage(this->imgLL, 134, 126, 20);
        } else if (this->screen == 100) {
            graphics.setColor(0);
            graphics.fillRect(0, 293, 240, 30);
            this->draw_mback(graphics);
            graphics.drawImage(this->imgPT, 39, 111, 20);
            graphics.drawImage(this->imgCheck, 19, this->m_mode * 21 + 92, 20);
            if (this->vol == 0) {
                graphics.drawImage(this->imgOff, 157, 155, 20);
            } else {
                graphics.drawImage(this->imgOn, 118, 155, 20);
            }
            graphics.drawImage(this->imgOk, this->btn_r_x, this->btn_y, 24);
        } else if (this->screen == 51) {
            graphics.drawImage(this->imgPT, 120, 20, 17);
            graphics.setColor(0);
            graphics.fillRect(0, 293, 240, 30);
            graphics.setColor(0xFFFFFF);
            graphics.drawRect(163, 18 * this->m_mode + 65, 54, 16);
            graphics.fillRect(32 * this->ani_step + 41, 151, 26, 26);
            graphics.drawImage(this->imgOk, this->btn_r_x, this->btn_y, 24);
            int n = 0;
            while (n < 5) {
                graphics.drawImage(this->imgHero[n], 32 * n + 54, 164, 3);
                ++n;
            }
            this->draw_int(graphics, this->item_p[this->ani_step], 81, 194);
            this->draw_int(graphics, this->gold, 188, 194);
            this->draw_pt();
            graphics.setColor(0xFFFFFF);
            if (this->msg != nullptr) {
                if (this->msg == String("aaaa")) {
                    this->draw_img(String("s_txt0"), 120, 225, 3);
                } else if (this->msg == String("bbbb")) {
                    this->draw_img(String("s_txt1"), 120, 225, 3);
                } else if (this->msg == String("wel")) {
                    this->draw_img(String("s_txt2"), 120, 225, 3);
                } else if (this->msg == String("ppp")) {
                    this->draw_img(String("s_txt3"), 120, 225, 3);
                } else if (this->msg == String("not")) {
                    this->draw_img(String("s_txt4"), 120, 225, 3);
                } else if (this->msg == String("hfull")) {
                    this->draw_img(String("s_txt5"), 120, 225, 3);
                } else if (this->msg == String("mfull")) {
                    this->draw_img(String("s_txt6"), 120, 225, 3);
                } else if (this->msg == String("p3r2")) {
                    this->draw_img(String("s_txt7"), 120, 225, 3);
                } else if (this->msg == String("p5r3")) {
                    this->draw_img(String("s_txt8"), 120, 225, 3);
                } else if (this->msg == String("p7r4")) {
                    this->draw_img(String("s_txt9"), 120, 225, 3);
                } else if (this->msg == String("Heal")) {
                    this->draw_img(String("heal"), 120, 225, 3);
                } else if (this->msg == String("Mana")) {
                    this->draw_img(String("mana"), 120, 225, 3);
                }
                this->msg = nullptr;
            }
        } else if (this->screen == 77) {
            this->draw_screen(graphics);
            if (this->b_step == 1000) {
                graphics.drawImage(this->imgBuf, 0, 0, 20);
                graphics.setColor(0);
                graphics.fillRect(0, 293, 240, 30);
                this->draw_img(String("ui"), 0, 256, 20);
                graphics.drawImage(this->imgOp, this->btn_r_x, this->btn_y, 24);
                this->draw_pt();
                this->draw_stat();
                
                this->b_step = 1001;
            }
            if (this->m_mode == 0) {
                graphics.setColor(0);
                graphics.fillRect(0, this->btn_y - 1, 240, 50);
                graphics.drawImage(this->imgOk, 120, this->btn_y, 17);
                graphics.drawImage(this->imgSkip, this->btn_r_x, this->btn_y, 24);
            }
            JArray<char> cArray = this->strSN[1].toCharArray();
            JArray<int> nArray = JArray<int>(cArray.length());
            int n = 0;
            while (n < nArray.length()) {
                nArray[n] = Integer::parseInt(String::valueOf(cArray[n]));
                ++n;
            }
            int n6 = 1;
            int n7 = this->strSN[this->m_mode + 2].indexOf(String("|"));
            int n8 = 0;
            if (n7 > 0) {
                n6 = 2;
                n8 = this->strSN[this->m_mode + 2].indexOf(String("|"), n7 + 1);
                if (n8 > 0) {
                    n6 = 3;
                }
            }
            int n9 = 207;
            int n10 = 8;
            graphics.setColor(10842880);
            graphics.fillRect(0, 199, 240, 57);
            graphics.drawImage(this->imgConCon, 0, 199, 20);
            if (nArray[this->m_mode] == 1) {
                n9 = 0;
                n10 = 45;
            }
            this->draw_img(String("sn") + (nArray[this->m_mode] - 1), n9, 256, 36);
            graphics.setColor(0xFFFFFF);
            if (n6 == 3) {
                graphics.drawString(this->strSN[this->m_mode + 2].substring(0, n7), n10, 221, 20);
                graphics.drawString(this->strSN[this->m_mode + 2].substring(n7 + 1, n8), n10, 234, 20);
                graphics.drawString(this->strSN[this->m_mode + 2].substring(n8 + 1), n10, 247, 20);
            } else if (n6 == 2) {
                graphics.drawString(this->strSN[this->m_mode + 2].substring(0, n7), n10, 211, 20);
                graphics.drawString(this->strSN[this->m_mode + 2].substring(n7 + 1), n10, 229, 20);
            } else if (n6 == 1) {
                graphics.drawString(this->strSN[this->m_mode + 2], n10, 220, 20);
            }
        } else if (this->screen == 311) {
            this->draw_img(String("load"), 120, 146, 3);
            this->screen = 333;
        } else if (this->screen == 444) {
            if (this->m_mode == 100) {
                this->screen = 110;
            } else if (this->m_mode == 200) {
                this->screen = 115;
            }
            this->ani_step = 0;
            this->MPlay(1);
        } else if (this->screen == -2) {
            this->draw_mback(graphics);
            if (this->b_step >= 0 && this->b_step < 5) {
                draw_controller_help(graphics,this->b_step);
            } else if (this->b_step != 4) {
                this->draw_img(String("help") + this->b_step, 35, 103, 20);
            } else {
                this->draw_img(String("help") + this->b_step, 120, 103, 17);
            }
            this->draw_img(String("ch1"), 9, 213, 20);
            this->draw_img(String("ch"), 231, 213, 24);
        } else if (this->screen == -3) {
            this->draw_mback(graphics);
            static const int delays[]={85,67,55,41,27};this->game_speed=delays[std::clamp(this->h_speed,1,5)-1];
            draw_presentation_settings(graphics,this->p_mode,this->vol,this->vib,this->h_speed);
        } else if (this->screen == -4) {
            this->draw_mback(graphics);
            try {
                graphics.drawImage(Image::createImage((String)String("/about.png")), 119, 97, 17);
            }
            catch (const std::exception&) {}
        } else if (this->screen == 200) {
            int n = -26;
            int n11 = -13;
            graphics.drawImage(this->imgBuf, 0, 15, 20);
            graphics.setColor(0);
            graphics.fillRect(0, 293, 240, 30);
            graphics.setColor(8304127);
            graphics.fillRect(0, 0, 240, 16);
            graphics.drawImage(this->imgSkip, this->btn_r_x, this->btn_y, 24);
            if (this->ani_step != 1) {
                if (this->ani_step < 5) {
                    ++this->h_x;
                    this->e_x[0] = this->e_x[0] - 1;
                } else if (this->ani_step < 13) {
                    this->e_et[0] = 5;
                    this->e_tt[0] = 13;
                } else if (this->ani_step < 21) {
                    this->e_tt[0] = 16;
                } else if (this->ani_step < 29) {
                    this->e_et[0] = 6;
                    this->e_tt[0] = 13;
                } else if (this->ani_step < 34) {
                    this->h_mo = 2;
                    --this->h_x;
                } else if (this->ani_step < 45) {
                    this->h_mo = 4;
                    this->h_idx = 0;
                    this->mo_stop = 1;
                    this->e_et[0] = 4;
                    this->e_tt[0] = 6;
                } else if (this->ani_step < 56) {
                    this->e_x[1] = this->e_x[1] - 1;
                    graphics.drawImage(this->imgEnemy[4 + this->e_mo[0] + this->e_idx[0]], this->e_x[1] * this->move_gap_x - 5, 93 - n, 33);
                    graphics.drawImage(this->imgEnemy[8 + this->e_mo[0] + this->e_idx[0]], this->e_x[1] * this->move_gap_x + 44, 93 - n, 33);
                } else if (this->ani_step < 62) {
                    graphics.drawImage(this->imgEnemy[4 + this->e_mo[0] + this->e_idx[0]], this->e_x[1] * this->move_gap_x - 5, 93 - n, 33);
                    graphics.drawImage(this->imgEnemy[8 + this->e_mo[0] + this->e_idx[0]], this->e_x[1] * this->move_gap_x + 44, 93 - n, 33);
                    this->e_et[1] = 1;
                    this->e_tt[1] = 16;
                } else if (this->ani_step < 72) {
                    this->e_x[1] = this->e_x[1] + 1;
                    this->e_x[0] = this->e_x[0] + 1;
                    graphics.drawImage(this->imgEnemy[2 + this->e_mo[0] + this->e_idx[0]], this->e_x[1] * this->move_gap_x - 5, 93 - n, 33);
                    graphics.drawImage(this->imgEnemy[6 + this->e_mo[0] + this->e_idx[0]], this->e_x[1] * this->move_gap_x + 44, 93 - n, 33);
                    this->e_et[1] = 1;
                    this->e_tt[1] = this->e_tt[1] + 1;
                } else if (this->ani_step < 77) {
                    this->e_x[2] = this->e_x[2] + 1;
                    this->e_x[0] = this->e_x[0] + 1;
                    graphics.drawImage(this->imgEnemy[13 + this->e_mo[0] + this->e_idx[0]], this->e_x[0] * this->move_gap_x - 275, 93 - n, 33);
                } else if (this->ani_step < 83) {
                    this->h_mo = 0;
                    this->mo_stop = 0;
                    this->e_et[0] = 2;
                    this->e_tt[0] = 7;
                    graphics.drawImage(this->imgEnemy[13 + this->e_mo[0] + this->e_idx[0]], this->e_x[0] * this->move_gap_x - 275, 93 - n, 33);
                } else if (this->ani_step < 90) {
                    this->h_mo = 2;
                    this->e_et[0] = 3;
                    graphics.drawImage(this->imgEnemy[13 + this->e_mo[0] + this->e_idx[0]], this->e_x[0] * this->move_gap_x - 275, 93 - n, 33);
                } else if (this->ani_step < 96) {
                    this->e_et[0] = 0;
                    this->e_et[1] = 1;
                    this->e_tt[1] = 4;
                    graphics.drawImage(this->imgEnemy[13 + this->e_mo[0] + this->e_idx[0]], this->e_x[0] * this->move_gap_x - 275, 93 - n, 33);
                } else if (this->ani_step < 118) {
                    this->h_mo = 0;
                    ++this->h_x;
                    this->e_x[0] = this->e_x[0] + 1;
                    this->e_et[1] = 0;
                    graphics.drawImage(this->imgEnemy[13 + this->e_mo[0] + this->e_idx[0]], this->e_x[0] * this->move_gap_x - 275, 93 - n, 33);
                } else {
                    this->del_img(200);
                    this->draw_img(String("load"), 120, 146, 3);
                    this->m_mode = 3;
                    this->screen = 333;
                }
            }
            if (this->ani_step < 118) {
                int n12 = 0;
                while (n12 < 2) {
                    if (this->e_et[n12] != 0) {
                        if (this->e_et[n12] == 4) {
                            graphics.drawImage(this->imgE[this->e_et[n12] - 1], this->e_tt[n12] * this->move_gap_x + 10, 66 - this->ani_step % 2 * 2 - n11, 33);
                        } else if (this->e_et[n12] == 6) {
                            graphics.drawImage(this->imgE[4], this->e_tt[n12] * this->move_gap_x + 7, 63 + this->h_y - n11, 33);
                            --this->h_y;
                        } else {
                            graphics.drawImage(this->imgE_box, this->e_tt[n12] * this->move_gap_x + 8, 63 - n11, 33);
                            if (this->e_et[n12] != 5) {
                                graphics.drawImage(this->imgE[this->e_et[n12] - 1], this->e_tt[n12] * this->move_gap_x + 8, 57 - n11, 33);
                            }
                        }
                    }
                    ++n12;
                }
                graphics.drawImage(this->imgHero[this->h_idx + this->h_mo], this->h_x * this->move_gap_x, 93 - n, 33);
                graphics.drawImage(this->imgEnemy[this->e_idx[0] + this->e_mo[0]], this->e_x[0] * this->move_gap_x, 93 - n, 33);
                if (this->mo_stop == 0) {
                    this->h_idx = this->h_idx == 0 ? 1 : 0;
                }
                if (this->e_mo_stop[0] == 0) {
                    this->e_idx[0] = this->e_idx[0] == 0 ? 1 : 0;
                }
            }
            ++this->ani_step;
        } else if (this->screen == 1) {
            graphics.drawImage(this->imgLogo, 0, 0, 20);
            graphics.drawImage(this->imgAw, 0, 295, 20);
            this->m_mode = this->m_mode == 1 ? 0 : 1;
            if (this->ani_step > 7) {
                this->h_dir = 1;
            }
            if (this->ani_step > 3) {
                graphics.drawImage(this->imgE[0], 23, 22, 20);
            }
            if (this->ani_step > 6) {
                graphics.drawImage(this->imgE[1], 54, 66, 20);
            }
            if (this->h_dir == 1 && this->ani_step % 2 == 0) {
                graphics.drawImage(this->imgPT, 120, 253, 17);
            }
        } else if (this->screen == 110) {
            int n = -26;
            if (this->ani_step == 0) {
                this->load_img(13);
                this->load_img(15);
                this->load_img(12);
                this->h_x = -22;
                this->e_x[0] = -9;
                this->e_x[1] = -3;
                this->e_x[2] = -6;
                this->e_y[2] = 93;
                this->e_x[3] = -25;
                this->e_x[4] = 21;
                this->e_y[4] = 44;
                this->e_k[0] = 0;
                this->e_k[1] = 6;
                this->e_idx[0] = 0;
                this->h_mo = 0;
                this->y_gap = 0;
                this->mo_stop = 0;
                this->stage = 201;
                this->make_map2();
                this->make_buf2();
            } else if (this->ani_step < 59) {
                int n13;
                graphics.drawImage(this->imgBuf, 0, 39, 20);
                graphics.setColor(8304127);
                graphics.fillRect(0, 0, 240, 39);
                graphics.setColor(0);
                graphics.fillRect(0, 293, 240, 30);
                if (this->ani_step < 37) {
                    n13 = 0;
                    while (n13 < 4) {
                        int n14 = n13++;
                        this->e_x[n14] = this->e_x[n14] + 1;
                    }
                    ++this->h_x;
                } else if (this->ani_step < 43) {
                    graphics.drawImage(this->imgE_box, this->h_x * this->move_gap_x - 12, 74 - n, 33);
                    graphics.drawImage(this->imgE[0], this->h_x * this->move_gap_x - 12, 69 - n, 33);
                    this->e_x[4] = this->e_x[4] + 1;
                } else if (this->ani_step < 60) {
                    this->e_x[3] = this->e_x[3] + 1;
                    ++this->h_x;
                }
                n13 = 0;
                while (n13 < 2) {
                    graphics.drawImage(this->imgEnemy[this->e_k[n13] + this->h_idx], this->e_x[n13] * this->move_gap_x + 2, 117 - n, 33);
                    ++n13;
                }
                graphics.drawImage(this->imgOB[this->h_idx], this->e_x[2] * this->move_gap_x + 2, this->e_y[2] + 24 - n, 33);
                graphics.drawImage(this->imgOB[this->h_idx + 2], this->e_x[3] * this->move_gap_x, 117 - n, 33);
                if (this->m_mode % 2 == 0) {
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x - 7, this->e_y[4] + 17, 33);
                }
                graphics.drawImage(this->imgHero[this->e_idx[0] + this->h_mo], this->h_x * this->move_gap_x, 93 + this->y_gap + 24 - n, 33);
                this->h_idx = this->h_idx == 0 ? 1 : 0;
                if (this->mo_stop == 0) {
                    this->e_idx[0] = this->e_idx[0] == 0 ? 1 : 0;
                }
            } else {
                this->imgBuf = nullptr;
                
                try {
                    this->imgBuf = Image::createImage((int)240, (int)256);
                    this->buf_g = this->imgBuf.getGraphics();
                }
                catch (const std::exception&) {
                    
                }
                this->del_img(15);
                this->draw_img(String("load"), 120, 146, 3);
                this->screen = 333;
            }
            ++this->ani_step;
        } else if (this->screen == 115) {
            int n = -26;
            if (this->ani_step == 0) {
                this->load_img(15);
                this->h_x = -2;
                this->w_x = 138;
                this->e_x[0] = -9;
                this->e_x[1] = -3;
                this->e_x[2] = 21;
                this->e_y[2] = 45;
                this->e_x[3] = -25;
                this->e_x[4] = 12;
                this->e_y[4] = 93;
                this->e_y[5] = 29;
                this->e_k[0] = 0;
                this->e_k[1] = 6;
                this->e_max_hp[4] = 100;
                this->e_hp[4] = 100;
                this->e_idx[0] = 0;
                this->h_mo = 0;
                this->y_gap = 0;
                this->mo_stop = 0;
                this->stage = 301;
                this->make_map2();
                this->make_buf2();
            } else if (this->ani_step < 170) {
                graphics.drawImage(this->imgBuf, 0, 39, 20);
                graphics.setColor(8304127);
                graphics.fillRect(0, 0, 240, 39);
                graphics.setColor(0);
                graphics.fillRect(0, 293, 240, 30);
                if (this->ani_step < 5) {
                    ++this->h_x;
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 10) {
                    this->mo_stop = 3;
                    ++this->h_x;
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 15) {
                    this->mo_stop = 4;
                    ++this->h_x;
                    if (this->ani_step > 12) {
                        this->e_x[4] = this->e_x[4] + 1;
                        this->e_hp[4] = 90;
                    }
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 20) {
                    this->mo_stop = 1;
                    if (this->ani_step == 18) {
                        this->e_x[4] = this->e_x[4] + 2;
                        this->e_hp[4] = 70;
                    }
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 24) {
                    this->mo_stop = 2;
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 29) {
                    this->mo_stop = 1;
                    if (this->ani_step == 27) {
                        this->e_x[4] = this->e_x[4] + 2;
                        this->e_hp[4] = 50;
                    }
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 33) {
                    this->mo_stop = 2;
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 38) {
                    this->mo_stop = 6;
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 43) {
                    this->mo_stop = 7;
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                } else if (this->ani_step < 49) {
                    this->mo_stop = 5;
                    graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                    int n15 = 0;
                    while (n15 < this->ani_step - 42) {
                        graphics.drawImage(this->imgPilll, this->h_x * this->move_gap_x + n15 * 20 + 20, 135, 33);
                        ++n15;
                    }
                } else if (this->ani_step < 55) {
                    if (this->ani_step == 49) {
                        this->e_hp[4] = 0;
                    }
                    this->mo_stop = 0;
                    this->h_mo = 0;
                    if (this->ani_step % 2 == 0) {
                        graphics.drawImage(this->imgOB[this->h_idx + 4], this->e_x[4] * this->move_gap_x + 4, this->e_y[4] + 24 - n, 33);
                    }
                } else if (this->ani_step < 61) {
                    this->h_mo = 6;
                    this->y_gap -= 12;
                    this->mo_stop = 8;
                } else if (this->ani_step == 61) {
                    this->y_gap = -64;
                    this->h_mo = 0;
                    this->mo_stop = 0;
                } else if (this->ani_step < 66) {
                    ++this->h_x;
                } else if (this->ani_step < 103) {
                    this->e_x[3] = this->e_x[3] + 1;
                } else if (this->ani_step > 110 && this->ani_step < 121) {
                    this->h_mo = 2;
                    this->e_y[5] = 29;
                } else if (this->ani_step == 121) {
                    this->h_mo = 0;
                } else if (this->ani_step > 152) {
                    graphics.fillRect(0, 0, 240, (this->ani_step - 152) * 9);
                    graphics.fillRect(0, 292 - (this->ani_step - 152) * 9, 240, (this->ani_step - 152) * 10);
                }
                graphics.drawImage(this->imgOB[this->h_idx], this->e_x[2] * this->move_gap_x, this->e_y[2] + 34, 33);
                graphics.drawImage(this->imgOB[this->h_idx + 2], this->e_x[3] * this->move_gap_x, 79, 33);
                graphics.drawImage(this->imgHero[this->e_idx[0] + this->h_mo], this->h_x * this->move_gap_x, 93 + this->y_gap + 24 - n, 33);
                if (this->mo_stop == 0) {
                    this->e_idx[0] = this->e_idx[0] == 0 ? 1 : 0;
                } else if (this->mo_stop == 1) {
                    this->w_x += 8;
                    graphics.drawImage(this->imgDD, this->w_x - 13, 134, 33);
                    this->h_mo = 4;
                } else if (this->mo_stop == 2) {
                    this->w_x -= 8;
                    graphics.drawImage(this->imgDD, this->w_x - 13, 134, 33);
                    this->h_mo = 0;
                    this->e_idx[0] = this->e_idx[0] == 0 ? 1 : 0;
                } else if (this->mo_stop == 3) {
                    this->y_gap -= 5;
                    this->h_mo = 6;
                } else if (this->mo_stop == 4) {
                    this->y_gap += 5;
                    this->h_mo = 14;
                } else if (this->mo_stop == 5) {
                    this->h_mo = 4;
                } else if (this->mo_stop == 6) {
                    graphics.drawImage(this->imgRing, this->h_x * this->move_gap_x, 145 + this->y_gap + (33 - this->ani_step) * 3 - 9, 33);
                    graphics.drawImage(this->imgRing, this->h_x * this->move_gap_x, 145 + this->y_gap - 4 + (33 - this->ani_step) * 3 + 1, 33);
                } else if (this->mo_stop == 7) {
                    graphics.drawImage(this->imgRing, this->h_x * this->move_gap_x, 145 + this->y_gap + (38 - this->ani_step) * 3 - 9, 33);
                    graphics.drawImage(this->imgRing, this->h_x * this->move_gap_x, 145 + this->y_gap - 4 + (38 - this->ani_step) * 3 + 1, 33);
                }
                this->h_idx = this->h_idx == 0 ? 1 : 0;
                if (this->m_mode > 199 && this->ani_step > 67 && this->ani_step < 108) {
                    this->m_mode = 201;
                    graphics.drawImage(this->imgOB[6], 184, this->e_y[5] + 14, 33);
                    this->e_y[5] = this->e_y[5] - 1;
                    if (this->ani_step == 81 || this->ani_step == 95) {
                        this->e_y[5] = 29;
                    }
                } else if (this->ani_step > 107 && this->ani_step < 113) {
                    graphics.drawImage(this->imgE_box, 123, 15, 20);
                } else if (this->ani_step > 112 && this->ani_step < 118) {
                    graphics.drawImage(this->imgE_box, 162, 15, 20);
                } else if (this->ani_step > 117 && this->ani_step < 129) {
                    graphics.drawImage(this->imgE_box, 162, 15, 20);
                } else if (this->ani_step > 131) {
                    graphics.drawImage(this->imgOB[6], 184, this->e_y[5] + 14, 33);
                    this->e_y[5] = this->e_y[5] - 1;
                    if (this->ani_step == 146) {
                        this->e_y[5] = 29;
                    }
                }
                if (this->ani_step > 12 && this->ani_step < 55) {
                    graphics.setColor(0xFFFF00);
                    graphics.fillRect(this->e_x[4] * this->move_gap_x - 8 + this->START_X, 78, 25, 5);
                    graphics.setColor(14211584);
                    graphics.fillRect(this->e_x[4] * this->move_gap_x - 8 + this->START_X, 81, 25, 2);
                    graphics.setColor(0xFF0000);
                    graphics.fillRect(this->e_x[4] * this->move_gap_x - 8 + this->START_X, 78, 25 * this->e_hp[4] / this->e_max_hp[4], 5);
                    graphics.setColor(0xD40000);
                    graphics.fillRect(this->e_x[4] * this->move_gap_x - 8 + this->START_X, 81, 25 * this->e_hp[4] / this->e_max_hp[4], 2);
                    graphics.setColor(0);
                    graphics.drawRect(this->e_x[4] * this->move_gap_x - 8 + this->START_X, 78, 25, 5);
                }
            } else {
                this->del_img(15);
                this->draw_img(String("load"), 120, 146, 3);
                this->screen = 333;
            }
            ++this->ani_step;
        } else if (this->screen == 333) {
            if (this->m_mode == 0) {
                this->del_img(2);
                this->del_img(12);
                this->stage = 1000;
                this->chap = 0;
                this->make_map2();
                this->load_img(12);
                this->make_buf2();
                this->load_img(200);
                this->h_x = 8;
                this->h_y = 0;
                this->h_mo = 0;
                this->h_idx = 0;
                this->mo_stop = 0;
                this->e_x[0] = 20;
                this->e_x[1] = 25;
                this->e_x[2] = 21;
                this->e_idx[0] = 0;
                this->e_mo[0] = 0;
                this->e_mo_stop[0] = 0;
                this->e_et[0] = 0;
                this->e_et[1] = 0;
                this->e_tt[0] = 0;
                this->e_tt[1] = 0;
                this->screen = 200;
                this->ani_step = 0;
                this->game_on = true;
            } else if (this->m_mode < 200) {
                this->init_game();
            } else if (this->m_mode > 199) {
                if (this->m_mode == 201) {
                    this->imgBuf = nullptr;
                    this->del_img(9);
                    this->del_img(10);
                    this->del_img(11);
                    this->del_img(12);
                    this->del_img(13);
                    this->del_img(100);
                    this->del_img(20);
                    this->menu_mode = 0;
                    this->load_img(1);
                    this->load_img(2);
                    this->m_mode = 202;
                } else if (this->m_mode == 202) {
                    this->ani_step = 0;
                    this->screen = 2;
                    this->m_mode = 0;
                    this->game_on = true;
                }
            }
        } else if (this->screen == 0) {
            if (this->ani_step == 0) {
                graphics.setColor(0);
                graphics.fillRect(0, 0, 240, 320);
                graphics.setColor(0xFFFFFF);
                graphics.fillRect(0, 160, 240, 161);
                try {
                    graphics.drawImage(Image::createImage((String)String("/logoTxt0.png")), 120, 80, 3);
                    graphics.drawImage(Image::createImage((String)String("/logoTxt1.png")), 120, 240, 3);
                }
                catch (const std::exception&) {
                    
                }
                this->gg = graphics;
                this->DF.start_app = true;
            }
            if (this->ani_step > 14) {
                this->screen = 1;
                this->MPlay(0);
            }
            ++this->ani_step;
        } else if (this->screen == 123) {
            graphics.drawImage(this->imgLogo, 0, 0, 20);
            graphics.setColor(0);
            graphics.fillRect(0, 293, 240, 30);
            if (this->ani_step > 6) {
                graphics.drawImage(this->imgWel, 120, 42, 3);
                graphics.drawImage(this->imgPlay, 5, this->btn_y, 20);
                graphics.drawImage(this->imgOp, this->btn_r_x, this->btn_y, 24);
            }
            ++this->ani_step;
        }
    }

    void tick() {

            if (this->game_on) {
                if (this->screen == 10) {
                    try {
                        
                    }
                    catch (const std::exception&) {
                        
                    }
                    if (this->h_dir == 4) {
                        if (this->h_x > 22) {
                            this->change_map(3);
                        } else {
                            if (this->check_map(this->h_x, this->h_y, 2) < 0) {
                                this->h_dir = -2;
                                this->h_idx = 0;
                                this->h_mo += 7;
                                this->mo_stop = 1;
                            } else {
                                this->h_mo = 0;
                            }
                            this->check_item(this->h_x, this->h_y, 0);
                            if(screen==-6)return;
                            ++this->h_x;
                        }
                    } else if (this->h_dir == 2) {
                        if (this->h_x < 2) {
                            this->change_map(2);
                        } else {
                            if (this->check_map(this->h_x - 2, this->h_y, 2) < 0) {
                                this->h_dir = -1;
                                this->h_idx = 0;
                                this->h_mo += 7;
                                this->mo_stop = 1;
                            } else {
                                this->h_mo = 2;
                            }
                            this->check_item(this->h_x, this->h_y, 0);
                            if(screen==-6)return;
                            --this->h_x;
                        }
                    } else if (this->h_dir == 6) {
                        if (this->sadari == 1 || this->auto_move == 1) {
                            if (this->y_gap == -56) {
                                this->y_gap = 0;
                                this->h_y -= 2;
                                if (this->h_y == 5) {
                                    this->auto_move = 0;
                                }
                                if (this->h_y == -1) {
                                    this->stage += 3;
                                    this->h_y = 7;
                                    if ((this->stage - 1) / 3 == 7) {
                                        this->del_img(9);
                                        this->del_img(13);
                                        this->h_y = 100;
                                        if (this->chap != 2) {
                                            this->del_img(12);
                                            this->m_mode = 100;
                                            ++this->chap;
                                        } else {
                                            this->m_mode = 200;
                                        }
                                        this->draw_img(String("load"), 120, 146, 3);
                                        this->screen = 444;
                                    } else {
                                        this->change_map(0);
                                        this->addStage(String("a"), 0);
                                        this->addStage(String("b"), 1);
                                        this->addStage(String("c"), 2);
                                        this->init_en();
                                        this->init_ob();
                                    }
                                } else {
                                    this->h_mo = 0;
                                }
                                if (this->h_y != 100) {
                                    if (this->check_map(this->h_x, this->h_y - 1, 1) == 52) {
                                        this->h_mo = 10;
                                    } else {
                                        this->h_dir = 0;
                                        this->ing_ss = false;
                                    }
                                }
                            } else {
                                if (this->h_y == 1) {
                                    this->auto_move = 1;
                                }
                                this->y_gap -= 8;
                                this->ing_ss = true;
                            }
                        }
                    } else if (this->h_dir == 8) {
                        if (this->sadari == 2) {
                            if (this->y_gap == 56) {
                                this->y_gap = 0;
                                this->h_y += 2;
                                this->h_mo = 0;
                                int n = this->check_map(this->h_x, this->h_y + 1, 1);
                                if (n == 52) {
                                    this->h_mo = 10;
                                } else {
                                    this->h_dir = 0;
                                    this->ing_ss = false;
                                }
                            } else {
                                this->y_gap += 8;
                                this->ing_ss = true;
                            }
                        }
                    } else if (this->h_dir > 9 && this->h_dir < 20) {
                        if (this->h_dir == 14) {
                            if (this->h_x < 23) {
                                ++this->h_x;
                            } else {
                                this->change_map(3);
                            }
                        } else if (this->h_dir == 12) {
                            if (this->h_x > 1) {
                                --this->h_x;
                            } else {
                                this->change_map(2);
                            }
                        }
                        if (this->y_gap == -30) {
                            this->h_dir += 10;
                            this->y_gap += 10;
                            if (this->h_mo < 13) {
                                ++this->h_mo;
                            }
                        } else {
                            this->y_gap -= 10;
                        }
                    } else if (this->h_dir > 19 && this->h_dir < 30) {
                        if (this->y_gap == 0) {
                            if (this->check_map(this->h_x - 1, this->h_y, 2) > 0) {
                                if (this->tmp_move == 0) {
                                    this->h_dir = 0;
                                    this->h_mo = this->h_mo < 13 ? (this->h_mo -= 7) : (this->h_mo == 13 ? (this->h_mo -= 11) : (this->h_mo -= 14));
                                    if (this->h_mo < 0) {
                                        this->h_mo = 0;
                                    }
                                    this->mo_stop = 0;
                                } else if (this->tmp_move == 1) {
                                    this->h_dir = 4;
                                    this->h_mo = 0;
                                    this->mo_stop = 0;
                                } else if (this->tmp_move == -1) {
                                    this->h_dir = 2;
                                    this->h_mo = 2;
                                    this->mo_stop = 0;
                                }
                            } else {
                                if (this->h_dir == 24) {
                                    if (this->h_x < 23) {
                                        ++this->h_x;
                                    }
                                    this->h_dir = -2;
                                    if (this->h_mo == 14) {
                                        this->h_mo = 7;
                                    }
                                } else if (this->h_dir == 22) {
                                    if (this->h_x > 1) {
                                        --this->h_x;
                                    }
                                    this->h_dir = -1;
                                    if (this->h_mo == 13) {
                                        this->h_mo = 9;
                                    }
                                }
                                this->y_gap += 16;
                            }
                        } else {
                            this->y_gap += 10;
                            if (this->h_dir == 24) {
                                if (this->h_x < 23) {
                                    ++this->h_x;
                                } else {
                                    this->change_map(3);
                                }
                            } else if (this->h_dir == 22) {
                                if (this->h_x > 1) {
                                    --this->h_x;
                                } else {
                                    this->change_map(2);
                                }
                            }
                            if (this->y_gap == -10 && this->h_mo > 12) {
                                if (this->h_mo == 14) {
                                    if (this->check_att(this->h_x + 1, this->h_y, 1) == 1) {
                                        --this->h_x;
                                    }
                                } else if (this->check_att(this->h_x - 1, this->h_y, -1) == 1) {
                                    ++this->h_x;
                                }
                            }
                        }
                    } else if (this->h_dir < 0) {
                        if (this->h_y < 7) {
                            if (this->y_gap == 32) {
                                this->y_gap = 0;
                                this->h_y += 2;
                                int n = 0;
                                n = this->h_mo == 9 ? this->h_x - 2 : (this->h_mo == 7 ? this->h_x : this->h_x - 1);
                                if (this->check_map(n, this->h_y, 2) > 0 && this->h_y != 7) {
                                    this->h_mo -= 7;
                                    if (this->h_dir == -2) {
                                        this->h_mo = 0;
                                    } else if (this->h_dir == -1) {
                                        this->h_mo = 2;
                                    }
                                    this->mo_stop = 0;
                                }
                            } else {
                                this->y_gap = this->y_gap != -10 ? (this->y_gap += 16) : 0;
                            }
                            if (this->h_dir == -1) {
                                if (this->h_x > 1) {
                                    --this->h_x;
                                } else {
                                    this->change_map(2);
                                }
                            } else if (this->h_dir == -2) {
                                if (this->h_x < 23) {
                                    ++this->h_x;
                                } else {
                                    this->change_map(3);
                                }
                            }
                            if (this->mo_stop == 0) {
                                this->h_dir = 0;
                            }
                        } else {
                            this->h_dir = 100;
                            this->ani_step = 0;
                            this->state = -100;
                            this->del_img(11);
                            this->MPlay(1);
                            this->call_vib(1000);
                        }
                    }
                    if (this->sn_m[3] > 0 && this->sn_m[0] == this->stage && this->sn_m[2] == this->h_y && this->h_x > this->sn_m[1] - 3 && this->h_x < this->sn_m[1] + 3) {
                        this->tmp_move = 0;
                        this->game_on = false;
                        this->m_mode = 0;
                        this->load_sn(this->stage);
                        this->screen = 77;
                    }
                    if (this->att_d != 0) {
                        ++this->att_d;
                        if (this->att_d == 4) {
                            this->att_d = 0;
                        }
                    }
                    this->repaint();
                    this->serviceRepaints();
                    return;
                }
                if (this->screen == 20 || this->screen == 50) {
                    try {
                        
                    }
                    catch (const std::exception&) {
                        
                    }
                    ++this->ani_step;
                    if (this->screen == 50) {
                        this->game_on = false;
                        this->m_mode = 0;
                        this->ani_step = 0;
                        this->del_img(11);
                        this->load_img(50);
                        this->screen = 51;
                        this->msg = String("wel");
                    }
                    this->repaint();
                    this->serviceRepaints();
                    return;
                }
                if (this->screen == 1 || this->screen == 2) {
                    if (this->ani_step <= -1) return;
                    int n = 20;
                    if (this->screen == 1) {
                        n = 80;
                    }
                    try {
                        
                    }
                    catch (const std::exception&) {
                        
                    }
                    ++this->ani_step;
                    this->repaint();
                    this->serviceRepaints();
                    return;
                }
                if (this->screen == 200 || this->screen == 333 || this->screen == 110 || this->screen == 115 || this->screen == 311 || this->screen == 444) {
                    int n = 20;
                    if (this->screen == 200 || this->screen == 110 || this->screen == 115) {
                        n = 55;
                    }
                    try {
                        
                    }
                    catch (const std::exception&) {
                        
                    }
                    this->repaint();
                    this->serviceRepaints();
                    return;
                }
                if (this->screen != 123 && this->screen != 0) return;
                try {
                    
                }
                catch (const std::exception&) {
                    
                }
                this->repaint();
                this->serviceRepaints();
                return;
            }
            try {
                
            }
            catch (const std::exception&) {
            }

    }

    
    void change_map(int n) {
        this->w_dir = 0;
        if (n == 2) {
            if (this->stage % 3 == 1) return;
            --this->stage;
            this->h_x = 23;
        } else if (n == 3) {
            if (this->stage % 3 == 0) return;
            ++this->stage;
            this->h_x = 1;
        }
        this->game_on = false;
        this->make_map(8, 8);
        this->make_buf(8, 8);
        this->game_on = true;
    }

    int check_map(int n, int n2, int n3) {
        byte by = this->map[n2][n / 3];
        if (n3 == 2 && by > 52) {
            return -1;
        }
        return this->map[n2][n / 3];
    }

    void check_item(int n, int n2, int n3) {
        int n4 = 0;
        while (n4 < 8) {
            if (this->o_k[n4] != 0 && this->stage == this->o_st[n4] && n2 == this->o_y[n4] && n == this->o_x[n4]) {
                if (this->o_k[n4] == 1) {
                    this->o_k[n4] = 0;
                    this->gold += 5;
                    this->MPlay(5);
                } else if (this->o_k[n4] == 2) {
                    this->h_dir = 0;
                    this->o_k[n4] = 3;
                    this->state = 10;
                    this->ani_step = 0;
                    this->gg.setColor(10842880);
                    this->gg.fillRect(0, 219, 240, 38);
                    this->gg.drawImage(this->imgConCon, 0, 219, 20);
                    this->gg.setColor(0xFFFFFF);
                    if (this->stage == 4 && this->chap == 0) {
                        this->draw_img(String("item0"), 155, 242, 6);
                        this->gg.drawImage(this->imgGetItem, 58, 237, 20);
                        this->w_rng = 2;
                        this->w_dem = 10;
                        this->load_img(100);
                        this->MPlay(5);
                        return;
                    }
                    if (this->stage == 8 && this->chap == 1 && this->h_y == 1) {
                        this->draw_img(String("item1"), 155, 242, 6);
                        this->gg.drawImage(this->imgGetItem, 58, 237, 20);
                        if (this->w_rng < 3) {
                            this->w_rng = 3;
                            this->w_dem = 15;
                            this->load_img(100);
                        }
                        this->MPlay(5);
                        return;
                    }
                    if (this->get_rnd(2) == 0) {
                        if (this->get_rnd(3) == 0) {
                            this->draw_img(String("item4"), 157, 242, 6);
                            if (this->pt[1] < 9) {
                                this->pt[1] = this->pt[1] + 1;
                            }
                        } else {
                            this->draw_img(String("item3"), 157, 242, 6);
                            if (this->pt[0] < 9) {
                                this->pt[0] = this->pt[0] + 1;
                            }
                        }
                        this->gg.drawImage(this->imgGetItem, 58, 237, 20);
                        this->draw_pt();
                    } else {
                        int n5 = this->get_rnd(5) + 23;
                        this->gold += n5;
                        this->gg.drawString(n5 + String("   GOLD"), 120, 231, 17);
                    }
                    this->MPlay(5);
                }
                if (this->gold > 999) {
                    this->gold = 999;
                }
            }
            ++n4;
        }
    }

    int get_rnd(int n) {
        int n2 = this->rnd.nextInt() % n;
        return n2;
    }

    int get_rnd2(int n) {
        int n2 = this->rnd.nextInt() % n;
        if (n2 < 0) {
            n2 = -n2;
        }
        return n2;
    }

    void goto_menu() {
        this->imgBuf = nullptr;
        this->del_img(9);
        this->del_img(10);
        this->del_img(11);
        this->del_img(12);
        this->del_img(13);
        this->del_img(100);
        this->del_img(20);
        this->menu_mode = 0;
        this->load_img(1);
        this->load_img(2);
        this->ani_step = 0;
        this->tmp_move = 0;
        this->auto_move = 0;
        this->key_pp = false;
        this->sadari = 0;
        this->h_idx = 0;
        this->h_mo = 0;
        this->h_dir = 0;
        this->h_dem = 0;
        this->y_gap = 0;
        this->mo_stop = 0;
        this->screen = 2;
        this->m_mode = 0;
        this->game_on = true;
    }

    void keyReleased(int n) {
        if (this->screen == 10) {
            if (this->h_dir == 2 || this->h_dir == 4) {
                this->h_dir = 0;
            }
            this->key_pp = false;
            this->sadari = 0;
            this->tmp_move = 0;
        }
    }

    void keyPressed(int n) {
        if(screen==-6){if(n==-5||n==-8){goto_menu();repaint();}return;}
        if (this->screen == 10 && this->auto_move == 0) {
            if (this->state == 1 && this->h_dem != 99 && this->p_mode == 2) {
                if (!(n != -1 && n != 50 || this->h_mo >= 3 && this->h_mo != 10)) {
                    int n2 = this->check_map(this->h_x, this->h_y - 1, 1);
                    if (n2 == 56 && (this->h_x % 3 == 0 || this->h_x % 3 == 1) || n2 > 56 && n2 < 59 && this->h_x % 3 == 2) {
                        this->mo_stop = 1;
                        this->tmp_mo = this->h_mo;
                        this->h_idx = 0;
                        this->y_gap = -12;
                        this->h_dir = 0;
                        this->h_mo = 12;
                        if (n2 > 56) {
                            ++this->h_x;
                        } else if (this->h_x % 3 == 1) {
                            --this->h_x;
                        }
                        if (this->check_map(this->h_x - 1, this->h_y - 1, 1) == 58) {
                            this->msg = String("shop");
                        }
                    } else if (n2 == 52 && this->h_x % 3 != 0 && this->h_dir != 8) {
                        this->mo_stop = 0;
                        this->h_dir = 6;
                        this->h_mo = 10;
                        this->sadari = 1;
                    } else if (this->h_dir != 8) {
                        this->h_idx = 0;
                        this->mo_stop = 1;
                        this->h_mo += 6;
                        this->h_dir += 10;
                    } else if (this->h_dir == 8) {
                        this->mo_stop = 0;
                        this->h_dir = 6;
                        this->h_mo = 10;
                        this->sadari = 1;
                        this->h_y += 2;
                        if (this->y_gap == 0) {
                            this->h_y -= 2;
                            if (!this->ing_ss) {
                                this->h_mo = 0;
                                this->h_dir = 0;
                            }
                        } else if (this->y_gap == 8) {
                            this->y_gap = -56;
                        } else if (this->y_gap == 16) {
                            this->y_gap = -48;
                        } else if (this->y_gap == 24) {
                            this->y_gap = -40;
                        } else if (this->y_gap == 32) {
                            this->y_gap = -32;
                        } else if (this->y_gap == 40) {
                            this->y_gap = -24;
                        } else if (this->y_gap == 48) {
                            this->y_gap = -16;
                        } else if (this->y_gap == 56) {
                            this->y_gap = -8;
                        }
                    }
                } else if (n == 49 && this->h_mo < 3) {
                    this->h_idx = 0;
                    this->mo_stop = 1;
                    this->h_mo = 8;
                    this->h_dir = 12;
                } else if (n == 51 && this->h_mo < 3) {
                    this->h_idx = 0;
                    this->mo_stop = 1;
                    this->h_mo = 6;
                    this->h_dir = 14;
                } else if (n == -2 || n == 56) {
                    if (this->h_dir > -1 && this->h_dir < 30 && this->h_dir != 10 && this->h_dir != 20) {
                        if (this->check_map(this->h_x, this->h_y, 8) == 52 && this->h_x % 3 != 0 && this->h_y != 5 && this->h_dir != 6) {
                            if (this->h_dir != 6) {
                                this->h_dir = 8;
                                this->h_mo = 10;
                                this->sadari = 2;
                            }
                        } else if (this->h_mo == 12) {
                            this->h_mo = this->tmp_mo;
                            this->mo_stop = 0;
                            this->msg = nullptr;
                            this->y_gap = 0;
                        } else if (this->h_dir == 6 && this->auto_move == 0) {
                            this->h_dir = 8;
                            this->h_mo = 10;
                            this->sadari = 2;
                            this->h_y -= 2;
                            if (this->y_gap == 0) {
                                this->h_y += 2;
                                if (!this->ing_ss) {
                                    this->h_mo = 0;
                                    this->h_dir = 0;
                                }
                            } else if (this->y_gap == -8) {
                                this->y_gap = 56;
                            } else if (this->y_gap == -16) {
                                this->y_gap = 48;
                            } else if (this->y_gap == -24) {
                                this->y_gap = 40;
                            } else if (this->y_gap == -32) {
                                this->y_gap = 32;
                            } else if (this->y_gap == -40) {
                                this->y_gap = 24;
                            } else if (this->y_gap == -48) {
                                this->y_gap = 16;
                            } else if (this->y_gap == -56) {
                                this->y_gap = 8;
                            }
                        } else if (this->h_dir < 5) {
                            this->h_dir = 0;
                        }
                    } else if (this->h_dir > 30) {
                        this->h_dir = 8;
                        this->mo_stop = 0;
                        this->y_gap = -this->y_gap;
                    }
                } else if (!(this->key_pp || n != -3 && n != 52)) {
                    if (this->h_mo < 6) {
                        this->h_dir = 2;
                        this->h_mo = 2;
                    } else if (this->h_mo == 8 || this->h_mo == 9 || this->h_mo == 6 || this->h_mo == 7) {
                        this->tmp_move = -1;
                    }
                } else if (!(this->key_pp || n != -4 && n != 54)) {
                    if (this->h_mo < 6) {
                        this->h_dir = 4;
                        this->h_mo = 0;
                    } else if (this->h_mo == 6 || this->h_mo == 7 || this->h_mo == 8 || this->h_mo == 9) {
                        this->tmp_move = 1;
                    }
                } else if ((n == -5 || n == 53) && this->h_dir != 6 && this->h_dir != 8) {
                    if (this->att_d != 0) {
                        return;
                    }
                    if (this->h_dir > -1 && (this->god == 0 || this->god > 200)) {
                        this->h_idx = 0;
                        if (this->h_dir < 10 && this->w_dir == 0) {
                            this->w_x = this->h_x;
                            this->w_y = this->h_y;
                            this->mo_stop = 1;
                            if (this->h_dir < 10) {
                                this->h_dir = 0;
                            }
                            if (this->w_rng < 2) {
                                this->att_d = 1;
                            }
                            if (this->h_mo == 0) {
                                this->h_mo = 4;
                                this->w_dir = 1;
                                this->MPlay(2);
                            } else if (this->h_mo == 2) {
                                this->h_mo = 5;
                                this->w_dir = -1;
                                this->MPlay(2);
                            }
                        } else if (this->w_dir == 0) {
                            if (this->h_mo == 8 || this->h_mo == 9) {
                                this->h_mo = 13;
                                this->MPlay(2);
                            } else if (this->h_mo == 6 || this->h_mo == 7) {
                                this->h_mo = 14;
                                this->MPlay(2);
                            }
                            this->mo_stop = 1;
                        }
                    }
                    if (this->h_mo == 12 && this->msg == String("shop")) {
                        this->msg = nullptr;
                        this->screen = 50;
                    }
                } else if (this->special == 0 && n == 48 && this->y_gap == 0 && this->h_dir != 6 && this->h_dir != 8 && this->h_dir < 12) {
                    this->special = this->mp / 33;
                    if (this->special > 0) {
                        this->w_y2 = -10;
                        this->w_y1 = -6;
                        this->h_idx = 1;
                        this->h_dir = 0;
                        try {
                            if (this->special < 3) {
                                this->imgFF = Image::createImage((String)(String("/fff") + (this->special - 1) + String(".png")));
                                this->god = 100;
                            } else if (this->special == 3) {
                                this->imgFF = Image::createImage((String)String("/fff1.png"));
                                this->god = 200;
                            }
                        }
                        catch (const std::exception&) {
                            
                        }
                        this->mp -= this->special * 33;
                        if (this->mp < 0) {
                            this->mp = 0;
                        }
                        this->draw_stat();
                        this->MPlay(6);
                    }
                } else if (n == -7) {
                    this->load_img(400);
                    this->m_mode = 1;
                    this->game_on = false;
                    this->ani_step = -1;
                    this->p_mode = 100;
                    this->screen = 100;
                    this->repaint();
                } else if (n == -6) {
                    this->game_on = false;
                    this->state = 20;
                    this->gg.setColor(0);
                    this->gg.fillRect(0, 293, 240, 30);
                    this->draw_img(String("m_resume"), this->btn_r_x, this->btn_y, 24);
                    this->draw_img(String("pause"), 120, 200, 3);
                    this->repaint();
                } else if (!(n != 55 && n != 57 || this->h_mo >= 3 && this->h_mo != 10 && this->h_mo != 12)) {
                    int n3 = 0;
                    if (n == 55) {
                        if (this->h_hp == this->h_max_hp) {
                            return;
                        }
                        n3 = 0;
                    } else if (n == 57) {
                        if (this->mp == this->max_mp) {
                            return;
                        }
                        n3 = 1;
                    }
                    if (this->pt[n3] > 0) {
                        try {
                            this->imgFF = Image::createImage((String)(String("/fff") + n3 + String(".png")));
                        }
                        catch (const std::exception&) {
                            
                        }
                        this->special = 0;
                        this->god = 107;
                        this->w_y2 = -10;
                        this->w_y1 = -6;
                        int n4 = n3;
                        this->pt[n4] = this->pt[n4] - 1;
                        if (n3 == 0) {
                            this->h_hp += this->h_max_hp / 3;
                            if (this->h_hp > this->h_max_hp) {
                                this->h_hp = this->h_max_hp;
                            }
                        } else {
                            this->mp += this->max_mp / 3;
                            if (this->mp > this->max_mp) {
                                this->mp = this->max_mp;
                            }
                        }
                        this->draw_pt();
                        this->draw_stat();
                        this->MPlay(5);
                    }
                }
            } else if (this->state == 20) {
                if (n == -7) {
                    this->state = 1;
                    this->gg.fillRect(0, 293, 240, 30);
                    this->gg.drawImage(this->imgPause, 5, this->btn_y, 20);
                    this->gg.drawImage(this->imgOp, this->btn_r_x, this->btn_y, 24);
                    this->game_on = true;
                    
                }
            } else if (this->state == 10 && this->ani_step > 1) {
                this->state = 1;
                this->game_on = true;
            }
            if (this->state == -100) {
                return;
            }
        } else if (this->screen == 2) {
            if (this->ani_step > 1) {
                if (n == -6) {
                    if (this->menu_mode == 1) {
                        this->imgLL = nullptr;
                        
                        try {
                            this->imgLL = Image::createImage((String)String("/mm.png"));
                        }
                        catch (const std::exception&) {
                            
                        }
                        this->menu_mode = 0;
                    } else {
                        this->m_mode = 0;
                        this->screen = 311;
                        this->game_on = true;
                        return;
                    }
                }
                if (n == -1) {
                    if (this->m_mode < 1) {
                        if (this->menu_mode == 0) {
                            this->m_mode = 4;
                        } else if (this->menu_mode == 1) {
                            this->m_mode = 1;
                        }
                    } else {
                        --this->m_mode;
                    }
                }
                if (n == -2) {
                    if (this->menu_mode == 0) {
                        this->m_mode = this->m_mode > 3 ? 0 : ++this->m_mode;
                    } else if (this->menu_mode == 1) {
                        this->m_mode = this->m_mode == 1 ? 0 : 1;
                    }
                }
                if (this->menu_mode == 1) {
                    if (n == -5 || n == -7 || n > 48 && n < 51) {
                        if (n > 48) {
                            this->m_mode = n - 49;
                        }
                        if (this->m_mode == 0) {
                            this->screen = 311;
                            this->game_on = true;
                            return;
                        }
                        if (this->m_mode == 1) {
                            this->printStage(String("a"), 0);
                            this->printStage(String("b"), 1);
                            this->printStage(String("c"), 2);
                            this->del_img(2);
                            if (this->stage == 1 && this->chap == 0) {
                                this->m_mode = 0;
                            }
                            this->screen = 311;
                            this->game_on = true;
                            return;
                        }
                    }
                } else if (this->menu_mode == 0 && (n == -5 || n == -7 || n > 48 && n < 54)) {
                    if (n > 48) {
                        this->m_mode = n - 49;
                    }
                    if (this->m_mode == 0) {
                        this->screen = 311;
                        this->game_on = true;
                        return;
                    }
                    if (this->m_mode == 1) {
                        this->printStage(String("a"), 0);
                        this->printStage(String("b"), 1);
                        this->printStage(String("c"), 2);
                        if (this->stage == 1 && this->chap == 0) {
                            this->m_mode = 0;
                        }
                        this->screen = 311;
                        this->game_on = true;
                        return;
                    }
                    if (this->m_mode == 4) {
                        this->DF.destroyApp(true);
                        this->DF.notifyDestroyed();
                        return;
                    }
                    if (this->m_mode > 1 && this->m_mode < 4) {
                        this->ani_step = -1;
                        this->p_mode = 0;
                        this->b_step = 0;
                        this->load_img(-this->m_mode);
                        this->screen = -this->m_mode;
                    }
                }
                this->repaint();
            }
        } else if (this->screen == 51) {
            if (n == -1 || n == 50) {
                this->m_mode = this->m_mode == 0 ? 2 : --this->m_mode;
            }
            if (n == -2 || n == 56) {
                this->m_mode = this->m_mode == 2 ? 0 : ++this->m_mode;
            }
            if (n == -3 || n == 52) {
                this->ani_step = this->ani_step == 0 ? 4 : --this->ani_step;
            }
            if (n == -4 || n == 54) {
                this->ani_step = this->ani_step == 4 ? 0 : ++this->ani_step;
            }
            if (n == -5 || n == -7 || n == 53) {
                if (this->m_mode == 1) {
                    if (this->ani_step == 0) {
                        this->msg = String("p3r2");
                    }
                    if (this->ani_step == 1) {
                        this->msg = String("p5r3");
                    }
                    if (this->ani_step == 2) {
                        this->msg = String("p7r4");
                    }
                    if (this->ani_step == 3) {
                        this->msg = String("Heal");
                    }
                    if (this->ani_step == 4) {
                        this->msg = String("Mana");
                    }
                }
                if (this->m_mode == 0) {
                    int n5 = 0;
                    if (this->gold >= this->item_p[this->ani_step]) {
                        if (this->ani_step > 2) {
                            if (this->pt[this->ani_step - 3] < 9) {
                                int n6 = this->ani_step - 3;
                                this->pt[n6] = this->pt[n6] + 1;
                                this->msg = this->ani_step == 3 ? String("ppp") : String("ppp");
                            } else {
                                n5 = -1;
                                this->msg = this->ani_step == 3 ? String("hfull") : String("mfull");
                            }
                        } else {
                            if (this->ani_step == 0) {
                                if (this->w_rng < 2) {
                                    this->msg = String("ppp");
                                    this->w_rng = 2;
                                } else if (this->w_rng == 2) {
                                    this->msg = String("aaaa");
                                    n5 = -1;
                                } else {
                                    this->msg = String("bbbb");
                                    n5 = -1;
                                }
                            }
                            if (this->ani_step == 1) {
                                if (this->w_rng < 3) {
                                    this->msg = String("ppp");
                                    this->w_rng = 3;
                                } else if (this->w_rng == 3) {
                                    this->msg = String("aaaa");
                                    n5 = -1;
                                } else {
                                    this->msg = String("bbbb");
                                    n5 = -1;
                                }
                            }
                            if (this->ani_step == 2) {
                                if (this->w_rng < 4) {
                                    this->msg = String("ppp");
                                    this->w_rng = 4;
                                } else if (this->w_rng == 4) {
                                    this->msg = String("aaaa");
                                    n5 = -1;
                                } else {
                                    this->msg = String("bbbb");
                                    n5 = -1;
                                }
                            }
                            this->w_dem = (this->w_rng - 1) * 5 + 5;
                            this->load_img(100);
                        }
                        if (n5 != -1) {
                            this->gold -= this->item_p[this->ani_step];
                        }
                    } else {
                        this->msg = String("not");
                    }
                }
                if (this->m_mode == 2) {
                    this->del_img(50);
                    this->load_img(11);
                    this->gg.setColor(0);
                    this->gg.fillRect(0, 150, 128, 11);
                    this->gg.drawImage(this->imgOp, this->btn_r_x, this->btn_y, 24);
                    this->gg.drawImage(this->imgPause, 5, this->btn_y, 20);
                    this->screen = 10;
                    this->game_on = true;
                }
            }
            this->repaint();
        } else if (this->screen == 100) {
            if (n == -1) {
                this->m_mode = this->m_mode == 1 ? 5 : --this->m_mode;
            }
            if (n == -2) {
                this->m_mode = this->m_mode == 5 ? 1 : ++this->m_mode;
            }
            if (this->m_mode == 3) {
                if (n == -3) {
                    this->vol = 1;
                    this->MPlay(5);
                }
                if (n == -4) {
                    this->vol = 0;
                }
            }
            if (n == -7 || n == -5 || n > 48 && n < 54) {
                if (n > 48) {
                    this->m_mode = n - 48;
                }
                if (this->m_mode == 4) {
                    this->del_img(400);
                    this->goto_menu();
                    return;
                }
                if (this->m_mode == 5) {
                    this->DF.destroyApp(true);
                    this->DF.notifyDestroyed();
                    return;
                }
                if (this->m_mode == 1) {
                    this->del_img(400);
                    this->screen = 10;
                    this->game_on = true;
                    
                }
                if (this->m_mode == 2) {
                    this->del_img(400);
                    this->ani_step = -1;
                    this->b_step = 0;
                    this->screen = -2;
                }
            }
            if (n == -8) {
                this->screen = 10;
                this->game_on = true;
                
            }
            this->repaint();
        } else if (this->screen == 77) {
            if (n == -5 || n == 53) {
                if (this->m_mode < this->ani_step - 1) {
                    ++this->m_mode;
                    this->repaint();
                } else {
                    this->gg.setColor(0);
                    this->gg.fillRect(0, 293, 240, 30);
                    this->gg.drawImage(this->imgOp, this->btn_r_x, this->btn_y, 24);
                    this->gg.drawImage(this->imgPause, 5, this->btn_y, 20);
                    if (this->sn_m[3] == 1) {
                        this->sn_m[3] = 2;
                        this->sn_m[0] = 2;
                        this->sn_m[1] = 7;
                        this->sn_m[2] = 3;
                    } else {
                        this->sn_m[3] = 0;
                    }
                    this->strSN = nullptr;
                    this->screen = 10;
                    this->game_on = true;
                    
                }
            } else if (n == -7) {
                this->gg.setColor(0);
                this->gg.fillRect(0, 293, 240, 30);
                this->gg.drawImage(this->imgOp, this->btn_r_x, this->btn_y, 24);
                this->gg.drawImage(this->imgPause, 5, this->btn_y, 20);
                if (this->sn_m[3] == 1) {
                    this->sn_m[3] = 2;
                    this->sn_m[0] = 2;
                    this->sn_m[1] = 7;
                    this->sn_m[2] = 3;
                } else {
                    this->sn_m[3] = 0;
                }
                this->strSN = nullptr;
                this->screen = 10;
                this->game_on = true;
                
                if (this->h_dir == 2 || this->h_dir == 4) {
                    this->h_dir = 0;
                }
                this->key_pp = false;
            }
        } else if (this->screen < 0) {
            if (n == -8 || n == -7) {
                this->del_img(-100);
                if (this->screen == -3) {
                    this->addStage(String("d"), 3);
                }
                if (this->p_mode != 100) {
                    this->screen = 2;
                    this->ani_step = 5;
                } else {
                    this->screen = 10;
                }
                this->game_on = true;
                return;
            }
            if (this->screen == -3) {
                if (n == -1) {
                    this->p_mode = this->p_mode <= 0 || this->p_mode > 5 ? 5 : this->p_mode-1;
                } else if (n == -2) {
                    this->p_mode = this->p_mode >= 5 ? 0 : this->p_mode+1;
                }
                if (this->p_mode == 0) {
                    if (n == -3) {
                        this->vol = 1;
                        this->MPlay(5);
                    }
                    if (n == -4) {
                        this->vol = 0;
                    }
                }
                if (this->p_mode == 1) {
                    if (n == -3) {
                        this->vib = 1;
                        this->call_vib(1000);
                    }
                    if (n == -4) {
                        this->vib = 0;
                    }
                }
                if(this->p_mode>=3&&this->p_mode<=5&&(n==-3||n==-4))change_presentation_setting(this->p_mode,n==-3?-1:1);
                if(this->p_mode==1&&n==-4&&controller)SDL_GameControllerRumble(controller,0,0,0);
                if (this->p_mode == 2) {
                    if (n == -3 && this->h_speed != 1) {
                        --this->h_speed;
                    }
                    if (n == -4 && this->h_speed != 5) {
                        ++this->h_speed;
                    }
                }
            }
            if (this->screen == -2) {
                if (n == -3) {
                    this->b_step = this->b_step == 0 ? 4 : --this->b_step;
                }
                if (n == -4) {
                    this->b_step = this->b_step == 4 ? 0 : ++this->b_step;
                }
            }
            this->repaint();
        } else if (this->screen == 0) {
            if (this->ani_step > 0) {
                this->load_img(1);
                this->screen = 1;
                this->MPlay(0);
            }
        } else if (this->screen == 200) {
            if (n == -7) {
                this->ani_step = 117;
            }
        } else if (this->screen == 1) {
            if (this->ani_step > 7) {
                this->imgE = nullptr;
                this->imgAw = nullptr;
                this->imgPT = nullptr;
                this->screen = 123;
                this->ani_step = 0;
                
            }
        } else if (this->screen == 123 && this->ani_step > 1 && (n == -6 || n == -7)) {
            if (n == -7) {
                this->menu_mode = 0;
            } else if (n == -6) {
                this->menu_mode = 1;
            }
            this->imgWel = nullptr;
            this->load_img(2);
            this->screen = 2;
            this->m_mode = 0;
            
        }
    }

    void MPlay(int n) {
        if(vol>0) play_midi(n);
    }

    void call_vib(int n) {
        if(vib==1) rumble(std::min(n,90));
    }

    void showshow(int n) {
        if (n == 0) {
            this->game_on = this->t_game_on;
            if (this->screen == 10) {
                this->p_mode = 100;
            }
        } else {
            this->t_game_on = this->game_on;
            this->game_on = false;
            if (this->audioClip != nullptr) {
                this->audioClip.stop();
            }
        }
    }

    void showNotify() {
        this->game_on = this->t_game_on;
        if (this->screen == 10) {
            this->p_mode = 100;
        }
    }
};
