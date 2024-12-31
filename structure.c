#include <stdio.h> 
#include <stdlib.h> 
#define MAX 5 // Maximum size of the stack
// Stack structure definition
struct Stack
{
    int items[MAX]; // Array to hold the elements
    int top;        // Variable to track the top of the stack
};
void initStack(struct Stack *s)
{
    s->top = -1;
}
int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}
void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack is full. Cannot push %d\n", value);
    }
    else
    {
        s->items[++(s->top)] = value;
        printf("%d pushed to stack\n", value);
    }
}
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty. Cannot pop\n");
        return -1; // Return an invalid value or error
    }
    else
    {
        int value = s->items[s->top--];
        return value;
    }
}
int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}
int main()
{
    struct Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Top element is %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    if (isEmpty(&s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
    return 0;
}