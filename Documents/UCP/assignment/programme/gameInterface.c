#include <stdio.h>
#include <stdlib.h>
#include "myBool.h"
#include "gameLogic.h"
#include "gameInterface.h"
#include "gameGraphics.h"
#include "memoryInterface.h"

/*PURPOSE: this where the main game loop is. Therefore, this function can be 
 * thought of as a function which brings all the elements of the game such
 * as drawing the game board, determining the winner, logging the game, and
 * the logic of the game */
void playGame(int *gameSettings)
{
    int *turn, *moves;
    Boolean  exit;
    int playerPos[2];
    player **gameBoard;
    
	turn = (int*)malloc(sizeof(int));
    moves = (int*)malloc(sizeof(int));
    gameBoard = (player**)malloc(gameSettings[0] * sizeof(player*));

    exit = FALSE;
    /*we're always going to start the game with player one*/
    *turn = 1;
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
            system("clear");
            redrawGameBoard(gameBoard, gameSettings, playerPos, turn);
            exit = determineWinner(gameBoard, gameSettings, playerPos);
        }
        else
        {
            printf(RED "ERROR: coordinates out of range please re-enter "
            "coordinates\n" RESET_COLOR);
            /*clearing the buffer*/ 
            while((getchar()) != '\n');
        }

        if(exit)
        {
            if((*turn - 1)  == 0)
            {
                printf(GREEN"player 2 has WON!!!!\n"RESET_COLOR);
            }
            else if((*turn - 1) == 1)
            {
                printf(GREEN"player 1 has WON!!!\n"RESET_COLOR);
            }
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
    int xCord, yCord, numReturned;
    Boolean valid;
    valid = FALSE;

    do
    {
        printf("Player %d enter move: ", *turn);
        numReturned = scanf("%d %d",&xCord, &yCord);
        valid = TRUE;
        if(numReturned != 2)
        {
            printf(RED"ERROR: enter coordinates as \"x\" \"y\" integers\n"RESET_COLOR);
            /*clearing the buffer, so funky stuff doesn't happen with scanf
            function */
            while((getchar()) != '\n');
            valid = FALSE;
        }
    }while(!valid);

    playerPos[0] = xCord;
    playerPos[1] = yCord;
}
