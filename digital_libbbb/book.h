#pragma once
#ifndef BOOK_H
#define BOOK_H

#include "lib_types.h"

void initLibrary(BookLinkedList* l);
void addBook(BookLinkedList* list, Book newBook);
Book* searchBookByID(BookLinkedList* list, int id);
void searchBookByTitle(BookLinkedList* list, char title[]);
int deleteBook(BookLinkedList* list, int id);
void displayAllBooks(BookLinkedList* list);
void displayAvailableBooks(BookLinkedList* list);
int countBooks(BookLinkedList* list);
void seedData(BookLinkedList* library);

#endif // BOOK_H