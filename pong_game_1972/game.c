#include<stdio.h>
#include<SDL2/SDL.h>
int main() {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("PONG GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);

    SDL_UpdateWindowSurface(window);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    // SDL_UpdateWindowSurface(window);
    // SDL_Delay(3000);
    SDL_Event event;
    int online = 1;
    while(online) {       // to update continuously---- flickering  
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            online = 0;
        }
        SDL_Rect rect = (SDL_Rect){10,10,90,400};
        Uint32 color = 0xffffffff;
        SDL_FillRect(surface, &rect, color);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
    }
}