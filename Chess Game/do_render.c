#include "main.h"

void dorender(GameState *gamestate)
{
    if(gamestate->status == STATUS_GAME)
    {
        SDL_SetRenderDrawColor(gamestate->renderer,0,0,0,255);
        SDL_RenderClear(gamestate->renderer);
        SDL_Surface *surface=NULL;
        SDL_Color cl={255,255,255,255};
        surface=TTF_RenderText_Blended(gamestate->font,gamestate->label,cl);
        gamestate->labelh=surface->h;
        gamestate->labelw=surface->w;
        gamestate->labeltex=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
        SDL_FreeSurface(surface);

        SDL_Color cl2={255,0,0,255};
        if(gamestate->check == 1)
        {
            surface=TTF_RenderText_Blended(gamestate->font,"black check",cl2);
        }
        else if(gamestate->check == 2)
        {
            surface=TTF_RenderText_Blended(gamestate->font,"white check",cl2);
        }
        else
        {
            surface=TTF_RenderText_Blended(gamestate->font,"no check",cl);
        }
        gamestate->check_labelh=surface->h;
        gamestate->check_labelw=surface->w;
        gamestate->check_labeltex=SDL_CreateTextureFromSurface(gamestate->renderer,surface);
        SDL_FreeSurface(surface);

        SDL_Rect cbrect = {0,0,800*gameSize,800*gameSize};
        SDL_RenderCopy(gamestate->renderer,gamestate->chessboard,NULL,&cbrect);

        if(gamestate->showSelection)
        {
            SDL_Rect selection_Rect = {100*gameSize*(gamestate->selected_x-1), 100*gameSize*(gamestate->selected_y-1), 100*gameSize, 100*gameSize};
            SDL_RenderDrawRect(gamestate->renderer, &selection_Rect);
        }
        SDL_SetRenderDrawColor(gamestate->renderer,255,255,255,255);
        SDL_Rect textRect={20*gameSize,820*gameSize,gamestate->labelw,gamestate->labelh};
        SDL_RenderCopy(gamestate->renderer,gamestate->labeltex,NULL,&textRect);
        SDL_Rect check_textRect={(780)*gameSize-gamestate->check_labelw,820*gameSize,gamestate->check_labelw,gamestate->check_labelh};
        SDL_RenderCopy(gamestate->renderer,gamestate->check_labeltex,NULL,&check_textRect);
        for(int i=0;gamestate->s_x[i]!=-1 && gamestate->s_y[i]!=-1;i++)
        {
            SDL_Rect s_Rect = {100*gameSize*(gamestate->s_x[i]-1), 100*gameSize*(gamestate->s_y[i]-1), 100*gameSize, 100*gameSize};
            SDL_RenderDrawRect(gamestate->renderer, &s_Rect);
        }

        for(int i=0; i<8; i++)
        {
            if(gamestate->pieces[i].live == 1)
            {
                SDL_Rect white_pawn_rect={gamestate->pieces[i].x, gamestate->pieces[i].y, 100*gameSize, 100*gameSize};
                SDL_RenderCopy(gamestate->renderer,gamestate->white_pawn,NULL,&white_pawn_rect);
            }
            if(gamestate->pieces[i+16].live == 1)
            {
                SDL_Rect black_pawn_rect={gamestate->pieces[i+16].x, gamestate->pieces[i+16].y, 100*gameSize, 100*gameSize};
                SDL_RenderCopy(gamestate->renderer,gamestate->black_pawn,NULL,&black_pawn_rect);
            }
        }
        for(int i=0; i<2; i++)
        {
            //BISHOP
            if(gamestate->pieces[i+8].live == 1)
            {
                SDL_Rect white_bishop_rect={gamestate->pieces[i+8].x,gamestate->pieces[i+8].y,100*gameSize,100*gameSize};
                SDL_RenderCopy(gamestate->renderer,gamestate->white_bishop,NULL,&white_bishop_rect);
            }
            if(gamestate->pieces[i+24].live == 1)
            {
                SDL_Rect black_bishop_rect={gamestate->pieces[i+24].x,gamestate->pieces[i+24].y,100*gameSize,100*gameSize};
                SDL_RenderCopy(gamestate->renderer,gamestate->black_bishop,NULL,&black_bishop_rect);
            }

            //KNIGHT
            if(gamestate->pieces[i+10].live == 1)
            {
                SDL_Rect white_knight_rect={gamestate->pieces[i+10].x,gamestate->pieces[i+10].y,100*gameSize,100*gameSize};
                SDL_RenderCopy(gamestate->renderer,gamestate->white_knight,NULL,&white_knight_rect);
            }
            if(gamestate->pieces[i+26].live == 1)
            {
                SDL_Rect black_knight_rect={gamestate->pieces[i+26].x,gamestate->pieces[i+26].y,100*gameSize,100*gameSize};
                SDL_RenderCopy(gamestate->renderer,gamestate->black_knight,NULL,&black_knight_rect);
            }

            //ROOK
            if(gamestate->pieces[i+12].live == 1)
            {
                SDL_Rect white_rook_rect={gamestate->pieces[i+12].x,gamestate->pieces[i+12].y,100*gameSize,100*gameSize};
                SDL_RenderCopy(gamestate->renderer,gamestate->white_rook,NULL,&white_rook_rect);
            }
            if(gamestate->pieces[i+28].live == 1)
            {
                SDL_Rect black_rook_rect={gamestate->pieces[i+28].x,gamestate->pieces[i+28].y,100*gameSize,100*gameSize};
                SDL_RenderCopy(gamestate->renderer,gamestate->black_rook,NULL,&black_rook_rect);
            }
        }

        if(gamestate->pieces[14].live == 1)
        {
            SDL_Rect white_queen_rect={gamestate->pieces[14].x,gamestate->pieces[14].y,100*gameSize,100*gameSize};
            SDL_RenderCopy(gamestate->renderer,gamestate->white_queen,NULL,&white_queen_rect);
        }
        if(gamestate->pieces[30].live == 1)
        {
            SDL_Rect black_queen_rect={gamestate->pieces[30].x,gamestate->pieces[30].y,100*gameSize,100*gameSize};
            SDL_RenderCopy(gamestate->renderer,gamestate->black_queen,NULL,&black_queen_rect);
        }
        //KING
        if(gamestate->pieces[15].live == 1)
        {
            SDL_Rect white_king_rect={gamestate->pieces[15].x,gamestate->pieces[15].y,100*gameSize,100*gameSize};
            SDL_RenderCopy(gamestate->renderer,gamestate->white_king,NULL,&white_king_rect);
        }
        if(gamestate->pieces[31].live == 1)
        {
            SDL_Rect black_king_rect={gamestate->pieces[31].x,gamestate->pieces[31].y,100*gameSize,100*gameSize};
            SDL_RenderCopy(gamestate->renderer,gamestate->black_king,NULL,&black_king_rect);
        }
        if(gamestate->move>=0)
        {
            SDL_SetRenderDrawColor(gamestate->renderer,0,0,0,255);
            SDL_Rect winRect = {800*gameSize-gamestate->move,0,800*gameSize,890*gameSize};
            gamestate->move -= 1.2*(1.718*(gamestate->cur))*gameSize;
            gamestate->cur -= 0.78374;
            if(gamestate->cur<=1)
                gamestate->cur=1;
            SDL_RenderFillRect(gamestate->renderer, &winRect);
            SDL_RenderCopy(gamestate->renderer,gamestate->menu,NULL,&winRect);
        }
    }
    if(gamestate->status == STATUS_MENU)
    {
        SDL_SetRenderDrawColor(gamestate->renderer,0,0,0,255);
        SDL_Rect winRect = {800*gameSize-gamestate->move,0,800*gameSize,890*gameSize};
        gamestate->move += 1.2*(1.718*(gamestate->cur))*gameSize;
        if(gamestate->move>800*gameSize)
        {
            gamestate->move=800*gameSize;
            gamestate->cur -= 0.78374;
        }
        SDL_RenderFillRect(gamestate->renderer, &winRect);
        SDL_RenderCopy(gamestate->renderer,gamestate->menu,NULL,&winRect);
    }
    SDL_RenderPresent(gamestate->renderer);
}
