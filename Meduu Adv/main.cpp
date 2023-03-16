#include "window.h"
#include "rect.h"
#include "text.h"

void pollEvents(Window& window, Rect& rect) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		rect.pollEvents(event);
		window.pollEvents(event);
	}
}

int main(int argc, char** argv) {
	Window window("Meduu Adventure", 1600, 1024);
	Rect Menu(1600, 1024, 0, 0, "res/Menu.jpg");
	Rect Start(1600, 1024, 0, 0, "res/Start.png");
	Rect Board(1600, 1024, 0, 0, "res/Board.png");
	Rect Player(400*3, 256*3, 0, 250, "res/Player.png");
	Rect scene01(1600, 1024, 0, 0, "res/Forest_Scene.png");
	Rect Slime(400*5, 256*5, 150, 0, "res/Blue_Slime.png");
	
	Text TextStart(Window::renderer,"res/ShortBaby.ttf",50,"Moving to first stage...",{0,0,0,255});
	Text PressAny(Window::renderer, "res/ShortBaby.ttf", 50, "Press any button", { 0,0,0,255 });
	SDL_Event event;
	int frame = 0, action = 0;
	while (!window.isClosed()) {
		
		while (SDL_PollEvent(&event)) {
			pollEvents(window, Menu);
			int x, y;
			SDL_GetMouseState(&x, &y);
			cout << x << " : " << y << endl;
			
			
			if (SDL_MOUSEBUTTONDOWN == event.type) {
				if (SDL_BUTTON_LEFT == event.button.button && x >= 537 && x <= 1063 && y >= 400 && y <= 527 && frame == 0) {
					window.clear();
					action = 1;
					frame=1;
				}
			}
			if (action == 0) {
				Menu.draw();
				Start.draw();
			}
			else if (action == 1) {
				Board.draw();
				TextStart.display(600, 400, Window::renderer);
				PressAny.display(600, 500, Window::renderer);
				if (SDL_KEYDOWN == event.type && frame ==1) {
					window.clear();
					action = 2;

				}
			}
			else if (action == 2) {
				scene01.draw();
				Player.draw();
				Slime.draw();
			}
			
			window.clear();
		}
		
		

	}

	return 0;
}