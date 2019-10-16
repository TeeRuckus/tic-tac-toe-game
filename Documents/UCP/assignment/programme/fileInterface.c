/*******************************************************************************
* FILE: fileInterface.c
* AUTHOR: Tawana David Kwaramba                                                *
* STUDENT ID: 19476700                                                         *
* DATE CREATED: 30/09/19                                                       *
* DATE LAST MODIFIED:                                                          *
* PURPOSE OF FILE: to handle the file input and output of the programme i.e.   *
*                  the reading and writing of files, and other surpporting     *
*                  functions which help in reading and writing of files        *
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "programmeConstants.h"
#include "myBool.h"
#include "gameLogic.h"
#include "memoryInterface.h"
#include "LinkList.h"
#include "fileInterface.h"

/*PURPOSE: to read in a game settings which contain the folowing settings of
M=<Integer>
N=<Integer> 
K=<Integer> 
The file can be read in any order and reglardess of capatilazation. The function
will return an array order in the  following manner <M>,<N>,<K>, otherwise 
if the file doesn't adhere to the format given  above in any manner the programme
should print out a meaningfull message and the retrun array will consist of
-1,-1,-1*/
void readGameSettings(char *fileName, int *retValue)
{
    int *gameSetting, mSettingAcess, nSettingAcess, kSettingAcesss,
    lineCount;
    /*used to exit out the while loop when reading in a file */
    Boolean errorDecteded, stop;
    ValidStatus *isValidLine;

    char line[MAX_READ], **gameSettingsStr;
    FILE *inStrm; 
    inStrm = fopen(fileName, "r");
    
    /*These following access counters are going to be used to detected if 
     * a file has duplicate setting, if the access is greater than 1 then  
     * the file has a duplicate setting*/
    mSettingAcess = 0;
    nSettingAcess = 0;
    kSettingAcesss = 0;

    gameSetting = (int*)malloc(sizeof(int));
    gameSettingsStr = (char**)malloc((sizeof(char*)) * MAX_SETTINGS);
    isValidLine = (ValidStatus*)malloc(sizeof(ValidStatus));
    
    /*creating a 2-d an array in order to create an array of strings, so
     * each line read in the file can be stored in each index as a string*/
    createChar2DArray(gameSettingsStr, MAX_SETTINGS, MAX_READ);

    if(inStrm != NULL)
    {
        /*a variable which can be used to count the line numbers in the file 
         * therefore, if an error happens in processing the file, the 
         * error handling methods can determine where the error occured hence,
         * allowing the user to go and fix the error */
        lineCount = 0;
        errorDecteded = FALSE;
        stop = FALSE;
        
        /*choosing to use a while loop instead of a for loop because a while
         *loop gives the function the ability to exit out the loop immedietely  
         *when an error is dectected in the file as a for loop will keep running
         *until it's terminatin number regardless if an error occurs*/
        do
        {
            /*fgets is choosen here becasause I want to be able to detect if
             * they is things in the line which are not meant to be their as
             * fgets gets the whole line. In contrast fscanf only reads in 
             * what it's told to read and doesn't care about the rest of the
             * line */ 
            fgets(line, MAX_READ, inStrm);
            processLine(line, gameSettingsStr, isValidLine);
            lineCount++;

            if(line != NULL && *isValidLine)
            {
                parseChar(gameSettingsStr, gameSetting);
                /*the settings cannot be a negative number or a zero number as 
                 * it doesn't make logical sense to have a game board which has 
                 * negative dimensions or zero*/
                if (*gameSetting > 0)
                {
                    /*the index of [0][0] is going to always be where the 
                     * character of the setting is going to be located if the
                     * file is written in the correct format. Furthermore, the
                     * switch statement allows the file to be read in any order
                     * and allowing the  algorithm the settings in the order of 
                     * m,n,k*/
                    switch(gameSettingsStr[0][0])
                    {
                        case 'M': case 'm':
                            retValue[0] = *gameSetting;
                            mSettingAcess++;
                            break;

                        case 'N': case 'n':
                            retValue[1] = *gameSetting;
                            nSettingAcess++;
                            break;

                        case 'K': case 'k':
                            retValue[2] = *gameSetting;
                            kSettingAcesss++;
                            break;

                        default:
                            printf(RED"line %d:ERROR: invalid  setting format\n"
                            RESET_COLOR, lineCount);
                            errorDecteded = TRUE;
                            /*an error occured hence, we should set the settings
                             * to invalid which is -1, -1, -1 */
                            setInvalid(retValue);
                            break;
                    }
                }
                /*if a setting is 0 or a negative number*/
                else
                {
                    printf(RED"ERROR: setting can't be <= 0:line:%d\n"
                    RESET_COLOR,lineCount); 
                    setInvalid(retValue);
                    errorDecteded = TRUE;
                }
                /*if they is more than 3 settings in the file*/
                if(lineCount == MAX_SETTINGS)
                {
                    printf(RED"ERROR: They is too many settings in the file\n"
                    RESET_COLOR);
                    stop = TRUE;
                }
                /*catching duplicate settings*/
                if(isDuplicates(mSettingAcess, nSettingAcess, kSettingAcesss))
                {
                    setInvalid(retValue);
                    errorDecteded = TRUE;
                    printf(RED"ERROR: duplicate in file found in line:%d\n"
                    RESET_COLOR, lineCount);
                }
                /*just an extra cautios check to ensure that no errors have 
                occured in processing the last line. If an error has occured,
                the function should stop reading in the file */
                if(ferror(inStrm))
                {
                    setInvalid(retValue);
                    printf("line %d", lineCount);
                    perror(":ERROR: in processing last read line ");
                    errorDecteded = TRUE;
                }
            }
            /*if the file is at the end of the stream we need to check if the 
             * requiref max settings are read, if it's less, the file doesn't
             * contain enough settings. If it's greater, it has too many settings
             * albeit the if statements above should've caught this*/
            else if(feof(inStrm))
            {
                if(lineCount != MAX_SETTINGS)
                {
                    setInvalid(retValue);
                    printf(RED"ERORR: not enough settings in file:line%d\n"
                    RESET_COLOR, lineCount);
                    errorDecteded = TRUE;
                }
            }
            /*if the programme gets to this else stament is because 
             * that the exported line is NULL or the exported isValidLine
             * check if false. Hence this can only mean that the setting
             * is not correct format i.e. it could be two letters or two numbers
             * or it could just be a letter and no number hence this else
             * statement is catching invalid arguments read in the file*/
            else
            {
                printf(RED"line %d:ERROR: invalid argument\n"
                RESET_COLOR, lineCount);
                stop = TRUE;
                setInvalid(retValue);
            }

        }while((!errorDecteded) && (!stop));
        fclose(inStrm);
    }
    /*if the stream is NULL and the file doesn't exist*/
    else
    {
        perror(RED"ERORR: file doesn't exist"RESET_COLOR);
        setInvalid(retValue);
    }
    /* we don't need game settings in the progamme anymore as retValue already 
     * has the game settings sorted out in the order of M,N,K */
    free(gameSetting);
    free(isValidLine);
    free2DCharArray(gameSettingsStr, MAX_SETTINGS);

    gameSettingsStr = NULL;
    gameSetting = NULL;
    isValidLine = NULL;
}

