/*PURPOSE OF FILE: */
#include <stdio.h>
#include "userInterface.h"

int main(void)
{
    userInterface();

    return 0; 
}

/*PURPOSE: to expose the functionality of the programm to the user. Furthermore,
it serves as a container for other function calls thus, it's the driving force
behind the programme */
void userInterface()
{
    int userSel;
    int stop; 
    int valid;
    stop = FALSE;
    printf("1: Start a new game\n"
    "2: View the settings of the game\n"
    "3: View the current log\n"
    "4: Save the logs to a file\n"
    "5: Exit the application\n");

    printf("Enter option:\n");
    do
    {
        scanf(" %d\n", &userSel);
        valid = validateInput(userSel);

        if(valid)
        {
            stop = TRUE;
            /*default statement is not neede as the outter if and statements
            valid the user input and if the programme has made it this far, the
            input has to be valid */
            switch(userSel)
            {
                case 1:
                    printf("UNSPORRTEDED\n");
                    break;

                case 2:
                    printf("UNSPORRTEDED\n");
                    break;

                case 3:
                    printf("UNSPORRTEDED\n");
                    break;

                case 4:
                    printf("UNSPORRTEDED\n");
                    break;

                case 5:
                    printf("GOODBYE :)\n");
                    break;
            }
        }
        else
        {
            printf("INVALID: please enter a valid option: ");
        }
    }while(!stop);
}

/*PURPOSE: it's the helper function to userInterface, in order to validate 
the userInput. Furthermore, it's to clean up the userInterface function*/
int validateInput(int input)
{
    int valid;
    valid = FALSE;
    if(input == 1 || input == 2 || input == 3 || input == 4 || 
      input == 5)
    {
        valid = TRUE;
    }

    return valid;
}
