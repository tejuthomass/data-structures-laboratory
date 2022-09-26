#include <stdio.h>
#include <stdlib.h>

int *list, n = 0;

void create();
void insert();
void delete();
void display();

void main()
{
    int c;
    
    printf("$$$ LIST ADT USING ARRAY $$$\n");
   
    while (1)
    {
        printf("\nSelect any operation:\n1 - Create\t2 - Insert/Append\t3 - Delete\t4 - Display\t5 - Exit\n\nYour choice: ");
        scanf("%d", &c);
       
        switch(c)
        {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                if (n > 0)
                {
                    delete();
                }
                else
                {
                    printf("Your list is empty!\n");
                }
                break;
            case 4:
                display();
                break; 
            case 5:
                free(list);
                printf("Successfully exited!\n");
                exit(0);
            default:
                printf("Invalid Choice!!");
        }
    }
}



void create()
{
    int e, i;
    char w; 
    
    if (n > 0)
    {
        while (1)
        {
            printf("\nYour list has been created already. This action will create a new list and remove your old list!\nDo you want to continue? (y / n): ");
            scanf(" %c", &w);
            
            if (w == 'y')
            {
                break;
            }
            else if (w == 'n')
            {
                return;
            }
        }
    }
    
    printf("Enter number of elements: ");
    scanf("%d", &e); // & - reference
    
    list = (int *) malloc(e * sizeof(int));
    
    printf("Enter the elements below\n");
    for (i = 0; i < e; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", (list + i));
    }
    n = e; //
}

void insert()
{
    int x, p = 1, i;
    
    printf("Enter the element: ");
    scanf("%d", &x);
    if (n > 0)
    {
        printf("Enter it's position: ");
        scanf("%d", &p);
    }
    
    if ((p < 1) || (p > n + 1))
    {
        printf("Invalid position!\n");
        return;
    }
    else if(p == n + 1) // append
    {
        list = realloc(list, (n + 1) * sizeof(int));
        list[p - 1] = x;
    }
    else // insert
    {
        list = realloc(list, (n + 1) * sizeof(int));
        for (i = n - 1; i >= p - 1; i--)
        {
            list[i + 1] = list[i];
        }
        list[p - 1] = x;
    }
    n++;
    printf("Successfully added!\n");
}

void delete()
{
    int p, i;
    
    printf("Enter the position of element to be deleted: ");
    scanf("%d", &p);
    
    if ((p < 1) || (p > n))
    {
        printf("Invalid position!\n");
    }
    else
    {
        for (i = p - 1; i < n; i++)
        {
            list[i] = list[i + 1];
        }
        n--;
        list = realloc(list, (n + 1) * sizeof(int));
        printf("Successfully deleted!\n");
    }
}

void display()
{
    int i;
    
    if (n == 0)
    {
        printf("Your list is empty!");
    }
    else
    {
        printf("\nYour list\nPosition\tElement");
        for (i = 0; i < n; i++)
        {
            printf("\n%d\t\t%d", i + 1, list[i]);
        }
    }
    printf("\n");
}