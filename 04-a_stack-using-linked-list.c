#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct stack
{
    int data;
    struct stack *next;
} node;

node *newn, *top = NULL, *temp;

void push();
void pop();
void display();

void main()
{
    int ch;
    
    clrscr();
    printf("$$$ STACK IMPLEMENTATION USING LINKED LIST $$$\n");
    
    while (1)
    {
        printf("\nSelect any operation:\n1 - PUSH\n2 - POP\n3 - DISPLAY\n4 - EXIT\n\nYour choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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

void push()
{
    newn = (node *)malloc(sizeof(node));

    printf("Enter the element: ");
    scanf("%d", &newn->data);

    if (top == NULL)
    {
        newn->next = NULL;
    }
    else
    {
        newn->next = top;
    }
    top = newn;
    printf("%d has been successfully pushed into stack!\n", newn->data);
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack underflow!!\n");
    }
    else
    {
        printf("%d has been successfully popped out of stack!\n", top->data);
        temp = top;
        top = top->next;
    }
    free(temp);
}

void display()
{
    if(top == NULL)
    {
        printf("Stack underflow!!\n");
    }
    else
    {
        
        printf("Your stack:\n");
        for (temp = top; temp != NULL; temp = temp->next)
        {
            printf("%d\n", temp->data);
        }
    }
}