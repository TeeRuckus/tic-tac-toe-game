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

    gameSettings = (int*)malloc(sizeof(int) * MAX_SETTINGS);
    numPassed = (int*)malloc(sizeof(int));

    numTests = 0;
    *numPassed = 0;

    numTests++;
    printf("TEST 1: ");
    fileInterfaceTest(gameSettings, numPassed);

	numTests++;
    printf("TEST :\n");
    playGame(gameSettings);

    free(gameSettings);
    free(numPassed);

    gameSettings = NULL;
    numPassed = NULL;

    return 0;
}

void fileInterfaceTest(int *gameSettings, int *numPassed)
{
    char *fileName = (char*)malloc(sizeof(char)*26);
    printf("fileInterfaceTest\n");
    strncpy(fileName, "gameSettingsTestValid.txt",26 );
    gameSettings = readGameSettings(fileName);

	/*if(*(*(*(retVal + 0))) == 5  && *(*(*(retVal + 1))) == 4 
	&& *(*(*(retVal + 2))))*/

    if(gameSettings[0] == 4 && gameSettings[1] == 5  && gameSettings[2] == 3)
    {
        printf("PASSED: reading a valid file in the order of m,n,k\n");
        (*numPassed)++;
    }

	free(fileName);
	fileName = NULL;
}
