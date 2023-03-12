#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include"RenderWindow.h"
using namespace std;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) 
	:window(NULL),renderer(NULL)
{
	window = SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,p_w,p_h,SDL_WINDOW_SHOWN);
	if (window == NULL) {
		cout << "Window failed. Error:" << SDL_GetError() << endl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL) {
		cout << "texture load failed. Error:" << SDL_GetError() << endl;
	}
	return texture;
}

void RenderWindow::cleanUp() {
	SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_text) {
	SDL_RenderCopy(renderer, p_text, NULL, NULL);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}