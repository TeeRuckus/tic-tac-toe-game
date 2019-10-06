#include <stdlib.h>
#include "gameLogic.h"
#include "memoryInterface.h"

void free2DArray(player **inArr, int rows)
{   
    int ii;
    for(ii = 0; ii < rows; ii++)
    {
        free(inArr[ii]);
        inArr[ii] = NULL;
    }

    free(inArr);
    inArr = NULL;
}


void create2DArray(player **inArr,int rows, int cols)
{
    int ii;
    /*mallocing the columns of the 2-D array*/
    for(ii = 0; ii < rows; ii++)
    {
        inArr[ii] = (player*)malloc(cols * sizeof(player));
    }
}

void createChar2DArray(char **inArr, int rows, int cols)
{
    int ii;
    /*mallocing the columns of the 2-D array*/
    for(ii = 0; ii < rows; ii++)
    {
        inArr[ii] = (char*)malloc(cols * sizeof(char));
    }
}
