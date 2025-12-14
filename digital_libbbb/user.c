#include <stdio.h>
#include <stdlib.h>
#include "lib_types.h"
#include "user.h"

void initUsers(UserLinkedList* u) {
    u->head = NULL;
}

void addUser(UserLinkedList* l, User u) {
    NodeUser* n = malloc(sizeof(NodeUser));
    n->data = u;
    n->data.borrowedHead = NULL;
    n->next = l->head;
    l->head = n;
}

User* findUser(UserLinkedList* l, int id) {
    NodeUser* t = l->head;
    while (t) { if (t->data.userID == id) return &t->data; t = t->next; }
    return NULL;
}

void addBorrowedBook(User* u, int id) {
    BorrowedNode* n = malloc(sizeof(BorrowedNode));
    n->bookID = id;
    n->next = u->borrowedHead;
    u->borrowedHead = n;
}

int removeBorrowedBook(User* u, int id) {
    BorrowedNode* t = u->borrowedHead, * p = NULL;
    while (t && t->bookID != id) { p = t; t = t->next; }
    if (!t) return 0;
    if (!p) u->borrowedHead = t->next;
    else p->next = t->next;
    free(t);
    return 1;
}

void displayUserBorrowedBooks(User* u) {
    BorrowedNode* t = u->borrowedHead;
    if (!t) { printf("No books available for borrowing.\n"); return; }
    while (t) { printf("%d ", t->bookID); t = t->next; }
    printf("\n");
}

void seedUsers(UserLinkedList* u) {
    addUser(u, (User) { 1, "Admin", LIBRARIAN, 0, NULL });
    addUser(u, (User) { 2, "Ahmed", MEMBER, 0, NULL });
}