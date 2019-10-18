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
#include "programmeConstants.h"
#include "myBool.h"
#include "userInterface.h"
#include "LinkList.h"
#include "fileInterface.h"
#include "gameInterface.h"
#include "logInterface.h"
/*PURPOSE: to expose the functionality of the programm to the user. Furthermore,
it serves as a container for other function calls thus, it's the driving force
behind the programme */
void userInterface(int *gameSettings)
{
    int userSel, stop, *gameNum, numReturned;
    Boolean valid; 
    LinkedList *gameLog;
    #ifdef Secret
    #else
    char *fileName;
    Status result;
    Boolean hasLogAccessed;
    hasLogAccessed = FALSE;
    #endif

    #ifdef Secret
    printf("----------------------------------------------------------------\n");
    printf("You have entered into secret mode: You have lost th ability to save"
    " logs. You may only view the logs. Keep everything a secret shhhhhh....\n");
    printf("----------------------------------------------------------------\n");
    #endif

    #ifdef Editor
    printf("----------------------------------------------------------------\n");
    printf("You have enteted into editor mode. You may change the settings of"
    " the game in the menu... I bestow you with the power of this game\n");
    printf("----------------------------------------------------------------\n");
    #endif
    

    /*to allow the algorithm to prompt the user that the game log hasn't been
     * saved. To enusure that data is not lost*/
    stop = FALSE;
    gameNum = (int*)malloc(sizeof(int)); 
    gameLog = createGameLog();
    *gameNum = 1;
    
    logGameSettings(gameLog, gameSettings);



    do
    {
        /*menu options*/
        printf("1: Start a new game\n"
        "2: View the settings of the game\n"
        "3: View the current log\n"
        "4: Save the logs to a file\n"
        "5: Exit the application\n");

        #ifdef Editor
        printf("6: Change game settings\n");
        #endif

        printf("Enter option: ");
        numReturned = scanf(" %d", &userSel);
        if(numReturned == 1)
        {
            valid = validateInput(userSel);
        }
        else
        {
            valid = FALSE;
        }

        if(valid)
        {
            switch(userSel)
            {
                case 1:
                    printf("Starting a new game....\n");
                    logGameNum(gameLog, gameNum);
                    playGame(gameSettings, gameLog);
                    /*every time the game finishs means that our log has to be 
                     * updated and we have to prompt the user before he exited
                     * that there's new data and he must not forget to save
                     * his wor*/
                    #ifdef Secret
                     /*so nothing*/
                    #else
                    hasLogAccessed = FALSE;
                    #endif
                    (*gameNum)++;
                    break;

                case 2:
                    displayCurrentSettings(gameSettings); 
                    break;

                case 3:
                    printf("Viewing the current logs\n");
                    displayLog(gameLog, printLogStruct);
                    break;
                
                case 4:
                    #ifdef Secret
                    printf(RED"THIS option is disabled while in secret mode\n"
                    RESET_COLOR);
                    #else
                    printf("saving the current log\n");
                    fileName = generateLogName(gameSettings);
                    result = writeFile(fileName, gameLog, printLogStructToFile);
                    checkFileWriteSucceed(result);
                    hasLogAccessed = TRUE;
                    free(fileName);
                    fileName = NULL;
                    #endif 


                    break;

                case 5:
                    #ifdef Secret
                    stop = TRUE;
                    printf("....goodbye, remeber to keep everything a secret\n");
                    #else
                    stop = TRUE;
                    if(!hasLogAccessed)
                    {
                        printf(YELLOW"Your current log hasn't been saved, press"
                        " exit again if you want to exit without saving your"
                        " current log\n"RESET_COLOR);
                        stop = FALSE;

                        /*we have warned the user that their current log hasn't 
                         * been saved yet. So on the next press of this option
                         * we should exit the game*/
                        hasLogAccessed = TRUE;
                    }
                    else
                    {
                        printf(BLUE"GOODBYE :)\n"RESET_COLOR);
                    }
                    #endif
                    break;

                #ifdef Editor
                case 6:
                    changeGameSettings(gameSettings);
                    /*whenever we change settings we want to add the new settings
                    onto the log*/
                    logGameSettings(gameLog, gameSettings);
                    break;
                #endif
                default:
                    printf(RED"ERROR: invalid option selected\n"RESET_COLOR);
                    stop = FALSE;
            }
        }
        else
        {
            printf(RED"ERROR: please enter a valid option:\n"RESET_COLOR);

        }
        /*clearing the buffer to ensure what the user inputs in after incorrect
        input is what the scanf statment will get. Additionally, it's 
        to stop the programme from unexpictedily going into an ifinite loop*/
        /*adapted from: 
        https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ */
        while((getchar()) != '\n');
    }while(!stop);

    freeLog(gameLog, freePrimitives);
    free(gameNum);

    gameNum = NULL; 
}

/*PURPOSE: it's the helper function to userInterface, in order to validate 
the userInput. Furthermore, it's to clean up the userInterface function*/
Boolean validateInput(int input)
{
    Boolean valid;
    valid = FALSE;
    #ifdef Editor
    if(input == 1 || input == 2 || input == 3 || input == 4 || 
      input == 5 || input == 6)
    {
        valid = TRUE;
    }
    #else
    if(input == 1 || input == 2 || input == 3 || input == 4 || 
      input == 5)
    {
        valid = TRUE;
    }
    #endif

    return valid;
}

/*ASSERTS: displays the settings to the terminal in the order of M,N, and K*/
void displayCurrentSettings(int *inGameSettings)
{
    printf("\nThe current settings of the game:\n"); 
    printf("M:%d\nN:%d\nK:%d\n\n",inGameSettings[0], inGameSettings[1], 
                              inGameSettings[2]);
}


/*PURPOSE: to change the values of the settings to settings given in by  user
 * input. This is to be used when the programme is compilied in editor mode*/
void changeGameSettings(int *inGameSettings)
{
    int mSetting, nSetting, kSetting, numReturned;
    Boolean stop;
    printf("Enter three values for game settings as m n k: ");
    
    mSetting = 0;
    nSetting = 0;
    kSetting = 0;
    stop = FALSE; 
    do
    {
        numReturned = scanf( "%d %d %d", &mSetting, &nSetting, &kSetting);
        stop = validateUserSettings(mSetting, nSetting, kSetting);

        if(numReturned != 3)
        {
            printf(RED"ERROR: invalid argument arrangment\n"RESET_COLOR);
            stop = FALSE;
            while((getchar()) != '\n');
        }
        else if(stop == FALSE)
        {
            printf(RED"ERROR: please ensure all three settings are greater"
            " than 0\n"RESET_COLOR);
            while((getchar()) != '\n');
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

void checkFileWriteSucceed(Status result)
{
    if(result == Success)
    {
        printf("finished wrting to file\n");
    }
    else
    {
        printf(RED"something went wrong"RESET_COLOR);
    }
}
