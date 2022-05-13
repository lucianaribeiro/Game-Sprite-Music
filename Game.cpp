#include "Game.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

Game * Game::instance = nullptr;

Game & Game::GetInstance(){
    return *instance;
};

Game::Game(string title, int width, int height){

    instance = instance ? instance : this;
    
    bool sdl_init_failed = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0;
    if(sdl_init_failed) {
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int images = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if(IMG_Init(images) == 0) { 
        SDL_Log("Image failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int musics = MIX_DEFAULT_FREQUENCY | MIX_DEFAULT_FORMAT | MIX_DEFAULT_CHANNELS;
    if(MIX_Init(musics) == 0) {
        SDL_Log("Mix failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,  0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(window || renderer == nullptr) {
        SDL_Log("%s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

};
