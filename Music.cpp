#include "Music.h"

Music::Music(){
	music = nullptr;
}

Music::Music(string file){
	Open(file);
}

void Music::Play(int times){
	Mix_PlayMusic(music, times);
}

void Music::Open(string file){
	if ( Mix_LoadMUS(file.c_str()) == nullptr ){
		SDL_Log("Load Music failed: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
	}
}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic(msToStop);
}

bool Music::IsOpen(){
	return music != nullptr;
}

Music::~Music(){
	Stop();
	Mix_FreeMusic(music);
}