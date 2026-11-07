#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_events.h>

static int DISPLACEMNT_FACTOR = 20;
static int VELOCITY_FACTOR_X;
static int VELOCITY_FACTOR_Y;

void move_player(SDL_Surface *surface ,SDL_Rect *player, int displacement) {
    if(player->y <= 0 && displacement < 0) return;
    if(player->y >= (surface->h - player->h) && displacement > 0) return;
    SDL_FillRect(surface, player, 0x00000000);
    player->y += displacement;
    SDL_FillRect(surface, player, 0xffffffff);
}
void move_ball(SDL_Surface *surface ,SDL_Rect *ball, int direction_x, int direction_y) {
    SDL_FillRect(surface, ball, 0x00000000);
    ball->x += direction_x*10;
    ball->y += direction_y*5;
    SDL_FillRect(surface, ball, 0xffffffff);
}

int main() {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("PONG GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1400, 900, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    SDL_Rect player1 = (SDL_Rect){20,200,40,200}; 
    SDL_Rect player2 = (SDL_Rect){1340,200,40,200};
    SDL_FillRect(surface, &player1, 0xffffffff);
    SDL_FillRect(surface, &player2, 0xffffffff);

    SDL_Rect net = (SDL_Rect){699,0,1,surface->h};
    SDL_FillRect(surface, &net, 0xffffffff);

    SDL_Rect ball = (SDL_Rect){680,420,40,40};
    SDL_FillRect(surface, &ball, 0xffffffff);

    SDL_UpdateWindowSurface(window);
    SDL_Delay(3000);

    srand(time(NULL));
    VELOCITY_FACTOR_X = (rand() % 2 == 0) ? -1 : 1;
    VELOCITY_FACTOR_Y = (rand() % 2 == 0) ? -1 : 1;


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
        if (state[SDL_SCANCODE_UP]) {
            move_player(surface, &player2, -DISPLACEMNT_FACTOR);
        }
        if (state[SDL_SCANCODE_DOWN]) {
            move_player(surface, &player2, +DISPLACEMNT_FACTOR);
        }
        if(ball.y == 0 || ball.y == surface->h-ball.h) {
            VELOCITY_FACTOR_Y = -VELOCITY_FACTOR_Y;
        }
        if(ball.x == (player1.x + player1.w) && (player1.y >= (ball.y - player1.h) && player1.y <= (ball.y + ball.h)) 
        || 
        ball.x == (surface->w - player2.w - ball.w - player1.x) && (player2.y >= (ball.y - player2.h) && player2.y <= (ball.y + ball.h))) {
            VELOCITY_FACTOR_X = -VELOCITY_FACTOR_X;
        }
        if(ball.x < (player1.x + player1.w) || ball.x > (surface->w - player2.w - ball.w - player1.x)) {
            SDL_Delay(3000);
            break;
        }
        move_ball(surface, &ball, VELOCITY_FACTOR_X, VELOCITY_FACTOR_Y);

        //   redraw blacked net pixel after ball moves --
        SDL_FillRect(surface, &net, 0xffffffff); 
        SDL_UpdateWindowSurface(window);
        SDL_Delay(14);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}