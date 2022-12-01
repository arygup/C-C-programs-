#include<stdio.h>
#include<string.h>

struct db
{
    int size;
    char op;
};
int main()
{
    struct db* s1;
    s1.size = 5;
    s1.op = 'a';
    printf("%d  %c", s1.size, s1.op);
}