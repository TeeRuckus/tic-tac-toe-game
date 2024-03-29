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

/*ASSERTS: returns the number of LinkedList node in the link list */
int getCount(LinkedList *list)
{
    int count; 
    count = list -> count;
    return count;
}

/*ASSERTS: it adds a linked list node to the head reference of the linked list*/
void insertFirst(LinkedList *list, void *inValue)
{   
    LinkListNode *nwNode;
    nwNode = (LinkListNode*)malloc(sizeof(LinkListNode));
    nwNode -> value = inValue;
    /*the  count variable will be used to determine if they is only one item on
    the linked list */
    list -> count++;
    
    nwNode -> nextRef = list -> head;
    nwNode -> prevRef = NULL;

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
        the itesm correctly */ 
        list -> head -> prevRef =  nwNode;
    }
    
    list -> head = nwNode;
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
        /*since this is  a doubly linked list, inserting last is very simple.
        we can just go straight to the refererence and set the next reference 
        as our new node, then we can link the new node's reference back to the
        node */ 
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
        valueLastNd = NULL;
    }
    /*if the link list has only one list node connected to it*/
    else if(list -> count == 1)
    {
        /* if we only have one node on the list, we can just delete the whole
        linked list, by the only node to null and freeing it. Furthermore,
        we need to  set the head and  tail reference to NULL*/
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
        /*we need to take greater care here! Since this is a doubly linked list 
        we can jump to the tail reference and grab it's previous reference. Before
        we set its next reference to NULL. We need to make a note of where that
        node is as C doesn't have automatic garabage collection. Hence, once
        we make a note were the last reference is we can set the previous nodes
        next reference to null, and free and set the last node to NULL*/
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
        /*if the linked list has only one node attached to it, we can
        set the whole  linked list to NULL*/
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
        /*Care has to be taken here! The current node is the node  which is
        after the first node (the node to be deleted) we need to do this so
        we can link the rest of out linked list to our head reference otherwise,
        if this is not done our linked list we be lost forever!!!! Once the 
        current node overides the position of the first node. We can free and
        set the first node to NULL*/
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
        /*displaying all the nodes recursively in order they're inserted as 
        we're printing out the value before we create another stack frame */
        (fptr)(node -> value); 
        displayRec(node -> nextRef, fptr);
    }
}

/*common primitive data types: the following print functions are to be used in 
conjuction with the display method */
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

void freePrimitives(void *data)
{
    free(data);
    data = NULL;
}
