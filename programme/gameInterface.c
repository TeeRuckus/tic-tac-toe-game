#include <stdio.h>
#include <stdlib.h>
#include "gameLogic.h"
#include "gameInterface.h"
#include "gameGraphics.h"
#include "memoryInterface.h"

void playGame(int *gameSettings)
{
    int *turn, *moves;
    int  exit;
    int playerPos[2];
    player **gameBoard;
    
	turn = (int*)malloc(sizeof(int));
    moves = (int*)malloc(sizeof(int));
    gameBoard = (player**)malloc(gameSettings[0] * sizeof(player*));

    /*we're always going to start the game with player one*/
    *turn = 1;
    exit = FALSE;
    *moves = 0;

    create2DArray(gameBoard, gameSettings[0], gameSettings[1]);
    clearGameBoard(gameBoard, gameSettings[0], gameSettings[1]);
    drawGameBoard(gameBoard, gameSettings, turn);

    /*entering into the main game loop*/
    do
    {
        getPosition(playerPos, turn);
        if(validatePos(playerPos, gameSettings[0], gameSettings[1]))
        {
            redrawGameBoard(gameBoard, gameSettings, playerPos, turn);
            exit = determineWinner(gameBoard, moves);
        }
        else
        {
            printf("ERROR: coordinates out of range please re-enter "
            "coordinates\n");
            /*clearing the buffer*/ 
            while((getchar()) != '\n');
        }
    }while(!exit);



    /*MAKE THIS INTO ONE FUNCTION SO IT'S A LOT CLEANER*/
    free2DArray(gameBoard, gameSettings[0]);
    free(turn);
    free(moves);

    moves = NULL;
    turn = NULL;
}

/*HAVE SOME ERROR HANDLING HERE, TO ENSURE THAT THE RIGHT THING IS INPUTTED, AND
IN THE RIGHT FORMAT*/
void getPosition(int *playerPos, int *turn)
{
    int xCord, yCord, numReturned, valid;
    valid = FALSE;

    do
    {
        printf("Player %d enter move: ", *turn);
        numReturned = scanf("%d %d",&xCord, &yCord);
        valid = TRUE;
        if(numReturned != 2)
        {
            printf("ERROR: enter coordinates as \"x\" \"y\"\n");
            /*clearing the buffer, so funky stuff doesn't happen with scanf
            function */
            while((getchar()) != '\n');
            valid = FALSE;
        }
    }while(!valid);

    playerPos[0] = xCord;
    playerPos[1] = yCord;
}
