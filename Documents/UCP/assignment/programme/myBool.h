#ifndef MY_BOOL_H 
#define MY_BOOL_H
    typedef enum Boolean{TRUE=1, FALSE=0}Boolean;
    typedef enum ValidStatus{VALID=1, INVALID= -1}ValidStatus;
    typedef enum Direction{Up, Down, Left, Right, DiagonallyUpLeft, 
                 DiagonallyUpRight, DiagonallyDownLeft, DiagonallyDownRight
                                                                    }Direction;

#endif
