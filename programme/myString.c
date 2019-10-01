/*CODE ADAPTED FROM MY PRACTICAL 4 SUBMISSION*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void myToUpperStrlen(char* inString)
{
    int ii, sizeOfInString;

    /*excluding the null pointer at the end of the string */
    sizeOfInString = strlen(inString);
    
    /*turn everything into upper case excluding the null terminantor */
    for (ii = 0; ii < sizeOfInString; ii++)
    {
        /*lower case letters sit in one range on the ASCII table*/
        if(inString[ii] >= 'a' && inString[ii] <= 'z')
        {
            inString[ii] = inString[ii] - 32;
        }

    }
}


void myToUpper(char* inString)
{
    int ii;
    ii = 0;

    while(inString[ii] !='\0')
    {
        if(inString[ii] >= 'a' && inString[ii] <= 'z')
        {
            inString[ii] = inString[ii] - 32;
        }

        ii++;
    }
}

void myToUpperPtr(char* inString)
{
    int ii;
    ii = 0;

    while(*(inString + ii) !='\0')
    {
        if(*(inString + ii)>= 'a' && *(inString + ii) <= 'z')
        {
            *(inString + ii) = *(inString + ii) - 32;
        }

        ii++;
    }
}


