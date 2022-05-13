#include "Sprite.h"

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(string file) {
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite() {
    if(texture) {
        SDL_DestroyTexture(texture);
    }
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

bool Sprite::IsOpen() {
    return texture != nullptr;
}

void Sprite::Open(string file) {

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    Sprite::~Sprite();

    if(texture == nullptr) {
        SDL_Log("Texture failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int query_texture = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    SetClip(0, 0, width, height);
    
}

void Sprite::Render(int x, int y) {
    SDL_Rect* rect;
    rect->x = x;
    rect->y = y;
    rect->w = clipRect.w;
    rect->h = clipRect.h;

    int render_copy = SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, rect);

    if(render_copy){
        SDL_Log("Render Copy failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
};