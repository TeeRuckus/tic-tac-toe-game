#File Created: Friday 9th of August 10:14
#AUTHOR: Tawana Kwaramba
#LAST MODIFIED: 
#MODIFIED BY:
#PURPOSE: A make file to run all the download relateded programmes 

# Makefile Variables
CC = gcc
EXEC = TicTacToe
gameTest = gameGraphics
TEST = TestSuite
CFLAGS = -g -Wall -ansi -pedantic -Werror -std=c89
OBJ = userInterface.o
TEST_OBJ = TicTacToeTestSuite.o gameInterface.o gameLogic.o gameGraphics.o \
memoryInterface.o fileInterface.o LinkList.o logInterface.o
game_OBJ = gameGraphics.o

#if the user wants to enable all the debuggin features of the programme 
ifdef DEBUG 
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) 

$(TEST) : $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $(TEST)

$(gameTest) : $(game_OBJ)
	$(CC) $(game_OBJ) -o $(gameTest)

userInterface.o : userInterface.c userInterface.h
	$(CC) $(CFLAGS) -c userInterface.c

fileInterface.o : fileInterface.c fileInterface.h 
	$(CC) $(CFLAGS) -c fileInterface.c

myString.o : myString.c myString.h
	$(CC) $(CFLAGS) -c myString.c


gameInterface.o : gameInterface.c gameGraphics.h memoryInterface.h gameLogic.h
	$(CC) $(CFLAGS) -c gameInterface.c

gameGraphics.o : gameGraphics.c gameGraphics.h gameLogic.h
	$(CC) $(CFLAGS) -c gameGraphics.c

memoryInterface.o : memoryInterface.c memoryInterface.h gameGraphics.h
	$(CC) $(CFLAGS) -c memoryInterface.c

gameLogic.o : gameLogic.c gameLogic.h gameGraphics.h
	$(CC) $(CFLAGS) -c gameLogic.c

TicTacToeTestSuite.o : TicTacToeTestSuite.c TicTacToeTestSuite.h \
fileInterface.h gameInterface.h LinkList.h logInterface.h
	$(CC) $(CFLAGS) -c TicTacToeTestSuite.c

LinkList.o : LinkList.h
	$(CC) $(CFLAGS) -c LinkList.c

logInterface.o : LinkList.h logInterface.h
	$(CC) $(CFLAGS) -c logInterface.c

clean:
	rm -f $(EXEC) $(TEST) $(OBJ) $(TEST_OBJ) $(gameTest) $(game_OBJ)
