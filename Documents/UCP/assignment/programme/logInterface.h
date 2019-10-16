/*******************************************************************************
*   FILE: logInterface.h                                                       *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: contains all the function prototypes and the data types   *
*                    used in  logInterface.c                                   *
*******************************************************************************/
#ifndef LOG_INTERFACE_H
#define LOG_INTERFACE_H

    /*it's used to store the game log  enteries into the log linked list. The
     * structure seperates the enteries of the log into they own varibles.
     * Making it easier to print the log to the terminal or either to write
     * the log to a file*/
    typedef struct gameLog
    {
        char mssg[MAX_LINE]; 
        char turn[MAX_LINE];
        char player[MAX_LINE];
        char pos[MAX_LINE];
    }gameLog;

    LinkedList* createGameLog();
    void logGameSettings(LinkedList *inLog, int *inSettings);
    void logGameNum(LinkedList *inLog, int *gameNum);
    void logGamePlay(LinkedList *inLog, int playerPos[2], char playerAvatar, 
                    int *turns);
    void clearGameStruct(gameLog *inLog);
    void displayLog(LinkedList *inList, funcPtr fptr);
    void printLogStructToFile(void *data, FILE *strmName);
    void printLogStruct(void *data);
    void freeLog(LinkedList *inLog, funcPtr fptr);
    char *generateLogName(int *gameSettings);
#endif
