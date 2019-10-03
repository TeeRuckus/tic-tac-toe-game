#ifndef GAME_GRAPHICS
#define GAME_GRAPHICS
	#define SPACING 5
	/*pre-processor macro to determine the size of an array. this is based on 
	the follwig rational "size of whole array" / "size of the first element (
	this will be the size of the data-types the arrays hold) = "number of 
	elements in the array"*/
	#define LEN_ARRAY(X,Y) ((sizeof(X))/(sizeof(Y)))
    typedef struct player 
    {
        char player;
        int occupied;
    }player;
	void redrawGameBoard(int *gameSettings);
#endif 
