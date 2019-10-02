/*PURPOSE OF FILE: it's to contain  any functions which relate to the muniplation
of strings or characters*/

/*CODE ADAPTED FROM MY PRACTICAL 4 SUBMISSION*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*PURPOSE: is to convert any of string to all upper cases. The function converts
every character of the string by subtracting 32 from each character, as a lower
case character subtracted - 32 will equal to its upper case conterpart. The
function will stop once it reaches the null terminator (every terminating string
has a null terminator */
char myToUpper(int inChar)
{
	inChar = (char)inChar;
	if(inChar >= 'a' && inChar <= 'z')
	{
		inChar = inChar - 32;
	}

	return  inChar;
}
