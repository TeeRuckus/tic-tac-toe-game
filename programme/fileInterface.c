#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileInterface.h"
#include "myString.h"

/*PURPOSE: to read in a game settings file which adheres to the following format
M=<integer> 
N=<integer>
K=<interger>.
The function is white space sensitive and line sensitive hence, for a file to
be correct, it must strictly adhere to the format given above.
whereby the characters in the folder are case insentive and can be placed in any
order. Additionally, if an error occurs during reading the settings, the
programme will stop*/

int*** readGameSettings(char *fileName)
{
    int **M, **N, **K, ***retValue, **gameSettings;
    char settingUpper;
    FILE *inStrm; 
    inStrm = fopen(fileName, "r");
    if(inStrm != NULL)
    {
        /*a variable which can count the line numbers in the file therefore, if
        an error happens in processing the file, the error handling methods can
        determine where the error occured */
        int lineCount, errorDecteded, stop, numReturned, settingIndex;

        lineCount = 0;
        settingIndex = 0;
        errorDecteded = FALSE;
        stop = FALSE;
        
        /*multiplying MAX_SETTINGS by 2 as the name of the settings is going to
        be stored inside here as characters are represented by integers 
        therefore the format is <setting name>,<setting value> */
        gameSettings = (int**)malloc((sizeof(int*)) * (MAX_SETTINGS*2));
        retValue = (int***)malloc((sizeof(int**)) * MAX_SETTINGS);
        M = (int**)malloc(sizeof(int*));
        N = (int**)malloc(sizeof(int*));
        K = (int**)malloc(sizeof(int*));

        /*choosing to use a while loop instead of a for loop because a while
        loop gives the function the ability to exit out the loop immedietely  
        when an error is dectected in the file*/
        do
        {
            numReturned = fscanf(inStrm, "%d=%d",gameSettings[settingIndex], 
                                gameSettings[settingIndex + 1]);
            lineCount++;
            if(numReturned == 2)
            {
                settingUpper = myToUpper(*(gameSettings[settingIndex]));
                switch(settingUpper)
                {
                    case 'M':
                        /*we want the game setting, to actually point to the 
                        value of its setting */
                        M = (gameSettings + settingIndex + 1);
                        break;

                    case 'N':
                        N = (gameSettings + settingIndex + 1);
                        break;

                    case 'K':
                        K = (gameSettings + settingIndex + 1);
                        break;

                    default:F
                        printf("line %d:ERROR: invalid  setting format", lineCount);
                        errorDecteded = TRUE;
                        break;
                }
                if(lineCount == MAX_LINES)
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
                settingIndex = settingIndex + 2;
            }
            else if(feof(inStrm))
            {
                if(lineCount != MAX_LINES)
                {
                    printf("ERORR: not enough settings in file\n");
                    errorDecteded = TRUE;
                }
            }
            else
            {
                printf("line %d:ERROR: in settings file\n", lineCount);
                stop = TRUE;
            }

        }while((!errorDecteded) && (!stop));
    }
    else
    {
        perror("ERORR: file doesn't exist - ");
    }
    retValue[0] = M;
    retValue[1] = N; 
    retValue[2] = K;
    fclose(inStrm);
    /* we don't need game settings anymore as retValue already has the game S
    settings sorted out in the order of M,N,K */
    free(gameSettings);
    free(M);
    free(N);
    free(K);

    gameSettings = NULL;
    M = NULL;
    N = NULL;
    K = NULL;

    return retValue;
}

/*PURPOSE: is to free all dynamically allocated memory by the fileInterface.
The rational behind this is that the vales read in by the fileInterface 
need to be used thorughout the whole programme, and we need the value read even
after the readGameSettings function returns*/
void freeFileInterFace(int ***gameValues)
{
    free(gameValues);
    gameValues = NULL;
}
