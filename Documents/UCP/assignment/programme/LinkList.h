#ifndef LINKLIST_H
#define LINKLIST_H
    typedef struct LinkListNode
    {
        void *value;
        struct LinkListNode *nextRef;
        struct LinkListNode *prevRef;

    }LinkListNode;

    typedef struct
    {
        LinkListNode *head;
        LinkListNode *tail;
        int count;
    }LinkedList;
    
    typedef void (*funcPtr)(void*);
    LinkedList* createLinkedList();
    int getCount(LinkedList *list);
    LinkListNode getHead();
    LinkListNode getTail();
    int isEmpty();
    void peekFirst();
    void peekLast();
    void insertFirst(LinkedList *list, void *inValue);
    void insertLast();
    void* removeLast();
    void* removeFirst();
    void display(LinkedList *list, funcPtr);
    void displayRec(LinkListNode *node, funcPtr);
    void printInt(void *data);
    void printFloat(void *data); 
    void printChar(void *data);
	void printString(void *data);
    void freeLinkedList(LinkedList *list, funcPtr fptr);
    void freeNodeRec(LinkListNode *node, funcPtr fptr);
    void freePrimitives(void *data);
#endif
