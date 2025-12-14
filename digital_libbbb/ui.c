#include <stdio.h>
#include "ui.h"

void displayMEMBERMenu() {
    printf("\n====================================\n");
    printf("Digital Library - Data Structures\n");
    printf("====================================\n");
    printf("1. Show all books (Linked List)\n");
    printf("2. Borrow a book (Linked List + Stack + Queue)\n");
    printf("3. Return a book (Linked List + Stack + Queue)\n");
    printf("4. Show transaction history (Stack)\n");
    printf("5. Show queue (Queue)\n");
    printf("6. Undo last transaction (Stack Pop)\n");
    printf("7. Search for a book by title (Linked List Search)\n");
    printf("8. Show only available books (Linked List Filter)\n");
    printf("9. Number of books in the library (Linked List Count)\n");
    printf("10. Show only the last transaction (Stack Peek)\n");
    printf("11. Clear the entire transaction history (Stack Clear)\n");
    printf("12. Show the first ID in the queue (Queue Peek)\n");
    printf("13. Clear the entire queue (Queue Clear)\n");
    printf("14. Show borrowed books for the user (Linked list Display)\n");
    printf("0. Exit\n");
    printf("====================================\n");
    printf("Your choice: ");
}

void displayLIBRARIANMenu() {
    printf("\n====================================\n");
    printf("Digital Library - Data Structures\n");
    printf("====================================\n");
    printf("1. Show all books (Linked List)\n");
    printf("2. Add a new book (Linked List Insert)\n");
    printf("3. Delete a book (Linked List Delete)\n");
    printf("4. Show operation history (Stack)\n");
    printf("5. Undo last operation (Stack Pop)\n");
    printf("6. Search for a book by title (Linked List Search)\n");
    printf("7. Show only available books (Linked List Filter)\n");
    printf("8. Number of books in the library (Linked List Count)\n");
    printf("9. Show only the last operation (Stack Peek)\n");
    printf("10. Clear the entire operations history (Stack Clear)\n");
    printf("0. Exit\n");
    printf("====================================\n");
    printf("Your choice: ");
}