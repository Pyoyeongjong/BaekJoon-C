#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))

int score[3][100001];


int main(void){
    int t,n;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&score[0][i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&score[1][i]);
        }


        for(int i=2;i<=n;i++){
            score[0][i]+=max(score[1][i-1],score[1][i-2]);
            score[1][i]+=max(score[0][i-1],score[0][i-2]);
        }

        printf("%d\n",max(score[0][n],score[1][n]));
    }
}