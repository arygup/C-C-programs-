#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <string.h>
int main()
{
    //long long int s = 0, i = 0;
    int a = 13, b = 17, countBuckets = 15;
    struct HashTable *T = init_hash_table(a, b, countBuckets);
    int key;
    char command[20];
    while (scanf("%s", command) != EOF)
    {
        if (strcasecmp(command, "EXIT") == 0)
        {
            break;
        }
        scanf("%d", &key);
        if (strcasecmp(command, "INSERT") == 0)
        {
            //i++;
            insert(T, key);
        }
        else if (strcasecmp(command, "SEARCH") == 0)
        {
            search(T, key);
            //s++;
            if(search(T, key)) printf("\nkey %d was found\n", key);
        }
        else if (strcasecmp(command, "DELETE") == 0)
        {
            Delete(T, key);
        }
    }
    print_table(T);
   // printf("%lf %lf", (double)T->search/(double)s, (double)T->insert/(double)i);
    return 0;
}