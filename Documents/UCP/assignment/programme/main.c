/*******************************************************************************
 * file: main.c                                                                *
 * author: tawana david kwaramba                                               *
 * student id: 19476700                                                        *
 * date created: 30/09/19                                                      *
 * date last modified:                                                         *
 * purpose of file:                                                            *
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
 int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        int *gameSettings;

        gameSettings = (int*)malloc(sizeof(int) * MAX_SETTINGS);
        readGameSettings(argv[1], gameSettings);

        if(*gameSettings != INVALID)
        {
            userInterface(gameSettings);
        }

        free(gameSettings);
        gameSettings = NULL;
    }
    else
    {
        printf(RED"ERROR: ensure that you only enter ./<programme name>"
        " <settings file>\n"RESET_COLOR);
    }

    
    return 0;
}
