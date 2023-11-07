#include <stdio.h>

int t[501][501];
int dp[501][501];

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(void){
    int n;
    scanf("%d",&n);

    int count=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=count;j++){
            scanf("%d",&t[i][j]);
        }
        count++;
    }

    for(int i=1;i<=n;i++){
        dp[n][i]=t[n][i];
    }

    int c= n-1;
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=c;j++){
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+t[i][j];
        }
    }

    printf("%d",dp[1][1]);

}