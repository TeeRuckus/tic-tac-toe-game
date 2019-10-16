/*******************************************************************************
*   FILE: LinkList.c                                                           *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: to create the abstract data structure of a doubly linked, *
*                    double eneded linked list                                 *
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "myBool.h"
#include "LinkList.h"

/*ASSERT: creates a list node with a head reference of null*/
LinkedList* createLinkedList()
{   
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list -> head = NULL;
    list -> tail = NULL;
    list -> count = 0;

	return list;
}

/*ASSERTS: returns the number of LinkedList node in the link list */
int getCount(LinkedList *list)
{
    return list -> count;
}

/*ASSERTS: it adds a linked list node to the head reference of the linked list*/
void insertFirst(LinkedList *list, void *inValue)
{   
    LinkListNode *nwNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    nwNode -> value = inValue;
    /*the  count variable will be used to determine if they is only one item on
    the linked list */
    list -> count++;

    nwNode -> nextRef = list -> head;
    /* first case: inserting in an empty linked list*/
    if ((list -> head == NULL) && (list -> tail == NULL))
    {
        /*if the list is empty, you can just make the head and the tail
        references to the new node */ 
        list -> tail = nwNode;
    }
    /*second case where they is one or more items stored onto the linked list*/
    else
    {
        /*a temporary node has to be created, to allow the link list to link 
        the items correctly */ 
        list -> head -> prevRef =  nwNode;
    }
    
    nwNode -> prevRef = NULL;
    list -> head = nwNode;
}

/*ASSERTS: inserts a listnode at the end of the link list */
void insertLast(LinkedList *list, void *inValue)
{
    LinkListNode *nwNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    nwNode -> value = inValue;
    list -> count++;
    nwNode -> prevRef = list -> tail;

    /*First case: where the link list is empty*/
    if(list -> head == NULL && list -> tail == NULL)
    {
        list -> head = nwNode;
    }
    /*second case: where the link list has one ore more list nodes connected to
    it */
    else
    {
        /*since this is  a doubly linked list, inserting last is very simple.
        we can just go straight to the refererence and set the next reference 
        as our new node, then we can link the new node's reference back to the
        node */ 
        list -> tail -> nextRef = nwNode;
    }

    list -> tail = nwNode;
    nwNode -> nextRef = NULL;
}

/*ASSERTS: removes the last node from the linked list*/
void* removeLast(LinkedList *list)
{
    LinkListNode *currNd;
    LinkListNode *lastNd;
    void *valueLastNd;

    lastNd = list -> tail;
    valueLastNd = lastNd -> value;

    /*if the link list has only one list node connected to it*/
    if(list -> count == 1)
    {
        /* if we only have one node on the list, we can just delete the whole
        linked list, by the only node to null and freeing it. Furthermore,
        we need to  set the head and  tail reference to NULL*/
        list -> tail = NULL;
        list -> head = NULL;
    }
    /*if the link list has 2 or more list nodes connected to it */
    else
    {
        /*we need to take greater care here! Since this is a doubly linked list 
        we can jump to the tail reference and grab it's previous reference. Before
        we set its next reference to NULL. We need to make a note of where that
        node is as C doesn't have automatic garabage collection. Hence, once
        we make a note were the last reference is we can set the previous nodes
        next reference to null, and free and set the last node to NULL*/
        currNd = list -> tail -> prevRef;
        list -> tail = currNd;
        currNd -> nextRef = NULL;
    }
    
    /*in the case where the linked list has one node or multiple node we need
     *to free the lastNd as we're deleting it hence, we are freeing the node
     *if the tail reference didn't equal to NULL as if you try to free something
     which is NULL you'll get an invalid free when you try to run the code*/
    if(lastNd != NULL)
    {
        list ->count--;
        free(lastNd);
        lastNd = NULL;
    }

    return valueLastNd;
}

