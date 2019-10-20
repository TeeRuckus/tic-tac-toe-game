/*******************************************************************************
* FILE: fileInterface.h                                                        *
* AUTHOR: Tawana David Kwaramba                                                *
* STUDENT ID: 19476700                                                         *
* DATE CREATED: 30/09/19                                                       *
* DATE LAST MODIFIED:                                                          *
* PURPOSE OF FILE: the forward declarations of the fileInterface and all the   *
*                  all the functions contained in the file interface.          *
********************************************************************************/
#ifndef FILE_INTERFACE_H
#define FILE_INTERFACE_H
    void setInvalid(int *inArr); 
	void readGameSettings(char *fileName, int *retValue);
    void processLine(char *line, char **inArr, ValidStatus *lineRead);
    void parseChar(char **inStrArr, int *settingNum);
    Boolean isDuplicates(int accessNumOne , int accessNumTwo, int accessNumThree);
    Status writeFile(char *fileName, LinkedList *dataToWrite, filePrintPtr fptr);
#endif
