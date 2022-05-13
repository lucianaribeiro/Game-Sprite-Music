#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>
#include <State.h>
#include <Music.h>
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

class Sprite {

    private:

        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;

    public:

        Sprite();
        Sprite(string file);
        ~Sprite();
        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render(int x, int y);
        int GetWidth();
        int GetHeight();
        bool IsOpen();

}; 

#endif