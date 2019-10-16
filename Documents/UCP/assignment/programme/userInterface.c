/*******************************************************************************
 * file: userinterface.c                                                       *
 * author: tawana david kwaramba                                               *
 * student id: 19476700                                                        *
 * date created: 30/09/19                                                      *
 * date last modified:                                                         *
 * purpose of file: this is where all the interfaces meet in one location to   *
 *                  make the programme. i.e. this file exposes the user to     *
 *                  the functionallity of the programme.                       *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInterface.h"
#include "programmeConstants.h"
#include "myBool.h"
#include "LinkList.h"
#include "fileInterface.h"
#include "gameInterface.h"
#include "logInterface.h"
/*PURPOSE: to expose the functionality of the programm to the user. Furthermore,
it serves as a container for other function calls thus, it's the driving force
behind the programme */
void userInterface(int *gameSettings)
{
    int userSel, stop, valid, *gameNum;
    char *fileName;
    Status result;
    Boolean hasLogAccessed;
    LinkedList *gameLog;

    #ifdef Secret
    printf("----------------------------------------------------------------\n");
    printf("You have entered into secret mode: You have lost th ability to save"
    " logs. You may only view the logs. Keep everything a secret shhhhhh....\n");
    printf("----------------------------------------------------------------\n");
    #endif

    #ifdef Editor
    printf("----------------------------------------------------------------\n");
    printf("You have enteted into edtor mode. You may change the settings of"
    " the game in the menu... I bestow you with the power of this game\n");
    printf("----------------------------------------------------------------\n");
    #endif
    

    /*to allow the algorithm to prompt the user that the game log hasn't been
     * saved. To enusure that data is not lost*/
    stop = FALSE;
    gameNum = (int*)malloc(sizeof(int)); 
    gameLog = createGameLog();
    hasLogAccessed = FALSE;
    *gameNum = 0;

    logGameSettings(gameLog, gameSettings);
    logGameNum(gameLog, gameNum);

    /*menu options*/
    printf("1: Start a new game\n"
    "2: View the settings of the game\n"
    "3: View the current log\n"
    "4: Save the logs to a file\n"
    "5: Exit the application\n");

    #ifdef Editor
    printf("6) Change game settings\n");
    #endif


    printf("Enter option:\n");
    do
    {
        scanf(" %d", &userSel);
        valid = validateInput(userSel);

        if(valid)
        {
            switch(userSel)
            {
                case 1:
                    printf("Starting a new game....\n");
                    playGame(gameSettings, gameLog);
                    /*every time the game finishs means that our log has to be 
                     * updated and we have to prompt the user before he exited
                     * that there's new data and he must not forget to save
                     * his wor*/
                    hasLogAccessed = FALSE;
                    break;

                case 2:
                    displayCurrentSettings(gameSettings); 
                    break;

                case 3:
                    printf("Viewing the current logs\n");
                    displayLog(gameLog, printLogStruct);
                    break;
                
                case 4:
                    #ifdef Editor
                    printf(RED"THIS option is disabled while in editor mode\n"
                    RESET_COLOR);
                    #else
                    printf("saving the current log\n");
                    fileName = generateLogName(gameSettings);
                    result = writeFile(fileName, gameLog, printLogStructToFile);

                    if(result == Success)
                    {
                        printf("finished wrting to file\n");
                    }
                    else
                    {
                        printf(RED"something went wrong"RESET_COLOR);
                    }
                    break;
                    #endif 

                case 5:
                    stop = TRUE;
                    if(!hasLogAccessed)
                    {
                        printf(YELLOW"Your current log hasn't been saved, press"
                        "exit again if you want to exit without saving your"
                        " current log\n"RESET_COLOR);
                        stop = FALSE;
                    }
                    else
                    {
                        printf("GOODBYE :)\n");
                    }

                    break;
                #ifdef Editor
                case 6:
                    changeGameSettings(gameSettings);
                    break;
                #endif
                default:
                    printf(RED"ERROR: invalid option selected\n"RESET_COLOR);
                    stop = FALSE;
            }
        }
        else
        {
            printf("INVALID: please enter a valid option: ");
            /*clearing the buffer to ensure what the user inputs in after incorrect
            input is what the scanf statment will get. Additionally, it's 
            to stop the programme from unexpictedily going into an ifinite loop*/
            /*adapted from: 
            https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ */
            while((getchar()) != '\n');

        }
    }while(!stop);

    freeLog(gameLog, freePrimitives);
    free(gameNum);
    free(fileName);

    gameNum = NULL; 
    fileName = NULL;
}

/*PURPOSE: it's the helper function to userInterface, in order to validate 
the userInput. Furthermore, it's to clean up the userInterface function*/
int validateInput(int input)
{
    int valid;
    valid = FALSE;
    if(input == 1 || input == 2 || input == 3 || input == 4 || 
      input == 5)
    {
        valid = TRUE;
    }

    return valid;
}

/*ASSERTS: displays the settings to the terminal in the order of M,N, and K*/
void displayCurrentSettings(int *inGameSettings)
{
    printf("The current settings of the game:\n:"); 
    printf("M:%d\nN:%d\nK:%d",inGameSettings[0], inGameSettings[1], 
                              inGameSettings[1]);
}


/*PURPOSE: to change the values of the settings to settings given in by  user
 * input. This is to be used when the programme is compilied in editor mode*/
void changeGameSettings(int *inGameSettings)
{
    int mSetting, nSetting, kSetting, numReturned;
    Boolean stop;
    printf("Enter three values seperated by settings for the following game"
    " settings m,n,k\n");

    stop = FALSE; 
    do
    {
        numReturned = scanf( "%d %d %d", &mSetting, &nSetting, &kSetting);
        stop = validateUserSettings(mSetting, nSetting, kSetting);

        if(stop == False)
        {
            printf(RED"ERROR: please ensure all three settings are greater"
            "than 0\n"RESET_COLOR);
        }

        if(numReturned != 3)
        {
            printf(RED"ERROR: invalid argument arrangment\n"RESET_COLOR);
            stop = FALSE;
        }

    }while(!stop);

    inGameSettings[0] = mSetting;
    inGameSettings[1] = nSetting;
    inGameSettings[2] = kSetting;
}

/*PURPOSE: this is the auxilary function to change game settings. This function
 * is to ensure that the user enters numbers whihc are non zero and are not
 * negative*/
Boolean validateUserSettings(int mSetting, int nSetting, int kSetting) 
{
    Boolean isValid;
    isValid = FALSE;
    if(mSetting > 0 && nSetting > 0 && kSetting > 0)
    {
        isValid = TRUE;
    }
    
    return isValid;
}
