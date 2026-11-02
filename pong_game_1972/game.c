#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_events.h>
int main() {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("PONG GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    Uint32 color = 0xffffffff;
    SDL_Rect player1 = (SDL_Rect){20,40,40,200};
    SDL_Rect player2 = (SDL_Rect){830,360,40,200};
    SDL_FillRect(surface, &player1, color);
    SDL_FillRect(surface, &player2, color);
    SDL_Event event;
    int online = 1;
    while(online) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            online = 0;
        } else if(event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    SDL_FillRect(surface, &player1, 0x00000000);
                    player1.y -= 40;
                    SDL_FillRect(surface, &player1, color);
                    printf("KEYUPP \n");
                    break;

                case SDLK_DOWN:
                    SDL_FillRect(surface, &player1, 0x00000000);
                    player1.y += 40;
                    SDL_FillRect(surface, &player1, color);
                    printf("KEYDOWNN \n");
                    break;
            }
        }
         
        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
    }
}