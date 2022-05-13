#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>
#include <string>
#include <State.h>
#include <Music.h>
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

class State {

    private:
        Sprite bg;
        Music music;
        bool quitRequested;

    public:

        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

};

#endif