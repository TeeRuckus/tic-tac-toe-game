/*PURPOSE OF FILE: it's to contain  any functions which relate to the muniplation
of strings or characters*/

/*CODE ADAPTED FROM MY PRACTICAL 4 SUBMISSION*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*PURPOSE: is to convert an incoming string of any length to all upper cases.
The function uses the strLen function to determine the length of the string*/
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

/*PURPOSE: is to convert any of string to all upper cases. The function converts
every character of the string by subtracting 32 from each character, as a lower
case character subtracted - 32 will equal to its upper case conterpart. The
function will stop once it reaches the null terminator (every terminating string
has a null terminator */
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

/*PURPOSE: is to convert any of string to all upper cases. The function converts
every character of the string by subtracting 32 from each character, as a lower
case character subtracted - 32 will equal to its upper case conterpart. The
function will stop once it reaches the null terminator (every terminating string
has a null terminator */
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


