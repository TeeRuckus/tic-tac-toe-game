#include <stdio.h>
#include "gameGraphics.h"

int main(void)
{
    int testSettings[3] = {5,4,4};
    /*int pos[2] = {0,0};*/
    redrawGameBoard(testSettings);
    
    return 0;
}

void redrawGameBoard(int *gameSettings, int *pos, int player)
{
    int width, height, ii, jj, kk, comboToWin, tileNumRow, tileNumCol, 
    lineBorders;

    player **placements;

    tileNumRow = 0;
    tileNumCol = 0; 
    lineBorders = 0; 
    width = gameSettings[0];
    height = gameSettings[1]; 
    comboToWin = gameSettings[2]; 
    printf("%d\n", comboToWin);
    lineBorders = width - 1;
    placements = (char**)malloc(width * sizeof(char*));
    
    /*mallocing the columns of the 2-D array*/
    for(ii = 0; ii < width; ii++)
    {
        placements[ii] = (char*)malloc(height * sizeof(char));
    }

    /*setting the 2-D array to blank spaces */
    for(ii = 0; ii < width; ii++)
    {
        for(jj =  0; jj < height; jj++)
        {
            placements[ii][jj] = " ";
        }
    }
    
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
            if(kk < lineBorders)
            {
                /*PUT PLAYER MOMENTS HERE*/
                printf("    |"); 
            
            else if (kk == lineBorders)
            {
                printf("   ||");
            }
        }
        printf("\n");
       /* printf("   ||\n");*/
        
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


void freeGameArrays(char **inArr)
{   
    int numRows, numCols, ii;
    numRows = LEN_ARRAY(inArrr,inArr[0]);

    for(ii = 0; ii < numRows; ii++)
    {
        free(inArr[ii]);
        inArr[ii] = NULL;
    }
    free(inArr);
    inArr = NULL;
}
