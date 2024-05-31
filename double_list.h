// Nicole Andreina Mena Porras C14663

//inicio del codigo double_list.h
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoubleList {
    Node* head;
    Node* tail;
} DoubleList;

DoubleList* createList();
void insertAtBeginning(DoubleList* list, int data);
void insertAtEnd(DoubleList* list, int data);
void insertAtPosition(DoubleList* list, int data, int position);
void deleteNode(DoubleList* list, int data);
Node* searchNode(DoubleList* list, int data);
void printListForward(DoubleList* list);
void printListBackward(DoubleList* list);
void freeList(DoubleList* list);

#endif
// fin del codigo, gracias...
