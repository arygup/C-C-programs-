#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define mod 1000000007
int encoded[27];
int two[27];
ll max(ll a, ll b)
{
    if(a > b) a = b;
    return a;
}
ll max(ll a, ll b)
{
    if(a < b) a = b;
    return a;
}
void convert(char c,int k){
     if(c==' ') encoded[26]++;
     else encoded[((c-'a')+k)%26]++;
}
void convert2(char c,int k){
     if(c==' ') two[26]++;
     else two[((c-'a'))]++;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d ",&k);
        size_t size=100001;
        for(int i=0;i<27;i++){
            encoded[i]=0;
            two[i]=0;
        }
        char c;
        char str[100001];
        scanf("%[^\n]s",str);
        scanf("%c",&c);
        for(int i=0;i<strlen(str);i++){
            convert(str[i],k);
        }
        char str2[100001];
        scanf("%[^\n]s",str2);
        for(int i=0;i<strlen(str2);i++){
            convert2(str2[i],k);
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(encoded[i]==two[i]) continue;
            else{
                printf("False\n");
                flag=1;
                break;
            }
        }
        if(flag==0) printf("True\n");
    }
}