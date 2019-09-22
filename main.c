#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ConnectFour.h"


uint8_t isValidPlacement(const char* input)
{
    size_t string_length = strlen(input) - 1;
    for(uint8_t i = 0; i < string_length; i++) if(!isdigit((int)input[i])) return 0;
    return 1;
}


int main()
{
    printf("Hello world!\n");

    ConnectFourBoard* board = generateBoard();
    drawBoard(board);

    dropPiece(board,0,1);
    dropPiece(board,0,2);
    printf("Height is %d\n", getColumnHeight(board,0));
    char* input = (char*)malloc(sizeof(char)*256);
    size_t user_input_size = 256;
    uint8_t current_player = 1;
    while(detectWin(board) == 0)
    {
        //Every Turn
        uint8_t success = 0;
        do
        {
            drawBoard(board);
            //Validate Input
            do
            {
                getline(&input,&user_input_size,stdin);
            }while(!isValidPlacement(input));
            printf("I got %d!\n", atoi(input));
            success = dropPiece(board,atoi(input), current_player);
            if(!success) printf("Invalid Placement!\n");


        }while(!success);
        if(current_player == 1) current_player = 2;
        else current_player = 1;

    }


    uint8_t result = detectWin(board);
    printf("The winner is player %d\n", result);


    drawBoard(board);
    free(input);
    destroyBoard(board);
    board = NULL;
    return 0;
}
