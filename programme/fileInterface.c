#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileInterface.h"
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
    int *retValue, *gameSettings;
    int lineCount, errorDecteded, stop, /*numReturned,*/ settingIndex;
    /*char settingUpper;*/
    char /*settingChar,*/ line[MAX_READ];
    FILE *inStrm; 
    inStrm = fopen(fileName, "r");
    if(inStrm != NULL)
    {
        /*a variable which can count the line numbers in the file therefore, if
        an error happens in processing the file, the error handling methods can
        determine where the error occured */

        lineCount = 0;
        settingIndex = 0;
        errorDecteded = FALSE;
        stop = FALSE;
        
        /*multiplying MAX_SETTINGS by 2 as the name of the settings is going to
        be stored inside here as characters are represented by integers 
        therefore the format is <setting name>,<setting value> */
        gameSettings = (int*)malloc((sizeof(int)) * (MAX_SETTINGS*2));
        retValue = (int*)malloc((sizeof(int)) * MAX_SETTINGS);
        /*M = (int**)malloc(sizeof(int*));
        N = (int**)malloc(sizeof(int*));
        K = (int**)malloc(sizeof(int*));*/

        /*choosing to use a while loop instead of a for loop because a while
        loop gives the function the ability to exit out the loop immedietely  
        when an error is dectected in the file*/
        do
        {
            /*numReturned = fscanf(inStrm, "%d=%d",&gameSettings[settingIndex], 
                                &gameSettings[settingIndex + 1]);*/
            fgets(line, MAX_READ, inStrm);
            processLine(line);
            lineCount++;
            if(line != NULL)
            {
                parseLine(line, gameSettings);
                switch(line[0])
                {
                    case 'M': case 'm':
                        /*we want the game setting, to actually point to the 
                        value of its setting */
                        retValue[0] = gameSettings[1];
                        break;

                    case 'N': case 'n':
                        retValue[1] = gameSettings[1];
                        break;

                    case 'K': case 'k':
                        retValue[2] = gameSettings[1];
                        break;

                    default:
                        printf("line %d:ERROR: invalid  setting format", lineCount);
                        errorDecteded = TRUE;
                        break;
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
                /*settingIndex = settingIndex + 2;*/
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
    }
    else
    {
        perror("ERORR: file doesn't exist - ");
    }
    /*retValue[0] = M;
    retValue[1] = N; 
    retValue[2] = K;*/
    fclose(inStrm);
    /* we don't need game settings anymore as retValue already has the game S
    settings sorted out in the order of M,N,K */
    free(gameSettings);
    /*free(M);
    free(N);
    free(K);*/

    gameSettings = NULL;
    /*M = NULL;
    N = NULL;
    K = NULL;*/

    return retValue;
}

void processLine(char *line)
{
    int tokCount, stop;
    char *retToks, *tok;
    retToks = (char*)malloc(sizeof(char) * MAX_READ);
    /*tok = (char*)malloc(sizeof(char) * 2);*/
    tokCount = 0;
    stop = FALSE;
    
    /*get the first token of line*/
    tok = strtok(line, "=");
    strcpy(&retToks[0], tok);
    tokCount++;

    /*checking if there's anything else in the line */
   /* while(tok != NULL && (!stop))
    {
        tokCount++;
        if(tokCount > 3)
        {
            stop = TRUE;
            retToks = NULL;
        }
        else
        {
            tok = strtok(NULL, " ");
            strcpy(&retToks[tokCount], tok);
        }

    }*/

    tok = strtok(NULL, " ");
    strcpy(&retToks[2], tok);

    strcpy(line, retToks);

    free(retToks);
    /*free(tok);*/
    retToks = NULL;
    tok = NULL;
}

/*CHANGE THIS TO parseChar */ 
void parseLine(char *line, int *inArr)
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

    int parsedInt;
    parsedInt = line[2] - '0';
    inArr[1] = parsedInt;
}
