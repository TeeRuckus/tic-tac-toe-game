#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H
    #define MAX_SETTINGS 3
    #define MAX_READ 10
    #define FALSE 0
    #define TRUE !FALSE
    #define INVALID -1
    #define VALID !INVALID
    void setInvalid(int *inArr); 
    /*int* readGameSettings(char *fileName);*/
	void readGameSettings(char *fileName, int *retValue);
    void processLine(char *line, char **inArr, int *lineRead);
    void parseLine(char **inStrArr, int *settingNum);
    int isDuplicates(int accessNumOne , int accessNumTwo, int accessNumThree);
#endif
