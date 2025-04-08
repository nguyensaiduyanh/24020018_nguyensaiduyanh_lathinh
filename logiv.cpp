#include <cstdlib>
#include "logiv.h"

int x=0;
int y=0;
int oso=-1;
int deml=0;
int oso1=-1;
int oso2=-1;

int anh::taomenu(SDL_Renderer* renderer, Graphics Graphics){

    Mix_Chunk* enter=Graphics.loadSound("music//enter.mp3");
    bool hienmenu=1;
    SDL_Texture* winmenu = Graphics.loadTexture("img//menu.jpg",renderer); // hien menu
    SDL_RenderCopy(renderer, winmenu, NULL,NULL);
    SDL_RenderPresent(renderer);

    SDL_Event menuevent;
    while(hienmenu==1){
        while(SDL_PollEvent(&menuevent)){
            switch(menuevent.type){
                case SDL_QUIT:{
                    SDL_Quit();
                    hienmenu=0;
                    return -1;
                break;

                }
                case SDL_MOUSEBUTTONDOWN:{
                    SDL_GetMouseState(&x,&y);
                    if(x>=(450)&&y>=(500)&&x<=(550)&&y<=600){

                        Graphics.plays(enter);

                        hienmenu=0;
                    }
                break;
                }
            }
        }
    }
    SDL_DestroyTexture(winmenu);
return 0;
}
int anh::hienchonlv(SDL_Renderer* renderer, int& thedoc,int& thengang, Graphics Graphics){

    bool chonlv=1;
    Mix_Chunk* enterlv= Graphics.loadSound("music//enter.mp3");
    SDL_Texture* winchonlv = Graphics.loadTexture("img//chonlv.jpg",renderer);           //hien chon lv
    SDL_RenderCopy(renderer, winchonlv, NULL,NULL);
    SDL_RenderPresent(renderer);

    SDL_Event eventchonlv;
    while(chonlv==1){
        while(SDL_PollEvent(&eventchonlv)){
            switch(eventchonlv.type){
                case SDL_QUIT:{
                    SDL_Quit();
                    chonlv=0;
                return -1;
                break;
                }
                case SDL_MOUSEBUTTONDOWN:{
                    SDL_GetMouseState(&x,&y);
                    if(x>=(100)&&y>=(100)&&x<=(300)&&y<=(300)){
                        thedoc=1;
                        thengang=thedoc+3;
                        Graphics.plays(enterlv);
                        chonlv=0;
                    }else if(x>=(400)&&y>=(100)&&x<=(600)&&y<=(300)){
                        thedoc=2;
                        thengang=thedoc+3;
                        Graphics.plays(enterlv);
                        chonlv=0;
                    }else if(x>=(700)&&y>=(100)&&x<=(900)&&y<=(300)){
                        thedoc=3;
                        thengang=thedoc+3;
                        Graphics.plays(enterlv);
                        chonlv=0;
                    }else if(x>=(100)&&y>=(400)&&x<=(300)&&y<=(600)){
                        thedoc=4;
                        thengang=thedoc+3;
                        Graphics.plays(enterlv);
                        chonlv=0;
                    }else if(x>=(400)&&y>=(400)&&x<=(600)&&y<=(600)){
                        thedoc=5;
                        thengang=thedoc+3;
                        Graphics.plays(enterlv);
                        chonlv=0;
                    }else if(x>=(700)&&y>=(400)&&x<=(900)&&y<=(600)){
                        thedoc=6;
                        thengang=thedoc+3;
                        Graphics.plays(enterlv);
                        chonlv=0;
                    }
                break;
                }
            }
        }
    }
    SDL_DestroyTexture(winchonlv);
return 0;
}

anh* anh::taobando(int n, int m, anh* brando){
    int size1= n*m;
    int size2= size1/2;
    int that=0;
    int* solanxh= new int[size2];
        for(int p=0;p<(n*m)/2;p++){
            solanxh[p]=0;
        }
    int* bando= new int[size1];
        for(int i=0;i<n;i++){
            for(int o=0;o<m;o++){
                bando[m*i+o]=checkxh(that,solanxh,size2);
            }
        }
            for(int i=0;i<n;i++){
            for(int o=0;o<m;o++){
                brando[m*i+o].stt=bando[m*i+o];
                }
            }
    delete []solanxh;
    solanxh=nullptr;
    delete []bando;
    bando=nullptr;

    return brando;
}

int anh::checkxh(int that, int* solanxh,int size2){

    bool chay=1;

    while(chay==1){

    int thu=rand() % size2+1;
        if(solanxh[thu-1]<2){
            that=thu;
            solanxh[thu-1]++;chay=0;
        }
    }
    return that;
}
SDL_Texture* background= nullptr;

SDL_Texture* anh::taobackgr(Graphics Graphics, SDL_Renderer* renderer,SDL_Texture* background){

        background = Graphics.loadTexture("img//backgr.jpg", renderer);
        SDL_RenderCopy( renderer, background, NULL, NULL);
        SDL_RenderPresent( renderer );

return background;
}

