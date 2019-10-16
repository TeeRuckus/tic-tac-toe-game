/*******************************************************************************
*   FILE: gameLogic.c                                                          *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: this file contains all the logic which is used in playing *
*                    the game i.e. determining the winner, validating  the     *
*                    players position, changing between player 1 and player 2  *
*                    avatars, and it also contains arithemtic used by the game.*
*                    Therefore, this file can be thought as the programmes     *
*                    brains.                                                   *
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "programmeConstants.h"
#include "myBool.h"
#include "gameLogic.h"
#include "gameGraphics.h"

/*PURPOSE: to place the players  avatar on the requested tile, if the tile is
already occupied an error message is shown and the players turn will be switched
back to the person which tried to play an occupied position*/
void playerMove(player **inArr, int *playPos, int *turn)
{   
	if(playPos != NULL)
	{
		char playerAvatar;
		int xCord, yCord;
		xCord = playPos[0];
		yCord = playPos[1];

        /*get either player 1's or 2's avatar as this is needed to be placed in
        the games 2 dimensional matrix*/
		playerAvatar = switchPlayers(turn);
        
        /*if the position is not occupied*/
		if(inArr[xCord][yCord].occupied == FALSE) 
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

/*PURPOSE: to return either player ones or two's avatar depending on who's turn
it is in the game, and to switch the turn to the other playe*/
char switchPlayers(int *turn)
{
	char playerAvatar;
    if(*turn == 1) 
    {
		playerAvatar = 'X';
        /*switching it back to player two's turn now */
        *turn = 2;
    }
    else if(*turn == 2)
    {
		playerAvatar = 'O';
        /*switching it back to player one's turn now */ 
        *turn = 1;
    }

	return playerAvatar;
}

/*PURPOSE: the ovearching purpose of this function is to validate if the users
coordinates are with in the games board. The other secondary use is to 
validate if the position entered is occupied or not and an accompaning
status will be exporteded. This stus is useful in telling the playGame function
that the last move entered was valid and you log this play into the log files
also it's useful in determing a draw as a draw checks if the number of valid
moves made is equal to the area of the board. This function will tell the 
playGame function that the last move played is validate and you can increase
the moves counter and determine if they is a winner or not*/
int validatePos(int  *pos, int rows, int cols, Boolean *status,player** gameBoard)
{ 
    int valid;
    valid = FALSE;
    if( (pos[0] < rows && pos[0] >= 0) && (pos[1] < cols && pos[1] >= 0))
    {
        valid = TRUE;
        if(status != NULL)
        {
            *status = FALSE; 
            if(gameBoard != NULL)
            {
                if(gameBoard[pos[0]][pos[1]].occupied == FALSE)
                {
                    *status = TRUE;
                }
            }
        }
    }

    return valid;
}

/*PURPOSE: to determine if a player is either won vertically, horizontally or 
diagonally*/
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

/*PURPOSE: TO determine if a player has won in the vertical plan and to
return a boolean indicating if they have or not. Furthermore, a wrapper function 
which houses the hasWonVerticallyRec function and gives a location for the 
recrusive algorithm to come back too and to start*/
Boolean hasWonVertically(player **board, int *settings,int playerPos[2])
{
    Boolean won;
    int numCalledUp;
    int numCalledDown;

    won = FALSE;
    numCalledUp = 0;
    numCalledDown = 0;

    /*the recrusive algorithm only looks one direction and counts matching
    avatars in that specified direction. What happens if the winning move
    is placed in between tiles? The logic would  have to be to look in both
    directions and and add the matching avatars founa in both direction and add 
    them up including itself. This scenerio is what this if statement is doing. 
    It's looking in both directions to see if the player has won by placing 
    their avatar in the middle of matching lines. Furthermore, 
    settings[2] is just the games k value. The greater sign is for the rare
    case where a player wins by exceeding the amount of required tiles*/
    if(((hasWonVerticallyRec(board, settings, playerPos, Down, 
            &numCalledDown) + (hasWonVerticallyRec(board, settings, playerPos,
            Up, &numCalledUp)) + 1)  >= settings[2]))
    {
        won = TRUE;
    }

    return won;
}

/*PURPOSE: to determine if a player has won in the horizontal plane and return
a boolean indicating if they have won or not. Furthermore, it acts as a wrapper
function for the hasWonHorizatallyRec function thus providing the recursive 
algorithm a place to start and to return too*/
Boolean hasWonHorizontally(player **board, int *settings,int playerPos[2])
{
    Boolean won;
    int numCalledLeft;
    int numCalledRight;

    won = FALSE;
    numCalledLeft = 0;
    numCalledRight = 0;

    /*the recrusive algorithm only looks one direction and counts matching
    avatars in that specified direction. What happens if the winning move
    is placed in between tiles? The logic would  have to be to look in both
    directions and and add the matching avatars founa in both direction and add 
    them up including itself. This scenerio is what this if statement is doing. 
    It's looking in both directions to see if the player has won by placing 
    their avatar in the middle of matching lines. Furthermore, 
    settings[2] is just the games k value. The greater than sign is for the rare
    case when someone wins put placing more than the required  tiles in the 
    game*/
    if(((hasWonHorizontallyRec(board, settings, playerPos, Left, 
    &numCalledLeft)) + (hasWonHorizontallyRec(board, settings, playerPos, Right,
    &numCalledRight)) + 1) >= settings[2])
    {
        won = TRUE;
    }

    return won;
}

/*PURPOSE: to determine if a player has won in any of the diagonal planes. 
Furthermore it acts as a wrapper methof for the hasWonDiagonallyRec function
thus, providing a location to start and to finish for the recrusive function*/
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

    /*the recrusive algorithm only looks one direction and counts matching
    avatars in that specified direction. What happens if the winning move
    is placed in between tiles? The logic would  have to be to look in both
    directions and and add the matching avatars founa in both direction and add 
    them up including itself. This scenerio is what this if statement is doing. 
    It's looking in both directions to see if the player has won by placing 
    their avatar in the middle of matching lines. Furthermore, 
    settings[2] is just the games k value. The greater than symbol is for the
    rare case when someone wins by more than the required tiles in the game*/

    /*one if statement is to loop diagonally in the positive gradient and the 
    other in the negatve gradient*/
    if(((hasWonDiagonallyRec(board, settings, playerPos, DiagonallyUpLeft, 
       &numDiagonallyUpLeft)) + (hasWonDiagonallyRec(board, settings, playerPos,
       DiagonallyDownRight, &numDiagonallyDownRight)) + 1) >= settings[2])
    {
        won = TRUE;
    }
    if(((hasWonDiagonallyRec(board, settings, playerPos, DiagonallyUpRight, 
       &numDiagonallyUpRight)) + (hasWonDiagonallyRec(board, settings, playerPos,
       DiagonallyDownLeft, &numDiagonallyDownLeft)) + 1) >= settings[2])
    {
        won = TRUE;
    }

    return won;
}

/*PURPOSE: A recurive method which looks in either the up or down direction
in the games board and counts how many matching avatars are the same as the
one given in the requested positon. The algorithm doesn't count the starting
player avatar. The alogorithm will return the number of matching player 
avatars*/
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
           
           /*to enusure the recursive algorithm doesn't go outside the game
           board*/
           if((validatePos(recPos, settings[0], settings[1], NULL, NULL) && currAvatar == 
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
    
    /*it may seem odd to have a return for a pointer as pointers are stored in 
    the heap and can just be exported out of the function. The rational behnd
    this is because a recurcive alogirithm needs a return value so it can
    exit it's current stack frame and go to the next frame. Additionally without
    the recrurcive algorithm will keep calling itself ifintely*/
    return *numCalled;
}

/*PUROSE: a recursive algorithm which looks in either the left or right direction
and counts how many matching avatars they're not including iself given it's 
starting position. The algoritm will then return the number of matching pieces*/
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
            
            /*stoping the board from accessing memory which is outside the 
            board*/
           if((validatePos(recPos, settings[0], settings[1],NULL,NULL) && currAvatar == 
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
    
    /*it may seem odd to have a return for a pointer as pointers are stored in 
    the heap and can just be exported out of the function. The rational behnd
    this is because a recurcive alogirithm needs a return value so it can
    exit it's current stack frame and go to the next frame. Additionally without
    the recrurcive algorithm will keep calling itself ifintely*/
    return *numCalled;
}


/*PURPOSE: a recursive algorithm to look either in the upward positive right
direction or the upward positive left direction or the downward negative right
direction or the downward left directon for matching player avatars given its
current positon, the algorithm will count how many matching avatars they're not
including itself and return the number of matching tiles*/
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
            
           /*stopping the algorithm from trying to access memory past the baords
           size*/
           if((validatePos(recPos, settings[0], settings[1],NULL,NULL) && currAvatar == 
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
    
    /*it may seem odd to have a return for a pointer as pointers are stored in 
    the heap and can just be exported out of the function. The rational behnd
    this is because a recurcive alogirithm needs a return value so it can
    exit it's current stack frame and go to the next frame. Additionally without
    the recrurcive algorithm will keep calling itself ifintely*/
    return *numCalled;
}

/*PURPOSE: to calculate the area of the baord and to return the area. This is
used in determing if the game is a draw*/
int calcGameSize(int *gameSettings)
{ 
    int boardSize;

    boardSize = gameSettings[0] * gameSettings[1];

    return boardSize;
}
