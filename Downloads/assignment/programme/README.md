# UCP_assignment
Tawana Kwaramba 19476700 README

DATE CREATED: 30/09/2019

DATE LAST MODIFIED: 19/10/2019

PURPOSE: A terminal text based terminal game of tic tac toe consisting of 2
		 players. The tic toc baord game is resizable through the settings file.
		 Furthermore, the number of matching tiles in a row to win can
		 be configured throguh the settings file. 
         
        
FUNCTIONALITY: The game can be loaded by running the executable 
               file accompinied by the settings file i.e. ./TicTacToe 
               gameSettings.txt. Additionally, the game can be played by users
		       taking turns to input their moves into the terminal using the 
               following notation "4 3" which represent 
               "x-coordinate y-coordinate". Whereby the very top row is the 0th 
               row and the most left column is the 0th column. Hence, the top
               left tile is 0 0. Futhermore, through game play every move made 
               by each accompanign player is logged. The log can be displayed 
               on the terminal or its contents saved to a file. Additonally
               during excution yon view the current settings of the programme.

               This programme comes equiped with two conditional compliation
               modes which are the following;

               -Editor mode: to activate simply enter the following in the
               terminal: make clean && make Editor=1 then ./TicTacToe 
               <setting file>. Editor modes grants the usr the permission 
               to change the game settings through run time through an
               extra option in the user interface.

               -Secret mode: to activate simply enter the following in the
               comannd line: make clean && make Secret=1 then ./TicTacToe
               <game settings file>. Secret mode takes away the ability to 
                save logs, the option to save logs will still be visible but
                when it's selected an error message will be displayed.

FILES IN PROJECT: 
    -fileInterface.c fileInterface.h
    -gameGraphics.c gameGraphics.h 
    -gameInterface.c gameInterface.h
    -gameLogic.c gameLogic.h
    -gameSettingInvalid2.txt
    -gameSettingInvalid3.txt
    -gameSettingInvalid4.txt
    -gameSettingInvalid5.txt
    -gameSettingInvalid6.txt
    -gameSettingInvalid.txt
    -gameSettingsTestInvalid.txt
    -gameSettingTestValid2.txt
    -gameSettingTestValid.txt
    -gameSettigs.txt
    -LinkList.c LinkList.h
    -logInterface.c logInterface.h
    -memoryInterface.c memoryInterface.h
    -myBool.h
    -programmeConstants.h
    -userInterface.c userInterface.h
    -Makefile

TEST FILES: TicTacToeTestSuite.c TicTacToeTestSuite.h

KNOWN BUGS: 

    1) gameInterface.c: when you enter 2 or more numbers, the programme will 
    just grab the first 2 numbers. The programme should, display an error 
    saying that you have entered more than 2 numbers and re-prompt the player
    to input their numbers.
        -----------------------------------------------------------------------
        solution: use fgets. Except have fgets reading in from stdin and try
        to convert that to an integer using the strtol function. If the strtol
        function succefully returns the parsed intergers it will return the null
        terminator. If it doesn't we know that something went wrong and a string
        is included after the integers been parsed. Then after you can have 
        another function which will check if the parsed intergers are only
        two  numbers. If they're everything is all good, if not we can display
        an error  message and ask for a re-prompt
        ------------------------------------------------------------------------

    2) when you are playing the game, if you enter a coordinate such as 0 1\
    the algorithm will accept the first two numbers. Display an error to the
    terminal and change the player to the next player
        -----------------------------------------------------------------------
        solution: the solution is quite similiar to the first one, instead of
        using scanf. Use fgets except for the stream name, you would change
        that to standard in. Then you try to parse that string using strtol 
        if the conversion is succesful your second argument in fgets will be
        the  terminato if it's not, it will be something else.
        -----------------------------------------------------------------------

    3)After a 10 x 10 gameboard the numbers on top of the board don't align
    with their tiles properly.
        ------------------------------------------------------------------------
        solution: this may to be how I hav ordereded my print statements
       in gameGraphics.c
       -------------------------------------------------------------------------

    4)When you enter a random input into the user interface, it will alway
    go to the first otion an input it as plyer ones option
        ------------------------------------------------------------------------
        solution: excatly the same as bug 2
        ------------------------------------------------------------------------

ADDITIONAL FUNCTIONALITY
    -When exiting the user interface, the programme checks if you have saved 
    your current game log and if you haven't it prompts you to do so.

TO DO:
    To have the programme handle ctrl-c action. Henc, if the user enters
    ctrl-c the programme should be able to rederict itself to a function which
    will clean  up everything i.e. free what needs to be done. Additionally, 
    the function can save the current game log so the data is not lost

    implementing those fixes to the bigs discussed in the bigs section
