#ifndef CONNECTFOUR_INCLUDED
#define CONNECTFOUR_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>



#define CF_LEFT 0x01
#define CF_RIGHT 0x02
#define CF_UP 0x04
#define CF_DOWN 0x08


typedef struct
{
    char player_1_id;
    char player_2_id;
    uint8_t width;
    uint8_t height;
    uint8_t ** board;
}ConnectFourBoard;

ConnectFourBoard* generateBoard();
void destroyBoard(ConnectFourBoard* board);
void drawBoard(ConnectFourBoard* board);
uint8_t detectWin(ConnectFourBoard* board);
uint8_t checkConnectFourDirection(uint8_t direction, uint8_t checkee);
uint8_t checkWinDirection(ConnectFourBoard* board, uint8_t x, uint8_t y, uint8_t direction);
uint8_t getColumnHeight(ConnectFourBoard* board, uint8_t x);
uint8_t dropPiece(ConnectFourBoard* board, uint8_t x, uint8_t player);

#endif // CONNECTFOUR_INCLUDED
