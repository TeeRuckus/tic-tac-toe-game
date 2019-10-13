#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myBool.h"
#include "gameLogic.h"
#include "gameGraphics.h"

void playerMove(player **inArr, int *playPos, int *turn)
{   
	if(playPos != NULL)
	{
		char playerAvatar;
		int xCord, yCord;
		xCord = playPos[0];
		yCord = playPos[1];
		playerAvatar = switchPlayers(turn);

		if(playPos == NULL)
		{
			/*Do nothing */
		}
		else if(inArr[xCord][yCord].occupied == FALSE) 
		{
			inArr[xCord][yCord].player = playerAvatar;
			inArr[xCord][yCord].occupied = TRUE;
		}
		else 
		{
			printf(RED"INVALID: this position is already occupied\n" RESET_COLOR);
            switchPlayers(turn);
		}
	}
}

char switchPlayers(int *turn)
{
	char playerAvatar;
    if(*turn == 1) 
    {
		playerAvatar = 'X';
        /*strcpy(playerAvatar, "X");*/
        /*switching it back to player two's turn now */
        *turn = 2;
    }
    else if(*turn == 2)
    {
		playerAvatar = 'O';
        /*strcpy(playerAvatar, "O");*/
        /*switching it back to player one's turn now */ 
        *turn = 1;
    }

	return playerAvatar;
}

/*rember this is used in your recrusive calls */
int validatePos(int  *pos, int rows, int cols)
{ 
    int valid;
    valid = FALSE;
    if( (pos[0] < rows && pos[0] >= 0) && (pos[1] < cols && pos[1] >= 0))
    {
        valid = TRUE;
    }
    return valid;
}

/*FUNCTION IS NOT FINISHED YET. IT JUST ALWAYS ASSUMES THAT IT'S A DRAW */
Boolean determineWinner(player **board,int *settings, int playerPos[2])
{
    Boolean winner;
    winner = FALSE;

    if(hasWonVertically(board, settings, playerPos))
    {
        winner = TRUE; 
    }
    else if(hasWonHorizontally(board, settings, playerPos))
    {
        winner = TRUE;
    }
    else if(hasWonDiagonally(board, settings, playerPos))
    {
        winner = TRUE;
    }


    return winner;
}

Boolean hasWonVertically(player **board, int *settings,int playerPos[2])
{
    Boolean won;
    int numCalledUp;
    int numCalledDown;

    won = FALSE;
    numCalledUp = 0;
    numCalledDown = 0;

    if(((hasWonVerticallyRec(board, settings, playerPos, Down, 
            &numCalledDown) + (hasWonVerticallyRec(board, settings, playerPos,
            Up, &numCalledUp)) + 1)  == settings[2]))
    {
        won = TRUE;
    }

    return won;
}

Boolean hasWonHorizontally(player **board, int *settings,int playerPos[2])
{
    Boolean won;
    int numCalledLeft;
    int numCalledRight;

    won = FALSE;
    numCalledLeft = 0;
    numCalledRight = 0;

    /*if(hasWonHorizontallyRec(board, settings, playerPos, Left, &numCalledLeft) + 1 
       == settings[2])
    {
        won = TRUE;
    }
    else if(hasWonHorizontallyRec(board, settings, playerPos, Right, 
            &numCalledRight) + 1 == settings[2])
    {
        won = TRUE;
    }*/ 

    if(((hasWonHorizontallyRec(board, settings, playerPos, Left, 
    &numCalledLeft)) + (hasWonHorizontallyRec(board, settings, playerPos, Right,
    &numCalledRight)) + 1) == settings[2])
    {
        won = TRUE;
    }

    return won;
}

