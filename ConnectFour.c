#include "ConnectFour.h"

ConnectFourBoard* generateBoard()
{
    ConnectFourBoard* board = (ConnectFourBoard*)malloc(sizeof(ConnectFourBoard));
    board->width = 7;
    board->height = 6;
    board->player_1_id = 'X';
    board->player_2_id = 'O';


    board->board = malloc(sizeof(uint8_t*)*board->width);

    for(uint8_t i = 0; i < board->width; i++) board->board[i] = malloc(sizeof(uint8_t)*board->height);

    for(uint8_t i = 0; i < board->width; i++)
    {
        for(uint8_t j = 0; j < board->height; j++)
        {
            board->board[i][j] = 0;
        }
    }

    return board;
}

void destroyBoard(ConnectFourBoard* board)
{
    //Destroy board array
    for(uint8_t i = 0; i < board->width; i++) free(board->board[i]);
    free(board->board);
}


void drawBoard(ConnectFourBoard* board)
{
    for(uint8_t i = 0; i < board->width; i++)
    {
        printf(" %d", i);
    }
    printf("\n ");

    for(uint8_t j = 0; j < board->width; j++)
    {
        printf("--");
    }
    printf("\n");

    for(uint8_t i = 0; i < board->height; i++)
    {
        printf("|");
        for(uint8_t j = 0; j < board->width; j++)
        {
            switch(board->board[j][board->height - i - 1])
            {
                case 0:
                {
                    printf(" |");
                }break;
                case 1:
                {
                    printf("%c|",board->player_1_id);
                }break;
                case 2:
                {
                    printf("%c|",board->player_2_id);
                }break;
            }


        }
        printf("\n");
        fflush(stdin);
    }
    printf(" ");
    for(uint8_t j = 0; j < board->width; j++)
    {
        printf("--");
    }
    printf("\n");
}

uint8_t checkWinDirection(ConnectFourBoard* board, uint8_t x, uint8_t y, uint8_t direction)
{
    if(checkConnectFourDirection(CF_LEFT, direction) && x < 4) return 0;



    return 0;
}

uint8_t detectWin(ConnectFourBoard* board)
{
    for(uint8_t i = 0; i < board->width; i++)
    {
        for(uint8_t j = 0; j < board->height; j++)
        {
            if(board->board[i][j] == 0) continue;
        }
    }
    return 0;
}

uint8_t checkConnectFourDirection(uint8_t direction, uint8_t checkee)
{
    if(direction & checkee) return 1;
    return 0;
}




