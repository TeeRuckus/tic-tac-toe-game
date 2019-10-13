#ifndef LOG_INTERFACE_H
#define LOG_INTERFACE_H
    #define LOG_MSSG 100
    #define MAX_LINE 20 

    /*EXPLAIN WHAT THIS DOES*/ 
    typedef struct gameLog
    {
        char mssg[LOG_MSSG]; 
        char turn[LOG_MSSG];
        char player[LOG_MSSG];
        char pos[LOG_MSSG];
    }gameLog;


    LinkedList* createGameLog();
    void logGame(LinkedList *inList, int *inSettings, char *playerAvatar,
          int *pos, int *moves, int *numGames);
    void insertLog(LinkedList *inList, char *playerAvatar, int *pos,
                   int *moves);
    void displayLog(LinkedList *inList, funcPtr fptr);
    void printLogStruct(void *data);
#endif
