#include <stdio.h>

int party[51][51]; //파티 참가정보
int parent[51];

void printparent(int n){
    for(int i=1;i<=n;i++){
        printf("%d ",parent[i]);
    }
    printf("\n");
}

int getParent(int x){
    if(parent[x]==x)
        return x;
    return parent[x]=getParent(parent[x]);
}

int unionParent(int a, int b){
    int aa = getParent(a);
    int bb = getParent(b);
    if(aa<bb){
        parent[b]=aa;
        return aa;
    }
    else{
        parent[a]=bb;
        return bb;
    }
}

void union_party(int i, int n, int m){

    int p;
    for(int j=1;j<=n;j++){
        if(party[i][j]==1){
            p=j;
            break;
        }
    }
    for(int j=p;j<=n;j++){
        if(party[i][j]==1){
            unionParent(p,j);
        }
    }
    return;
}

int main(void){
    int N, M;

    scanf("%d %d",&N,&M);

    for(int i=1;i<=N;i++){
        parent[i]=i;
    }
    int a, t;
    scanf("%d",&a);
    if(a>=1){
        for(int i=0;i<a;i++){
            scanf("%d",&t);
            parent[t]=0;
        }
    }

    

    for(int i=1;i<=M;i++){
        scanf("%d",&a);
        if(a>=1){
            for(int j=0;j<a;j++){
                scanf("%d",&t);
                party[i][t]=1;
            }
        }
    }

    int tt=50;
    while(tt--){
        for(int i=1;i<=M;i++){
            union_party(i, N, M);
        }
    }
    

    int count=0;
    for(int i=1;i<=M;i++){
        count++;
        for(int j=1;j<=N;j++){
            if(party[i][j]==1 && getParent(j)==0){
                count--;
                break;
            }
        }
    }

    printf("%d",count);
}