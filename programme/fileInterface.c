#include <stdio.h>
#include <stdlib.h>
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

int* readGameSettings(char *fileName)
{
    int *retValue, *gameSetting;
    int lineCount, errorDecteded, stop, settingIndex;
    char line[MAX_READ], **gameSettingsStr;
    FILE *inStrm; 
    inStrm = fopen(fileName, "r");

    gameSetting = (int*)malloc(sizeof(int));
    gameSettingsStr = (char**)malloc((sizeof(char*)) * MAX_SETTINGS);
    retValue = (int*)malloc((sizeof(int)) * MAX_SETTINGS);
    if(inStrm != NULL)
    {
        /*a variable which can count the line numbers in the file therefore, if
        an error happens in processing the file, the error handling methods can
        determine where the error occured */

        lineCount = 0;
        settingIndex = 0;
        errorDecteded = FALSE;
        stop = FALSE;
        
        createChar2DArray(gameSettingsStr, MAX_SETTINGS, MAX_READ);
        /*choosing to use a while loop instead of a for loop because a while
        loop gives the function the ability to exit out the loop immedietely  
        when an error is dectected in the file*/
        do
        {
            fgets(line, MAX_READ, inStrm);
            processLine(line, gameSettingsStr);
            lineCount++;
            if(line != NULL)
            {
                parseLine(gameSettingsStr, gameSetting);
                if (*gameSetting > 0)
                {
                    switch(gameSettingsStr[0][0])
                    {
                        case 'M': case 'm':
                            /*we want the game setting, to actually point to the 
                            value of its setting */
                            retValue[0] = *gameSetting;
                            break;

                        case 'N': case 'n':
                            retValue[1] = *gameSetting;
                            break;

                        case 'K': case 'k':
                            retValue[2] = *gameSetting;
                            break;

                        default:
                            printf("line %d:ERROR: invalid  setting format", lineCount);
                            errorDecteded = TRUE;
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
                /*just an extra cautios check to ensure that no errors have 
                occured in processing the last line. If an error has occured,
                the function should stop reading in the file */
                if(ferror(inStrm))
                {
                    printf("line %d", lineCount);
                    perror(":ERROR: in processing last read line ");
                    errorDecteded = TRUE;
                }
            }
            else if(feof(inStrm))
            {
                if(lineCount != MAX_SETTINGS)
                {
                    printf("ERORR: not enough settings in file\n");
                    errorDecteded = TRUE;
                }
            }
            else
            {
                printf("line %d:ERROR: too many arguments\n", lineCount);
                stop = TRUE;
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
    free(gameSettingsStr);

    gameSettingsStr = NULL;
    gameSetting = NULL;

    return retValue;
}

void setInvalid(int *inArr)
{
    int ii;
    for(ii = 0; ii < MAX_SETTINGS;ii++)
    {
        inArr[ii] = INVALID;
    }
}
void processLine(char *line, char **inArr)
{
    /*char *retToks, *tok;
    retToks = (char*)malloc(sizeof(char) * MAX_READ);
    tokCount = 0;
    stop = FALSE;*/
    char *tok;
    
    /*get the first token of line*/
    tok = strtok(line, "=");
    strcpy(inArr[0], tok);

    tok = strtok(NULL, "\n");
    strcpy(inArr[1], tok);

    /*strcpy(line, retToks);

    free(retToks);
    retToks = NULL;
    tok = NULL;*/
}

/*CHANGE THIS TO parseChar */ 
void parseLine(char **inStrArr, int *settingNum)
{
    /*int retOne;
    char *check = (char*)malloc(sizeof(char) * MAX_READ);
    retOne = strtol((&line[2]), &check, MAX_READ);
    if(*check == '\0')
    {
        inArr[1] = retOne;
    }
    else
    {
        inArr[0] = 0;
        inArr[1] = 0;
    }*/

    /*int parsedInt;
    parsedInt = line[2] - '0';
    inArr[1] = parsedInt;*/

    int num;
    char *check = (char*)malloc(sizeof(char) * MAX_READ);

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
