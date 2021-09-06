#include "main.h"

int main(int argc,char *argv[])
{
    GameState gamestate;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0) //INITIALIZES SDL
    {
        printf("error Initializing SDL : %s\n",SDL_GetError());
    }

    window = SDL_CreateWindow("Game",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              800*gameSize,
                              890*gameSize,
                              0);
                              //CREATES A DISPLAY WINDOW
    gamestate.renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    loadgame(&gamestate);

    int done=0;
    while(!done)
    {
        done=processevents(window,&gamestate);
        dorender(&gamestate);
    }

    endgame(&gamestate);

    SDL_DestroyTexture(gamestate.chessboard);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(gamestate.renderer);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
