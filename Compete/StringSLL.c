#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100]; // Assuming a maximum string length of 100 characters
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertDoubly(char* value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void deleteDoubly(char* value) {
    struct Node* current = head;

    while (current != NULL && strcmp(current->data, value) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the doubly linked list.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}

void traverseDoubly() {
    struct Node* current = head;
    printf("Doubly Linked List (forward): ");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    printf("Doubly Linked List (backward): ");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    insertDoubly("A");
    insertDoubly("B");
    insertDoubly("C");

    traverseDoubly();

    deleteDoubly("B");

    traverseDoubly();

    return 0;
}
