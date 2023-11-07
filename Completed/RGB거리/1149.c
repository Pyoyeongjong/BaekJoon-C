#include <stdio.h>

struct cost{
    int r;
    int g;
    int b;
};
struct cost c[1001];
struct cost dp[1001];

int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

void _dp(int n){
    dp[1].r=c[1].r;
    dp[1].b=c[1].b;
    dp[1].g=c[1].g;

    for(int i=2;i<=n;i++){
        dp[i].r=c[i].r+min(dp[i-1].b,dp[i-1].g);
        dp[i].g=c[i].g+min(dp[i-1].r,dp[i-1].b);
        dp[i].b=c[i].b+min(dp[i-1].r,dp[i-1].g);
    }
    return;
}

int main(void){
    int n;
    scanf("%d",&n);

    int r,g,b;
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&r,&g,&b);
        c[i].r=r; c[i].g=g; c[i].b=b;
    }

    _dp(n);
    printf("%d",min(min(dp[n].r,dp[n].g),dp[n].b));
    return 0;
}