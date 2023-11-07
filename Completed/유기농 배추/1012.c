#include <stdio.h>

int farm[50][50];
int visited[50][50];


void initialize(int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            farm[i][j]=0;
            visited[i][j]=0;
        }
    }
    return;
}

void get_range(int x, int y, int m, int n){//dfs
    if(x<0 || x>=m || y<0 || y>=n)
        return;
    visited[x][y]=1;
    if(farm[x+1][y]==1 && visited[x+1][y]==0){
        get_range(x+1,y, m, n);
    }
    if(farm[x-1][y]==1 && visited[x-1][y]==0){
        get_range(x-1,y, m, n);
    }
    if(farm[x][y+1]==1 && visited[x][y+1]==0){
        get_range(x,y+1, m, n);
    }
    if(farm[x][y-1]==1 && visited[x][y-1]==0){
        get_range(x,y-1, m, n);
    }
    return;

}

void printvisited(int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",visited[i][j]);
        }
        printf("\n");
    }
    return;
}
void dp(int m, int n){

    int count=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(farm[i][j]==1){
                if(visited[i][j]==0){
                    get_range(i,j,m,n);
                    count++;
                    //printvisited(m,n);
                }
            }
        }
    }
    
    printf("%d\n",count);
}

void printfarm(int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",farm[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(void){
    int T, M, N, K;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d %d",&M,&N,&K);

        int x,y;
        for(int i=0;i<K;i++){
            scanf("%d %d",&x,&y);
            farm[x][y]=1;
        }

        //printfarm(M,N);

        dp(M,N);
        initialize(M,N);
    }
}