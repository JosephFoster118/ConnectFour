#include "AI.h"

uint8_t calculateMove(ConnectFourBoard* board, uint8_t player, uint8_t depth)
{
    printf("Calculating AI move...");
    printf("The depth is %d and the player is %d\n", depth, player);
    return 0;
}

float MinniMax(ConnectFourBoard* board, uint8_t player, uint8_t whos_turn, uint8_t turn_cnt)
{
    return 0.0f;
}

float getOpponentScore(ConnectFourBoard* board, uint8_t ai_id)
{

    return 0.0f;
}

float getAIScore(ConnectFourBoard* board, uint8_t ai_id)
{
    return 0.0f;
}


uint8_t detect2P(ConnectFourBoard* board, uint8_t player)
{
    for(uint8_t x = 0; x < board->width; x++)
    {
        uint8_t column_height = getColumnHeight(board,x);//Go until height is met to save some cycles
        for(uint8_t y = 0; y < column_height; y++)
        {

        }
    }
    return 0;
}

uint8_t detect2PDirection(ConnectFourBoard* board, uint8_t player, uint8_t direction)
{
    return 0;
}

uint8_t detect3P(ConnectFourBoard* board, uint8_t player)
{
    return 0;
}

uint8_t detectWP(ConnectFourBoard* board, uint8_t player)
{
    return 0;
}

