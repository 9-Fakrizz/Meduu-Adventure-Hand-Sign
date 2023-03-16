#pragma once
#include<string>
#include<SDL.h>
#include<string>
#include<string>
#include<string>
using namespace std;

class Window {
public:

	Window(const std::string& title, int width, int height);
	~Window();

	void pollEvents(SDL_Event& event);
	void clear() const;

	inline bool isClosed() const { return _closed; }

private:
	bool init();
private:
	string _title;
	int _width = 1600;
	int _height = 1024;

	bool _closed = false;

	SDL_Window* _window = nullptr;

public:
	static SDL_Renderer* renderer;
};