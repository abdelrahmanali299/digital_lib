#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_types.h"
#include "book.h"
#include "queue.h"
#include "user.h"
#include "ui.h"
#include "stack.h"


int main() {
    BookLinkedList library;
    HoldQueue queue;
    TransactionStack stack;
    UserLinkedList users;
    User* currentUser;

    initLibrary(&library);
    initQueue(&queue);
    initStack(&stack);
    initUsers(&users);

    seedData(&library);
    seedUsers(&users);

    int uid;
    printf("Enter your user ID: ");
    if (scanf("%d", &uid) != 1) return 0;
    getchar();

    currentUser = findUser(&users, uid);
    if (!currentUser) {
        printf("User not found.\n");
        return 0;
    }

    printf("Hello %s \n", currentUser->name);

    int choice = -1, id;
    char title[100];

    do {
        if (currentUser->role == LIBRARIAN) displayLIBRARIANMenu();
        else displayMEMBERMenu();

        if (scanf("%d", &choice) != 1) break;
        getchar();

        if (currentUser->role == LIBRARIAN) {
            switch (choice) {
            case 1: displayAllBooks(&library); break;
            case 2:
                printf("Enter the new book ID: ");
                scanf("%d", &id); getchar();
                printf("Enter the book title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0;
                addBook(&library, (Book) { id, "", "Unknown", 1 });
                strcpy(searchBookByID(&library, id)->title, title);
                push(&stack, (Transaction) { "Add", id, currentUser->userID });
                break;
            case 3:
                printf("Enter the book ID to delete: ");
                scanf("%d", &id); getchar();
                if (deleteBook(&library, id))
                    push(&stack, (Transaction) { "Delete", id, currentUser->userID });
                else
                    printf("Deletion failed.\n");
                break;
            case 4: displayHistory(&stack); break;
            case 5: pop(&stack); break;
            case 6:
                printf("Enter the book title to search: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0;
                searchBookByTitle(&library, title);
                break;
            case 7: displayAvailableBooks(&library); break;
            case 8: printf("Number of books in the library: %d\n", countBooks(&library)); break;
            case 9: peekStack(&stack); break;
            case 10: clearStack(&stack); break;
            }
        }
        else { // MEMBER
            switch (choice) {
            case 1: displayAllBooks(&library); break;
            case 2:
                printf("Enter the book ID to borrow: ");
                scanf("%d", &id); getchar();
                if (currentUser->borrowedCount >= 3) {
                    printf("You cannot borrow more than 3 books !\n");
                    break;
                }
                {
                    Book* b = searchBookByID(&library, id);
                    if (b && b->isAvailable) {
                        b->isAvailable = 0;
                        currentUser->borrowedCount++;
                        addBorrowedBook(currentUser, id);
                        push(&stack, (Transaction) { "Borrow", id, currentUser->userID });
                        printf("Borrow completed: %s\n", b->title);
                    }
                    else {
                        enqueue(&queue, id);
                    }
                }
                break;
            case 3:
                printf("Enter the book ID for return: ");
                scanf("%d", &id); getchar();
                if (!removeBorrowedBook(currentUser, id)) {
                    printf("This book is not for loan.\n");
                    break;
                }
                {
                    Book* b = searchBookByID(&library, id);
                    if (b) {
                        b->isAvailable = 1;
                        currentUser->borrowedCount--;
                        push(&stack, (Transaction) { "Return", id, currentUser->userID });
                        int nextID = dequeue(&queue);
                        if (nextID != -1)
                            printf(" Book ID %d is now available for the next person on the list.\n", nextID);
                    }
                }
                break;
            case 4: displayHistory(&stack); break;
            case 5: displayQueue(&queue); break;
            case 6: pop(&stack); break;
            case 7:
                printf("Enter the book title to search: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = 0;
                searchBookByTitle(&library, title);
                break;
            case 8: displayAvailableBooks(&library); break;
            case 9: printf("Number of books in the library: %d\n", countBooks(&library)); break;
            case 10: peekStack(&stack); break;
            case 11: clearStack(&stack); break;
            case 12: peekQueue(&queue); break;
            case 13: clearQueue(&queue); break;
            case 14: displayUserBorrowedBooks(currentUser); break;
            }
        }

    } while (choice != 0);

    printf("Thank you for using the library system. Goodbye!\n");
    return 0;
}
