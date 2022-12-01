#include <stdio.h>
#include <math.h>

int main()
{
    int B[3][3], a, b, c, d, e, f, g;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    float p, x, y, z;
    //0-female,1-male
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%6d", B[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++)
    { //a
        for (int j = 0; j < 3; j++)
        {
            if (B[i][j] == 1)
            {
                a = a + 1;
            }
        }
    }
    p = a * 11.11111111111111111111111111111111111111;
    printf("%f \n", p);
    for (int j = 0; j < 3; j++)
    { //b
        if (B[0][j] == 1)
        {
            b = b + 1;
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (B[1][j] == 1)
        {
            c = c + 1;
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (B[2][j] == 1)
        {
            d = d + 1;
        }
    }
    x = b * 11.11111111111111111111111111111111111111 * 3;
    y = c * 11.11111111111111111111111111111111111111 * 3;
    z = d * 11.11111111111111111111111111111111111111 * 3;
    printf("%3f %3f %3f \n", x, y, z); //c
    if ((x > y) & (x > z))
    {
        printf("%f line 1\n", x);
    }
    if ((y > x) & (y > z))
    {
        printf("%f line 2\n", y);
    }
    if ((z > y) & (z > x))
    {
        printf("%f line 3\n", x);
    }

    if (a % 3 == 0)
    { //d
        f = a / 3;
        for (int l = 0; l < f; l++)
        {
            for (int k = 0; k < 3; k++)
            {
                B[l][k] = 1;
            }
        }
        for (int l = f; l < 3; l++)
        {
            for (int k = 0; k < 3; k++)
            {
                B[l][k] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%6d", B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
