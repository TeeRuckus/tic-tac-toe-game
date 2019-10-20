/*******************************************************************************
*   FILE: memoryInterface.c                                                    *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: this file contains all the functions to create and to free*
*                    two dimensional arrays                                    *
*******************************************************************************/
#include <stdlib.h>
#include "myBool.h"
#include "gameLogic.h"
#include "memoryInterface.h"

/*ASSERTS: free all the elements of an array of arrays of the data type  
 * "player"*/
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

/*ASSERTS: creates an array of arrays of the size of rows by cols of the
 * data type "player"*/
void create2DArray(player **inArr,int rows, int cols)
{
    int ii;
    /*mallocing the columns of the 2-D array*/
    for(ii = 0; ii < rows; ii++)
    {
        inArr[ii] = (player*)malloc(cols * sizeof(player));
    }
}

/*ASSERTS: creates an array of arrays in memory the size of rows by cols with
 * the  data type of char*/
void createChar2DArray(char **inArr, int rows, int cols)
{
    int ii;
    /*mallocing the columns of the 2-D array*/
    for(ii = 0; ii < rows; ii++)
    {
        inArr[ii] = (char*)malloc(cols * sizeof(char));
    }
}

/*ASSERTS: frees an array of arrays in memory the size of rows with the data
 * type char*/
void free2DCharArray(char **inArr, int rows) 
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
