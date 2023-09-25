#include <stdio.h>

int p[1000];
int sorted[1000];

void merge(int f, int m, int e){
    int i, j, k;
    i = f;
    j = m+1;
    k = f;

    while(i<=m && j<=e){
        if(p[i]<=p[j])
            sorted[k++]=p[i++];
        else
            sorted[k++]=p[j++];
    }
    if(i>m){
        while(j<=e){
            sorted[k++]=p[j++];
        }
    }
    else{
        while(i<=m){
            sorted[k++]=p[i++];
        }
    }
    for(int l=f;l<=e;l++){
        p[l]=sorted[l];
    }
    return;
}

void mergesort(int f, int e){
    int m;

    if(f<e){
        m = (f+e)/2;
        mergesort(f,m);
        mergesort(m+1,e);
        merge(f,m,e);
    }

    return;
}

void printlist(int n){
    for(int i=0;i<n;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
    return;
}

int main(void){
    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&p[i]);
    }

    mergesort(0,N-1);
    //printlist(N);

    int sum = 0;
    int mux = N;

    for(int i=0;i<N;i++){
        sum += p[i]*mux--;
    }
    printf("%d",sum);

    return 0;
}