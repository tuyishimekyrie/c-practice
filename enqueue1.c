#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void enqueue(int **queue, int *size, int value);
void printQueue(int *queue, int size);
void freeQueue(int **queue);

int main() {
    int *queue = NULL; // Pointer for dynamic queue
    int size = 0;      // Current size of the queue
    int n, value;

    // Prompt user for the number of elements
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size. Exiting.\n");
        return 1;
    }

    // Enqueue user-provided integers
    for (int i = 0; i < n; i++) {
        printf("Enter an integer to enqueue: ");
        scanf("%d", &value);
        enqueue(&queue, &size, value);
    }

    // Print each element of the queue
    printf("Queue elements:\n");
    printQueue(queue, size);

    // Display the size of the queue
    printf("Size of the queue: %d\n", size);

    // Deallocate memory
    freeQueue(&queue);

    return 0;
}

// Function to enqueue an element
void enqueue(int **queue, int *size, int value) {
    *queue = realloc(*queue, (*size + 1) * sizeof(int));
    if (*queue == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    (*queue)[*size] = value; // Add the new value at the end
    (*size)++;              // Increment the size
}

// Function to print the queue
void printQueue(int *queue, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Function to free the allocated memory
void freeQueue(int **queue) {
    free(*queue);
    *queue = NULL;
}