/*PURPOSE: to write to a file through the assistance of a function pointer 
 * which will tell how the function will write to a file. Therefore, this 
 * function opens the stream for writing and closes the stream. The function 
 * will return a status which will indicate if it's succesfully written to a
 * file. Which can be used to check if the write has happened or not. This 
 * function is designed to be used with linked list*/
Status writeFile(char *fileName, LinkedList *dataToWrite, filePrintPtr fptr)
{
    Status retStatus;
    FILE *inStrm;
    inStrm = fopen(fileName, "w");
    /*displayToFile is a function which is found in LinkList.c. The function 
     * prints out the contents of th linked list to a file without actually 
     * deleting any of the linked list enteries*/
    retStatus = displayToFile(dataToWrite,inStrm, fptr);
    fclose(inStrm);
    
    return  retStatus;
}

/*PURPOSE: to set the return status of the readGameSettings to invalid which
 * is signfied with -1. Hence, the function will always export an array 
 * with -1 in each of its indexes*/
void setInvalid(int *inArr)
{
    int ii;
    for(ii = 0; ii < MAX_SETTINGS;ii++)
    {
        inArr[ii] = INVALID;
    }
}

/*PURPOSE: is to tokenize a line given the delimeter of '='. The function will
 * tokenize the line into it's character counter part and its integers counter 
 * part otherwise if it cannot do that it should set the lineRead to INVALID
 * which can be used to catch errors in the readGameSettings function*/
void processLine(char *line, char **inArr, ValidStatus *lineRead)
{
    char *tok;
    
    /*get the first token of the line*/
    tok = strtok(line, "=");
    /*if the strtok successfully tokenize the string, the tokenized string
     * should be passed back to the readGameSettings function throught the 
     * import of inArr otherwise, set the line read to invalid*/
    if(tok != NULL)
    {
        strcpy(inArr[0], tok);
        *lineRead = VALID;
    }
    else
    {
        *lineRead  = INVALID;
    }

    tok = strtok(NULL, "\n");
    if(tok != NULL)
    {
        strcpy(inArr[1], tok);
        *lineRead = VALID;
    }
    else
    {
        *lineRead = INVALID;
    }
}

/*PURPOSE: the processed line will return a tokenized string hence, we need
 * to convert that string into a character so we can use the character as
 * switch statment argument to find the  place where it belongs*/
void parseChar(char **inStrArr, int *settingNum)
{
    int num;
    char *check;
    check = NULL;

    num = strtol(inStrArr[1], &check, 10);
    
    /*if the end of the string doesn't equal to the null terminator or an
     * empty space, the string hasn't been processed properly and an error 
     * occured. If does, everything worked well and just as expecteded*/
    if(*check == '\0' || *check == ' ')
    {
        *settingNum = num;
    }
    else
    {
        *settingNum = INVALID;
    }
}

/*PUPROSE: to determine if the file been read in contains an duplicates, by 
 * checking if any of the settings has been accesssed more than once*/
Boolean isDuplicates(int accessNumOne , int accessNumTwo, int accessNumThree)
{
    Boolean duplicate;

    duplicate = FALSE;

    if(accessNumOne > 1 || accessNumTwo > 1 || accessNumThree > 1)
    {
        duplicate = TRUE;
    }

    return duplicate;
}