Boolean hasWonDiagonally(player **board, int *settings,int playerPos[2])
{
    Boolean won;
    int numDiagonallyUpLeft, numDiagonallyUpRight, numDiagonallyDownLeft,
    numDiagonallyDownRight;

    won = FALSE;
    numDiagonallyUpLeft = 0;
    numDiagonallyUpRight = 0;
    numDiagonallyDownLeft = 0;
    numDiagonallyDownRight = 0;

    /*if(hasWonDiagonallyRec(board, settings, playerPos, DiagonallyUpLeft, 
                           &numDiagonallyUpLeft) + 1 == settings[2])
    {
        won = TRUE;
    }
    else if(hasWonDiagonallyRec(board, settings, playerPos, DiagonallyUpRight, 
            &numDiagonallyUpRight) + 1 == settings[2])
    {
        won = TRUE;
    }
    else if(hasWonDiagonallyRec(board, settings, playerPos, DiagonallyDownLeft, 
                                &numDiagonallyDownLeft) + 1 == settings[2])
    {
        won = TRUE;
    }
    else if(hasWonDiagonallyRec(board, settings, playerPos, DiagonallyDownRight, 
            &numDiagonallyDownRight) + 1 == settings[2])
    {
        won = TRUE;
    }*/

    if(((hasWonDiagonallyRec(board, settings, playerPos, DiagonallyUpLeft, 
       &numDiagonallyUpLeft)) + (hasWonDiagonallyRec(board, settings, playerPos,
       DiagonallyDownRight, &numDiagonallyDownRight)) + 1) == settings[2])
    {
        won = TRUE;
    }
    if(((hasWonDiagonallyRec(board, settings, playerPos, DiagonallyUpRight, 
       &numDiagonallyUpRight)) + (hasWonDiagonallyRec(board, settings, playerPos,
       DiagonallyDownLeft, &numDiagonallyDownLeft)) + 1) == settings[2])
    {
        won = TRUE;
    }

    return won;
}

int hasWonVerticallyRec(player **board, int *settings, int playerPos[2], 
                        Direction searchDir, int *numCalled)
{
    int recPos[2], recCall;
    char currAvatar;
    Boolean matchingAvatar;
    
    recPos[0] = playerPos[0]; 
    recPos[1] = playerPos[1];
    recCall = 0;
    currAvatar = board[playerPos[0]][playerPos[1]].player;
    matchingAvatar = TRUE;

    if(recCall != settings[2])
    {
        if(matchingAvatar)
        {
            recCall++;
            if(searchDir == Up)
            {
                recPos[1]--;
            }
            else if(searchDir == Down)
            {
                recPos[1]++;
            }
            
           if((validatePos(recPos, settings[0], settings[1]) && currAvatar == 
            board[recPos[0]][recPos[1]].player))
            {
                hasWonVerticallyRec(board, settings, recPos, searchDir, numCalled);
                (*numCalled)++;
            }
            else
            {
                matchingAvatar = FALSE;
            }
        }
    }
    
    return *numCalled;
}

int hasWonHorizontallyRec(player **board, int *settings, int playerPos[2], 
                        Direction searchDir, int *numCalled)
{
    int recPos[2], recCall;
    char currAvatar;
    Boolean matchingAvatar;
    
    recPos[0] = playerPos[0]; 
    recPos[1] = playerPos[1];
    recCall = 0;
    currAvatar = board[playerPos[0]][playerPos[1]].player;
    matchingAvatar = TRUE;
    if(recCall != settings[2])
    {
        if(matchingAvatar)
        {
            recCall++;
            if(searchDir == Left)
            {
                recPos[0]--;
            }
            else if(searchDir == Right)
            {
                recPos[0]++;
            }
            
           if((validatePos(recPos, settings[0], settings[1]) && currAvatar == 
            board[recPos[0]][recPos[1]].player))
            {
                hasWonHorizontallyRec(board, settings, recPos, searchDir, numCalled);
                (*numCalled)++;
            }
            else
            {
                matchingAvatar = FALSE;
            }
        }
    }
    
    return *numCalled;
}


int hasWonDiagonallyRec(player **board, int *settings, int playerPos[2], 
                        Direction searchDir, int *numCalled)
{
    int recPos[2], recCall;
    char currAvatar;
    Boolean matchingAvatar;
    
    recPos[0] = playerPos[0]; 
    recPos[1] = playerPos[1];
    recCall = 0;
    currAvatar = board[playerPos[0]][playerPos[1]].player;
    matchingAvatar = TRUE;
    if(recCall != settings[2])
    {
        if(matchingAvatar)
        {
            recCall++;
            if(searchDir == DiagonallyUpLeft)
            {
                recPos[0]--;
                recPos[1]--;
            }
            else if(searchDir == DiagonallyUpRight)
            {
                recPos[0]++;
                recPos[1]--;
            }
            else if(searchDir == DiagonallyDownLeft)
            {
                recPos[0]--;
                recPos[1]++;
            }
            else if(searchDir == DiagonallyDownRight)
            {
                recPos[0]++;
                recPos[1]++;
            }
            
           if((validatePos(recPos, settings[0], settings[1]) && currAvatar == 
            board[recPos[0]][recPos[1]].player))
            {
                hasWonDiagonallyRec(board, settings, recPos, searchDir, numCalled);
                (*numCalled)++;
            }
            else
            {
                matchingAvatar = FALSE;
            }
        }
    }
    
    return *numCalled;
}
