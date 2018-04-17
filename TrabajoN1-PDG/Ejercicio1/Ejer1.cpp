#include "SDL.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
	//Variables
	bool quit = false;
	SDL_Event event;
	int x = 180;
	int y = 90;

	// Inicializar SDL2
	SDL_Init(SDL_INIT_VIDEO);              
	SDL_Window *window = SDL_CreateWindow("Window SDL2",SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = SDL_LoadBMP("tiger.bmp");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Manejar eventos

	while (!quit) {
		SDL_WaitEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
			case SDLK_LEFT: x--; break;
			case SDLK_RIGHT: x++; break;
			case SDLK_UP: y--; break;
			case SDLK_DOWN: y++; break;
			}
			break;
		}
		SDL_Rect dstrect = { x,y,300,300 };
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderPresent(renderer);
	}

	//Limpiar SDL2
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}