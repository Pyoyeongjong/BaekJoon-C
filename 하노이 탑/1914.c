#include <stdio.h>

void power(int x, int n, char arr[]){
    int temp=0, last=0, cnt=0;
    arr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=last;j++){
            temp = arr[j]*x+cnt;
            if(temp>=10){
                arr[j]=temp%10;
                cnt=temp/10;
                if(j==last){
                    arr[++last]=cnt;
                    cnt=0;
                    break;
                }
            }else{
                arr[j]=temp;
                cnt=0;
            }
        }
    }
    arr[0]= arr[0]-1;
    for(int i=last;i>=0;i--){
        printf("%d",arr[i]);
    }
    printf("\n");
}

void hanoi(int st, int de, int ex, int n){

    if(n==1){
        printf("%d %d\n",st,de);

        return;
    }
    int s;//시작지점
    int d;//목표지점
    int e;//경유지점
    s = st; d = de; e = ex;
    hanoi(s, e, d, n-1);
    printf("%d %d\n",s,d);
    hanoi(e,d,s,n-1);
    return;
}

int main(void){
    int N;
    scanf("%d",&N);
    char result[100]={0};
    
    power(2, N, result);

    if(N<=20){
        hanoi(1,3,2, N);
    }   
}