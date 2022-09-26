#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data; 
    struct node *next;
} node;

node *head = NULL, *newn, *temp, *t;
int n = 0;

void insert();
void delete();
void freeList();
void reverse();
void display();
void length();

void main()
{
    int ch;
    printf("$$$ SINGLY LINKED LIST $$$\n");
    
    while (1)
    {
        printf("\nSelect any operation:\n1 - Insert/Append a node\n2 - Delete a node\n3 - Delete the list\n4 - Reverse\n5 - Display\n6 - Know it's length\n7 - Exit\n\nYour choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                freeList();
                printf("Successfully deleted the list!\n");
                break;
            case 4:
                reverse();
                break;
            case 5:
                display();
                break;
            case 6:
                length();
                break;
            case 7:
                freeList();
                printf("Successfully exited!\n");
                exit(0);
            default:
                printf("Invalid Choice!!");
        }
    }
}

void insert()
{
    int op = 1, i;
    
    newn = (node *) malloc(sizeof(node));

    printf("Enter the element: ");
    scanf("%d", &newn->data);
    
    if (n > 0)
    {
        printf("Enter it's position: ");
        scanf("%d", &op);
    }
    
    if ((op < 1) || (op > n + 1))
    {
        printf("Invalid position!\n");
        free(newn);
        return;
    }
    
    else if (op == n + 1)
    {
        if (head == NULL)
        {
            head = newn; 
            head->next = NULL;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->next = NULL;
        }
    }
    
    else
    {
        if (op == 1)
        {
            newn->next = head;
            head = newn;
        }
        else
        {
            temp = head;
            for (i = 1; i < op - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
        }
    }
    printf("Successfully added!\n");
    n++;
}

void delete()
{
    int op, no, i;
    
    if (head == NULL)
    {
        printf("Your list is empty\n");
    }
    else
    {
        printf("Enter it's position: ");
        scanf("%d", &op);
        
        if ((op < 1) || (op > n))
        {
            printf("Invalid position!\n");
            return;
        }
        
        if (op == 1)
        {
            if (head->next == NULL)
            { 
                head = NULL;
            }
            else
            {
                temp = head;
                head = head->next;
                free(temp);
            }
        }
        else if (op == n)
        {
            temp = head;
            for (i = 1; i < n - 1; i++)
            {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
        else
        {
            temp = head;
            for (i = 1; i < op; i++)
            {
                t = temp;
                temp = temp->next;
            }
            t->next = temp->next;
            free(temp);
        }
        
        printf("Successfully deleted!\n");
        n--;
    }
}

void reverse()
{
    t = NULL;
    temp = head;
    
    while (temp)
    {
        newn = temp->next;
        temp->next = t;
        t = temp;
        temp = newn;
    }
    head = t;
    printf("Your list has been successfully reversed!\n");
}

void display()
{
    int i;
    
    if (head == NULL)
    { 
        printf("Your list is empty\n");
    }
    else
    {
        temp = head;
        printf("\nYour list\nPosition\tElement");
        for (i = 0; temp != NULL; i++)
        {
            printf("\n%d\t\t%d", i + 1, temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void length()
{
    printf("Length: %d\n", n);
}

void freeList()
{
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}