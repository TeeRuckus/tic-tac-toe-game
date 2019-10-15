#ifndef GAME_GRAPHICS
#define GAME_GRAPHICS
    void drawGameBoard(player **placements, int *gameSettings, int *turn);
    void redrawGameBoard(player **placements, int *gameSettings, int  *pos, int *turn);
    void clearGameBoard(player **inArr, int rows, int cols);
#endif 
