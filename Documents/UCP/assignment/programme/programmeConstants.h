/*******************************************************************************
 * FILE: programmeConstants.h                                                  *
 * AUTHOR: Tawana David Kwaramba                                               *
 * STUDENT ID: 19476700                                                        *
 * DATE CREATED: 30/09/19                                                      *
 * DATE LAST MODIFIED:                                                         *
 * PURPOSE OF FILE: a header file which contains constants which are used      *
 *                  throughout the programm                                    *
 *******************************************************************************/

#ifndef PROGRAMME_CONSTANTS_H
#define PROGRAMME_CONSTANTS_H
	#define SPACING 5
    #define MAX_SETTINGS 3
    #define MAX_READ 10
    #define MAX_LINE 100 
    #define MAX_FILE_NAME 46

    /*constants relating to the visuals of the game */
    /*the following #defines are adapted from - 
     * https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c*/
    #define RED "\x1b[31m"
    #define GREEN "\x1b[32m"
    #define BLUE "\x1b[34m"
    #define YELLOW "\x1b[33m"
    #define RESET_COLOR "\x1b[0m"
#endif
