// roots of quadratic polynomial linked list
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node 
{
    int coef ; 
    int order ; 
    struct node *next ; 
}; 
struct node * create_poly(struct node *poly , int maxx_order)
{
    struct node *p , *tail ;  
    while(maxx_order>=0)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->order = maxx_order ; 
        printf("Enter coeffecient for %d order : ",p->order);
        scanf("%d",&p->coef);
        p->next = NULL ; 
        if (poly == NULL)
        {
            poly = tail = p ; 
        }
        else
        {
                tail->next = p ; 
                tail = p ;
        }
        maxx_order-- ; 
    }
    return(poly);
}
void display(struct node * poly)
{
    struct node *temp = poly ; 
    while(temp!= NULL)
    {
        if(temp->next == NULL)
        {
            printf("%d = 0",temp->coef);
        }
        else
        {
            printf("%dx^%d + ",temp->coef,temp->order);
        }
        temp = temp->next ; 
    }
    printf("\n");
}
void roots(struct node *poly1 )
{
        struct node *temp = poly1 ; 
        int a = temp->coef ; 
        int b = temp->next->coef ; 
        int c = temp->next->next->coef ; 
        int d = b*b - 4*a*c; 
        if(d>=0)
        {
        int r1 = (-b + sqrt(d))/(2*a); 
        int r2 = (-b - sqrt(d))/(2*a); 
        printf("Roots are real : %d\t%d",r1,r2);  
        }
        else
        {
            printf("Roots are imaginary");
        }
}
int main()
{
    struct node *poly1 = NULL ; 
    poly1 = create_poly(poly1 ,2);
    display(poly1);
    roots(poly1);
return 0;
}