#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct names_list
{
    char *n;
    struct names_list *next;
} names;
names *head = NULL;
// int swap(names* curr, names*curr2, names*op) // A pointing B pointing C
// {
//     curr2->next = curr;
//     op->next = curr2;
//     return 0;
// }
void swap(names *xp, names *yp)
{
    names *temp = xp->next;   // 1 xp 2 3 yp 4
    xp->next = yp->next;
    yp->next = temp;
    names t = *xp;     
    *xp = *yp;
    *yp = t;
}
int bs(names *head)
{
    names *curr;
    curr = head;
    int x = 0;
    while(curr->next != NULL)
    {
        if(strcmp(curr->n, curr->next->n) > 0)
        {
            x++;
            swap(curr, curr->next);        
        }
        curr = curr->next;
    }
    // for (curr = head; curr->next != NULL; curr = curr->next)
    // {
    //     if (strcmp(curr->n, (curr->next)->n) > 0)
    //     {
    //         x++;
    //         swap(curr, curr->next);
    //     }
    // }
    if (x > 0) bs(head);
    return 0;
}
int main()
{
    char a[20];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", a);
        names *curr;
        curr = malloc(sizeof(names));
        curr->n = malloc(strlen(a) + 1);
        strcpy(curr->n, a);
        curr->next = head;
        head = curr;
    }
    names *curr;
    curr = head;
    bs(head);
    // swap(head->next, head->next->next);
    while (head != NULL)
    {
        printf("%s\n", curr->n);
        head = curr->next;
        curr = head;
    }
    return 0;
}