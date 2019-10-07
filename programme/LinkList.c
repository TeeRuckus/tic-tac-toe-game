/*PURPOSE: to create the abstract data structure of single linked, single ended
linked list */
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*ASSERT: creates a list node with a head reference of null*/
LinkedList* createLinkedList()
{   
    LinkedList *list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list -> head = NULL;
    list -> tail = NULL;
    list -> count = 0;

	return list;
}

int getCount(LinkedList *list)
{
    int count; 
    count = list -> count;
    return count;
}

void insertFirst(LinkedList *list, void *inValue)
{   
    LinkListNode *nwNode;
    nwNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    nwNode -> value = inValue;
    list -> count++;
    
    /* first case: inserting in an empty linked list*/
    if ((list -> head == NULL) && (list -> tail == NULL))
    {
        list -> head  = nwNode;
        list -> tail = nwNode;
        nwNode -> nextRef = NULL;
        nwNode -> prevRef = NULL;
    }
    /*second case where they is one or more items stored onto the linked list*/
    else
    {
        nwNode -> nextRef = list -> head;
        nwNode -> prevRef = NULL;
        list -> head -> prevRef =  nwNode;
        list -> head = nwNode;
    }
}

void insertLast(LinkedList *list, void *inValue)
{
    LinkListNode *nwNode;
    nwNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    nwNode -> value = inValue;
    list -> count++;
    /*First case: where the link list is empty*/
    if(list -> head == NULL && list -> tail == NULL)
    {
        list -> head = nwNode;
        list -> tail = nwNode;
        nwNode -> nextRef = NULL;
        nwNode -> prevRef = NULL;
    }
    /*second case: where the link list has one ore more list nodes connected to
    it */
    else
    {
        list -> tail -> nextRef = nwNode;
        nwNode -> prevRef = list -> tail;
        nwNode -> nextRef = NULL;
        list -> tail = nwNode;
    }
}

void* removeLast(LinkedList *list)
{
    LinkListNode *currNd;
    LinkListNode *lastNd;
    void *valueLastNd;
    /*trying to remove from an empty list*/
    if(list -> head == NULL && list -> tail == NULL)
    {
        printf("ERROR: Link list is empty. Can't remove Last\n");
    }
    /*if the link list has only one list node connected to it*/
    else if(list -> count == 1)
    {
        list ->count--;
        lastNd = list -> tail;
        list -> tail = NULL;
        list -> head = NULL;
        valueLastNd = lastNd -> value;
        free(lastNd);
        lastNd = NULL;
    }
    /*if the link list has 2 or more list nodes connected to it */
    else
    {
        list ->count--;
        currNd = list -> tail -> prevRef;
        lastNd = list -> tail;
        list -> tail = currNd;
        currNd -> nextRef = NULL;
        valueLastNd = lastNd -> value;
        free(lastNd);
        lastNd = NULL;
    }

    return valueLastNd;
}

void* removeFirst(LinkedList *list)
{
    LinkListNode *currNd;
    LinkListNode *firstNd;
    LinkListNode *valueFirstNd;
    /*trying to remove from an empty list */
    if(list -> head == NULL && list -> tail == NULL)
    {
        printf("ERROR: Link list is empty. Can't remove first\n");
    }
    /*if the link list has one node connected to it */
    else if(list -> count  == 1)
    {
        list -> count--;
        firstNd = list -> head;
        list -> tail = NULL;
        list -> head = NULL;
        
        valueFirstNd = firstNd -> value;
        free(firstNd);
        firstNd = NULL;
    }
    /*if the link list has 2 or mote list nodes connected to it */
    else
    {
        list -> count--;
        currNd = list -> head -> nextRef;
        firstNd = list -> head;

        list -> head = currNd;
        currNd -> prevRef = NULL;
        
        valueFirstNd = firstNd -> value;
        firstNd -> nextRef =  NULL;
        free(firstNd);
        firstNd = NULL;
    }

    return valueFirstNd;
}

/*PURPOSE: to display all the values for every single list node in the linked
list */
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

void displayRec(LinkListNode *node, funcPtr fptr)
{
    if(node != NULL)
    {
        /*printf("%s\n",(char*) node -> value);*/
        (fptr)(node -> value); 
        displayRec(node -> nextRef, fptr);
    }
}

/*common primitive data types */
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
void freeLinkedList(LinkedList *list)
{
    freeNodeRec(list -> head);
    free(list);
}

/*PURPOSE: serves as a helper function to freeLinkedList(). The purpose is to 
recursively free nodes given a starting node*/
void freeNodeRec(LinkListNode *node)
{
    if(node != NULL)
    {
        /*creating alterantive stack frames with different node values i.e.
        using recursion */
        freeNodeRec(node -> nextRef);
        
        /*when they is no more stack frames to create, I am going to go back 
        to each stack frame I created adn free the node. If the structures
        value field is a pointer, that needs to be freed aswell */ 
        free(node);
        /*good practice to set freed items to null */
        node = NULL; 
    }
}
