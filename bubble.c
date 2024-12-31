#include <stdio.h>

void bubble_sort(int arr[], int size)
{
    printf("array before sorted\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n-------------------------------------\n");
    printf("Array after sorted\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
}

int main()
{
    int arr[] = {22,11,34,-5,2,40,16,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, size);
    return 0;
}