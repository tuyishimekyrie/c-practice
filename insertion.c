#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    int  j, key;
    printf("Array before sorted by insertion sort\n");
    printf("------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    printf("\nArray after sorted by insertion sort\n");
    printf("------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
}

int main()
{
    int arr[] = {22, 11, 34, -5, 2, 40, 9, 16, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    return 0;
}