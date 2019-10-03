#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H
    #define MAX_SETTINGS 3
    #define MAX_LINES 3
    #define FALSE 0
    #define TRUE !FALSE
    int*** readGameSettings(char *fileName);
    void freeFileInterFace(int ***gameValues);
#endif
