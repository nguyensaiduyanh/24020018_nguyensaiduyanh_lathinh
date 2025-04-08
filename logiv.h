#ifndef LOGIV__H_
#define LOGIV__H_

#include "graphics.h"

struct anh{

    int stt;
    bool ngua;
    bool hien;

    int taomenu(SDL_Renderer* renderer, Graphics Graphics);

    int hienchonlv(SDL_Renderer* renderer, int& thedoc,int& thengang, Graphics Graphics);

    int checkxh(int that, int* solanxh,int size2);

    anh* taobando(int n, int m, anh* brando);

    int chuyentd(int &thedoc,int &thengang);

    SDL_Texture* taobackgr(Graphics Graphics, SDL_Renderer* renderer, SDL_Texture* background);

    int taothe(anh* brando,SDL_Texture** mh,char** ds,int& thedoc, int& thengang,SDL_Renderer* renderer,Graphics Graphics);

    int taogame(anh* brando, SDL_Texture ** mh, SDL_Renderer *renderer, char** ds, int& thedoc, int &thengang, Graphics Graphics);

    int endgame(SDL_Renderer* renderer, Graphics);

    };


#endif // _LOGIV__H
