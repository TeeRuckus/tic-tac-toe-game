#ifndef LOG_INTERFACE_H
#define LOG_INTERFACE_H
    /*EXPLAIN WHAT THIS DOES*/ 
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
