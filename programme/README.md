# UCP_assignment
Tawana Kwaramba 19476700 README

DATE CREATED: 30/09/2019

DATE LAST MODIFIED:

PURPOSE: A terminal text based terminal game of tic tac toe consisting of 2
		 players. The tic toc baord game is resizable through the settings file.
		 Furthermore, the number of matching tiles in a row to win can
		 be configured throguh the settings file. The game can be loaded by
		 running the executable file accompinied by the settings file i.e.
		 ./TicTacToe settings.txt. Additionally, the game can be played by users
		 taking turns to input their moves into the terminal using the following
		 notation "(0,0)". Whereby the very top row is the 0th row and the most
		 left column is the 0th column. Hence, the top left tile is (0,0)

FILES IN PROJECT: 

TEST FILES:

FUNCTIONALITY: logging -> fileIO -> saving the data structure -> the conditional
			   compliation etc. -> how finding a winner is done etc

TO DO:

KNOWN BUGS: 
	1) in userInterface.c the user has to input their option twice for the 
	function to register the input

    Possible problems:
        -The scanf is not been used properly used in the function call 

	2) in userInterface.c when an invlaid integer is entered the function works
	well. Although, when an valid integer is entered the "invalid" prompt is 
	displayed and you're asked to re-enter your option albeit, the value put in
	the function will validate the last corrrect you entered from the prevous
	call

    3) in userInterface.c when  a string is entered, it sends the programme into
    an ifinit loop.

ADDITIONAL FUNCTIONALITY
