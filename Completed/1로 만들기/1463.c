#include <stdio.h>

int dp[1000002];

int min(int a, int b){
    if(a<b) return a;
    else return b;
}


int main(void){
    int n;
    scanf("%d",&n);

    dp[1]=0; dp[2]=1; dp[3]=1;

    int a, b;
    for(int i=4;i<=n;i++){
        if(i%2==0 && i%3==0){
            dp[i]=min(min(dp[i/2],dp[i/3]),dp[i-1])+1;
        }
        else if(i%3==0){
            dp[i]=min(dp[i/3],dp[i-1])+1;
        }
        else if(i%2==0){
            dp[i]=min(dp[i/2],dp[i-1])+1;
        }
        else{
            dp[i]=dp[i-1]+1;
        }
    }
    printf("%d",dp[n]);
}