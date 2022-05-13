#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <State.h>
#include <string>
#include "SDL_include.h"
#include "State.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

using namespace std;


class Game {
    private:
        Game(string title, int width, int height);
        SDL_Renderer* renderer;
        static Game* instance;
        SDL_Window* window;
        State* state;

    public:
        ~Game();
        void Run();
        SDL_Renderer* GetRenderer();
        State& GetState();
        static Game& GetInstance();

};

#endif