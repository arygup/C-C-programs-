#include <stdio.h>

#define MAX_LEN 20

int main()
{
    char name[MAX_LEN];
    printf("Enter your name: ");

    scanf("%s", name);
    printf("Hello %s\n", name);

    for (int i = 0; name[i] != '\0'; i++)
    {
        printf("%c\t", name[i]);
    }
    printf("\n");

    for (char *chptr = name; *chptr != '\0'; chptr++)
    {
        printf("%10c", *chptr);
    }
    printf("\n");

    for (int i = 0; name[i] != '\0'; i++)
    {
        printf("%s\n", &name[i]); 
    }

    return 0;
}