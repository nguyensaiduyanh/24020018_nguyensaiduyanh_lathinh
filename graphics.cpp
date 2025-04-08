#include <SDL_image.h>
#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "graphics.h"
#include <SDL_mixer.h>

void Graphics::logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

SDL_Window* Graphics::initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        logErrorAndExit( "SDL_image error:", IMG_GetError());

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",Mix_GetError() );
    }
    return window;
}

SDL_Renderer* Graphics::createRenderer(SDL_Window* window,const int winwi, const int winhei,const char* wintitle)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, winwi, winhei);

    return renderer;
}

void Graphics::quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    IMG_Quit();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void Graphics::renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

SDL_Texture *Graphics::loadTexture(const char *filename, SDL_Renderer* renderer)
{
	//SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
	SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
	if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

	return texture;
}

Mix_Music *Graphics::loadMusic(const char* path){
    Mix_Music *gMusic = Mix_LoadMUS(path);
    if (gMusic == nullptr) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"Could not load music! SDL_mixer Error: %s", Mix_GetError());
    }
return gMusic;
}

void Graphics::playm(Mix_Music *gMusic){
    if (gMusic == nullptr) {return;}
        if (Mix_PlayingMusic() == 0) {

            Mix_PlayMusic( gMusic, -1 );

        }else if( Mix_PausedMusic() == 1 ){

        Mix_ResumeMusic();
 }
 }

Mix_Chunk* Graphics::loadSound(const char* path) {
    Mix_Chunk* gameChunk = Mix_LoadWAV(path);
    if (gameChunk == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR,"Could not load sound! SDL_mixer Error: %s", Mix_GetError());
    }
    return gameChunk;
 }
 void Graphics::plays(Mix_Chunk* gameChunk) {
    if (gameChunk != nullptr) {
        Mix_PlayChannel( -1, gameChunk, 0 );
    }
}





