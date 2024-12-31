// Implements a stack using an array in C to push integer values and print the
// elements in stack.

#include <stdio.h>

int max = 5;

int stack_arr[5];
int top = -1;

void push(int data)
{

    if (top == max - 1)
    {
        printf("Stack Array is full");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}
void display()
{
    for (int i = 0; i < 5; i++)
    {
        printf("value is %d\n", stack_arr[i]);
    }
}
int main()
{

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();

    return 0;
}