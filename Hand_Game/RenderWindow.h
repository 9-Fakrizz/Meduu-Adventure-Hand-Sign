#pragma once
#include <SDL.h>
#include<SDL_image.h>
#include "Entity.h"
using namespace std;

class RenderWindow {
public:
	RenderWindow(const char* p_title,int p_w,int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

class RenderText {
public:
	void puttext(const char* msg, int x, int y, int r, int g, int b,int size);
private:
	SDL_Renderer* renderer;
	SDL_Window* window;
};