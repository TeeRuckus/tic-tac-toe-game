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
char* readGameSettings(char *fileName)
{
    FILE *inStrm; 
    inStrm = fopen(fileName, "r");
    if(inStrm != NULL)
    {
        /*a variable which can count the line numbers in the file therefore, if
        an error happens in processing the file, the error handling methods can
        determine where the error occured */
        int lineCount, ii, errorDecteded, stop, numReturned, settingIndex;
        int **M, **N, **K;
        char settingUpper;

        lineCount = 0;
        settingIndex = 0;
        errorDecteded = FALSE;
        stop = FALSE;
        
        /*multiplying MAX_SETTINGS by 2 as the name of the settings is going to
        be stored inside here as characters are represented by integers 
        therefore the format is <setting name>,<setting value> */
        int *gameSettings = (int*)malloc((MAX_SETTINGS*2) * sizeof(int));

        /*choosing to use a while loop instead of a for loop because a while
        loop gives the function the ability to exit out the loop immedietely  
        when an error is dectected in the file*/
        do
        {
            numReturned = fscanf(inStrm, "%c=%d",gameSettings[settingIndex], 
                                gameSettings[settingIndex + 1]);
            lineCount++;
            if(numReturned == 2)
            {
                settingUpper = myToUpper(settingIndex);
                switch(settingUpper)
                {
                    case 'M':
                        /*we want the game setting, to actually point to the 
                        value of its setting */
                        M = gameSettings[settingIndex + 1];
                        break;

                    case 'N':
                        N = gameSettings[settingIndex +1];
                        break;

                    case 'K':
                        K = gameSettings[settingIndex +1];
                        break;

                    default:
                        printf("%d:ERROR: invalid  setting format", lineCount);
                        errorDecteded = TRUE;
                        break;
                }
                if(count == MAX_LINES)
                {
                    stop = TRUE;
                }
                /*just an extra cautios check to ensure that no errors have 
                occured in processing the last line. If an error has occured,
                the function should stop reading in the file */
                if(ferror(inStrm))
                {
                    printf("%d " count);
                    perror(":ERROR: in processing last read line ");
                    errorDecteded = TRUE;
                }
            }
            else if(feof(inStrm))
            {
                if(count != MAX_LINES)
                {
                    printf("ERORR: not enough settings in file\n");
                    errorDecteded = TRUE;
                }
            }
            else
            {
                printf("ERROR: in settings file\n");
            }

        }while((!errorDecteded) && (!stop));
    }
    else
    {
        perror("ERORR: file doesn't exist - ");
    }
    fclose(inStrm);
    return settingValues;
}

void freeFileInterFace()
{
    free(gameSettings);
}
