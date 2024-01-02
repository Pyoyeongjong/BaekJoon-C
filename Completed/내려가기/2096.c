//24:40
#include <stdio.h>


int score[100000][3];
int dp[100000][3];

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

void dp_max(int n){

    dp[0][0]=score[0][0];
    dp[0][1]=score[0][1];
    dp[0][2]=score[0][2];

    for(int i=1;i<n;i++){
        dp[i][0] = score[i][0]+max(dp[i-1][0],dp[i-1][1]);
        dp[i][1] = score[i][1]+max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
        dp[i][2] = score[i][2]+max(dp[i-1][1],dp[i-1][2]);
    }

    return;
}

void dp_min(int n){

    dp[0][0]=score[0][0];
    dp[0][1]=score[0][1];
    dp[0][2]=score[0][2];

    for(int i=1;i<n;i++){
        dp[i][0]= score[i][0]+min(dp[i-1][0],dp[i-1][1]);
        dp[i][1]= score[i][1]+min(dp[i-1][2],min(dp[i-1][0],dp[i-1][1]));
        dp[i][2]= score[i][2]+min(dp[i-1][1],dp[i-1][2]);
    }

    return;
}

int main(void){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d %d",&score[i][0],&score[i][1],&score[i][2]);
    }

    dp_max(n);
    int a = max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
    dp_min(n);
    int b = min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);

    printf("%d %d",a,b);



}