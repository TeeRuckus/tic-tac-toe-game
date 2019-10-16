/*******************************************************************************
*   FILE: LinkList.h                                                           *
*   AUTHOR: Tawana David Kwaramba                                              *
*   STUDENT ID: 19476700                                                       *
*   DATE CREATED: 30/09/19                                                     *
*   DATE LAST MODIFIED:                                                        *
*   PURPOSE OF FILE: contains all the functions protoypes and data type        *
*                    declarations for the the file linkList.c                  *
*******************************************************************************/
#ifndef LINKLIST_H
#define LINKLIST_H

    /*this structure is to represent the node of the linked list which contain
    the nodes value and next and previous references. This is what is stored
    inside the linked list*/
    typedef struct LinkListNode
    {
        void *value;
        struct LinkListNode *nextRef;
        struct LinkListNode *prevRef;

    }LinkListNode;

    /*this structure is to represent the abstract data structure of a linked
    list which contains the linked lists head and tail reference*/
    typedef struct
    {
        LinkListNode *head;
        LinkListNode *tail;
        int count;
    }LinkedList;
    
    typedef void (*funcPtr)(void*);
    typedef void (*filePrintPtr)(void*, FILE*);
    LinkedList* createLinkedList();
    int getCount(LinkedList *list);
    void insertFirst(LinkedList *list, void *inValue);
    void insertLast(LinkedList *list, void *inValue);
    void* removeLast(LinkedList *list);
    void* removeFirst(LinkedList *list);
    void display(LinkedList *list, funcPtr);
    void displayRec(LinkListNode *node, funcPtr fptr);
    Status displayToFile(LinkedList *list,FILE *strmName, filePrintPtr fptr);
    void displayFileRec(LinkListNode *node,FILE *strmName, filePrintPtr fptr);
    void printInt(void *data);
    void printFloat(void *data); 
    void printChar(void *data);
	void printString(void *data);
    void freeLinkedList(LinkedList *list, funcPtr fptr);
    void freeNodeRec(LinkListNode *node, funcPtr fptr);
    void freePrimitives(void *data);
#endif
