#include <stdio.h>
#include <stdlib.h>
#include "gameGraphics.h"
#include "memoryInterface.h"
#include "gameLogic.h"

void playGame(int *gameSettings)
{
    int *turn = (int*)malloc(sizeof(int));
    int  exit;
    int playerPos[2];
    player **gameBoard;

    /*we're always going to start the game with player one*/
    *turn = 1;
    exit = FALSE;

    create2DArray(gameBoard, gameSettings[0], gameSettings[1]);
    clearGameBoard(gameBoard, gameSettings[0], gameSettings[1]);
    drawGameBoard(gameBoard, gameSettings);

    /*entering into the main game loop*/
    do
    {
        getPosition(playerPos, turn);
        if(validatePos(playerPos) == TRUE)
        {
            redrawGameBoard(gameBoard, gameSettings, playerPos, turn);
            exit = determineWinner(gameBoard);
        }
        else
        {
            printf("ERROR: coordinates out of range please re-enter "
            "coordinates");
        }
    }while(!exit);



    /*MAKE THIS INTO ONE FUNCTION SO IT'S A LOT CLEANER*/
    free2DArray(gameBoard, gameSettings[0]);
    free(turn);
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
        printf("Enter move: ");
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
