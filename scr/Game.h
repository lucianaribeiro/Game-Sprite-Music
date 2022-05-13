#ifndef GAME_H
#define GAME_H

#include "SDL_include.h"
#include "State.h"
#include <string>

#define INCLUDE_SDL

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