#include <stdio.h>

int main(void){
    int n, r, c;

    scanf("%d %d %d",&n,&r,&c);

    int k;
    int result = 0;
    while(n){

        k = 1<<n;
        if(0 <= r%k && r%k < k/2){
            if(0 <= c%k && c%k < k/2){
                result += 0;
            }else{
                result += k*k/4;
            }
        }
        if(k/2 <= r%k && r%k < k){
            if(0 <= c%k && c%k < k/2){
                result +=  k*k/4*2;
            }else{
                result += k*k/4*3;
            }
        }
        n--;
    }

    printf("%d",result);
}