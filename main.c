#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ConnectFour.h"
#include "AI.h"


uint8_t isValidPlacement(const char* input)
{
    size_t string_length = strlen(input) - 1;
    for(uint8_t i = 0; i < string_length; i++) if(!isdigit((int)input[i])) return 0;
    return 1;
}


int main()
{
    char* input = (char*)malloc(sizeof(char)*256);
    size_t user_input_size = 256;



    uint8_t human_player_number = 0;

    while(!human_player_number)
    {
        printf("Are you player \"1\" or \"2\": ");
        getline(&input, &user_input_size, stdin);
        human_player_number = atoi(input);
        if(human_player_number > 2) human_player_number = 0;
    }

    ConnectFourBoard* board = generateBoard();


    uint8_t current_player = 1;
    while(detectWin(board) == 0)
    {
        if(current_player == human_player_number)
        {
            //Every Turn
            uint8_t success = 0;
            do
            {
                drawBoard(board);
                printf("Player %c input drop location:",(current_player == 1) ? board->player_1_id : board->player_2_id);
                //Validate Input
                do
                {
                    getline(&input,&user_input_size,stdin);
                }while(!isValidPlacement(input));
                printf("I got %d!\n", atoi(input));
                success = dropPiece(board,atoi(input), current_player);
                if(!success) printf("Invalid Placement!\n");


            }while(!success);
        }
        else
        {
            dropPiece(board, calculateMove(board,current_player,4),current_player);
        }
        if(current_player == 1) current_player = 2;
        else current_player = 1;

    }

    drawBoard(board);
    uint8_t result = detectWin(board);
    printf("The winner is player %c\n", (result == 1) ? board->player_1_id : board->player_2_id);

    ConnectFourBoard* clone_board = cloneBoard(board);
    drawBoard(clone_board);
    destroyBoard(clone_board);
    clone_board = NULL;



    free(input);
    destroyBoard(board);
    board = NULL;
    return 0;
}
















