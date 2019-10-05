#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
    #define FALSE 0
    #define TRUE !FALSE
	char *playerMove(player **inArr, int *playPos, int *turn);
    void switchPlayers(int *turn, char *playerAvatar);
    int validatePos(int  *pos, int rows, int cols):
    int determineWinner(player **board);
#endif
