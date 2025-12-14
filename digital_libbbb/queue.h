#ifndef QUEUE_H
#define QUEUE_H

#include "lib_types.h"

void initQueue(HoldQueue* q);
int isQueueEmpty(HoldQueue* q);
void enqueue(HoldQueue* q, int bookID);
int dequeue(HoldQueue* q);
void displayQueue(HoldQueue* q);
void peekQueue(HoldQueue* q);
void clearQueue(HoldQueue* q);

#endif // QUEUE_H#pragma once
