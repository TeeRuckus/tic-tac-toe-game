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
    typedef void (*filePrintPtr)(void*, FILE*);
    LinkedList* createLinkedList();
    int getCount(LinkedList *list);
    LinkListNode getHead();
    LinkListNode getTail();
    int isEmpty();
    void peekFirst();
    void peekLast();
    void insertFirst(LinkedList *list, void *inValue);
    void insertLast();
    void* removeLast(LinkedList *list);
    void* removeFirst(LinkedList *list);
    void display(LinkedList *list, funcPtr);
    Status displayToFile(LinkedList *list,FILE *strmName, filePrintPtr fptr);
    void displayRec(LinkListNode *node, funcPtr);
    void displayFileRec(LinkListNode *node,FILE *strmName, filePrintPtr fptr);
    void printInt(void *data);
    void printFloat(void *data); 
    void printChar(void *data);
	void printString(void *data);
    void freeLinkedList(LinkedList *list, funcPtr fptr);
    void freeNodeRec(LinkListNode *node, funcPtr fptr);
    void freePrimitives(void *data);
#endif
