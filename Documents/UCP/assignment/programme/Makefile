#File Created: Friday 9th of August 10:14
#AUTHOR: Tawana Kwaramba
#LAST MODIFIED: 
#MODIFIED BY:
#PURPOSE: A make file to run all the download relateded programmes 

# Makefile Variables
CC = gcc
EXEC = TicTacToe
TEST = TestSuite
CFLAGS = -g -Wall -ansi -pedantic -Werror -std=c89
GAME_OBJ =  main.o userInterface.o gameInterface.o gameLogic.o gameGraphics.o \
memoryInterface.o fileInterface.o LinkList.o logInterface.o
TEST_OBJ = TicTacToeTestSuite.o gameInterface.o gameLogic.o gameGraphics.o \
memoryInterface.o fileInterface.o LinkList.o logInterface.o

ifdef Secret
CFLAGS += -D Secret
Secret : clean $(EXEC)
endif 

ifdef Editor 
CFLAGS += -D Editor 
Editor : clean $(EXEC)
endif 

$(EXEC) : $(GAME_OBJ)
	$(CC) $(GAME_OBJ) -o $(EXEC)

$(TEST) : $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $(TEST)

userInterface.o : userInterface.c
	$(CC) $(CFLAGS) -c userInterface.c

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

fileInterface.o : fileInterface.c
	$(CC) $(CFLAGS) -c fileInterface.c

gameInterface.o : gameInterface.c
	$(CC) $(CFLAGS) -c gameInterface.c

gameGraphics.o : gameGraphics.c
	$(CC) $(CFLAGS) -c gameGraphics.c

memoryInterface.o : memoryInterface.c
	$(CC) $(CFLAGS) -c memoryInterface.c

gameLogic.o : gameLogic.c
	$(CC) $(CFLAGS) -c gameLogic.c

TicTacToeTestSuite.o : TicTacToeTestSuite.c
	$(CC) $(CFLAGS) -c TicTacToeTestSuite.c

LinkList.o : LinkList.h
	$(CC) $(CFLAGS) -c LinkList.c

logInterface.o : LinkList.h
	$(CC) $(CFLAGS) -c logInterface.c

clean:
	rm -f $(EXEC) $(TEST) $(GAME_OBJ) $(TEST_OBJ)  
