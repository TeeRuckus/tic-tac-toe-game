#ifndef GAME_GRAPHICS
#define GAME_GRAPHICS
	#define SPACING 5
    /*the following #defines are adapted from - 
     * https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c*/
    #define RED "\x1b[31m"
    #define GREEN "\x1b[32m"
    #define BLUE "\x1b[34m"
    #define RESET_COLOR "\x1b[0m"

    void drawGameBoard(player **placements, int *gameSettings, int *turn);
    void redrawGameBoard(player **placements, int *gameSettings, int  *pos, int *turn);
    void clearGameBoard(player **inArr, int rows, int cols);
#endif 
