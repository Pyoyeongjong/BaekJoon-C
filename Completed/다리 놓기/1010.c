#include <stdio.h>

// Combine 함수
long long int cbn(int n, int m){
    long long int result=1;

    for(int i=0;i<n;i++){
        result*=m--;
        result/=i+1;
    }
    return result;
}

int main(void){
    int T, N, M;
    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&N, &M);
        long long int result = cbn(N, M);
        printf("%d\n",result);
    }

}