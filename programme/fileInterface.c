#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileInterface.h"
#include "myString.h"

/*PURPOSE: to read in a game settings file which adheres to the following format
M=<integer> 
N=<integer>
K=<interger>
whereby the characters in the folder are case insentive and can be placed in any
order. Additionally, if an error occurs during reading the settings, the
programme will stop.*/
char* readGameSettings(char *fileName)
{
    FILE *inStrm; 
    inStrm = fopen(fileName, "r");
    if(inStrm != NULL)
    {
        
    }
    else
    {
        perror("ERORR: in processing the file - ");
    }
    fclose(inStrm);

}