int anh::taothe(anh* brando,SDL_Texture** mh,char** ds,int&thedoc, int& thengang,SDL_Renderer* renderer,Graphics Graphics){


        for(int i=0;i<thedoc;i++){
            for(int o=0;o<thengang;o++){

                if(brando[i*thengang+o].hien==1){
                    if(brando[i*thengang+o].ngua==0){

                        mh[i*thengang+o]= Graphics.loadTexture("img//ms.png",renderer);
                    }else{

                    mh[i*thengang+o]= Graphics.loadTexture(ds[brando[i*thengang+o].stt-1],renderer);
                    }

                    Graphics.renderTexture(mh[i*thengang+o],(1000-thengang*100)/2+o*100,(700-thedoc*100)/2+i*100,renderer);
                    SDL_RenderPresent( renderer );}
            }
        }
return 0;
}
int anh::chuyentd(int &thedoc, int &thengang){
    int x_ch,y_ch;
    x=x-(700-thedoc*100)/2;
    y=y-(1000-thengang*100)/2;

    if(x%100==0){
        x_ch=(x/100)-1;
    }else{
        x_ch=x/100;
     }
    if(y%100==0){
        y_ch=(y/100)-1;
    }else{
        y_ch=y/100;
    }
    oso=y_ch*thengang+x_ch;
return oso;
}

int anh::taogame(anh* brando, SDL_Texture ** mh, SDL_Renderer *renderer, char** ds, int & thedoc, int &thengang,Graphics Graphics){

    SDL_Event event;
    int sothelat=0;
    bool gameOver=0;
    bool choilai=1;
    Mix_Chunk* clik=Graphics.loadSound("music//clik.mp3");
    Mix_Chunk* khop=Graphics.loadSound("music//khop.mp3");
    Mix_Chunk* kokhop=Graphics.loadSound("music//kokhop.mp3");

    taobackgr(Graphics, renderer, background);
    taothe(brando,mh,ds,thedoc, thengang, renderer,Graphics);

    while(gameOver==0){
        while(SDL_PollEvent(&event)){

            switch(event.type){
                case SDL_QUIT:{

                    SDL_Quit();
                    gameOver=1;
                    return -1;

                break;
                }

                case SDL_MOUSEBUTTONDOWN:{

                    SDL_GetMouseState(&x,&y);

                    if((x>=(1000-thengang*100)/2)&&(y>=(700-thedoc*100)/2)&&(x<=(1000-(1000-thengang*100)/2))&&(y<=700-((700-thedoc*1000)/2))){
                        if(brando[chuyentd(thedoc,thengang)].ngua==0&&brando[oso].hien==1){
                            Graphics.plays(clik);
                            if(deml==0){
                                oso1=oso;
                            }else if(deml==1){
                                oso2=oso;
                            }
                                deml++;
                                brando[oso].ngua=1;

                                SDL_DestroyTexture(mh[oso]);

                                mh[oso]= Graphics.loadTexture(ds[brando[oso].stt-1],renderer);
                                Graphics.renderTexture(mh[oso],(1000-thengang*100)/2+oso%thengang*100,(700-thedoc*100)/2+oso/thengang*100,renderer);

                                SDL_RenderPresent( renderer );

                            if(deml==2){
                                    deml=0;
                                if(brando[oso1].stt==brando[oso2].stt){
                                    Graphics.plays(khop);
                                    brando[oso1].hien=0;
                                    brando[oso2].hien=0;
                                    sothelat+=2;

                                }
                                    SDL_Delay(333);

                                    brando[oso1].ngua=0;
                                    brando[oso2].ngua=0;
                                    SDL_DestroyTexture(mh[oso1]);
                                    SDL_DestroyTexture(mh[oso2]);
                                if(brando[oso1].hien==1&&brando[oso2].hien==1){
                                    Graphics.plays(kokhop);

                                    mh[oso1]= Graphics.loadTexture("img//ms.png",renderer);
                                    Graphics.renderTexture(mh[oso1],(1000-thengang*100)/2+oso1%thengang*100,(700-thedoc*100)/2+oso1/thengang*100,renderer);
                                    SDL_RenderPresent( renderer );

                                    mh[oso2]= Graphics.loadTexture("img//ms.png",renderer);
                                    Graphics.renderTexture(mh[oso2],(1000-thengang*100)/2+oso2%thengang*100,(700-thedoc*100)/2+oso2/thengang*100,renderer);
                                    SDL_RenderPresent( renderer );

                                }else if(brando[oso1].hien==0&&brando[oso2].hien==0){

                                    mh[oso1]=NULL;

                                    mh[oso2]=NULL;
                                }

                                if(sothelat==thengang*thedoc){gameOver=1;}

                            }
                        }
                    }
                break;
                }
            }
        }
    }

    SDL_DestroyTexture( background );
    background = NULL;

return 0;
}

int anh::endgame(SDL_Renderer* renderer, Graphics Graphics){
    bool choilai=1;
    Mix_Chunk* enchoilai=Graphics.loadSound("music//enter.mp3");
    SDL_Event ev_endgame;
    while(choilai==1){
        while(SDL_PollEvent(&ev_endgame)){
            SDL_Texture* end_Game = Graphics.loadTexture("img//uwin.jpg", renderer);
            SDL_RenderCopy( renderer, end_Game, NULL, NULL);
            SDL_RenderPresent( renderer );
            switch(ev_endgame.type){
                case SDL_QUIT:{
                    SDL_Quit();
                    choilai=0;
                    return -1;
                    break;
                }
                case SDL_MOUSEBUTTONDOWN:{
                    SDL_GetMouseState(&x,&y);
                    if(x>=(450)&&y>=(500)&&x<=(550)&&y<=600){
                        Graphics.plays(enchoilai);
                        choilai=0;
                        SDL_DestroyTexture( end_Game );
                        end_Game = NULL;
                    }
                break;
                }
                case SDL_KEYDOWN:{
                    if(ev_endgame.key.keysym.scancode==SDL_SCANCODE_E){
                        choilai=0;
                        SDL_DestroyTexture(end_Game);
                        end_Game=NULL;
                        SDL_Quit();
                        return -1;
                    }
                }
            }
        }

}
return 0;
}
