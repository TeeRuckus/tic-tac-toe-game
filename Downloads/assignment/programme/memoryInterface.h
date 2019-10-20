/*******************************************************************************
*   FILE: memoryInterface.h                                                    *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: contains all the function prototypes of functions declared*
*                    in memory.c                                               *
*******************************************************************************/
#ifndef MEMORY_INTERFACE_H
#define MEMORY_INTERFACE_H
    void free2DArray(player **inArr, int rows);
	void create2DArray(player **inArr,int rows, int cols);
    void createChar2DArray(char **inArr, int rows, int cols);
    void createChar2DArray(char **inArr, int rows, int cols);
	void free2DCharArray(char **inArr, int rows); 
#endif
