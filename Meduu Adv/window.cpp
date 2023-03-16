#include "window.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<iostream>

SDL_Renderer* Window::renderer = nullptr;

Window::Window(const std::string& title, int width, int height):_title(title), _width(width), _height(height) {

	_closed = !init();
}
Window::~Window() {
	SDL_DestroyRenderer(Window::renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Failed\n";
		return false;
	}

	if (IMG_Init((IMG_INIT_PNG || IMG_INIT_JPG) != (IMG_INIT_PNG || IMG_INIT_JPG))) {
		cerr<<"Failed\n";
		return false;
	}

	if (TTF_Init() == -1) {
		cerr << "Failed\n";
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);

	if (_window == nullptr) {
		cerr << "Failed\n";
		return false;
	}

	Window::renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (Window::renderer == nullptr) {
		cerr << "Failed\n";
		return false;
	}
	return true;
}

void Window::pollEvents(SDL_Event &event) {
	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			_closed = true;
			break;
		}
		break;
	default:
		break;
	}
}

void Window::clear() const {

	SDL_RenderPresent(Window::renderer);
	SDL_SetRenderDrawColor(Window::renderer, 0, 0, 0, 255);
	SDL_RenderClear(Window::renderer);
	
}