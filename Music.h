#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL.h>
#include <string>
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include "Game.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

using namespace std;

class Music {

    private:

        Mix_Music* music;

    public:

        Music();
        Music(string file);
        void Play(int times = -1);
        void Stop(int msToStop = 1500);
        void Open(string file);
        bool IsOpen();

};


#endif