#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+,-./:;<=>?@[]^_`{}|~";
int main(int argc, char** argv)
{
    srand(time(0));
    int n = atoi(argv[1]);
    FILE* out = fopen(argv[2], "w");
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= 100; ++j)
        {
            fprintf(out, "%c", chars[rand() % 82]);
        }
        fprintf(out, "\n");
    }
}
