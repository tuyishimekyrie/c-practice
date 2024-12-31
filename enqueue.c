#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} IntQueue;


void initializeQueue(IntQueue *queue)
{
    queue->front = 0;
    queue->rear = -1;
}

int isEmpty(IntQueue *queue)
{
    return queue->rear < queue->front;
}

void enqueue(IntQueue *queue, int value)
{
    if (queue->rear == MAX_SIZE - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    queue->items[++queue->rear] = value;
}

int main()
{
    IntQueue queue;
    initializeQueue(&queue);

    int size;

    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    
    for (int i = 1; i <= size; i++)
    {
        printf("Enter value at position %d ",i);
        scanf("%d",&queue.items[i]);
    }
    

    enqueue(&queue, queue.items[1]);
    enqueue(&queue, queue.items[2]);
    enqueue(&queue, queue.items[3]);

    printf("Print Element in the queue\n");
    for (int i = queue.front; i <= queue.rear; i++)
    {
        printf("%d\n", queue.items[i]);
    }

    printf("the length of the rear queue : %d\n", queue.rear);
    printf("the length of the front queue is : %d\n", queue.front);
    printf("the size of the queue is : %d", queue.rear - queue.front + 1);

    return 0;
}