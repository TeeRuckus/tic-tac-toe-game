#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gameLogic.h"
#include "gameGraphics.h"

void playerMove(player **inArr, int *playPos, int *turn)
{   
	if(playPos != NULL)
	{
		char playerAvatar;
		int xCord, yCord;
		xCord = playPos[0];
		yCord = playPos[1];
		/*playerAvatar = (char*)malloc((sizeof(char)) * 2);*/
		playerAvatar = switchPlayers(turn);

		if(playPos == NULL)
		{
			/*Do nothing */
		}
		else if(inArr[xCord][yCord].occupied == FALSE) 
		{
			inArr[xCord][yCord].player = playerAvatar;
			inArr[xCord][yCord].occupied = TRUE;
		}
		else 
		{
			printf("INVALID: this position is already occupied\n");
            switchPlayers(turn);
		}
	}

    /*return playerAvatar;*/
}

char switchPlayers(int *turn)
{
	char playerAvatar;
    if(*turn == 1) 
    {
		playerAvatar = 'X';
        /*strcpy(playerAvatar, "X");*/
        /*switching it back to player two's turn now */
        *turn = 2;
    }
    else if(*turn == 2)
    {
		playerAvatar = 'O';
        /*strcpy(playerAvatar, "O");*/
        /*switching it back to player one's turn now */ 
        *turn = 1;
    }

	return playerAvatar;
}

int validatePos(int  *pos, int rows, int cols)
{ 
    int valid;
    valid = FALSE;
    if(pos[0] < rows && pos[1] < cols)
    {
        valid = TRUE;
    }
    return valid;
}

/*FUNCTION IS NOT FINISHED YET. IT JUST ALWAYS ASSUMES THAT IT'S A DRAW */
int determineWinner(player **board)
{
    int valid;
    valid = FALSE;
    return valid;
}
