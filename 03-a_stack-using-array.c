#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 5

void push();
void pop();
void display();

int s[SIZE], top = -1, i, item;

void main()
{
    int ch;
    
    clrscr();
    printf("$$$ STACK IMPLEMENTATION USING ARRAY $$$\n");
    
    while (1)
    {
        printf("\nSelect any operation:\n1 - PUSH\n2 - POP\n3 - DISPLAY\n4 - EXIT\n\nYour choice: ");
        scanf("%d", &ch);
        
        switch(ch)
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
    if(top == SIZE - 1)
    {
        printf("Stack overflow!!\n");
    }
    else
    {
        top++;
        printf("Enter the element: ");
        scanf("%d", &s[top]);
        printf("%d has been successfully pushed into stack!\n", s[top]);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack underflow!!\n");
    }
    else
    {
        printf("%d has been successfully popped out of stack!\n", s[top]);
        top--;
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack underflow!!\n");
    }
    else
    {
        printf("Your stack:\n");
        for(i = top; i >= 0; i--)
        {
            printf("%d\n", s[i]);
        }
    }
}