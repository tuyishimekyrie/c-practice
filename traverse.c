#include <stdio.h>

int main() {
    int arr[5] = {1,2,3,4,5};
    int position = 0;
    int element = 0;
    printf("Array Before Insertion\n");
    printf("-----------------------\n");
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++) {
    printf("Element at arr[%d] =  %d\n",i,arr[i]);
    }

}