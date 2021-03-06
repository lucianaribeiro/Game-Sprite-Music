#include "Game.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

Game & Game::GetInstance(){
    if (instance == nullptr) {
        instance = new Game("Luciana Ribeiro Lins de Albuquerque - 150016131", 1024, 600);
    }
    return *instance;
};

SDL_Renderer * Game::GetRenderer(){
	return renderer;
}

State & Game::GetState(){
	return *state;
}

void Game::Run(){
	while(!state->QuitRequested()){
        state->Update(10);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}


Game::Game(string title, int width, int height){

    if (instance != nullptr) {
        SDL_Log("Get instance failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE); 
    }

    instance = this;
    
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
    if(Mix_Init(musics) == 0) {
        SDL_Log("Mix failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,  0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(window == nullptr || renderer == nullptr) {
        SDL_Log("%s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

};

Game::~Game(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
    Mix_CloseAudio();
	IMG_Quit();
	SDL_Quit();
}
