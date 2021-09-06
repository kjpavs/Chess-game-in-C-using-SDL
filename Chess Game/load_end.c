#include "main.h"

void loadgame(GameState *gamestate)
{
    FILE *fptr;
    gamestate->time=0;
    gamestate->ptime=0;
    fptr= fopen("timer.txt","w");
    fclose(fptr);
    SDL_Surface *Surf=NULL;

    Surf = IMG_Load("img/chess_board.png");

    if(Surf==NULL)
    {
        printf("Cannot find Image");

        SDL_Quit();

        exit(1);
    }
    gamestate->chessboard = SDL_CreateTextureFromSurface(gamestate->renderer,Surf);

    SDL_FreeSurface(Surf);

    for(int i=0;i<64;i++)
    {
        gamestate->s_x[i]=-1;
        gamestate->s_y[i]=-1;

    }
    strcpy(gamestate->label," ");
    gamestate->font=TTF_OpenFont("font/Nexa_Light.otf",48*gameSize);
    if(!gamestate->font)
    {
        printf("Font file not found");
        SDL_Quit();
        exit(1);
    }
    gamestate->labeltex=NULL;
    gamestate->check_labeltex=NULL;
    gamestate->check=0;
    SDL_Surface *surface=NULL;
    SDL_Color cl={255,255,255,255};
    surface=TTF_RenderText_Blended(gamestate->font,gamestate->label,cl);
    gamestate->labelh=surface->h;
    gamestate->labelw=surface->w;
    gamestate->labeltex=SDL_CreateTextureFromSurface(gamestate->renderer,surface);

    surface=IMG_Load("img/menu.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->menu=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Pawn_White.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->white_pawn=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Pawn_Black.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->black_pawn=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Knight_White.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->white_knight=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Knight_Black.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->black_knight=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Queen_White.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->white_queen=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Queen_Black.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->black_queen=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Rook_White.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->white_rook=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);


    surface=IMG_Load("img/Rook_Black.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->black_rook=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Bishop_White.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->white_bishop=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/Bishop_Black.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->black_bishop=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/King_White.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->white_king=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    surface=IMG_Load("img/King_Black.png");
    if (surface==NULL)
    {
        printf("FATAL ERROR\n");
        SDL_Quit();
        exit(1);
    }
    gamestate->black_king=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
    SDL_FreeSurface(surface);

    gamestate->status = STATUS_MENU;
    gamestate->currentPlayerColor = 0;
    gamestate->selected_x = 1;
    gamestate->selected_y = 1;
    gamestate->showSelection = 0;
    gamestate->move = 800*gameSize;
    gamestate->cur = 24.5;


    for(int i=1; i<=8; i++)
    {
        updatePiece(gamestate, i+15, i, 7, 1, PAWN, 1);
        updatePiece(gamestate, i-1, i, 2, 1, PAWN, 0);
    }
    updatePiece(gamestate, 26, 2, 8, 1, KNIGHT, 1);
    updatePiece(gamestate, 27, 7, 8, 1, KNIGHT, 1);
    updatePiece(gamestate, 10, 2, 1, 1, KNIGHT, 0);
    updatePiece(gamestate, 11, 7, 1, 1, KNIGHT, 0);
    updatePiece(gamestate, 24, 3, 8, 1, BISHOP, 1);
    updatePiece(gamestate, 25, 6, 8, 1, BISHOP, 1);
    updatePiece(gamestate,  8, 3, 1, 1, BISHOP, 0);
    updatePiece(gamestate,  9, 6, 1, 1, BISHOP, 0);
    updatePiece(gamestate, 28, 1, 8, 1, ROOK, 1);
    updatePiece(gamestate, 29, 8, 8, 1, ROOK, 1);
    updatePiece(gamestate, 12, 1, 1, 1, ROOK, 0);
    updatePiece(gamestate, 13, 8, 1, 1, ROOK, 0);
    updatePiece(gamestate, 30, 4, 8, 1, QUEEN, 1);
    updatePiece(gamestate, 14, 4, 1, 1, QUEEN, 0);
    updatePiece(gamestate, 31, 5, 8, 1, KING, 1);
    updatePiece(gamestate, 15, 5, 1, 1, KING, 0);
}

void endgame(GameState *gamestate)
{
    SDL_DestroyTexture(gamestate->white_pawn);
    SDL_DestroyTexture(gamestate->white_knight);
    SDL_DestroyTexture(gamestate->white_queen);
    SDL_DestroyTexture(gamestate->black_pawn);
    SDL_DestroyTexture(gamestate->black_knight);
    SDL_DestroyTexture(gamestate->black_queen);
    SDL_DestroyTexture(gamestate->labeltex);
    SDL_DestroyTexture(gamestate->check_labeltex);
    SDL_DestroyTexture(gamestate->chessboard);
    SDL_DestroyTexture(gamestate->menu);
}


