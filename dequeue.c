#include <stdio.h>
#include <stdlib.h>

int main()
{

    int size = 10; // Define the size of the queue
    int te = 0;
    int R = -1;  // Initialize the rear pointer (assuming -1 means empty queue)
    int arr[10]; // Define the array to hold the queue elements

    int new_item = 42;

    if (te == size)
    {

        printf("Queue is full\n");
    }
    else
    {

        R = (R + 1) % size;

        arr[R] = new_item;
        te = te + 1;
        printf("Item %d added to the queue at position %d\n", new_item, R);
    }
    printf("Queue contents: ");
    for (int i = 0; i < te; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
