#include <stdio.h>
#include <stdlib.h>
#include "myBool.h"
#include <string.h>
#include "fileInterface.h"
#include "gameLogic.h"
#include "memoryInterface.h"
/*#include "myString.h"*/

/*PURPOSE: to read in a game settings file which adheres to the following format
M=<integer> 
N=<integer>
K=<interger>.
The function is white space sensitive and line sensitive hence, for a file to
be correct, it must strictly adhere to the format given above.
whereby the characters in the folder are case insentive and can be placed in any
order. Additionally, if an error occurs during reading the settings, the
programme will stop*/

void readGameSettings(char *fileName, int *retValue)
{
    int *gameSetting, mSettingAcess, nSettingAcess, kSettingAcesss,
    lineCount;
    Boolean errorDecteded, stop;
    ValidStatus *isValidLine;

    char line[MAX_READ], **gameSettingsStr;
    FILE *inStrm; 
    inStrm = fopen(fileName, "r");

    mSettingAcess = 0;
    nSettingAcess = 0;
    kSettingAcesss = 0;

    gameSetting = (int*)malloc(sizeof(int));
    gameSettingsStr = (char**)malloc((sizeof(char*)) * MAX_SETTINGS);
    isValidLine = (ValidStatus*)malloc(sizeof(ValidStatus));

    createChar2DArray(gameSettingsStr, MAX_SETTINGS, MAX_READ);

    if(inStrm != NULL)
    {
        /*a variable which can count the line numbers in the file therefore, if
        an error happens in processing the file, the error handling methods can
        determine where the error occured */
        lineCount = 0;
        errorDecteded = FALSE;
        stop = FALSE;
        
        /*choosing to use a while loop instead of a for loop because a while
        loop gives the function the ability to exit out the loop immedietely  
        when an error is dectected in the file*/
        do
        {
            fgets(line, MAX_READ, inStrm);
            processLine(line, gameSettingsStr, isValidLine);
            lineCount++;
            if(line != NULL && *isValidLine)
            {
                parseLine(gameSettingsStr, gameSetting);
                /*if the gameSetting is a positive number*/
                if (*gameSetting > 0)
                {
                    switch(gameSettingsStr[0][0])
                    {
                        case 'M': case 'm':
                            /*we want the game setting, to actually point to the 
                            value of its setting */
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
                            printf("line %d:ERROR: invalid  setting format\n", lineCount);
                            errorDecteded = TRUE;
                            setInvalid(retValue);
                            break;
                    }
                }
                else
                {
                    printf("ERROR: setting can't be <= 0:line:%d\n",lineCount); 
                    setInvalid(retValue);
                    errorDecteded = TRUE;
                }
                if(lineCount == MAX_SETTINGS)
                {
                    stop = TRUE;
                }
                if(isDuplicates(mSettingAcess, nSettingAcess, kSettingAcesss))
                {
                    setInvalid(retValue);
                    errorDecteded = TRUE;
                    printf("ERROR: duplicate in file found in line:%d\n",
                    lineCount);
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
            else if(feof(inStrm))
            {
                if(lineCount != MAX_SETTINGS)
                {
                    setInvalid(retValue);
                    printf("ERORR: not enough settings in file\n");
                    errorDecteded = TRUE;
                }
            }
            else
            {
                /*THIS ERROR MESSAGE CAN BE MISLEADIN*/
                printf("line %d:ERROR: too many arguments\n", lineCount);
                stop = TRUE;
                setInvalid(retValue);
            }

        }while((!errorDecteded) && (!stop));
        fclose(inStrm);
    }
    else
    {
        perror("ERORR: file doesn't exist");
        setInvalid(retValue);
    }
    /* we don't need game settings anymore as retValue already has the game S
    settings sorted out in the order of M,N,K */

    free(gameSetting);
    free(isValidLine);
    free2DCharArray(gameSettingsStr, MAX_SETTINGS);

    gameSettingsStr = NULL;
    gameSetting = NULL;
    isValidLine = NULL;

}

void setInvalid(int *inArr)
{
    int ii;
    for(ii = 0; ii < MAX_SETTINGS;ii++)
    {
        inArr[ii] = INVALID;
    }
}

void processLine(char *line, char **inArr, ValidStatus *lineRead)
{
    char *tok;
    
    /*get the first token of line*/
    tok = strtok(line, "=");
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

/*CHANGE THIS TO parseChar */ 
void parseLine(char **inStrArr, int *settingNum)
{
    int num;
    char *check;
    check = NULL;

    num = strtol(inStrArr[1], &check, 10);

    if(*check == '\0' || *check == ' ')
    {
        *settingNum = num;
    }
    else
    {
        *settingNum = INVALID;
    }
    
    /*free(check);
    check = NULL;*/ 
}

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
