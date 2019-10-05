#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameGraphics.h"

int main(void)
{
    int *turn = (int*)malloc(sizeof(int));
    player **placements;
    /*lets always start the game with player one;*/
    int testSettings[2] = {5,8};
    int pos[2] = {2,1};
    *turn  = 2;
    placements = (player**)malloc(testSettings[0] * sizeof(player*));

    /*make a function called create board which will do this */
    create2DArray(placements, testSettings[0], testSettings[1]);
    clearGameBoard(placements, testSettings[0], testSettings[1]);
    redrawGameBoard(placements, testSettings, pos, turn);
    free2DArray(placements, testSettings[0]);
    free(turn);
    turn = NULL;
    return 0;
}

void drawGameBoard(player **placements, int *gameSettings)
{
    void *playerPos = malloc(sizeof(int));
    int *turn = (int*)malloc(sizeof(int));
    *turn = 1;
    playerPos = NULL;

    redrawGameBoard(placements, gameSettings, playerPos, turn);

    free(playerPos);
    free(turn);
    playerPos =  NULL;
    turn = NULL;
}

void redrawGameBoard(player **placements, int *gameSettings, int  *pos, int *turn)
{
    int width, height, ii, jj, kk, tileNumRow, tileNumCol;
    char *player;
    tileNumRow = 0;
    tileNumCol = 0; 
    width = gameSettings[0];
    height = gameSettings[1]; 
    player = playerMove(placements, pos, turn);
    
    /*printing out the number references for the rows */
    printf("  ");
    for(ii = 0; ii < width; ii++)
    {
        printf("   %d ",tileNumRow);
        tileNumRow++;
    }
    printf("\n");
    /*printing out the first border */
    printf("  ");
    for(ii = 0; ii <  ((width * SPACING) + 2); ii++)
    {   
        printf("=");
    }
    printf("\n"); 

    for(jj = 0; jj < height; jj++)
    {
        /*printing out the column numbers alongside printing out the games
        remaining boarders*/
        printf("%d", tileNumCol);
        tileNumCol++;
        printf(" ||");
        for(kk = 0; kk < ((width * SPACING) - 4); kk++)
        {
            if(kk < width-1)
            {
                /*PUT PLAYER MOMENTS HERE*/
                printf("  %s |", placements[kk][jj].player);
                /*printf("    |"); */
            }
            else if (kk == (width - 1))
            {
                printf(" %s ||", placements[kk][jj].player);
            }
        }
        printf("\n");
        
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

    free(player);
    player = NULL;
}


void clearGameBoard(player **inArr, int rows, int cols)
{
    int  ii, jj;
    for(ii = 0; ii < rows; ii++)
    {
        for(jj =  0; jj < cols; jj++)
        {
            inArr[ii][jj].player = " ";
            inArr[ii][jj].occupied = FALSE;
        }
    }
                                                            
}
