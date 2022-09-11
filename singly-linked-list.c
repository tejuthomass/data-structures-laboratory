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
void display();

void main()
{
    int ch;
    printf("$$$ SINGLY LINKED LIST $$$\n");
    
    while (1)
    {
        printf("\nSelect any operation:\n1 - Insert/Append\t2 - Delete\t3 - Display\t4 - Exit\n\nYour choice: ");
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
                display();
                break;
            case 4:
                free(head);
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
    
    // Append
    else if (op == n + 1)
    {
        if (head == NULL)
        {
            head = newn; // **
            head->next = NULL;
        }
        else
        {
            temp = head;
            while (temp->next != NULL) // **
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->next = NULL;
        }
    }
    
    // Insert
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
            for (i = 0; i < op - 2; i++)
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
            for (i = 0; i < n - 2; i++)
            {
                temp = temp->next;
            }
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
        }
        
        printf("Successfully deleted!\n");
        n--;
    }
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