#include <stdio.h>

unsigned int length[10000];

int main(void){
    // 입력
    int K,N;
    unsigned long max = 0;
    scanf("%d %d",&K,&N);

    for(int i=0;i<K;i++){
        scanf("%d",&length[i]);
        if(length[i]>max)
            max=length[i];
    }

    // // 브루트 포스
    // unsigned int len = 0;
    // while(1){
    //     int possibleN = 0;
    //     len++;
    //     for(int i=0;i<K;i++){
    //         possibleN+=length[i]/len;
    //     }
    //     if(possibleN<N)
    //         break;
    // }
    // printf("%d",len-1);

    // 이분 탐색
    unsigned long len;
    long minscope = 0;
    long maxscope = max;
    while(1){
        len = (minscope+maxscope)/2;
        if(len==0)
            len=1;
        //printf("len: %d mins:%d maxs:%d\n",len,minscope,maxscope);
        //Sleep(500);
        long long int possibleN = 0;
        for(int i=0;i<K;i++){
            possibleN+=length[i]/len;
        }
        if(possibleN>=N){
            if(minscope==maxscope){
                printf("%d",minscope);
                return 0;
            }
            minscope = (maxscope+minscope)/2+1;
        }else{
            if(minscope==maxscope){
                printf("%d",minscope-1);
                return 0;
            }
            maxscope = (maxscope+minscope)/2;
        }
    }


}