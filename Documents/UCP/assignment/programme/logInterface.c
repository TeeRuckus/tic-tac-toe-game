/*******************************************************************************
*   FILE: logInterface.c                                                       *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: to facilate the functionality of the logging of the game. *
*   i.e. creating the log, logging the game settings, logging the game number  *
*   we're on, logging the valid positions whihc have been played on the game   *
*   board, displaying the log to the terminal, writing the log to a file, and  *
*   other auxiliary functions to assist in this functionality                  *
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "programmeConstants.h"
#include "myBool.h"
#include "LinkList.h"
#include "logInterface.h"
#include "fileInterface.h"

/*ASSERTS: returns a game log with the abstract data type of a linked list 
 *
 * note: it may seem like a pointless function but I have created this because
 * when a user is using the  log interface which is not me. They're not going
 * to know what abstract data structure have used to create the log interface
 * nor are they going to care. Hence, it's to created uniformaity with this 
 * file*/
LinkedList* createGameLog()
{
    LinkedList *gameLog;
    gameLog = createLinkedList();

    return gameLog;
}

/*ASSERTS: adds gameLog structure containing the gameSettings into the  linked
 * list */
void logGameSettings(LinkedList *inLog, int *inSettings)
{
    char initLogMssg[MAX_LINE];
    gameLog *nwLog = (gameLog*)malloc(sizeof(gameLog));

    /*intializing everything in the structure into blank spaces so we don't
     * have any issues when trying to access every element of the structure
     * when printing or writing to a file*/
    clearGameStruct(nwLog);
    
    /*formatting the settings in the log */
    sprintf(initLogMssg,"SETTINGS\n\tM:%d\n\tN:%d\n\tK:%d\n\n",inSettings[0], 
    inSettings[1], inSettings[2]); 
    
    strcpy(nwLog -> mssg, initLogMssg);

    /*doesn't really matter if we insert first or last but, the settings are
     * always going to be the top of the log file*/
    insertFirst(inLog, nwLog);
}

/*ASSERTS: inserts a structure into a linked list which only contains the game
 * number*/
void logGameNum(LinkedList *inLog, int *gameNum)
{
    char gameLogNum[MAX_LINE];
    gameLog *nwLog = (gameLog*)malloc(sizeof(gameLog));

    /*intialising every entry in the structure to blank soaces. To avoid errors
     * when we try to read from those enteries*/
    clearGameStruct(nwLog);

    sprintf(gameLogNum, "GAME %d:\n", *gameNum);

    strcpy(nwLog -> mssg, gameLogNum);
    insertLast(inLog, nwLog);
}

/*ASSERTS: inserts a structure into a linked list which contains the elements
 * of turn, player and location*/
void logGamePlay(LinkedList *inLog, int playerPos[2], char playerAvatar, 
                int *turns)
{
    char turn[MAX_LINE];
    char player[MAX_LINE];
    char pos[MAX_LINE]; 

    gameLog *nwLog = (gameLog*)malloc(sizeof(gameLog));

    /*intiliasing all the enteries in teh structure into blank spaces. To avoid
     * errors when reading from the structure enteries*/
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
 * programme won't crush or print out unexpected output as the programme won't
 * always have every entery in the structure filled in*/
void clearGameStruct(gameLog *inLog)
{
    strcpy(inLog -> mssg, "");
    strcpy(inLog -> turn, "");
    strcpy(inLog -> player, "");
    strcpy(inLog -> pos, "");
}

/*ASSERTS: displays everything on the Linked list to the terminal.
 *
 * note: it may seem like a pointless function but I have created this because
 * when a user is using the  log interface which is not me. They're not going
 * to know what abstract data structure have used to create the log interface
 * nor are they going to care. Hence, it's to created uniformaity with this 
 * file*/
void displayLog(LinkedList *inList, funcPtr fptr)
{
    display(inList, fptr);
}

/*PURPOSE: this function is to help the linked lists display method to print
 * out the contents of the log to the terminal */
void printLogStruct(void *data)
{
    gameLog *inData;
    inData = (gameLog*)data;

    printf("%s", inData -> mssg);
    printf("%s", inData -> turn);
    printf("%s", inData -> player);
    printf("%s", inData -> pos);
}

/*PURPOSE: this function to help the linked lists dispay to file method to print
 * out its contents to a file wihout deleting the actual content*/
void printLogStructToFile(void *data, FILE *strmName)
{
    gameLog *inData;
    inData = (gameLog*)data;

    fprintf(strmName, "%s", inData -> mssg);
    fprintf(strmName, "%s", inData -> turn);
    fprintf(strmName, "%s", inData -> player);
    fprintf(strmName, "%s", inData -> pos);
}

/*PURPOSE: to generate a name to what the log is going to be saved as. The
 * name will always follow this format 
 * "MNK_<M setting>-<N - setting>-<k setting>_<current hour (24 hours)>-
 * <current mins>_<current day>-<current month>.log*/
char *generateLogName(int *gameSettings)
{
    /*the following code is adapted from the following source: 
    https://www.techiedelight.com/print-current-date-and-time-in-c/ */
    int hours, mins, day, month, mSetting, nSetting, kSetting; 
    /*is a time type*/
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

    /*get what the current time is now*/
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

/*ASSERTS: frees all the log enteries add onto the log.
 *
 * the reason for having this function here is the same as the reason given in
 * the createLog and displayLog functions*/
void freeLog(LinkedList *inLog, funcPtr fptr)
{
    freeLinkedList(inLog, fptr);
}
