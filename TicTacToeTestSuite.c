/*******************************************************************************
 * FILE: TicTacToeSuites.c                                                     *
 * AUTHOR: Tawana David Kwaramba                                               *
 * STUDENT ID: 19476700                                                        *
 * DATE CREATED: 30/09/19                                                      *
 * DATE LAST MODIFIED:                                                         *
 * PURPOSE OF FILE: contains the testing of all functions found in this        *
 *                  programme which comprise of the userInterface and the      *
 *                  main                                                       *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "programmeConstants.h"
#include "myBool.h"
#include "LinkList.h"
#include "fileInterface.h"
#include "gameInterface.h"
#include "logInterface.h"
#include "TicTacToeTestSuite.h"

int main(void)
{
    int *gameSettings;
    LinkedList *testLog;

    gameSettings = (int*)malloc(MAX_SETTINGS * (sizeof(int)));

    printf(BLUE"TEST 1: "RESET_COLOR);
    fileInterfaceTest(gameSettings);

    printf(BLUE"TEST 2: "RESET_COLOR);
    linkedListTest();
    
    printf(BLUE"TEST 3: "RESET_COLOR);
    testLog = displayLogTest();
    
    printf(BLUE"Test 4: "RESET_COLOR);

    printf(BLUE"\nMANUAL TESTING OF THE GAME:\n"RESET_COLOR);
    playGame(gameSettings,NULL);

    free(gameSettings);
    freeLog(testLog, freePrimitives);

    gameSettings = NULL;
    
    return 0;
}

/*PURPOSE: to test possibl files the file interface may be requiref to read in*/
void fileInterfaceTest(int *retSettings)
{
    char *fileName = (char*)malloc(sizeof(char)*50);
    printf("fileInterfaceTest\n");

    /*testing for a file which doesn't exist*/
    strncpy(fileName, "name.txt",9);
    readGameSettings(fileName, retSettings);

    if(retSettings[0] == INVALID && retSettings[1] == INVALID && 
    retSettings[2] == INVALID)
    {
        printf(GREEN"PASSED:"RESET_COLOR" tried to open a file which doesn't exist\n");
    }
    else
    {
        printf(RED"FAILED:"RESET_COLOR" tried to open a file which doesn't exist\n");
    }
    printf("\n");

    /*trying to read in a negative number from a file*/
    strncpy(fileName, "gameSettingsInvalid2.txt",25);
    readGameSettings(fileName, retSettings);

    if(retSettings[0] == INVALID && retSettings[1] == INVALID &&
    retSettings[2] == INVALID)
    {
        printf("PASSED: tried to read a file with a negative value\n");
    }
    else
    {
        printf("FAILED: tried to read a file with a negative value\n");
    }
    printf("\n");

    /*testing gameSetting = 0*/
    strncpy(fileName, "gameSettingsInvalid3.txt",25);
    readGameSettings(fileName, retSettings);
    if(retSettings[0] == INVALID && retSettings[1] == INVALID &&
    retSettings[2] == INVALID)
    {
        printf("PASSED: tried to read game setting = 0\n");
    }
    else
    {
        printf("FAILED: tried to read game setting = 0\n");
    }
    printf("\n");

    /*testing dupilcate settings in file */
    strncpy(fileName, "gameSettingsInvalid4.txt",25); 
    readGameSettings(fileName, retSettings);
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
    readGameSettings(fileName, retSettings);
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
    readGameSettings(fileName, retSettings);

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
    readGameSettings(fileName, retSettings);


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
    
    /*tetsing reading a valid file in the order of m,n,k*/
    strncpy(fileName, "gameSettingsTestValid.txt",26 );
    readGameSettings(fileName, retSettings);
    if(retSettings[0] == 5 && retSettings[1] == 4  && retSettings[2] == 3)
    {
        printf("PASSED: reading a valid file in the order of m,n,k\n");
    }
    else
    {
        printf("FAILED: the fileInterface didn't return the correct numbers\n");
    }
    printf("\n");

    /*testing reading a file of mixed order and mixed captilization*/
    strncpy(fileName, "gameSettingsTestValid2.txt",27);
    readGameSettings(fileName, retSettings);

    if(retSettings[0] == 3 && retSettings[1] == 3 && retSettings[2] == 3)
    {
        printf("PASSED: reading a valid file with; upper cases, lower cases"
        " mixed order of settings\n");

    }
    else 
    {
        printf("FAILED: reading a valid file with; upper cases, lower cases"
        " mixed order of settings\n");
    }
    printf("\n");

	free(fileName);
	fileName = NULL;
}

