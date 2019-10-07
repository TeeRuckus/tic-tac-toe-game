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
    char *fileName = (char*)malloc(sizeof(char)*50);
    int *retSettings = (int*)malloc(sizeof(int) * MAX_SETTINGS); 
    printf("fileInterfaceTest\n");

    /*testing for a file which doesn't exist*/
    strncpy(fileName, "name.txt",9);
    retSettings = readGameSettings(fileName);

    if(retSettings[0] == INVALID && retSettings[1] == INVALID && 
    retSettings[2] == INVALID)
    {
        printf("PASSED: tried to open a file which doesn't exist\n");
    }
    else
    {
        printf("FAILED: tried to open a file which doesn't exist\n");
    }
    printf("\n");

    /*trying to read in a negative number from a file*/
    strncpy(fileName, "gameSettingsInvalid2.txt",25);
    retSettings = readGameSettings(fileName);

    if(retSettings[0] == INVALID && retSettings[1] == INVALID &&
    retSettings[2] == INVALID)
    {
        printf("PASSED: tried to read a file with a negative value\n");
        (*numPassed)++;
    }
    else
    {
        printf("FAILED: tried to read a file with a negative value\n");
    }
    printf("\n");

    /*testing gameSetting = 0*/
    strncpy(fileName, "gameSettingsInvalid3.txt",25);
    retSettings = readGameSettings(fileName);
    if(retSettings[0] == INVALID && retSettings[1] == INVALID &&
    retSettings[2] == INVALID)
    {
        printf("PASSED: tried to read game setting = 0\n");
        (*numPassed)++;
    }
    else
    {
        printf("FAILED: tried to read game setting = 0\n");
    }
    printf("\n");

    /*testing dupilcate settings in file */
    strncpy(fileName, "gameSettingsInvalid4.txt",25); 
    retSettings = readGameSettings(fileName);
    if(retSettings[0] == INVALID && retSettings[1] == INVALID &&
    retSettings[2] == INVALID)
    {
        printf("PASSED: dupilcate in the file found\n");
    }
    else
    {
        printf("FAILED: dupilcate in the file found\n");
    }
    printf("\n");

    /*testing setting with random text in it*/
    strncpy(fileName, "gameSettingsInvalid.txt",24);
    retSettings = readGameSettings(fileName);
    if(retSettings[0] == INVALID && retSettings[1] == INVALID &&
    retSettings[2] == INVALID)
    {
        printf("PASSED: tried to read in a file with incomplete settings\n");
    }
    else
    {
        printf("FAILED: tried to read in a file with incomplete settings\n");
    }
    printf("\n");

    /*testing a file with only one setting in it*/
    strncpy(fileName, "gameSettingsInvalid5.txt",25);
    retSettings = readGameSettings(fileName);

    if(retSettings[0] == INVALID && retSettings[1] == INVALID &&
    retSettings[2] == INVALID)
    {
        printf("PASSED: tried to read in a file with only one setting in it\n");
    }
    else
    {
        printf("FAILED: tried to read in a file with only one setting in it\n");
    }
    printf("\n");

    /*testing a file which has an invalid setting name*/
    strncpy(fileName, "gameSettingsInvalid6.txt",25);
    retSettings = readGameSettings(fileName);


    if(retSettings[0] == INVALID && retSettings[1] == INVALID &&
    retSettings[2] == INVALID)
    {
        printf("PASSED: tried reading a file with invalid setting p\n");
    }
    else
    {
        printf("FAILED: tried reading a file with invalid setting p\n");
    }
    printf("\n");

    strncpy(fileName, "gameSettingsTestValid.txt",26 );
    retSettings = readGameSettings(fileName);
    if(retSettings[0] == 5 && retSettings[1] == 4  && retSettings[2] == 3)
    {
        printf("PASSED: reading a valid file in the order of m,n,k\n");
        (*numPassed)++;
    }
    else
    {
        printf("FAILED: the fileInterface didn't return the correct numbers\n");
    }
    printf("\n");

    strncpy(fileName, "gameSettingsTestValid2.txt",27);
    retSettings = readGameSettings(fileName);

    if(retSettings[0] == 10 && retSettings[1] == 5 && retSettings[2] == 4)
    {
        printf("PASSED: reading a valid file with; upper cases, lower cases"
        " mixed order of settings\n");
        (*numPassed)++;

    }
    else 
    {
        printf("FAILED: reading a valid file with; upper cases, lower cases"
        " mixed order of settings\n");
    }
    printf("\n");

	free(fileName);
	fileName = NULL;

    return retSettings;
}
