#File Created: Friday 9th of August 10:14
#AUTHOR: Tawana Kwaramba
#LAST MODIFIED: 
#MODIFIED BY:
#PURPOSE: A make file to run all the download relateded programmes 

# Makefile Variables

CC = gcc
EXEC = TicTacToe
TEST = TestSuite
CFLAGS = -g -Wall -ansi -pedantic -Werror
OBJ = userInterface.o
TEST_OBJ = fileInterface.o myString.o

#if the user wants to enable all the debuggin features of the programme 
ifdef DEBUG 
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) 

$(TEST) : $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $(TEST)

userInterface.o : userInterface.c userInterface.h
	$(CC) $(CFLAGS) -c userInterface.c

fileInterface.o : fileInterface.c fileInterface.h myString.h
	$(CC) $(CFLAGS) -c fileInterface.c

myString.o : myString.c myString.h
	$(CC) $(CFLAGS) -c myString.c

clean:
	rm -f $(EXEC) $(TEST) $(OBJ) $(TEST_OBJ)
