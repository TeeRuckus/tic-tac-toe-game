#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

int main(int argc, char const *argv[])
{
    char* value;
    char *input1 = (char*)malloc(sizeof(char)*6);
    char *input2 = (char*)malloc(sizeof(char)*4);
    char *input3 = (char*)malloc(sizeof(char)*9);
    char *input4 = (char*)malloc(sizeof(char)*8);

    int numPassed;
    int numTests;

    LinkedList* list = NULL;

    numPassed = 0;
    numTests = 0;

    strncpy(input1, "hello",6);
    strncpy(input2, "bye",4);
    strncpy(input3, "Mercedes",9);
    strncpy(input4, "Nissian",8);

    /*CREATING*/
    numTests++;
    printf("Creating List: ");
    list = createLinkedList();
    if(list == NULL || list->head != NULL || list -> tail != NULL)
    {
        printf("FAILED\n");
    }
    else
    {
        printf("PASSED\n");
        numPassed++;
    }
    
    printf("count: %d\n", list -> count);
    /*INSERTING FIRST*/
    numTests++;
    printf("Inserting First: ");
    insertFirst(list,input1);
    if(list->head == NULL)
    {
        printf("FAILED\n");
    }
    else if(strncmp((char*)list->head->value, input1, strlen(input1)+1)==0)
    {
        printf("PASSED\n");
        numPassed++;
    }
    else
    {
        printf("FAILED\n");
    }

    display(list, printString);
    printf("count: %d\n", list -> count);

    printf("Inserting First (2): ");
    insertFirst(list,input2);
    if(list->head == NULL)
    {
        printf("FAILED\n");
    }
    else if(strncmp((char*)list->head->value, input2, strlen(input2)+1)==0 && 
        strncmp((char*)list->tail->value, input1, strlen(input1)+1)==0)
    {
        printf("PASSED\n");
        numPassed++;
    }
    else
    {
        printf("FAILED\n");
    }

    display(list, printString);
    printf("count: %d\n", list -> count);

    /*INSERTING LAST*/
    printf("Inserting last ");
    insertLast(list, input3);
    if(list->head == NULL)
    {
        printf("FAILED\n");
    }
    else if(strncmp((char*)list->tail->value, input3, strlen(input3)+1)==0)
    {
        printf("PASSED\n");
        numPassed++;
    }
    else
    {
        printf("FAILED\n");
    }

    display(list, printString);
    printf("count: %d\n", list -> count);

    printf("Inserting last (2) ");
    insertLast(list, input4);
    if(list -> head == NULL)
    {
        printf("FAILED\n");
    }
    else if (strncmp((char*)list->tail->value, input4, strlen(input4)+1)==0 &&
      strncmp((char*)list->tail->prevRef->value, input3, strlen(input3)+1)==0)
    {
        printf("PASSED\n");
        numPassed++;
    }
    else
    { 
        printf("FAILED\n");
    }
    

    display(list, printString);
    printf("count: %d\n", list -> count);

    /*REMOVING LAST*/
    removeLast(list);
    value = (char*)removeLast(list);

    printf("remove last :");
    if(list -> head == NULL || list -> tail == NULL)
    {
        printf("FALIED\n");
    }
    else if (strncmp(value, input3, strlen(input3)+1)==0)
    {
        printf("PASSED\n");
        numPassed++;
    }

    display(list, printString);
    /*REMOVING FIRST*/
    printf("Remove First: ");
    value = (char*)removeFirst(list);

    if(strncmp(value, input2, strlen(input2)+1) == 0)
    {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }
    
    display(list, printString);
    
    printf("Remove Last (2): with only one element on the list: ");
    value = (char*)removeLast(list);
    if(strncmp(value, input1, strlen(input1)+1) == 0)
    {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }

    display(list, printString);
    
    printf("inserting element..\n");
    insertLast(list, input4);
    display(list, printString);
    printf("Remove first (2): with only one element on the list: ");
    value = (char*)removeFirst(list);
    if(strncmp(value, input4, strlen(input4)+1) == 0)
    {
        printf("PASSED\n");
    }
    else
    {
        printf("FAILED\n");
    }
    display(list, printString);

    /*PRINTING*/

    /*FREEING*/
    freeLinkedList(list);
    free(input1);
    free(input2);
    free(input3);
    free(input4);

    input1 = NULL;
    input2 = NULL;
    input3 = NULL;
    input4 = NULL;

    return 0;
}
