#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TicTacToeTestSuite.h"
#include "fileInterface.h"
#include "gameInterface.h"

int main(void)
{
    int numTests, *numPassed, *gameSettings;
    /*int gameSettings[2] = {5,7};*/

    gameSettings = (int*)calloc(MAX_SETTINGS, sizeof(int));
    numPassed = (int*)malloc(sizeof(int));

    numTests = 0;
    *numPassed = 0;

    numTests++;
    printf("TEST 1: ");
    gameSettings = fileInterfaceTest(numPassed);

	numTests++;
    printf("TEST :\n");
    playGame(gameSettings);

    free(gameSettings);
    free(numPassed);

    gameSettings = NULL;
    numPassed = NULL;

    return 0;
}

int *fileInterfaceTest(int *numPassed)
{
    char *fileName = (char*)malloc(sizeof(char)*26);
    int *retSettings = (int*)malloc(sizeof(int) * MAX_SETTINGS); 
    printf("fileInterfaceTest\n");
    strncpy(fileName, "gameSettingsTestValid.txt",26 );
    retSettings = readGameSettings(fileName);

	/*if(*(*(*(retVal + 0))) == 5  && *(*(*(retVal + 1))) == 4 
	&& *(*(*(retVal + 2))))*/

    if(retSettings[0] == 5 && retSettings[1] == 4  && retSettings[2] == 3)
    {
        printf("PASSED: reading a valid file in the order of m,n,k\n");
        (*numPassed)++;
    }
    else
    {
        printf("FAILED: the fileInterface didn't return the correct numbers\n");
    }

	free(fileName);
	fileName = NULL;

    return retSettings;
}
