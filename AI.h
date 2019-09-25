#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#include "ConnectFour.h"



uint8_t calculateMove(ConnectFourBoard* board, uint8_t player, uint8_t depth);
float MinniMax(ConnectFourBoard* board, uint8_t player, uint8_t whos_turn, uint8_t turn_cnt);
float getOpponentScore(ConnectFourBoard* board, uint8_t ai_id);
float getAIScore(ConnectFourBoard* board, uint8_t ai_id);
uint8_t detect2P(ConnectFourBoard* board, uint8_t player);
uint8_t detect3P(ConnectFourBoard* board, uint8_t player);
uint8_t detectWP(ConnectFourBoard* board, uint8_t player);
uint8_t detect2PDirection(ConnectFourBoard* board, uint8_t player, uint8_t direction);

#endif // AI_H_INCLUDED
