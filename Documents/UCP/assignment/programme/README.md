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

    1) gameInterface.c: when you enter 2 or more numbers, the programme will 
    just grab the first 2 numbers. The programme should, display an error 
    saying that you have entered more than 2 numbers and re-prompt the player
    to input their numbers.

    2) when you are playing the game, if you enter a coordinate such 0,1\
    the algorithm will accept the first two numbers. Display an error to the
    terminal and change the player to the next player

    3)After a 10 x 10 gameboard the numbers on top of the board don't align
    with their tiles properly.

ADDITIONAL FUNCTIONALITY
