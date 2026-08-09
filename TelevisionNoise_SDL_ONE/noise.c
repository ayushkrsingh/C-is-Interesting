#include<stdlib.h>
#include<SDL2/SDL.h>
#include<stdio.h>

void print_random_data(SDL_Surface *surface) {
    // int bytes_per_pixel = surface->format->BytesPerPixel;
    // printf("Bytes per pixel %d ", bytes_per_pixel);   // it's 4
    int num_pixel = surface->w * surface->h;
    Uint32 *pixels = (Uint32 *) surface->pixels;
    for (int i = 0; i < num_pixel; i++)
    {
        pixels[i] = (Uint32) rand();
    }
    

}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Noisy TV", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Event event;
    int online = 1;
    while(online) {       // to update continuously---- flickering  
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            online = 0;
        }
        print_random_data(surface);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
    }
}