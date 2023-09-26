#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int left, int mid, int right, int num){
    static int count = 0;

    int i,j,k;
    i = left;
    j = mid+1;
    k = left;
    // 내부선언하면 오류?
    static int temp[500000];

    while(i<=mid && j<=right){

        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    if(i>mid){
        while(j<=right){
            temp[k++]=a[j++];
        }
    }else{
        while(i<=mid){
            temp[k++]=a[i++];
        }
    }
    for(int l=left;l<=right;l++){
        a[l]=temp[l];
        count++;
        if(count==num){
            printf("%d\n",a[l]);
            exit(0);
        }
    }
    return;
}


void printarr(int a[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return;
}

void merge_sort(int a[], int left, int right, int num){
    int mid = (left+right)/2;
    if(left<right){
        merge_sort(a,left,mid, num);
        merge_sort(a,mid+1,right, num);

        merge(a,left,mid,right,num);
    }
    return;
}


int main(void){

    int a[500000];
    int N,K;
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(a, 0, N-1, K);
    printf("-1\n");
    return 0;
}