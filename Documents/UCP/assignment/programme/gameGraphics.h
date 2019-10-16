/*******************************************************************************
*  FILE: gameGraphics.h                                                        *
*  AUTHOR: Tawana David Kwaramba                                               *
*  STUDENT ID: 19476700                                                        *
*  DATE CREATED: 30/09/19                                                      *
*  DATE LAST MODIFIED:                                                         *
*  PURPOSE OF FILE: contains the forward declarations and the function         *
*                   protype of the gameGraphics.c file                         *
*********************************************************************************/
#ifndef GAME_GRAPHICS
#define GAME_GRAPHICS
    void drawGameBoard(player **placements, int *gameSettings, int *turn);
    void redrawGameBoard(player **placements, int *gameSettings, int  *pos, int *turn);
    void clearGameBoard(player **inArr, int rows, int cols);
#endif 
