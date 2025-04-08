#include <SDL_image.h>
#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <SDL_mixer.h>
#include "defs.h"
#include "graphics.h"
#include "logiv.h"
#include "logicgame.h"

using namespace std;

anh Anh;

Graphics Graphics;

string dstfile[35]={"img//1.png", "img//2.png", "img//3.png", "img//4.png", "img//5.png", "img//6.png", "img//7.png", "img//8.png", "img//9.png", "img//10.png", "img//11.png", "img//12.png", "img//13.png", "img//14.png", "img//15.png", "img//16.png", "img//17.png", "img//18.png", "img//19.png", "img//20.png",
                    "img//21.png", "img//22.png", "img//23.png", "img//24.png", "img//25.png", "img//26.png", "img//27.png", "img//28.png", "img//29.png", "img//30.png", "img//31.png", "img//32.png", "img//33.png", "img//34.png", "img//35.png"};

char** taods(char** ds){

    for(int i=0;i<35;i++){
        int co=dstfile[i].size()+1;
        ds[i]=new char[co];
        for(int o=0;o<co;o++){
            ds[i][o]=dstfile[i][o];
        }
    }
return ds;
}

anh* taobrando(anh* brando){
    for(int i=0;i<thedoc;i++){
        for(int o=0;o<thengang;o++){
            brando[thengang*i+o].stt=-1;
            brando[thengang*i+o].ngua=0;
            brando[thengang*i+o].hien=1;
        }
    }
return brando;
}

int main(int argc, char* argv[])
{
    window = Graphics.initSDL(winwi, winhei, wintitle);
    renderer = Graphics.createRenderer(window,winwi,winhei,wintitle);

    char** ds=new char*[35];
    taods(ds);
    Mix_Music *nhacnen = Graphics.loadMusic("music\\nhacnen.mp3");
    Graphics.playm(nhacnen);
    int me=Anh.taomenu(renderer, Graphics);
    if(me==-1){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "EXIT %s",IMG_GetError());
        return 0;
    }else if(me==0){
    }else{
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load menu failed %s", IMG_GetError());
        return -1;
    }

    bool thoat=0;
    while(thoat==0){
        srand(time(0));

        int tvchonlv = Anh.hienchonlv(renderer, thedoc, thengang,Graphics);
        if(tvchonlv==-1){

            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "EXIT %s",IMG_GetError());

        return 0;
        }else if(tvchonlv==0){

        }else{

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load chonlv failed %s", IMG_GetError());

        return -1;
        }

        anh* brando= new anh[thengang*thedoc];
        taobrando(brando);

        Anh.taobando(thengang, thedoc, brando);

        SDL_Texture** mh=new SDL_Texture* [thengang*thedoc];

        int trvtaogame = Anh.taogame(brando, mh, renderer, ds, thedoc, thengang,Graphics);
        if(trvtaogame==-1){

            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "EXIT %s",IMG_GetError());

        return 0;
        }else if(trvtaogame==0){

        }else{

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load game failed %s", IMG_GetError());

        return -1;
        }

        int trvendgame = Anh.endgame(renderer, Graphics);
        if(trvendgame==-1){

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "EXIT %s",IMG_GetError());

        return 0;
        }else if(trvendgame==0){

        }else{

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load game failed %s", IMG_GetError());

        return -1;
        }
    }

    Graphics.quitSDL(window, renderer);
    return 0;
}
