#include <iostream>
using namespace std;
int main()
{
    long long t, n;
    scanf("%lld", &t);
    for (long long i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        n = s.length();
        if(n == 0 || n == 1 || n == 2) 
        {
            printf("0\n");
            continue;
        }
        long long c = 0, z = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') c++;
            else z++;
        }
        if(c != z)
        {
            z = min(c, z);
            printf("%lld\n", z);
            continue;
        }
        if(c == z)
        {
            printf("%lld\n", z -1);
            continue;
        }
    }
    return 0;
}