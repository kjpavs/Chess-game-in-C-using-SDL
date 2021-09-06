#include "main.h"
void timer(GameState* gamestate)
{
    FILE *fptr;
    fptr=fopen("timer.txt","a");
    fprintf(fptr,"Player %d took %d secs to move \n",gamestate->currentPlayerColor+1,(gamestate->time-gamestate->ptime)/60);
    gamestate->ptime=gamestate->time;
    fclose(fptr);

}


int get_index(GameState *gamestate, int x, int y)
{
    int found = -1;
    x=(int)((x-1)*100*gameSize);
    y=(int)((y-1)*100*gameSize);
    for(int i=0;i<32;i++)
    {
        if(gamestate->pieces[i].x == x && gamestate->pieces[i].y == y)
            found = i;

    }
    return found;
}

void updatePiece(GameState *gamestate, int i, int x, int y, int live, int type, int color)
{
        gamestate->pieces[i].x = (x-1)*100*gameSize;
        gamestate->pieces[i].y = (y-1)*100*gameSize;
        gamestate->pieces[i].live = live;
        gamestate->pieces[i].type = type;
        gamestate->pieces[i].color = color;
}

int processevents(SDL_Window *window,GameState *gamestate)
{
    gamestate->time++;
    gamestate->check=check_for_check(gamestate);
    static char userip[30] = "";
    int done = 0, flag = 0;

    static int inv_move = 0;
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT: done=1;
            break;
            case SDL_WINDOWEVENT_CLOSE:
            {
                if(window==0)
                {
                    SDL_DestroyWindow(window);
                    window=NULL;
                    done=1;
                }
            }
            break;
            case SDL_KEYDOWN:
            if(gamestate->status == STATUS_MENU)
            {
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    done = 1;
                }
            }
            if(gamestate->status == STATUS_GAME)
            {
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE: gamestate->status = STATUS_MENU;
                            gamestate->currentPlayerColor = 0;
                            gamestate->selected_x = 1;
                            gamestate->selected_y = 1;
                            gamestate->showSelection = 0;
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
                            gamestate->cur = 24.5;
                            break;
                            case SDLK_q: sprintf(userip,"q");
                            break;
                            case SDLK_k: sprintf(userip,"k");
                            break;
                            case SDLK_r: sprintf(userip,"r");
                            break;
                            case SDLK_n: sprintf(userip,"n");
                            break;
                            case SDLK_a: sprintf(userip,"a");
                            break;
                            case SDLK_b: sprintf(userip,"b");
                            break;
                            case SDLK_c: sprintf(userip,"c");
                            break;
                            case SDLK_d: sprintf(userip,"d");
                            break;
                            case SDLK_e: sprintf(userip,"e");
                            break;
                            case SDLK_f: sprintf(userip,"f");
                            break;
                            case SDLK_g: sprintf(userip,"g");
                            break;
                            case SDLK_h: sprintf(userip,"h");
                            break;
                            case SDLK_x: sprintf(userip,"x");
                            break;
                            case SDLK_1: sprintf(userip,"1");
                            break;
                            case SDLK_2: sprintf(userip,"2");
                            break;
                            case SDLK_3: sprintf(userip,"3");
                            break;
                            case SDLK_4: sprintf(userip,"4");
                            break;
                            case SDLK_5: sprintf(userip,"5");
                            break;
                            case SDLK_6: sprintf(userip,"6");
                            break;
                            case SDLK_7: sprintf(userip,"7");
                            break;
                            case SDLK_8: sprintf(userip,"8");
                            break;
                            case SDLK_SPACE: sprintf(userip,"_");
                            break;
                            case SDLK_BACKSPACE: flag=1;
                            break;
                            case SDLK_RETURN: flag=2;
                            break;
                        }
                        if(inv_move)
                        {
                            strcpy(gamestate->label, " ");
                            inv_move = 0;
                        }
                        if(flag == 0 && strlen(gamestate->label)<=7)
                        {
                            strcat(gamestate->label, userip);
                            if(strlen(gamestate->label)==3)
                                strcat(gamestate->label, "-");
                            if(strlen(gamestate->label)==5)
                                gamestate->label[4] = toupper(gamestate->label[4]);
                            strcpy(userip, "");
                        }
                        else if(flag == 1 && strlen(gamestate->label)>1)
                        {
                            gamestate->label[strlen(gamestate->label)-1] = '\0';
                            if(strlen(gamestate->label)==3)
                            {
                                gamestate->label[strlen(gamestate->label)-1] = '\0';
                            }
                            flag = 0;
                        }
                        else if(flag == 2)
                        {
                            strcpy(userip, gamestate->label);
                            int temp_index = get_index(gamestate, (int)(userip[1]-'a'+1), (int)(userip[2]-'0'));
                            int type, cutting = 0;
                            if(userip[4] == '_')
                            {
                                type = PAWN;
                            }
                            else if(userip[4] == 'N')
                            {
                                type = KNIGHT;
                            }
                            else if(userip[4] == 'Q')
                            {
                                type = QUEEN;
                            }
                            else if(userip[4] == 'B')
                            {
                                type = BISHOP;
                            }
                            else if(userip[4] == 'R')
                            {
                                type = ROOK;
                            }
                            else if(userip[4] == 'K')
                            {
                                type = KING;
                            }
                            if(userip[5]=='x')
                            {
                                cutting = 1;
                            }

                            if((valid_move_check(gamestate, (int)(userip[1]-'a'+1), (int)(userip[2]-'0'), type, cutting, (int)(userip[6]-'a'+1), (int)(userip[7]-'0'))
                                  && temp_index!=-1 && gamestate->pieces[temp_index].color == gamestate->currentPlayerColor
                               && gamestate->pieces[temp_index].live == 1 && gamestate->pieces[temp_index].type == type))
                            {

                                int temp_index_cut = get_index(gamestate, (int)(userip[6]-'a'+1), (int)(userip[7]-'0'));

                                if(cutting)
                                {
                                    updatePiece(gamestate, temp_index_cut,
                                                9,9,0, gamestate->pieces[temp_index_cut].type, !gamestate->currentPlayerColor);
                                }

                                updatePiece(gamestate,
                                            temp_index,
                                            (int)(userip[6]-'a'+1), (int)(userip[7]-'0'),
                                            1, type, gamestate->currentPlayerColor);

                                if((gamestate->check==0 && check_for_check(gamestate) == 1 && gamestate->currentPlayerColor == 1) ||
                                   (gamestate->check==0 && check_for_check(gamestate) == 2 && gamestate->currentPlayerColor == 0) ||
                                   (gamestate->check==1 && check_for_check(gamestate) != 0) ||
                                   (gamestate->check==2 && check_for_check(gamestate) != 0))

                                {
                                    if(cutting)
                                    {
                                        updatePiece(gamestate, temp_index_cut,
                                                    (int)(userip[6]-'a'+1), (int)(userip[7]-'0'),
                                                1, gamestate->pieces[temp_index_cut].type, !gamestate->currentPlayerColor);
                                    }

                                    updatePiece(gamestate,
                                                temp_index,
                                                (int)(userip[1]-'a'+1), (int)(userip[2]-'0'),
                                                1, type, gamestate->currentPlayerColor);
                                    strcpy(gamestate->label, "Invalid move");
                                    inv_move = 1;
                                }
                                else
                                {
                                    timer(gamestate);
                                    gamestate->currentPlayerColor = !gamestate->currentPlayerColor;
                                }
                            }
                            else
                            {
                                strcpy(gamestate->label, "Invalid move");
                                inv_move = 1;
                            }
                            if(!inv_move)
                            {
                                strcpy(gamestate->label, " ");
                            }
                            strcpy(userip, "");
                            flag = 0;
                        }
            }
            break;
            case SDL_MOUSEBUTTONDOWN:
                if(gamestate->status == STATUS_MENU)
                {
                    if(event.button.x > (260*gameSize) && event.button.x < (540*gameSize) && event.button.y > (722*gameSize) && event.button.y < (822*gameSize))
                    {
                        gamestate->cur = 24.5;
                        gamestate->status = STATUS_GAME;
                    }
                }

        }
    }

    if(strlen(gamestate->label) >= 3)
    {
        gamestate->selected_x = (int)(gamestate->label[1]-'a'+1);
        gamestate->selected_y = (int)(gamestate->label[2]-'0');
        gamestate->showSelection = 1;
    }
    else
    {
        gamestate->showSelection = 0;
    }
    return done;
}

