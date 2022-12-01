#include<stdlib.h>
#include<stdio.h>
#include"node.h"
#include"my_dll.h"
#include<string.h>
int main()
{
    char f1[20] = "insert";
    char f2[20] = "insert_at";
    char f3[20] = "delete";
    char f4[20] = "find";
    char f5[20] = "prune";
    char f6[20] = "print";
    char f7[20] = "print_reverse";
    char f8[20] = "get_size";

    mystr list;
    list = (mystr)malloc(sizeof(struct my_dll));
    list->root = NULL;
    list->tail = NULL;
    list->size = -1;
    char scn[20];
    int x, i;
    while (scanf("%s", scn) != EOF)
    {
        if(strcasecmp(f1, scn) == 0)
        {
            scanf("%d", &x);
            insert(list, x);
        }
        if(strcasecmp(f2, scn) == 0)
        {
            scanf("%d %d", &x, &i);
            insert_at(list, x, i);
        }
        if(strcasecmp(f3, scn) == 0)
        {
            scanf("%d", &i);
            Delete(list, i);
        }
        if(strcasecmp(f4, scn) == 0)
        {
            scanf("%d", &x);
            int a = find(list, x);
            printf("%d\n", a);
        }
        if(strcasecmp(f5, scn) == 0)
        {
            prune(list);
        }
        if(strcasecmp(f6, scn) == 0)
        {
            print(list);
        }
        if(strcasecmp(f7, scn) == 0)
        {
            print_reverse(list);
        }
        if(strcasecmp(f8, scn) == 0)
        {
            get_size(list);
        }
    }
    return 0;
}
