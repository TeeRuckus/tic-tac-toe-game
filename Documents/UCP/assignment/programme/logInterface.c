#include <stdio.h>
#include <string.h>
#include "LinkList.h"
#include "logInterface.h"

LinkedList* createGameLog()
{
    LinkedList *gameLog;
    gameLog = createLinkedList();
    return gameLog;
}

void logGame(LinkedList *inList, int *inSettings, char *playerAvatar, int *pos,
            int *moves, int *numGames)
{   
    char initLogMssg[LOG_MSSG];
    gameLog nwLog;
    /*nwLog = NULL;*/
	(*moves)++;
    /*when the game is just beggining */
    if(*moves == 0)
    {
        sprintf(initLogMssg,"SETTINGS\n\tM:%d\n\tN:%d\n\tK:%d\nGAME:%d",
        inSettings[0], inSettings[1], inSettings[2], *numGames); 
        strcpy(nwLog.mssg, initLogMssg);
        strcpy(nwLog.turn, "");
        strcpy(nwLog.player, "");
        strcpy(nwLog.pos, "");
        insertFirst(inList, &nwLog);
    }
    /*when the game already has commenced */
    else
    {
        insertLog(inList, playerAvatar, pos, moves);
    }
}

void insertLog(LinkedList *inList, char *playerAvatar, int *pos,
               int *moves)
{
    char turn[MAX_LINE];
    char player[MAX_LINE];
    char playerPos[MAX_LINE]; 
    gameLog gameEntry;

    /*intialising the enteries of gameLog*/
    strcpy(gameEntry.turn, "");
    strcpy(gameEntry.player, "");
    strcpy(gameEntry.pos, "");

    sprintf(playerPos, "Location: %d,%d\n",pos[0], pos[1]);
    sprintf(player, "Player: %s\n", playerAvatar);
    sprintf(turn, "turn: %d\n",*moves);

    strcpy(gameEntry.turn, turn); 
    strcpy(gameEntry.player, player);
    strcpy(gameEntry.pos, playerPos);
    insertLast(inList, gameEntry);
}

void displayLog(LinkedList *inList, funcPtr fptr)
{
    display(inList, fptr);
}

void printLogStruct(void *data)
{
    gameLog *inData;
    inData = (gameLog*)data;

    printf(" %s", inData -> mssg);
    printf(" %s", inData -> turn);
    printf(" %s", inData -> player);
    printf(" %s", inData -> pos);
}

/*make a method in fileInterface.c which will just print out stings to a file
 i.e. it will just write to a file */
