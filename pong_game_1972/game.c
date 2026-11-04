#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_events.h>

static int DISPLACEMNT_FACTOR = 20;

void move_player(SDL_Surface *surface ,SDL_Rect *player, int displacement) {
    SDL_FillRect(surface, player, 0x00000000);
    player->y += displacement;
    SDL_FillRect(surface, player, 0xffffffff);
}

int main() {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("PONG GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    SDL_Rect player1 = (SDL_Rect){20,40,40,200};
    SDL_Rect player2 = (SDL_Rect){830,360,40,200};
    SDL_FillRect(surface, &player1, 0xffffffff);
    SDL_FillRect(surface, &player2, 0xffffffff);

    SDL_Event event;
    int online = 1;
    while(online) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) {
            online = 0;
        }

        // NOT good way to track keypresses ----

        // if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_w) {
        //     move_player(surface, &player1, -DISPLACEMNT_FACTOR);
        // }
        // if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s) {
        //     move_player(surface, &player1, +DISPLACEMNT_FACTOR);
        // }



        // BETTER way to track keypresses----------

        const Uint8* state = SDL_GetKeyboardState(NULL);

        //      ----- player 1   -----
        if (state[SDL_SCANCODE_W]) {
            move_player(surface, &player1, -DISPLACEMNT_FACTOR);
        }
        if (state[SDL_SCANCODE_S]) {
            move_player(surface, &player1, +DISPLACEMNT_FACTOR);
        }

        //      ----- player 2   -----
        if (state[SDL_SCANCODE_I]) {
            move_player(surface, &player2, -DISPLACEMNT_FACTOR);
        }
        if (state[SDL_SCANCODE_K]) {
            move_player(surface, &player2, +DISPLACEMNT_FACTOR);
        }
        
        
         
        SDL_UpdateWindowSurface(window);
        SDL_Delay(15);
    }
}