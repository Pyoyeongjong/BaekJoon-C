#include <stdio.h>
#include <stdlib.h>

struct jewerly{
    int w; //weight;
    int c; //cost;
};

//1. linked list 정렬.
// struct jewerly* list[1000001]; 을 통해서 무게마다 최댓값이 맨 앞으로 오도록 정렬하기.
//2. qsort후 max[1000001];을 통해 무게 당 맨 첫번째 index값을 저장.

struct jewerly j[300002];
int bag[300002];
int max[1000001];
int am[1000001];

void setmax(int n){

    max[j[0].w]=0;
    am[j[0].w]+=1;

    for(int i=0;i<n-1;i++){
        if(j[i].w<j[i+1].w){
            max[j[i+1].w]=i+1;
        }
        am[j[i+1].w]+=1;
    }

    return;
}


int compare_b(const void *a, const void *b){//오름차순
    int x=*(int*)a;
    int y=*(int*)b;

    if(x>y)
        return 1;
    else   
        return -1;
}

int compare_j(const void *a, const void *b){
    struct jewerly jx=*(struct jewerly*)a;
    struct jewerly jy=*(struct jewerly*)b;

    if(jx.w>jy.w)
        return 1;
    if(jx.w==jy.w){
        if(jx.c<jy.c)
            return 1;
        else
            return -1;
    }
    else
        return -1;
}
int main(void){
    int n, k;
    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++){
        scanf("%d %d",&j[i].w,&j[i].c);
    }

    for(int i=0;i<k;i++){
        scanf("%d",&bag[i]);
    }

    qsort(bag,k,sizeof(int),compare_b);
    qsort(j,n,sizeof(struct jewerly),compare_j);
    setmax(n);

    int result=0;
    int tmp, maxw, maxc;
    for(int i=0;i<k;i++){
        maxc=0;
        tmp=bag[i];//가방의 최대무게
        for(int a=0;a<=tmp;a++){
            if(maxc<j[max[a]].c && am[a]>0){//새로운 max 찾음
                maxc=j[max[a]].c;
                maxw=j[max[a]].w;
            }
        }
        result+=maxc;
        max[maxw]++;
        am[maxw]--;
    }

    printf("%d",result);


}