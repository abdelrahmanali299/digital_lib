#include <stdio.h>
#include <stdlib.h>
#include "lib_types.h"
#include "queue.h"

void initQueue(HoldQueue* q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(HoldQueue* q) {
    return q->front == NULL;
}

void enqueue(HoldQueue* q, int bookID) {
    NodeInt* newNode = (NodeInt*)malloc(sizeof(NodeInt));
    newNode->data = bookID;
    newNode->next = NULL;

    if (!q->rear) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    printf("The book is unavailable. You have been added to the waiting list. ID: %d\n", bookID);
}

int dequeue(HoldQueue* q) {
    if (isQueueEmpty(q)) return -1;

    NodeInt* temp = q->front;
    int id = temp->data;
    q->front = temp->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return id;
}

void displayQueue(HoldQueue* q) {
    NodeInt* temp = q->front;
    if (!temp) {
        printf("The borrow waiting list is empty..\n");
        return;
    }

    printf("\n=== Borrow waiting list (IDs): ");
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" -> ");
        temp = temp->next;
    }
    printf(" ===\n");
}

void peekQueue(HoldQueue* q) {
    if (isQueueEmpty(q))
        printf("The waiting list is empty.\n");
    else
        printf("First ID in the queue: %d\n", q->front->data);
}

void clearQueue(HoldQueue* q) {
    while (!isQueueEmpty(q))
        dequeue(q);
    printf("✔ The entire waiting list has been cleared.\n");
}