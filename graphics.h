#ifndef GRAPHICS__H_
#define GRAPHICS__H_
#include <SDL.h>
#include <SDL_mixer.h>
#include <cstring>

struct Graphics{

    void logErrorAndExit(const char* msg, const char* error);

    SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);

    SDL_Renderer* createRenderer(SDL_Window* window,const int winwi,const int winhei,const char* wintitle);

    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

    void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer);

    SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer);

    Mix_Music *loadMusic(const char* path);

    void playm(Mix_Music *gameMusic);

    Mix_Chunk* loadSound(const char* path);

    void plays(Mix_Chunk* gameChunk);

};

#endif // _GRAPHICS__H
