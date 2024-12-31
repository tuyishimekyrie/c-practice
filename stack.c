#include <stdio.h>
#define max 5       // preprosesor directive to declare size of stack
int stack_arr[max]; // global declaration of stack_arr[]
int top = -1;
void push(int data)
{
    if (top == max - 1)
    {
        printf("stack is oveflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}
void display()
{
    printf("Stack Element:");
    for (int i = 0; i < max; i++)
    {
        printf("%d ", stack_arr[i]);
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(5);
    push(6);
    display();
}