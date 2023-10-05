#include <stdio.h>
#include <stdlib.h>

int num[500000];
int testnum[500000];

int compare(const void *a, const void *b){
    int A = *(int*)a;
    int B = *(int*)b;
    if(A>B)
        return 1;
    else
        return -1;
}

void findnum(int n, int size){
    int st = 0;
    int ed = size-1;
    int mid;
    while(1){
        if(st>ed){
            printf("0 ");
            return;
        }
        mid = (st+ed)/2;
        if(num[mid]==n){
            printf("1 ");
            return;
        }else if(num[mid]>n){
            ed=mid-1;
        }else{
            st=mid+1;
        }
    }
}


int main(void){
    int N, M;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }

    qsort(num, N, sizeof(int),compare);

    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&testnum[i]);
    }

    for(int i=0;i<M;i++){
        findnum(testnum[i], N);
    }
    return 0;

}