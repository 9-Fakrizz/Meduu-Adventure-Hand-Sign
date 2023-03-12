#pragma once
#include <SDL.h>
#include<SDL_image.h>
using namespace std;

class RenderWindow {
public:
	RenderWindow(const char* p_title,int p_w,int p_h);
	void cleanUp();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};