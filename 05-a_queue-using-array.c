#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5

void enqueue();
void dequeue();
void display();

int q[SIZE], front = -1;

void main()
{
    int ch;
    clrscr();
    
    printf("$$$ QUEUE IMPLEMENTATION USING ARRAY $$$\n");
    
    while (1)
    {
        printf("\nSelect any operation:\n1 - Enqueue\t2 - Dequeue\t3 - Display\t4 - Exit\n\nYour choice: ");
        scanf("%d", &ch);
    
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
            printf("Successfully exited!\n");
            exit(0);
        default:
            printf("Invalid Choice!!");
        } 
    }
}

void enqueue()
{
    int i;
    
    if (front == SIZE - 1)
    {
        printf("Queue overflow!!\n");
    }
    else
    {
        for (i = front; i >= 0; i--)
        {
            q[i + 1] = q[i];
        }
        printf("Enter the element: ");
        scanf("%d", &q[0]);
        printf("%d has been successfully enqueued!\n", q[0]);
        front++;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow!!\n");
    }
    else
    {
        printf("%d has been successfully dequeued!\n", q[front]);
        front--;
    }
}

void display()
{
    int i;
    
    if (front == -1)
    {
        printf("Queue underflow!!\n");
    }
    else
    {
        printf("Your Queue\n");
        for(i = 0; i <= front; i++)
        {
            printf("%d\n", q[i]);
        }
    }
}
