#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include"RenderWindow.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		cout << "SDL_Init failed. Error:" << SDL_GetError() << endl;
	}
	if (!(IMG_Init(IMG_INIT_PNG))) {
		cout << "IMG_Init failed. Error:" << SDL_GetError() << endl;
	}

	RenderWindow window("Meduu Adventure", 1600, 1024);

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameRunning = false;
			}
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}