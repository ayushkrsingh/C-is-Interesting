#include<stdio.h>
#include<SDL2/SDL.h>
int main() {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("PONG GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Delay(5000);
}