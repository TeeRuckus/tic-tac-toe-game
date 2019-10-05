#ifndef GAME_GRAPHICS
#define GAME_GRAPHICS
	#define SPACING 5
    #define FALSE 0
    #define TRUE !FALSE
    /*DON'T FORGOT TO EXPLAIN WHAT THIS DOES*/
    typedef struct player 
    {
        char *player;
        int occupied;
    }player;
    void drawGameBoard(player **placements, int *gameSettings);
    void redrawGameBoard(player **placements, int *gameSettings, int  *pos, int *turn);
    void clearGameBoard(player **inArr, int rows, int cols);
#endif 
