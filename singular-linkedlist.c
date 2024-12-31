

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

struct node *add_at_beginning(struct node *head, int data)
{
    struct node *currentn = (node *)malloc(sizeof(node));
    currentn->data = data;
    currentn->link = head;
    return currentn;
}
struct node* add_at_end(struct node* head,int data) {
    struct node *currentn = (node*)malloc(sizeof(node));
    currentn->data=data;
    currentn->link=NULL;

    if(head == NULL) {
        return currentn;
    }

    struct node* temp = head;
    while(temp->link != NULL) {
        temp = temp -> link;
    }
    temp-> link = currentn;
    
    return head;
}

void print_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;

    node *current = (node *)malloc(sizeof(node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    node *current2 = (node *)malloc(sizeof(node));
    current2->data = 3;
    current2->link = NULL;
    current->link = current2;

    int data = 3;
    head = add_at_beginning(head, data);

    int val2 =4;
    current2 = add_at_end(current2,val2);

    print_list(head);

    // Free the allocated memory
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->link;
        free(temp);
    }

    return 0;
}
