#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
using namespace std;
const int WIDTH = 1600, HEIGHT = 1024;
int main(int argc, char* argv[]) {
	SDL_Surface* imageSurface = NULL;
	SDL_Surface* windowSurface = NULL;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Meduu Adventure", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	windowSurface = SDL_GetWindowSurface(window);
	if (NULL == window) {
		cout << "Could not create window: " << SDL_GetError() << endl;
		return EXIT_FAILURE;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		cout << "Failed to initialise SDL_image for PNG files:" << IMG_GetError() << endl;
	}
	SDL_Event windowEvent;

	imageSurface = IMG_Load("Blue_Slime.png");

	if (NULL == imageSurface) {
		cout << "SDL could not load image! SDL Error:" << SDL_GetError() << endl;
	}

	while (true) {
		if (SDL_PollEvent(&windowEvent)) {
			if (SDL_QUIT == windowEvent.type) {
				break;
			}
		}
		SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}
	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(windowSurface);
	imageSurface = NULL;
	windowSurface = NULL;
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}