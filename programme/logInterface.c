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
    gameLog *nwLog;
    nwLog = NULL;
    /*when the game is just beggining */
    if(*moves == 0)
    {
        sprintf(initLogMssg,"SETTINGS\n\tM:%d\n\tN:%d\n\tK:%d\n\nGAME:%d",
        inSettings[0], inSettings[1], inSettings[2], *numGames); 
        strcpy(nwLog -> mssg, initLogMssg);
        /*nwLog -> turn = "";
        nwLog -> player = "";
        nwLog -> pos = "";*/ 
        strcpy(nwLog -> turn, "");
        strcpy(nwLog -> player, "");
        strcpy(nwLog -> pos, "");
        insertFirst(inList, nwLog);
        (*moves)++;
    }
    /*when the game already has commenced */
    else
    {
        insertLog(inList, playerAvatar, pos, moves);
        (*moves )++; 
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
    /*gameEntry.turn = "";
    gameEntry.player = "";
    gameEntry.pos = "";*/
    strcpy(gameEntry.turn, "");
    strcpy(gameEntry.player, "");
    strcpy(gameEntry.pos, "");
    /*turn = (char*)malloc(sizeof(char) * MAX_LINE);
    player = (char*)malloc(sizeof(char) * MAX_LINE);
    playerPos = (char*)malloc(sizeof(char) * MAX_LINE);*/


    sprintf(playerPos, "Location: %d,%d\n",pos[0], pos[1]);
    sprintf(player, "Player: %s\n", playerAvatar);
    sprintf(turn, "turn: %d\n",*moves);

    strcpy(gameEntry.turn, turn); 
    strcpy(gameEntry.player, player);
    strcpy(gameEntry.pos, playerPos);
    insertLast(inList, gameEntry);

    /*free(turn);
    free(player);
    free(playerPos); 

    turn = NULL;
    player = NULL;
    playerPos = NULL;*/
}

void displayLog(LinkedList *inList, funcPtr fptr)
{
    display(inList, fptr);
}

void printLogStruct(void *data)
{
    printf(" %s", ((gameLog*)data) -> mssg);
    printf(" %s", ((gameLog*)data) -> turn);
    printf(" %s", ((gameLog*)data) -> player);
    printf(" %s", ((gameLog*)data) -> pos);
}
