#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void insert(Node** head, int value);
void delete(Node** head, int value);
void display(Node* head);
void freeList(Node** head);

int main() {
    Node* head = NULL; // Initialize the linked list
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the allocated memory
    freeList(&head);

    return 0;
}

// Function to insert a new node at the end of the list
void insert(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; // The list was empty
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Value %d inserted successfully.\n", value);
}

// Function to delete a node with a specific value
void delete(Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // Check if the head node contains the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Value %d deleted successfully.\n", value);
        return;
    }

    // Search for the value in the list
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Value not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Value %d deleted successfully.\n", value);
}

// Function to display the elements of the list
void display(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the entire list
void freeList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}
