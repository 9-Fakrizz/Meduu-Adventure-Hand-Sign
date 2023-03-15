#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "RenderWindow.h"
#include "Entity.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		cout << "SDL_Init failed. Error:" << SDL_GetError() << endl;
	}
	if (!(IMG_Init(IMG_INIT_PNG))) {
		cout << "IMG_Init failed. Error:" << SDL_GetError() << endl;
	}

	RenderWindow window("Meduu Adventure", 1600, 1024);

	SDL_Texture* forest_background = window.loadTexture("res/Forest_Scene.png");
	SDL_Texture* slime = window.loadTexture("res/Blue_Slime.png");
	SDL_Texture* player_pic = window.loadTexture("res/Player.png");
	Entity scene01(0,0, forest_background);
	Entity blue_slime(250, 75,slime );
	Entity player(0,0,player_pic);
	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameRunning = false;
			}
		}
		window.clear();
		window.render(scene01);
		window.render(blue_slime);
		window.render(player);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}