#include<stdlib.h>
#include<SDL2/SDL.h>
#include<stdio.h>

void print_random_data(SDL_Surface *surface) {
    // int bytes_per_pixel = surface->format->BytesPerPixel;
    // printf("Bytes per pixel %d ", bytes_per_pixel);   // it's 4

    
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Noisy TV", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    print_random_data(surface);
    SDL_Delay(10000);
}