#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H
    #define MAX_SETTINGS 3
    #define MAX_READ 100
    /*#define MAX_LINES 3*/
    #define FALSE 0
    #define TRUE !FALSE
    int* readGameSettings(char *fileName);
    void processLine(char *line);
    void parseLine(char *line, int *inArr);
    /*void freeFileInterFace(int ***gameValues);*/
#endif
