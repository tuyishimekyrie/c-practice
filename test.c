#include <stdio.h>

void askUserName()
{
    char name[50];
    printf("Enter your name: ");
    scanf("%s", &name);
    printf("Your name is :  %s", name);
}

struct patients {
    int beds;
    double prices;
};

void largestNumberIndex() {
    int arr[5] = {1,2,3,4,5};
    int index;
    int size = sizeof(arr) / sizeof(arr[0]); // 5
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
       if(max < arr[i]) {
           max = arr[i];
           index = i;
       }
    }
    printf("Largest Number is %d\n", max);
    printf("Index of largest number is %d",index);
    
}
int main()
{
    struct patients patient;
    patient.beds = 2;
    patient.prices = 10,000;

    // largestNumberIndex();

  askUserName();
    return 0;
}
