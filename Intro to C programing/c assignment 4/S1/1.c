#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    int B[6] = {0}, n = 0;
    for (int i = 0; i < 1000000; i++)
    {
        int y, z;
        y = rand();
        y = y%6;
        if(y == 0) B[0]++;
        if(y == 1) B[1]++;
        if(y == 2) B[2]++;
        if(y == 3) B[3]++;
        if(y == 4) B[4]++;
        if(y == 5) B[5]++;
        n++;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d: %d\n", i+1, B[i]);
    }
    //printf("    %d    ", n);
}
