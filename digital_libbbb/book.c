#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_types.h"
#include "book.h"

void initLibrary(BookLinkedList* l) {
    l->head = NULL;
}

void addBook(BookLinkedList* list, Book newBook) {
    NodeBook* newNode = (NodeBook*)malloc(sizeof(NodeBook));
    newNode->data = newBook;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        printf("The first book has been successfully added.\n");
        return;
    }

    NodeBook* temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("The book has been added: %s\n", newBook.title);
}

Book* searchBookByID(BookLinkedList* list, int id) {
    NodeBook* temp = list->head;
    while (temp != NULL) {
        if (temp->data.bookID == id)
            return &temp->data;
        temp = temp->next;
    }
    return NULL;
}

void searchBookByTitle(BookLinkedList* list, char title[]) {
    NodeBook* temp = list->head;
    while (temp != NULL) {
        if (strcmp(temp->data.title, title) == 0) {
            printf("The book is available | ID: %d | Author: %s\n",
                temp->data.bookID, temp->data.author);
            return;
        }
        temp = temp->next;
    }
    printf("The book is not available.\n");
}

int deleteBook(BookLinkedList* list, int id) {
    NodeBook* temp = list->head;
    NodeBook* prev = NULL;

    if (temp != NULL && temp->data.bookID == id) {
        list->head = temp->next;
        free(temp);
        return 1;
    }

    while (temp != NULL && temp->data.bookID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return 0;

    prev->next = temp->next;
    free(temp);
    return 1;
}

void displayAllBooks(BookLinkedList* list) {
    NodeBook* temp = list->head;

    if (!temp) {
        printf("The library is empty.\n");
        return;
    }

    printf("\n=================================================================\n");
    printf("| ID | %-30s | %-20s | Available? |\n", "title", "Author");
    printf("=================================================================\n");

    while (temp) {
        printf("| %-2d | %-30s | %-20s | %s |\n",
            temp->data.bookID,
            temp->data.title,
            temp->data.author,
            temp->data.isAvailable ? "Yes" : "NO");
        temp = temp->next;
    }
    printf("=================================================================\n");
}

void displayAvailableBooks(BookLinkedList* list) {
    NodeBook* temp = list->head;
    while (temp) {
        if (temp->data.isAvailable)
            printf("ID: %d | %s\n", temp->data.bookID, temp->data.title);
        temp = temp->next;
    }
}

int countBooks(BookLinkedList* list) {
    int count = 0;
    NodeBook* temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void seedData(BookLinkedList* library) {
    addBook(library, (Book) { 101, "C Programming", "Dennis Ritchie", 1 });
    addBook(library, (Book) { 102, "Data Structures", "Wirth", 1 });
    addBook(library, (Book) { 103, "Operating Systems", "Silberschatz", 1 });
    addBook(library, (Book) { 104, "Algorithms", "Cormen", 0 });
}