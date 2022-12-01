#include <stdio.h>
int main() {    

    int n1, n2, n3;
    
    printf("Enter 3 int, last one being the largest: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    if (n1*n1 + n2*n2 == n3*n3) {
        printf("yea ");
    }
    else {
        printf("no ");
    }
    
       
    
    
    return 0;
}
