#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int r;
    int c;
};

struct matrix m[501];
int result[501][501];

void dp(int s, int e){
    if(s==e){
        return;
    }
    if(s+1==e){
        result[s][e]=m[s].r*m[e].r*m[e].c;
        return;
    }
    int min=-1;

    for(int i=s;i<e;i++){
        int tmp=0;
        if(result[s][i]==0){
            dp(s,i);
        }
        if(result[i+1][e]==0){
            dp(i+1,e);
        }
        tmp = result[s][i]+result[i+1][e]+m[s].r*m[i].c*m[e].c;
        if(min<0){
            min=tmp;
        }
        if(min>tmp){
            min=tmp;
        }
    }
    result[s][e]=min;
    return;
}

 
int main(void){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d %d",&m[i].r,&m[i].c);
    }
    dp(1, N);
    printf("%d",result[1][N]);


}