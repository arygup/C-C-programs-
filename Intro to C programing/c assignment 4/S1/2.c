#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    int B[13] = {0}, n = 0;
    for (int i = 0; i < 1000000; i++)
    {
        int y, z;
        y = rand();
        y = y%6;
        z = rand();
        z = z%6;
        z = z+y;
        B[z]++;
        n++;
    }
    for (int i = 0; i < 11; i++)
    {
       printf("%d \n", B[i]);
    }
}