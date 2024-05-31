// Nicole Mena Porras C14663
//este es el codigo en c que hice para el double list:

#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

DoubleList* createList() {
    DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}
void insertAtBeginning(DoubleList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }

    list->head = newNode;
}
void insertAtEnd(DoubleList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }

    list->tail = newNode;
}
void insertAtPosition(DoubleList* list, int data, int position) {
    if (position == 0) {
        insertAtBeginning(list, data);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* current = list->head;

    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        insertAtEnd(list, data);
    } else {
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        } else {
            list->tail = newNode;
        }

        current->next = newNode;
    }
}
void deleteNode(DoubleList* list, int data) {
    Node* current = list->head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) return;

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
}
Node* searchNode(DoubleList* list, int data) {
    Node* current = list->head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

void printListForward(DoubleList* list) {
    Node* current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}
void printListBackward(DoubleList* list) {
    Node* current = list->tail;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }

    printf("\n");
}
void freeList(DoubleList* list) {
    Node* current = list->head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}
// fin del codigo, gracias...
