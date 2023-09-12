#include <stdio.h>

int arr[7];

void printNum(int N, int M, int d){
    for(int i=1;i<=N;i++){
        arr[d]=i;
        if(M-1==d){
            for(int k=0;k<M;k++)
                printf("%d ",arr[k]);
            printf("\n");
        }
        else
            printNum(N,M,d+1);
    }
}

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);

    printNum(N,M,0);

    return 0;
}