#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
    #define FALSE 0
    #define TRUE !FALSE
    /*DON'T FORGOT TO EXPLAIN WHAT THIS DOES*/
    typedef struct player 
    {
        char player;
        int occupied;
    }player;
	void playerMove(player **inArr, int *playPos, int *turn);
	char switchPlayers(int *turn);
	int validatePos(int  *pos, int rows, int cols);
	int determineWinner(player **board);
#endif
