#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int st;
    unsigned int et;
}meeting;

int compare(const void *a, const void *b){
    meeting A = *(meeting*)a;
    meeting B = *(meeting*)b;
    if(A.et>B.et)
        return 1;
    else if(A.et==B.et){
        if(A.st>B.st)
            return 1;
        else
            return -1;
    }
    else
        return -1;
}

meeting meet[100010];

int main(void){
    
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&meet[i].st,&meet[i].et);
    }
    qsort(meet,N,sizeof(meeting),compare);
    int pivot = 0;
    int count = 1;
    for(int i=1;i<N;i++){
        if(meet[pivot].et<=meet[i].st){
            pivot=i;
            count++;
        }
    }
    printf("%d",count);
    
}