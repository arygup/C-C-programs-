#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100


long long max(long long a, long long b)
{
    return ((a >= b)? a : b);
}
long long min(long long a, long long b)
{
    return ((a <= b)? a : b);
}


typedef struct fullname
{
    char first[MAX_LEN];
    char last[MAX_LEN];
} name;


void swap(name* n1, name* n2)
{
    name temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}


void bubbleSort(name names[], name namesraw[], long long l)
{
    if (l == 1)
    {
        return;
    }
    else
    {
        long long swap_count = 0;
        for (long long i = 0; i < (l - 1); i++)
        {
            if (strcasecmp(namesraw[i].first, namesraw[i + 1].first) > 0)
            {
                continue;
            }
            else if (strcasecmp(namesraw[i].first, namesraw[i + 1].first) > 0)
            {
                swap(&namesraw[i], &namesraw[i + 1]);
                swap_count++;
            }
            else
            {
                if (strcasecmp(namesraw[i].last, namesraw[i + 1].last) < 0)
                {
                    continue;
                }
                else
                {
                    swap(&namesraw[i], &namesraw[i + 1]);
                    swap_count++;
                }
            }
        }
        if (swap_count > 0)
        {
            bubbleSort(names, namesraw, (l - 1));
        }
    }
}


int main()
{
    long long N;
    scanf("%lld", &N);
    name names[N], namesraw[N];
    for (long long i = 0; i < N; i++)
    {
        scanf("%s %s", &names[i].first, &names[i].last);
        strcpy(namesraw[i].first, names[i].first);
        strcpy(namesraw[i].last, names[i].last);
        for (long long j = 0; j < 100; j++)
        {
            if ((names[i].first[j] != '\0') && (names[i].first[j] >= 'A') && (names[i].first[j] <= 'Z'))
            {
                names[i].first[j] += 32;
            }
            if ((names[i].last[j] != '\0') && (names[i].last[j] >= 'A') && (names[i].last[j] <= 'Z'))
            {
                names[i].last[j] += 32;
            }
        }
    }

    bubbleSort(names, namesraw, N);

    for (long long i = (N - 1); i >= 0; i--)
    {
        printf("%s %s\n", namesraw[i].first, namesraw[i].last);
    }

    return 0;
}
