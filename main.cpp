#include "SDL.h"
#include "SDL_mixer.h"
#include <iostream>
#include "media.h"

int main(int argc, char *argv[]) {
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Window* window = SDL_CreateWindow("Test Silo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_Surface* texturee = SDL_LoadBMP("media/pepe.bmp");
		SDL_Texture* textureha = SDL_CreateTextureFromSurface(renderer, texturee);

		SDL_RenderCopy(renderer, textureha, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderClear(renderer);
		startmixer();
		Mix_PlayMusic(music, -1);
		while(true) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) { // poll until all events are handled!
				if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
					SDL_Quit();
					close();
				}
			}
		}
	return 0;
}