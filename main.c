#include <stdio.h>
#include <stdlib.h>

#include "ConnectFour.h"



int main()
{
    printf("Hello world!\n");

    ConnectFourBoard* board = generateBoard();
    drawBoard(board);
    board->board[1][0] = 1;
    drawBoard(board);
    destroyBoard(board);
    board = NULL;
    return 0;
}
