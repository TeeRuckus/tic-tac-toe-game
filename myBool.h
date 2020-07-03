/*******************************************************************************
*   FILE: myBool.h                                                             *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: it contains enumarator declrations which is used to       *
*                    control a functions or an algorithms logic in a manner of *
*                    some sought.                                              *
*******************************************************************************/
#ifndef MY_BOOL_H 
#define MY_BOOL_H
    typedef enum Boolean{TRUE=1, FALSE=0}Boolean;
    typedef enum ValidStatus{VALID=1, INVALID= -1}ValidStatus;
    typedef enum Direction{Up, Down, Left, Right, DiagonallyUpLeft, 
                 DiagonallyUpRight, DiagonallyDownLeft, DiagonallyDownRight
                                                                    }Direction;
    typedef enum Status{Failed = 0, Success = 1}Status;

#endif
