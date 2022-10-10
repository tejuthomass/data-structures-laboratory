#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct queue
{
    int data;
    struct queue *next;
} node;

node *newn, *front = NULL, *rear, *temp;

void enqueue();
void dequeue();
void display();
void freeList();

void main()
{
    int ch;
    clrscr();
    
    printf("$$$ QUEUE IMPLEMENTATION USING LINKED LIST $$$\n");
    
    while (1)
    {
        printf("\nSelect any operation:\n1 - Enqueue\t2 - Dequeue\t3 - Display\t4 - Exit\n\nYour choice: ");
        scanf("%d",&ch);
        
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
		    freeList();
            printf("Successfully exited!\n");
            exit(0);
        default:
            printf("Invalid Choice!!");
        }
    }
}

void enqueue()
{
    newn = (node *) malloc(sizeof(node));
    
    printf("Enter the element: ");
    scanf("%d", &newn->data);
    
    newn->next = NULL;
    
    if (front == NULL)
    {
        front = newn;
        rear = newn;
    }
    else
    {
        rear->next = newn;
        rear = newn;
    }
    
    printf("%d has been successfully enqueued!\n", newn->data);
}    

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue underflow!!\n");
    }
    else
    {
        temp = front;
        front = front->next;
        printf("%d has been successfully dequeued!\n", temp->data);
    }
    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("Queue underflow!!");
    }
    else
    {
        temp = front;
        printf("Your Queue\n");
        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void freeList()
{
    while (front)
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}