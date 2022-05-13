#include "State.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets() {
    // TODO
}

void State::Render() {
    // TODO
}

void State::Update(float dt) {
    quitRequested = SDL_QuitRequested() == SDL_TRUE;
}

State::State() {

    quitRequested = false;
}