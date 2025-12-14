#pragma once
#ifndef LIB_TYPES_H
#define LIB_TYPES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
    int bookID;
    char title[100];
    char author[100];
    int isAvailable;
} Book;

typedef struct Transaction {
    char type[20];
    int bookID;
    int userID;
} Transaction;

typedef enum { LIBRARIAN, MEMBER } Role;

typedef struct BorrowedNode {
    int bookID;
    struct BorrowedNode* next;
} BorrowedNode;

typedef struct User {
    int userID;
    char name[50];
    Role role;
    int borrowedCount;
    BorrowedNode* borrowedHead;
} User;

typedef struct NodeBook {
    Book data;
    struct NodeBook* next;
} NodeBook;

typedef struct NodeInt {
    int data;
    struct NodeInt* next;
} NodeInt;

typedef struct NodeTransaction {
    Transaction data;
    struct NodeTransaction* next;
} NodeTransaction;

typedef struct NodeUser {
    User data;
    struct NodeUser* next;
} NodeUser;

typedef struct {
    NodeBook* head;
} BookLinkedList;

typedef struct {
    NodeUser* head;
} UserLinkedList;

typedef struct {
    NodeInt* front;
    NodeInt* rear;
} HoldQueue;

typedef struct {
    NodeTransaction* top;
} TransactionStack;

#endif // LIB_TYPES_H