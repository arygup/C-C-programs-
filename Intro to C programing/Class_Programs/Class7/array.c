#include <stdio.h>
#define NOSTUDENTS 5

int main()
{
    float marks[NOSTUDENTS], sum=0;

    for (int i = 0; i < NOSTUDENTS; i++)
    {
        scanf("%f", &marks[i]);
    }

    for (int j = 0; j < NOSTUDENTS; j++)
    {
        sum = sum + marks[j];
    }

    printf("%3f/n", sum/NOSTUDENTS);
}