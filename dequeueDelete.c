#include <stdio.h>  
  
int main() {  
    int size = 10;    
    int te = 0;       
    int R = -1;     // Initialize the rear pointer (assuming -1 means empty queue)  
    int arr[10];    // Define the array to hold the queue elements  
  
    int new_item = 42;  // Replace this with the actual item you want to add  
  
    if (te == size) {  
        printf("Queue is full\n");  
    } else {  
        R = (R + 1) % size;  
        arr[R] = new_item;  
        te = te + 1;  
        printf("Item %d added to the queue at position %d\n", new_item, R);  
    }  
    if (te == 0) {  
        printf("Queue is empty\n");  
    } else {  
        if (R == -1) {  
            R = size - 1;  
        }  
        printf("Number Deleted From Rear End = %d\n", arr[R]);  
        R = (R - 1 + size) % size;  
        te = te - 1;  
    }  
  
    printf("Queue contents: ");  
    for (int i = 0; i < te; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
  
    return 0;  
}  