#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "programmeConstants.h"
#include "myBool.h"
#include "LinkList.h"
#include "logInterface.h"
#include "fileInterface.h"

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

void printLogStructToFile(void *data, FILE *strmName)
{
    gameLog *inData;
    inData = (gameLog*)data;

    fprintf(strmName, "%s", inData -> mssg);
    fprintf(strmName, "%s", inData -> turn);
    fprintf(strmName, "%s", inData -> player);
    fprintf(strmName, "%s", inData -> pos);
}

char *generateLogName(int *gameSettings)
{
    /*the following code is adapted from the following source: 
    https://www.techiedelight.com/print-current-date-and-time-in-c/ */
    int hours, mins, day, month, mSetting, nSetting, kSetting; 
    time_t now;
    struct tm *local;
    /*cannot forget the  null terminator*/
    char fileConf[MAX_SETTINGS + 1], *fileName;
    local = NULL;

    fileName = (char*)malloc(sizeof(char) * MAX_FILE_NAME);

    strcpy(fileConf, "MNK");
    mSetting = gameSettings[0];
    nSetting = gameSettings[1]; 
    kSetting = gameSettings[2];
    time(&now); 
    local = localtime(&now);
    
    hours = local -> tm_hour;
    mins = local -> tm_min;

    day = local -> tm_mday;

    /*need to add one, as this function returns a month from 0 - 11. Hence  you
    need to add 1 to make it more human readable hence 1 - 12 */
    month = local -> tm_mon + 1;

    sprintf(fileName, "%s_%d-%d-%d_%d-%d_%d-%d.log", fileConf, mSetting, 
            nSetting, kSetting, hours, mins, day, month);

    return fileName;

}

void freeLog(LinkedList *inLog, funcPtr fptr)
{
    freeLinkedList(inLog, fptr);
}
