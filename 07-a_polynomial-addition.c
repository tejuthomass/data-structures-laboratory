#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct polynomial
{
    int coef, exp;
    struct polynomial *next;
} node;

void insert(node **, int, int);
void display(node *);
void add(node *, node *, node**);

int main()
{
    node *p = NULL, *q = NULL, *r = NULL;
    int a, b;
    clrscr();
    
    printf("$$$ POLYNOMIAL ADITION USING LINKED LIST $$$\n\nEnter the coefficients and powers for the first polynomial(P) equation (Enter 0 0 to stop)\n");

    while (1)
    {
        printf("Enter: ");
        scanf("%d %d", &a, &b);
        if ((a == 0) && (b == 0))
        {
            break;
        }
        else
        {
            insert(&p, a, b);
        }
    }
    printf("\nEnter the coefficients and powers for the second polynomial(Q) equation (Enter 0 0 to stop)\n");
    
    while (1)
    {
        printf("Enter: ");
        scanf("%d %d", &a, &b);
        if ((a == 0) && (b == 0))
        {
            break;
        }
        else
        {
            insert(&q, a, b);
        }
    }
    
    printf("\nP = ");
    display(p);
    printf("\nQ = ");
    display(q);
    printf("\n\nP + Q = ");
    add(p, q, &r);
    display(r);
}

void insert(node **s, int x, int y)
{
    node *n, *t = *s;
    
    n = (node *)malloc(sizeof(node));
    n->coef = x;
    n->exp = y;
    n->next = NULL;
    
    if(*s == NULL)
    {
        *s = n;
    }
    else
    {
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = n;
    }
}

void display(node *t)
{
    while (t->next != NULL)
    {
        printf("%dx^%d + ", t->coef, t->exp);
        t = t->next;
    }
    printf("%dx^%d", t->coef, t->exp);
}

void add(node *x, node *y, node **z)
{
    node *t;
    
    while (x != NULL && y != NULL)
    {
        if(*z == NULL)
        {
            *z = (node *)malloc(sizeof(node));
            t = *z;
        }
        else
        {
            t->next = (node *)malloc(sizeof(node));
            t = t->next;
        }
        
        if(x->exp > y->exp)
        {
            t->coef = x->coef;
            t->exp = x->exp;
            x = x->next;
        }
        else if(x->exp < y->exp)
        {
            t->coef = y->coef;
            t->exp = y->exp;
            y = y->next;
        }
        else // x->exp == y->exp
        {
            t->coef = x->coef + y->coef;
            t->exp = x->exp;
            x = x->next;
            y = y->next;
        }
    }
    
    while(x != NULL)
    {
        if(*z == NULL)
        {
            *z = (node *)malloc(sizeof(node));
            t = *z;
        }
        else
        {
            t->next = (node *)malloc(sizeof(node));
            t=t->next;
        }
        t->coef = x->coef;
        t->exp = x->exp;
        x = x->next;
    }
    
    while(y != NULL)
    {
        if(*z == NULL)
        {
            *z = (node *)malloc(sizeof(node));
            t = *z;
        }
        else
        {
            t->next = (node *)malloc(sizeof(node));
            t = t->next;
        }
        t->coef = y->coef;
        t->exp = y->exp;
        y = y->next;
    }
    
    t->next = NULL;
}