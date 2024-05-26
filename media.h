#pragma once

#include "SDL_mixer.h"
#include <iostream>

Mix_Music* music = NULL;
bool startmixer() {
	bool success = true;
	Mix_Init(MIX_INIT_MP3);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cout << "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError();
		success = false;
	}

	music = Mix_LoadMUS("media/bemyguest.mp3");
	if (music == NULL) {
		std::cout << "couldn't load mp3";
		success = false;
	}
	return success;
}

void close() {
	Mix_FreeMusic(music);
	music = NULL;

	Mix_Quit();
}