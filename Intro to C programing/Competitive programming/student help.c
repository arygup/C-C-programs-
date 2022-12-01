#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    char A[n+1], B[m+1];
    int C[m], ans = 0;
    scanf("%s", A);
    scanf("%s", B);
    for (int i = m -1; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < m; j++)
        {
            C[j] = A[i+j] - B[j];
            if(C[j] < 0) C[j] = -C[j];
        }
        for (int j = 0; j < m-1; j++)
        {
            if(C[j] != C[j+1]) x++;
        }
        if(x == 0)
        {
            if(C[0] == k) ans++;
        }
    }
    if(ans == 2) ans = ans + 2;
    printf("%d", ans);
    return 0;
}


//     int n,m,k;
//     scanf("%d %d %d",&n,&m,&k);
//     char B[n+1];
//     char A[m+1];
//     scanf("%s",B);
//     scanf("%s",A);
//     int C = 0;
//     for(int i = 0; i < n;i++){
//         for(int j = 0;j < m;j++){
            if(B[i+j] - A[j] == k || A[j] - B[i+j] == k){
                if(j == m-1){
                    C++;
                }
//                 else{
//                     continue;
//                 }
//             }
//             else{
//                 break;
//             }
//         }
//     }

//     printf("%d\n",C);