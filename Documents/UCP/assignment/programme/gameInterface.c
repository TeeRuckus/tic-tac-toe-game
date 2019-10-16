/*******************************************************************************
*   FILE: gameInterface.c                                                      *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: contains function which makes the game playable hence,    *
*                    combining the logic of the game and the graphics of       *
*                    the game to make a playable game                          *
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "programmeConstants.h"
#include "myBool.h"
#include "gameLogic.h"
#include "LinkList.h"
#include "gameInterface.h"
#include "gameGraphics.h"
#include "memoryInterface.h"
#include "logInterface.h"


/*PURPOSE: this where the main game loop is. Therefore, this function can be 
 * thought of as a function which brings all the elements of the game such
 * as drawing the game board, determining the winner, logging the game, and
 * the logic of the game */
void playGame(int *gameSettings, LinkedList *gameLog)
{
    /*if the number of valid moves is equal to the area of the board, the game
    has ended in a draw*/
    int *turn, boardSize, playerPos[2], *moves;

    /*the valid boolean is used to make sure it's safe to insert a log of the 
    game and to increase the number of valid moves in the game. Therefore, to
    enusre that the calculation of a draw is done correctly and invalid moves
    don't actually get counted additionally, it's to ensure only valid moves 
    are  placed in the log. i.e. movees such as the player trying to input a 
    position which is already occupied or out of range shouldn't be included in
    the log or shouldn't be used in the calculation of determining a winner*/
    Boolean  exit, *valid;
    player **gameBoard;
    
	turn = (int*)malloc(sizeof(int));
    moves = (int*)malloc(sizeof(int));
    valid = (Boolean*)malloc(sizeof(Boolean));
    gameBoard = (player**)malloc(gameSettings[0] * sizeof(player*));

    exit = FALSE;

    /*we're always going to start the game with player one. Moves is to help
     * with the logging of the game and in determining if the game is a draw*/
    *turn = 1;
    *moves = 0;
    *valid = TRUE;
    
    /*2-d array used to hold the players avatars*/
    create2DArray(gameBoard, gameSettings[0], gameSettings[1]);
    /*intiliasing the game board to blank spaces*/
    clearGameBoard(gameBoard, gameSettings[0], gameSettings[1]);

    drawGameBoard(gameBoard, gameSettings, turn);

    /*we need to know how big the game baord is so the function can tell if
     * the game has ended in a draw or not*/
    boardSize = calcGameSize(gameSettings);

    /*entering into the main game loop*/
    do
    {
        getPosition(playerPos, turn);
        if(validatePos(playerPos, gameSettings[0], gameSettings[1], valid, gameBoard))
        {
            /*clearing the terminal, so it gives the effect that the 
             * pieces are been drawn into their place and it's the same board 
             * and not a redrawn board*/
            system("clear");

            redrawGameBoard(gameBoard, gameSettings, playerPos, turn);
            exit = determineWinner(gameBoard, gameSettings, playerPos);
        }
        else
        {
            printf(RED "ERROR: coordinates out of range please re-enter "
            "coordinates\n" RESET_COLOR);
            /*clearing the buffer soan ifinite loop doesn't occur*/
            while((getchar()) != '\n');
        }

        if(exit)
        {
            /*the redrawGameBoard function switches the player to the opposing
            player hence, when a player has won the game. It would've been the
            previous player who actually won the game not the current player.
            Hence, we need to subtract one from what  is at turn and if that 
            difference is equal to 0 we know that the last turn was player ones, 
            and if it's equal to 1 we know it was player two's turn*/
            if((*turn - 1)  == 0)
            {
                printf(GREEN"player 2 has WON!!!!\n"RESET_COLOR);
            }
            else if((*turn - 1) == 1)
            {
                printf(GREEN"player 1 has WON!!!\n"RESET_COLOR);
            }
        }
        if(*valid)
        {
            (*moves)++;
            /*a valid position is played on the gameboard we're safe to log the
             * game*/
            if(gameLog != NULL)
            {
                logGamePlay(gameLog, playerPos, 
                gameBoard[playerPos[0]][playerPos[1]].player, moves);
            }
            /*if the amount of valid moves is equal to the board size and a 
            player hasn't won on the final move it  only means that the game
            has ended up in a draw*/
            if(*moves == boardSize && !exit)
            {
                printf(YELLOW"it's a draw :( you both suck!!!\n"RESET_COLOR);
                exit = TRUE;
            }
        }

    }while(!exit);

    free2DArray(gameBoard, gameSettings[0]);
    free(turn);
    free(moves);
    free(valid);
    moves = NULL;
    turn = NULL;
    valid = NULL;
}

/*PURPOSE: to get to coordinate integer positions from the user seperated by 
spaces. Otherwise if it's anything else, the function should re-prompt the user
until the right coordinates are entered*/ 
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
        /*if the scanf function didn't succesfully return 2 integer numbers we
        know that something has definetely gone wrong and we should re-prompt
        the user to re-enter their options*/
        if(numReturned != 2)
        {
            printf(RED"ERROR: enter coordinates as \"x\" \"y\" integers\n"
            RESET_COLOR);

            /*clearing the buffer, so funky stuff doesn't happen with scanf
            function */
            while((getchar()) != '\n');
            valid = FALSE;
        }
    }while(!valid);
    
    playerPos[0] = xCord;
    playerPos[1] = yCord;
}
