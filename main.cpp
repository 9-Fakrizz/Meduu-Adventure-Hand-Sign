#include<iostream>
#include<SDL2/SDL.h>


const int WIDTH = 1600,HEIGH = 1024;
using namespace std;
int main(int argc,char *argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Meduu Adventure",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGH,SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL == window){
        cout<<"Could not create window: "<<SDL_GetError() <<endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,0);

    SDL_SetRenderDrawColor(renderer,255,255,0,255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_Event event;

    while(true){
        if(SDL_PollEvent( &event)){
            if(SDL_QUIT == event.type){
                break;
            }

            if(SDL_MOUSEMOTION == event.type){
                int x,y;
                SDL_GetMouseState(&x,&y);
                cout<<x<<" : "<<y<<endl;
            }

            if(SDL_MOUSEBUTTONDOWN == event.type){
                if(SDL_BUTTON_LEFT == event.button.button){
                    cout<<"Left click!"<<endl;
                }
                if(SDL_BUTTON_RIGHT == event.button.button){
                    cout<<"Right click!"<<endl;
                }
                if(SDL_BUTTON_MIDDLE == event.button.button){
                    cout<<"Middle click!"<<endl;
                }
            }

            if(SDL_MOUSEBUTTONUP == event.type){
                if(SDL_BUTTON_LEFT == event.button.button){
                    cout<<"Left unclick!"<<endl;
                }
                if(SDL_BUTTON_RIGHT == event.button.button){
                    cout<<"Right unclick!"<<endl;
                }
                if(SDL_BUTTON_MIDDLE == event.button.button){
                    cout<<"Middle unclick!"<<endl;
                }
            }

            if(SDL_MOUSEWHEEL == event.type){
                if(event.wheel.y > 0){
                    cout<<"scroll up"<<endl;
                }
               else if(event.wheel.y < 0){
                    cout<<"scroll down"<<endl;
                }

                if(event.wheel.x > 0){
                    cout<<"scroll right"<<endl;
                }
               else if(event.wheel.x < 0){
                    cout<<"scroll left"<<endl;
                }
            }

            if(SDL_KEYDOWN == event.type){
                if(SDLK_a == event.key.keysym.sym){
                    cout<<"A is down - move left"<<endl;
                }
                else if(SDLK_s == event.key.keysym.sym){
                    cout<<"S is down - move down"<<endl;
                }
                else if(SDLK_d == event.key.keysym.sym){
                    cout<<"D is down - move right"<<endl;
                }
                else if(SDLK_w == event.key.keysym.sym){
                    cout<<"W is down - move up"<<endl;
                }
            }
            else if (SDL_KEYUP == event.type){
                if(SDLK_a == event.key.keysym.sym){
                    cout<<"A is up - stop moving left"<<endl;
                }
                else if(SDLK_s == event.key.keysym.sym){
                    cout<<"S is up - stop moving down"<<endl;
                }
                else if(SDLK_d == event.key.keysym.sym){
                    cout<<"D is up - stop moving right"<<endl;
                }
                else if(SDLK_w == event.key.keysym.sym){
                    cout<<"W is up - stop moving up"<<endl;
                }
            }
            
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}