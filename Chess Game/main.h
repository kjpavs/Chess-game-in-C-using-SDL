#ifndef chess_game_main_h
#define chess_game_main_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

#define gameSize 0.7f
#define STATUS_GAME 0
#define STATUS_MENU 1

enum
{
    PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING
};

typedef struct
{
    int x, y;
    int live;
    int type;
    int color;
}Piece;

typedef struct
{
    SDL_Renderer *renderer;

    TTF_Font *font;

    SDL_Texture *white_queen, *white_knight, *white_pawn, *black_queen, *black_knight, *black_pawn;
    SDL_Texture *white_king, *white_rook, *white_bishop, *black_king, *black_rook, *black_bishop;
    SDL_Texture *labeltex;
    SDL_Texture *check_labeltex;
    SDL_Texture *chessboard;
    SDL_Texture *menu;

    Piece pieces[33];

    char label[30];

    int labelh, labelw;
    int selected_x, selected_y;
    int showSelection;
    int currentPlayerColor;
    int check;
    int check_labelh, check_labelw;
    int s_x[64],s_y[64];
    int status;
    int move;
    float cur;
    int time;
    int ptime;



}GameState;
void dorender(GameState *gamestate);
void endgame(GameState *gamestate);
void loadgame(GameState *gamestate);
void updatePiece(GameState *gamestate, int i, int x, int y, int live, int type, int color);
int check_for_check(GameState *gamestate);
int get_index(GameState *gamestate, int x, int y);
int processevents(SDL_Window *window,GameState *gamestate);
int valid_move_check(GameState *gamestate, int sx, int sy, int type, int cutting, int x, int y);
void timer(GameState* gamestate);
#endif // chess_game_main_h

