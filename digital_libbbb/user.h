#ifndef USER_H
#define USER_H

#include "lib_types.h"

void initUsers(UserLinkedList* u);
void addUser(UserLinkedList* l, User u);
User* findUser(UserLinkedList* l, int id);
void addBorrowedBook(User* u, int id);
int removeBorrowedBook(User* u, int id);
void displayUserBorrowedBooks(User* u);
void seedUsers(UserLinkedList* u);

#endif // USER_H#pragma once
