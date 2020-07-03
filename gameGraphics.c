/*******************************************************************************
*  FILE: gameGraphics.c
*  AUTHOR: Tawana David Kwaramba                                               *
*  STUDENT ID: 19476700                                                        *
*  DATE CREATED: 30/09/19                                                      *
*  DATE LAST MODIFIED:                                                         *
*  PURPOSE OF FILE: it's contain all the visual acspects of the game.          *
*                   Therefore the file is to handle the drawing of the whole   *
*                   game board, handling the avatars of each player.           *
*********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "programmeConstants.h"
#include "myBool.h"
#include "gameLogic.h"
#include "gameGraphics.h"

/*PURPOSE: to draw an empty game baord, this is used at the beginning of each 
 * game*/
void drawGameBoard(player **placements, int *gameSettings, int *turn)
{
    int *playerPos;
    playerPos = NULL;
    redrawGameBoard(placements, gameSettings, playerPos, turn);
}

/*PURPOSE: is to redraw the game with either player one's or two's avatar placed 
 * in the imported position.*/
void redrawGameBoard(player **placements, int *gameSettings, int  *pos, int *turn)
{
	int width, height, ii, jj, kk, tileNumRow, tileNumCol;
	tileNumRow = 0;
	tileNumCol = 0; 
    
    /*game setting is always exported in the order of m,n,k. Hence we know that
     * the first two numbers are going to be width and height respectively*/
	width = gameSettings[0];
	height = gameSettings[1]; 
    
    /*placements is a 2 dimensional array which represents the game baord in 
     * memory. hence player move will  place either player one's or two's
     * avatar in the required position in the 2-dimensional array*/
	playerMove(placements, pos, turn);
    
    /*printing out the number coordinated at the top of the game board*/ 
	printf("  ");
	for(ii = 0; ii < width; ii++)
	{
		printf("   %d ",tileNumRow);
		tileNumRow++;
	}
	printf("\n");
	/*printing out the top  border of the game*/
	printf("  ");
    /*spacing is used to allow the game board more astheticall pleasing and 
     * most importantly allowing the width of each tile to be enough to place 
     * the players avatar and to have the coordinates cleary referencing a cell*/
	for(ii = 0; ii <  ((width * SPACING) + 2); ii++)
	{   
		printf("=");
	}
	printf("\n"); 
    
	for(jj = 0; jj < height; jj++)
	{
		/*printing out the column numbers alongside printing out the games
		left boarder and intermediary boarders*/
		printf("%d", tileNumCol);
		tileNumCol++;
		printf(" ||");
		for(kk = 0; kk < ((width * SPACING) - 4); kk++)
		{
			if(kk < width-1)
			{
                /*printing out the intermediary boarders of the game baord
                 * and what is actually at that location which is either 
                 * a blank space or a player avatar*/
				printf("  %c |", placements[kk][jj].player);
			}
			else if (kk == (width - 1))
			{
                /*once the width of the board is reached. We need to print out
                 * the right boarder and what is actually at that location
                 * which is either a blank space or a player avatar*/
				printf(" %c ||", placements[kk][jj].player);
			}
		}
		printf("\n");
		
        /*printing out the bottom boarder of the game board*/
		printf("  ");
		for(ii = 0; ii < (width * SPACING + 2); ii++)
		{
			if(jj == (height - 1))
			{
				printf("=");
			}
			else
			{
				printf("-");
			}
		}
		printf("\n");
	}
}

/*PURPOSE: this function is to set the game's 2-d array to blank spaces. This 
 * is to tbe used at the start of the game*/
void clearGameBoard(player **inArr, int rows, int cols)
{
    int  ii, jj;
    for(ii = 0; ii < rows; ii++)
    {
        for(jj =  0; jj < cols; jj++)
        {
            inArr[ii][jj].player = ' ';
            inArr[ii][jj].occupied = FALSE;
        }
    }
                                                            
}