/*ASSERTS: removes the last node of th imported linked list*/
void* removeFirst(LinkedList *list)
{
    /*the current is in reference to the node after the first node*/
    LinkListNode *currNd;
    LinkListNode *firstNd;
    LinkListNode *valueFirstNd;

    firstNd = list -> head;
    valueFirstNd = firstNd -> value;

    /*if the link list has one node connected to it */
    if(list -> count  == 1)
    {
        /*if the linked list has only one node attached to it, we can
        set the whole  linked list to NULL*/
        list -> tail = NULL;
        list -> head = NULL;
        
    }
    /*if the link list has 2 or mote list nodes connected to it */
    else
    {
        currNd = list -> head -> nextRef;
        list -> head = currNd;
        currNd -> prevRef = NULL;
        firstNd -> nextRef =  NULL;

    }

    if(valueFirstNd != NULL)
    {
        list -> count--;
        free(firstNd);
        firstNd = NULL;
    }

    return valueFirstNd;
}

/*PURPOSE: to display all the values for every single list node in the linked
list. Furthermore, it acts a wrapper method for the displayRec hence providing
a location to start and to return too*/
void display(LinkedList *list, funcPtr fptr)
{
    if(list -> head == NULL && list -> tail == NULL)
    {
        printf("empty list :,(\n");
        printf("\n");
    }
    else
    {
        displayRec(list -> head, fptr);
        printf("\n");
    }
}

/*PURPOSE: to print all the contents of the linked list to a file without
deleteting any of its content through the assitatnce of a function pointer*/
Status displayToFile(LinkedList *list,FILE *strmName, filePrintPtr fptr)
{
    Status retStatus;
    if(list -> head == NULL && list -> tail == NULL)
    {
        retStatus = Failed;
    }
    else
    {
        displayFileRec(list -> head, strmName, fptr);
        printf("\n");
        retStatus = Success;
    }

    return retStatus;
}

/*PURPOSE: a recursive algorithm which goes to each node adn displays the nodes
values thorugh the assistance of a function pointers*/
void displayRec(LinkListNode *node, funcPtr fptr)
{
    if(node != NULL)
    {
        /*displaying all the nodes recursively in order they're inserted as 
        we're printing out the value before we create another stack frame */
        (fptr)(node -> value); 
        displayRec(node -> nextRef, fptr);
    }
}

/*PURPOSE: a recursive alorithm which goes through each node and prints the 
nodes value to a file stream through the assitance of a function pointer*/
void displayFileRec(LinkListNode *node,FILE *strmName, filePrintPtr fptr)
{
    if(node != NULL)
    {
        (fptr)(node -> value, strmName);
        displayFileRec(node -> nextRef, strmName, fptr);
    }
}

/*common primitive data types: to assit the displayRec function to print out
any of the common primitives listed below*/ 
void printInt(void *data)
{
    printf(" %d", *(int*)data);
}

void printFloat(void *data)
{
    printf(" %f", *(float*)data);
}

void printChar(void *data)
{
    printf(" %c", *(char*)data);
}

void printString(void *data)
{
    printf(" %s", (char*)data);
}

/*ASSERTS: frees all a linked lists node starting at the head node */
void freeLinkedList(LinkedList *list, funcPtr fptr)
{
    freeNodeRec(list -> head, fptr);
    free(list);
}

/*PURPOSE: serves as a helper function to freeLinkedList(). The purpose is to 
recursively free nodes given a starting node*/
void freeNodeRec(LinkListNode *node, funcPtr fptr)
{
    if(node != NULL)
    {
        /*creating alterantive stack frames with different node values i.e.
        using recursion */
        freeNodeRec(node -> nextRef, fptr);

        (*fptr)(node->value);

        /*when they is no more stack frames to create, I am going to go back 
        to each stack frame I created adn free the node. If the structures
        value field is a pointer, that needs to be freed aswell */ 
        free(node);
        /*good practice to set freed items to null */
        node = NULL; 
    }
}

/*PURPOSE: a general purpose free method to act as a function pointer in the
freeNodeRec code */
void freePrimitives(void *data)
{
    free(data);
    data = NULL;
}
