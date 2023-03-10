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

    SDL_Event windowEvent;

    while(true){
        if(SDL_PollEvent( &windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}