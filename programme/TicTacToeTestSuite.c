#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TicTacToeTestSuite.h"
#include "fileInterface.h"
#include "gameInterface.h"

int main(void)
{
    int numTests, numPassed;
    int gameSettings[2] = {5,7};

    numTests = 0;
    numPassed = 0;

	numTests++;
    printf("TEST 1:\n");
    playGame(gameSettings);

    return 0;
}

/*void fileInterfaceTest(int numPassed)
{
    int ***retVal;
    char *fileName = (char*)malloc(sizeof(char)*26);
    strncpy(fileName, "gameSettingsTestValid.txt",26 );
    retVal = readGameSettings(fileName);

	if(*(*(*(retVal + 0))) == 5  && *(*(*(retVal + 1))) == 4 
	&& *(*(*(retVal + 2))))
    {
        printf("PASSED: reading a valid file in the order of m,n,k\n");
        numPassed++;
    }

    freeFileInterFace(retVal);
	free(fileName);
	fileName = NULL;
}*/
