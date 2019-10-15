#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
    /*DON'T FORGOT TO EXPLAIN WHAT THIS DOES*/
    typedef struct player 
    {
        char player;
        Boolean occupied;
    }player;

	void playerMove(player **inArr, int *playPos, int *turn);
	char switchPlayers(int *turn);
	int validatePos(int  *pos, int rows, int cols);
    Boolean determineWinner(player **board,int *settings, int playerPos[2]);
    Boolean hasWonVertically(player **board, int *settings,int playerPos[2]);
    int hasWonVerticallyRec(player **board, int *settings, int playerPos[2], 
                            Direction searchDir, int *numCalled);
    Boolean hasWonHorizontally(player **board, int *settings,int playerPos[2]);
    int hasWonHorizontallyRec(player **board, int *settings, int playerPos[2], 
                            Direction searchDir, int *numCalled);
    Boolean hasWonDiagonally(player **board, int *settings,int playerPos[2]);
    int hasWonDiagonallyRec(player **board, int *settings, int playerPos[2], 
                            Direction searchDir, int *numCalled);
    int calcGameSize(int *gameSettings);

#endif
