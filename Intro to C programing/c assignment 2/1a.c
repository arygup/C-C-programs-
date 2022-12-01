#include<stdio.h>
#include<math.h>

void read(int A[]){
    for(int i = 0;i < 5;i++){
        scanf("%d", &A[i]);
        if((A[i]>10)||(A[i]<0)){
            printf("no");
            break;
        }
    }
   for (int i = 0;i<5;i++){
       printf("%d", A[i]);
   }
}

void main(){
    int N, A[4],B[11];
    float c, d, e,f;
    N=0;
    int sum = 0;
    read(A);
    for(int i = 0;i < 5;i++){
       if(A[i]>3.5){
           N++;
       }
       
       sum = sum + A[i];
    }
    c = N*20;
    printf("%.2f \n", c);  //pass percentage 
    
    c = sum/5;
    printf("%.2f \n", c); //mean variance standard deviation
    
    d = 0;
    for(int i = 0;i < 5;i++){  
      d = d + (A[i]-c)*(A[i]-c);
            
    }
    e = sqrt(d)/2;
    printf("%.2f \n", e);
   
    int a = 0;
    int b = 10;
    for(int j = 0; j < 5;j++ ){  //min max
       if(A[j]>a){
          a=A[j];
        }
      if(A[j]<b){
         b=A[j];
        }
    }  
    printf("%d %d", a, b);
    printf("\n");
    for(int i = 0;i < 11;i++){
        B[i]=0;
    }

    for (int i = 0;i<5;i++){
        if(A[i]<1){
            B[1]++;

        }
        if((A[i]<=2)&(A[i]>1)){
            B[2]++;

        }
        if((A[i]<=3)&(A[i]>2)){
            B[3]++;

        }
        if((A[i]<=4)&(A[i]>3)){
            B[4]++;

        }
        if((A[i]<=5)&(A[i]>4)){
            B[5]++;

        }
        if((A[i]<=6)&(A[i]>5)){
            B[6]++;

        }

        if((A[i]<=7)&(A[i]>6)){
            B[7]++;

        }
        if((A[i]<=8)&(A[i]>7)){
            B[8]++;

        }
        if((A[i]<=9)&(A[i]>8)){
            B[9]++;

        }
        if((A[i]<=10)&(A[i]>9)){
            B[10]++;

        }
   }

   for(int i = 0; i < 11; i++){
       printf("%d", i);
       for(int j = 0; j < B[i]; j++){
           printf("*");

       }
       printf("\n");
    }
}