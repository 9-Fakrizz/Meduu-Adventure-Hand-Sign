#include "window.h"
#include "rect.h"
#include "text.h"
#include "function.h"
#include <ctime>


string SSK = "life drain";


void pollEvents(Window& window, Rect& rect) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		rect.pollEvents(event);
		window.pollEvents(event);
	}
}

int main(int argc, char** argv) {
	srand(time(0));
	string name;
	char eq;
	int turn_count = 1;
	char player_action = '\0', monster_action = '\0';
	int p = 0, m = 0;


	Unit hero("Hero", "player");
	Unit mons("Monster", "enemy");


	Equipment buff1(2, 2, 4);
	Equipment buff2(4, 4, 8);
	Equipment buff3(8, 8, 16);
	Equipment buff4(16, 16, 32);

	Window window("Meduu Adventure", 1600, 1024);
	Rect Menu(1600, 1024, 0, 0, "res/Menu.jpg");
	Rect Start(1600, 1024, 0, 0, "res/Start.png");
	Rect Board(1600, 1024, 0, 0, "res/Board.png");
	Rect Player(400*3, 256*3, 0, 250, "res/Player.png");
	Rect scene01(1600, 1024, 0, 0, "res/Forest_Scene.png");
	Rect Slime(400*5, 256*5, 150, 0, "res/Blue_Slime.png");
	Rect Box(400, 100, 1200, 0,190,190,190,255);
	Rect Box2(400, 200, 400, 900, 190, 190, 190, 255);
	
	Text TextStart(Window::renderer,"res/ShortBaby.ttf",50,"Moving to first stage...",{0,0,0,255});
	Text PressAny(Window::renderer, "res/ShortBaby.ttf", 50, "Press any button", { 0,0,0,255 });
	Text MonName01(Window::renderer, "res/Fast.ttf", 50, "Slime:", { 0,0,0,255 });
	Text PlayerName(Window::renderer, "res/Fast.ttf", 50, "Player:", { 0,0,0,255 });

	SDL_Event event;
	int frame = 0, action = 0,num = 0;
	while (!window.isClosed()) {
		
		while (SDL_PollEvent(&event)) {
			pollEvents(window, Menu);
			int x, y;
			SDL_GetMouseState(&x, &y);
			
			
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
				Box.draw();
				Box2.draw();
				MonName01.display(1200, 25, Window::renderer);
				PlayerName.display(400, 925, Window::renderer);
				/*while (true) {
					
					cout << " [1] buff1 \n [2] buff2 \n [3] buff3 \n [4] buff4 \n";
					cout << "Please selet your buff: ";
					cin >> eq;
					if (eq == '1') hero.equip(&buff1);
					if (eq == '2') hero.equip(&buff2);
					if (eq == '3') hero.equip(&buff3);
					if (eq == '4') hero.equip(&buff4);
					cout << "[A] Attack [H] HEAL [G] Guard [D] Dodge  [P] Change skills " << "[U] " << SSK;
					cout << "\n[Turn " << turn_count << "] Enter your action: ";
					cin >> player_action;
					player_action = toupper(player_action);
					if (player_action == 'E') break;

					int temp = rand() % 5;
					if (temp <= 1) monster_action = 'A';
					else if (temp == 2) monster_action = 'G';
					else if (temp == 3) monster_action = 'D';
					else if (temp == 4) monster_action = 'U';

					if (player_action == 'G') hero.guard();
					if (monster_action == 'G') mons.guard();

					if (player_action == 'D') hero.dodge();
					if (monster_action == 'D') mons.dodge();

					if (player_action == 'H') p = hero.heal();

					if (player_action == 'A') p = hero.attack(mons);
					if (player_action == 'L') p = hero.life_drain(mons);
					if (monster_action == 'A') m = mons.attack(hero);
					if (player_action == 'U') {
						if (SSK == "life drain") {
							p = hero.life_drain(mons);
						}
						if (SSK == "buff") {
							p = hero.buff();
						}
						if (SSK == "skill3") {
							p = hero.life_drain(mons);
						}
						if (SSK == "skill4") {
							p = hero.life_drain(mons);
						}
					}

					if (player_action == 'P') {
						char sk;
						cout << " [1]life drain \n [2] buff \n [3] skill3 \n [4] skill4 \n";
						cout << "change your skill: ";
						cin >> sk;
						if (sk == '1') {
							skill(sk);
							SSK = skill(sk);
						}
						if (sk == '2') {
							skill(sk);
							SSK = skill(sk);
						}
						if (sk == '3') {
							skill(sk);
							SSK = skill(sk);
						}
						if (sk == '4') {
							skill(sk);
							SSK = skill(sk);
						}
					}

					if (hero.isDead()) {
						break;
					}

					if (mons.isDead()) {
						break;
					}
					turn_count++;
				}*/
			}

			window.clear();
			}
			
			
		}
		
		
		return 0;
	}

	
