#include <stdio.h>
#include "gameGraphics.h"

int main(void)
{
    int testSettings[3] = {5,4,4};
    /*int pos[2] = {0,0};*/
    redrawGameBoard(testSettings);
    
    return 0;
}

void redrawGameBoard(int *gameSettings, int  *pos)
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
    create2DArray(placements, width, height);
    playerMove(placements, pos, turn);
    
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

/*PURPOSE: is to create a 2-dimensional array filled with blank spaces*/
void create2DArray(player **inArr, int rows, int cols)
{
    int ii, jj;
    /*mallocing the columns of the 2-D array*/
    for(ii = 0; ii < rows; ii++)
    {
        inArr[ii] = (char*)malloc(cols * sizeof(char));
    }

    /*setting the 2-D array to blank spaces */
    for(ii = 0; ii < rows; ii++)
    {
        for(jj =  0; jj < cols; jj++)
        {
            inArr[ii][jj].player = " ";
            inArr[ii][jj].occupied = FALSE;
        }
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

void playerMove(player **inArr, int *playPos, int *turn)
{   
    int row, col;
    row = playPos[0];
    col = playPos[1];

    if(inArr[row][col].occupied == FALSE) 
    {
        inArr[row][col] = switchPlayers(*turn);
    }
    else 
    {
        printf("INVALID: this position is already occupied\n");
    }
}

char* switchPlayers(int *turn)
{
    char *playerAvatar;
    playerAvatar[2];
    if(*turn == 1) 
    {
        playerAvatar = "X";
        /*switching it back to player two's turn now */
        *turn = 2;
    }
    else if(turn == 2)
    {
        playerAvatar = "O";
        /*switching it back to player one's turn now */ 
        *turn = 1;
    }

    return playerAvatar;
}
