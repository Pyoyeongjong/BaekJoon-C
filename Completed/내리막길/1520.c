#include <stdio.h>

int h[501][501]; //height
int res[501][501]; //result

void printres(int n, int m){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%3d ",res[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void getres(int r, int c, int n, int m){

    if(r==n && c==m){
        res[r][c]=1;
        return;
    }

    int result=0;
    if(1<r){
        if(h[r][c]>h[r-1][c]){
            if(res[r-1][c]==-1)
                getres(r-1,c,n,m);
            result +=res[r-1][c];
        }
    }

    if(r<n){
        if(h[r][c]>h[r+1][c]){
            if(res[r+1][c]==-1)
                getres(r+1,c,n,m);
            result +=res[r+1][c];
        }
    }

    if(1<c){
        if(h[r][c]>h[r][c-1]){
            if(res[r][c-1]==-1)
                getres(r,c-1,n,m);
            result +=res[r][c-1];
        }
    }

    if(c<m){
        if(h[r][c]>h[r][c+1]){
            if(res[r][c+1]==-1)
                getres(r,c+1,n,m);
            result +=res[r][c+1];
        }
    }

    res[r][c]=result;
    printf("----r=%d,c=%d------\n",r,c);
    printres(n,m);
    return;
}

void dp(int n, int m){

    getres(1,1,n,m);
    printf("%d",res[1][1]);
}

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&h[i][j]);
            res[i][j]=-1;
        }
    }

    dp(N,M);
}