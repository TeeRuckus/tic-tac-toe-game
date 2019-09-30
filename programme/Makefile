#File Created: Friday 9th of August 10:14
#AUTHOR: Tawana Kwaramba
#LAST MODIFIED: 
#MODIFIED BY:
#PURPOSE: A make file to run all the download relateded programmes 

# Makefile Variables

CC = gcc
EXEC1 = TicTacToe
CFLAGS = -g -Wall -ansi -pedantic -Werror
OBJ1 = userInterface.o

#if the user wants to enable all the debuggin features of the programme 
ifdef DEBUG 
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC1) : $(OBJ1)
	$(CC) $(OBJ1) -o $(EXEC1) 

userInterface.o : userInterface.c userInterface.h
	$(CC) $(CFLAGS) -c userInterface.c

clean:
	rm -f $(EXEC1) $(OBJ1) 