/*PURPOSE: to test if the linked list is functioning properly i.e. if all its
 * methods are working properly*/
void linkedListTest()
{
    /*code adapted from practical 7 submission */
    char* value;
    char *input1 = (char*)malloc(sizeof(char)*6);
    char *input2 = (char*)malloc(sizeof(char)*4);
    char *input3 = (char*)malloc(sizeof(char)*9);
    char *input4 = (char*)malloc(sizeof(char)*8);


    LinkedList* list = NULL;

    
    printf("Linked list test\n");

    strncpy(input1, "hello",6);
    strncpy(input2, "bye",4);
    strncpy(input3, "Mercedes",9);
    strncpy(input4, "Nissian",8);

    /*CREATING*/
    printf("Creating List: ");
    list = createLinkedList();
    if(list == NULL || list->head != NULL || list -> tail != NULL)
    {
        printf("FAILED\n");
    }
    else
    {
        printf("PASSED\n");
    }
    
    printf("count: %d\n", list -> count);
    /*INSERTING FIRST*/
    printf("Inserting First: ");
    insertFirst(list,input1);
    if(list->head == NULL)
    {
        printf("FAILED\n");
    }
    else if(strncmp((char*)list->head->value, input1, strlen(input1)+1)==0)
    {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }

    display(list, printString);
    printf("count: %d\n", list -> count);

    printf("Inserting First (2): ");
    insertFirst(list,input2);
    if(list->head == NULL)
    {
        printf("FAILED\n");
    }
    else if(strncmp((char*)list->head->value, input2, strlen(input2)+1)==0 && 
        strncmp((char*)list->tail->value, input1, strlen(input1)+1)==0)
    {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }

    display(list, printString);
    printf("count: %d\n", list -> count);

    /*INSERTING LAST*/
    printf("Inserting last ");
    insertLast(list, input3);
    if(list->head == NULL)
    {
        printf("FAILED\n");
    }
    else if(strncmp((char*)list->tail->value, input3, strlen(input3)+1)==0)
    {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }

    display(list, printString);
    printf("count: %d\n", list -> count);

    printf("Inserting last (2) ");
    insertLast(list, input4);
    if(list -> head == NULL)
    {
        printf("FAILED\n");
    }
    else if (strncmp((char*)list->tail->value, input4, strlen(input4)+1)==0 &&
      strncmp((char*)list->tail->prevRef->value, input3, strlen(input3)+1)==0)
    {
        printf("PASSED\n");
    }
    else
    { 
        printf("FAILED\n");
    }
    

    display(list, printString);
    printf("count: %d\n", list -> count);

    /*REMOVING LAST*/
    removeLast(list);
    value = (char*)removeLast(list);

    printf("remove last :");
    if(list -> head == NULL || list -> tail == NULL)
    {
        printf("FALIED\n");
    }
    else if (strncmp(value, input3, strlen(input3)+1)==0)
    {
        printf("PASSED\n");
    }

    printf("count: %d\n", list -> count);
    free(value);

    display(list, printString);
    /*REMOVING FIRST*/
    printf("Remove First: ");
    value = (char*)removeFirst(list);

    if(strncmp(value, input2, strlen(input2)+1) == 0)
    {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }
    printf("count: %d\n", list -> count);

    free(value);
    
    display(list, printString);
    
    /*REMOVING with only one element on the list*/
    printf("Remove Last (2): with only one element on the list: ");
    value = (char*)removeLast(list);
    if(strncmp(value, input1, strlen(input1)+1) == 0)
    {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }
    printf("count: %d\n", list -> count);
    free(value);

    display(list, printString);
    
    /*INSERTING*/ 
    printf("inserting element..\n");
    insertLast(list, input4);
    display(list, printString);
    printf("Remove first (2): with only one element on the list: ");
    value = (char*)removeFirst(list);
    if(strncmp(value, input4, strlen(input4)+1) == 0)
    {

        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }
    display(list, printString);
    printf("count: %d\n", list -> count);
    free(value);


    /*FREEING*/
    freeLinkedList(list, freePrimitives);
}

