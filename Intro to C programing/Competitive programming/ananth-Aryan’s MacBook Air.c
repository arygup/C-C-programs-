#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    for(int asd = 0; asd < N; asd++){
        long long cookies, friends;
        scanf("%lld %lld", &cookies, &friends);

        long long arr[friends];
        int runs = 0;
        int flag = 1;
        int ptr = 0;

        for(int i = 0; i < friends; i++){
            arr[i] = 0;
        }

        while(cookies != 0){

            if(runs != 0) {
                if (ptr == 0 || ptr == friends - 1) flag = -flag;
            }
            runs++;
            arr[ptr]++;
            if(flag == 1) ptr++;
            if(flag == -1) ptr--;
            cookies--;
        }
        for(int i = 0; i < friends; i++){
            printf("%lld ", arr[i]);
        }

        printf("\n");
    }


}