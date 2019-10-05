#include <stdlib.h>
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


void create2DArray(player **inArr, int rows, int cols)
{
    inArr = (player**)malloc(rows * sizeof(player*));
    int ii;
    /*mallocing the columns of the 2-D array*/
    for(ii = 0; ii < rows; ii++)
    {
        inArr[ii] = (player*)malloc(cols * sizeof(player));
    }
}