/*PURPOSE: testing if the log will display the information in the right format
 * to the terminal*/
LinkedList* displayLogTest()
{
    int ii, logCount, turn, pos[2], *numMoves, *gameNum;
    char playerOne, playerTwo;
    LinkedList *testGameLog;

    /*to be used to simulate players moves. These numbers are not meant to be
     * taken seriously they're  just random numbers*/
    int logMovesOne[32] = {2,1,0,0,2,0,2,2,1,1,0,1,0,2,2,3,1,3,1,2,1,0,3,0,3,1,
                           3,2,0,2,3,3};
    int logMovesTwo[28] = {0,0,2,1,5,4,4,5,5,3,2,1,9,3,2,6,6,7,3,2,3,5,6,3,5
                          ,5,6,9}; 
    int randomSettings[3] = {10, 10, 3};
    testGameLog = NULL;
    numMoves = (int*)malloc(sizeof(int));
    gameNum = (int*)malloc(sizeof(int));
    
    /*displaying log test*/
    printf("display Log test\n");
    
    turn = 1;
    logCount = 0;
    *gameNum = 1;
    *numMoves = 0;
    pos[0] = -1;
    pos[1] = -1;
    
    playerOne = 'X';
    playerTwo = 'O';

    testGameLog = createGameLog();
    
    /*logging the start of the games*/
    logGameSettings(testGameLog, randomSettings);
    logGameNum(testGameLog, gameNum);

    for(ii = 0; ii < 16; ii++)
    {
		pos[0] = logMovesOne[logCount];
		pos[1] = logMovesOne[logCount + 1]; 
		(*numMoves)++;
		logCount = logCount + 2;

        if(turn == 1)
        {
            logGamePlay(testGameLog, pos, playerOne, numMoves);
            turn = 2;
        }
        else if (turn == 2)
        {
            logGamePlay(testGameLog, pos, playerTwo, numMoves);
            turn = 1;
        }
    }
    
    displayLog(testGameLog, printLogStruct);

    *gameNum = 2;
    logGameNum(testGameLog, gameNum);
    *numMoves = 0;


    printf("Simulating the start of another game\n");

    for(ii = 0; ii < 14; ii++)
    {
		pos[0] = logMovesTwo[logCount];
		pos[1] = logMovesTwo[logCount + 1]; 
		(*numMoves)++;
		logCount = logCount + 2;

        if(turn == 1)
        {
            logGamePlay(testGameLog, pos, playerOne, numMoves);
            turn = 2;
        }
        else if (turn == 2)
        {
            logGamePlay(testGameLog, pos, playerTwo, numMoves);
            turn = 1;
        }
    }

    displayLog(testGameLog, printLogStruct);

    free(gameNum);
    free(numMoves);

    numMoves = NULL;
    gameNum = NULL;

    return testGameLog;
}

/*PURPOSE: to test if the supporting functions can write the logs as they're
 * showed on screen to a file*/
void writingLogFileTest(LinkedList *inLog)
{
    Status result;
    char test[9], *fileName;
    int *randomTestSettings;

    randomTestSettings = (int*)malloc(sizeof(int) * MAX_SETTINGS);
    randomTestSettings[0] = 10;
    randomTestSettings[1] = 10;
    randomTestSettings[2] = 3;

    strcpy(test, "test.log"); 
    printf("Writing to a log file test\n");

    result = writeFile(test, inLog, printLogStructToFile);

    if(result == Success)
    {
        printf("writing a log to a file: PASSED");
    }
    else if(result == Failed)
    {
        printf("writing a log to a file: FAILED");
    }

    printf("writing another log...\nTesting if generate log name is working");
    fileName = generateLogName(randomTestSettings);

    result = writeFile(fileName, inLog, printLogStructToFile);


    if(result == Success)
    {
        printf("writing a log to and saved using the appropriate name: PASSED");
    }
    else if(result == Failed)
    {
        printf("writing a log to a file and saved using the appropriate name: FAILED");
    }

    free(fileName);
    free(randomTestSettings);

    fileName = NULL;
    randomTestSettings = NULL;
}
