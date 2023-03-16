#pragma once
#include "window.h"


class Rect {
public:

	Rect(int w, int h, int x, int y, int r, int g, int b, int a);
	Rect(int w, int h, int x, int y, const string &image_path);
	~Rect();
	void draw() const;
	void pollEvents(SDL_Event& event);

private:

	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
	SDL_Texture* _texture = nullptr;
};