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
    void redrawGameBoard(player **placements, int *gameSettings, int  *pos, int *turn);
    void create2DArray(player **inArr, int rows, int cols);
    void clearGameBoard(player **inArr, int rows, int cols);
    void free2DArray(player **inArr, int rows);
	char *playerMove(player **inArr, int *playPos, int *turn);
    void switchPlayers(int *turn, char *playerAvatar);
#endif 
