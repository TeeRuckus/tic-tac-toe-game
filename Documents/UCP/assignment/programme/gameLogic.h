/*******************************************************************************
*   FILE: gameLogic.h                                                          *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: contains gameLogic.c function prototypes and data tyeps   *
*******************************************************************************/
#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

    /*this stucture is used as the players avatar in the game's 2 dimensional
    array. The strcuture allows the actual player avatar to be stored which is
    just a character, and it will allow to determine if the current tile in 
    the game board is occupied or not*/ 
    typedef struct player 
    {
        char player;
        Boolean occupied;
    }player;

	void playerMove(player **inArr, int *playPos, int *turn);
	char switchPlayers(int *turn);
    Boolean determineWinner(player **board,int *settings, int playerPos[2]);
    int validatePos(int  *pos, int rows, int cols, Boolean *status,player** gameBoard);
    Boolean hasWonVertically(player **board, int *settings,int playerPos[2]);
    int hasWonVerticallyRec(player **board, int *settings, int playerPos[2], 
                            Direction searchDir, int *numCalled);
    Boolean hasWonHorizontally(player **board, int *settings,int playerPos[2]);
    int hasWonHorizontallyRec(player **board, int *settings, int playerPos[2], 
                            Direction searchDir, int *numCalled);
    Boolean hasWonDiagonally(player **board, int *settings,int playerPos[2]);
    int hasWonDiagonallyRec(player **board, int *settings, int playerPos[2], 
                            Direction searchDir, int *numCalled);
    int calcGameSize(int *gameSettings);

#endif
