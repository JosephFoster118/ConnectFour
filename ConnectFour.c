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
    //Skip the check if not possible

    if(board->board[x][y] == 0) return 0;
    if((CF_LEFT & direction) != 0 && x < 3) return 0;
    if((CF_RIGHT & direction) != 0 && x > board->width - 4) return 0;
    if((CF_DOWN & direction) != 0 && y < 3) return 0;
    if((CF_UP & direction) != 0 && y > board->height - 4) return 0;



    uint8_t to_check = board->board[x][y];
    if(checkConnectFourDirection(CF_RIGHT | CF_UP, direction))
    {
        for(uint8_t i = 0; i < 3; i++)
        {
            if(board->board[x + 1 + i][y + 1 + i] != to_check) return 0;
        }
        return to_check;
    }
    else if(checkConnectFourDirection(CF_LEFT | CF_UP, direction))
    {
        for(uint8_t i = 0; i < 3; i++)
        {
            if(board->board[x - 1 - i][y + 1 + i] != to_check) return 0;
        }
        return to_check;
    }
    else if(checkConnectFourDirection(CF_LEFT | CF_DOWN, direction))
    {
        printf("CKECK\n");
        for(uint8_t i = 0; i < 3; i++)
        {
            if(board->board[x - 1 - i][y - 1 - i] != to_check) return 0;
        }
        return to_check;
    }
    else if(checkConnectFourDirection(CF_RIGHT | CF_DOWN, direction))
    {
        for(uint8_t i = 0; i < 3; i++)
        {
            if(board->board[x + 1 + i][y - 1 - i] != to_check) return 0;
        }
        return to_check;
    }
    else if(checkConnectFourDirection(CF_RIGHT, direction))
    {
        for(uint8_t i = 0; i < 3; i++)
        {
            if(board->board[x + 1 + i][y] != to_check) return 0;
        }
        return to_check;
    }
    else if(checkConnectFourDirection(CF_LEFT, direction))
    {
        for(uint8_t i = 0; i < 3; i++)
        {
            if(board->board[x - 1 - i][y] != to_check) return 0;
        }
        return to_check;
    }
    else if(checkConnectFourDirection(CF_UP, direction))
    {
        for(uint8_t i = 0; i < 3; i++)
        {
            if(board->board[x][y + 1 + i] != to_check) return 0;
        }
        return to_check;
    }
    else if(checkConnectFourDirection(CF_UP, direction))
    {
        for(uint8_t i = 0; i < 3; i++)
        {
            if(board->board[x][y - 1 - i] != to_check) return 0;
        }
        return to_check;
    }

    return 0;
}

uint8_t detectWin(ConnectFourBoard* board)
{
    for(uint8_t i = 0; i < board->width; i++)
    {
        for(uint8_t j = 0; j < board->height; j++)
        {
            if(board->board[i][j] == 0) continue;
            uint8_t result = checkWinDirection(board,i,j,CF_RIGHT);
            if(result != 0) return result;
            result = checkWinDirection(board,i,j,CF_LEFT);
            if(result != 0) return result;
            result = checkWinDirection(board,i,j,CF_UP);
            if(result != 0) return result;
            result = checkWinDirection(board,i,j,CF_DOWN);
            if(result != 0) return result;
            result = checkWinDirection(board,i,j,CF_RIGHT | CF_UP);
            if(result != 0) return result;
            result = checkWinDirection(board,i,j,CF_LEFT | CF_UP);
            if(result != 0) return result;
        }
    }
    return 0;
}

uint8_t checkConnectFourDirection(uint8_t direction, uint8_t checkee)
{
    if((direction & checkee) == direction) return 1;
    return 0;
}

uint8_t getColumnHeight(ConnectFourBoard* board, uint8_t x)
{
    if(x >= board->width) return board->height;
    for(uint8_t i = 0; i < board->height; i++)
    {
        if(board->board[x][i] == 0) return i;
    }
    return board->height;
}

uint8_t dropPiece(ConnectFourBoard* board, uint8_t x, uint8_t player)
{
    if(x >= board->width) return 0;
    uint8_t height = getColumnHeight(board,x);
    if(height >= board->height) return 0;
    board->board[x][height] = player;
    return 1;
}


