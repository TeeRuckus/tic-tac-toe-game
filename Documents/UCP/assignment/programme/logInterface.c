#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myBool.h"
#include "LinkList.h"
#include "logInterface.h"

/*PURPOSE: is to create a game log which is consisted of the abstract data
 * structure of a Linked List */
LinkedList* createGameLog()
{
    LinkedList *gameLog;
    gameLog = createLinkedList();
    return gameLog;
}

void logGameSettings(LinkedList *inLog, int *inSettings)
{
    char initLogMssg[MAX_LINE];
    gameLog *nwLog = (gameLog*)malloc(sizeof(gameLog));
    clearGameStruct(nwLog);

    sprintf(initLogMssg,"SETTINGS\n\tM:%d\n\tN:%d\n\tK:%d\n\n",inSettings[0], 
    inSettings[1], inSettings[2]); 
    
    strcpy(nwLog -> mssg, initLogMssg);
    insertLast(inLog, nwLog);
}

void logGameNum(LinkedList *inLog, int *gameNum)
{
    char gameLogNum[MAX_LINE];
    gameLog *nwLog = (gameLog*)malloc(sizeof(gameLog));
    clearGameStruct(nwLog);

    sprintf(gameLogNum, "GAME %d:\n", *gameNum);

    strcpy(nwLog -> mssg, gameLogNum);
    insertLast(inLog, nwLog);
}

void logGamePlay(LinkedList *inLog, int playerPos[2], char playerAvatar, 
                int *turns)
{
    char turn[MAX_LINE];
    char player[MAX_LINE];
    char pos[MAX_LINE]; 

    gameLog *nwLog = (gameLog*)malloc(sizeof(gameLog));
    clearGameStruct(nwLog);

    sprintf(player, "\tPlayer: %c\n", playerAvatar);
    sprintf(turn, "\tturn: %d\n", *turns);
    sprintf(pos, "\tLocation: %d,%d\n\n",playerPos[0], playerPos[1]);

    strcpy(nwLog -> turn, turn); 
    strcpy(nwLog -> player, player);
    strcpy(nwLog -> pos, pos);

    insertLast(inLog, nwLog);
}

/*PURPOSE: to turn every entry of a game stuct to an empty strings. This is to 
 * intialise the struct so when another function tries to access it. The 
 * programme won't crush or print out unexpected output*/
void clearGameStruct(gameLog *inLog)
{
    strcpy(inLog -> mssg, "");
    strcpy(inLog -> turn, "");
    strcpy(inLog -> player, "");
    strcpy(inLog -> pos, "");
}

void displayLog(LinkedList *inList, funcPtr fptr)
{
    display(inList, fptr);
}

void printLogStruct(void *data)
{
    gameLog *inData;
    inData = (gameLog*)data;

    printf("%s", inData -> mssg);
    printf("%s", inData -> turn);
    printf("%s", inData -> player);
    printf("%s", inData -> pos);
}

void freeLog(LinkedList *inLog, funcPtr fptr)
{
    freeLinkedList(inLog, fptr);
}
