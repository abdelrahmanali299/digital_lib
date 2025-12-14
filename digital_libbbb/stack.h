
#pragma once
#ifndef STACK_H
#define STACK_H

#include "lib_types.h"

void initStack(TransactionStack* s);
int isStackEmpty(TransactionStack* s);
void push(TransactionStack* s, Transaction t);
Transaction pop(TransactionStack* s);
void peekStack(TransactionStack* s);
void displayHistory(TransactionStack* s);
void clearStack(TransactionStack* s);

#endif // STACK_H
