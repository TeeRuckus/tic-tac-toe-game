#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H
    #define MAX_SETTINGS 3
    #define MAX_READ 10
    void setInvalid(int *inArr); 
    /*int* readGameSettings(char *fileName);*/
	void readGameSettings(char *fileName, int *retValue);
    void processLine(char *line, char **inArr, ValidStatus *lineRead);
    void parseLine(char **inStrArr, int *settingNum);
    Boolean isDuplicates(int accessNumOne , int accessNumTwo, int accessNumThree);
    Status writeFile(char *fileName, LinkedList *dataToWrite, filePrintPtr fptr);
#endif
