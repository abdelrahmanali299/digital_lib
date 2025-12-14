#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_types.h"

void initStack(TransactionStack* s) {
    s->top = NULL;
}

int isStackEmpty(TransactionStack* s) {
    return s->top == NULL;
}

void push(TransactionStack* s, Transaction t) {
    NodeTransaction* newNode = (NodeTransaction*)malloc(sizeof(NodeTransaction));
    newNode->data = t;
    newNode->next = s->top;
    s->top = newNode;
}

Transaction pop(TransactionStack* s) {
    Transaction empty = { "", -1, -1 };
    if (isStackEmpty(s)) return empty;

    NodeTransaction* temp = s->top;
    Transaction t = temp->data;
    s->top = temp->next;
    free(temp);
    return t;
}

void peekStack(TransactionStack* s) {
    if (isStackEmpty(s)) {
        printf("The transaction log is empty..\n");
        return;
    }
    printf("Last operation: %s | Book ID: %d\n",
        s->top->data.type, s->top->data.bookID);
}

void displayHistory(TransactionStack* s) {
    NodeTransaction* temp = s->top;
    int count = 0;
    if (!temp) {
        printf("The transaction log is empty..\n");
        return;
    }
    printf("\n=== The last 5  completed transactions (Stack): ===\n");
    while (temp && count < 5) {
        printf("- type: %s | Book ID: %d\n",
            temp->data.type, temp->data.bookID);
        temp = temp->next;
        count++;
    }
}

void clearStack(TransactionStack* s) {
    while (!isStackEmpty(s))
        pop(s);
    printf("The entire transaction history has been cleared.\n");
}