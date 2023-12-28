#include <stdio.h>

int map[1001][1001];
int dist[1001][1001];
int checked[1001][1001];

struct point{
    int x;
    int y;
};

struct point queue[1000001];
int front=0; int rear=0;

void push(int x, int y, int n, int m){

    if(x<0 || x>=n || y<0 || y>=m || map[x][y]==0)
        return;

    struct point tmp = {x, y};
    queue[rear++]=tmp;
    return;
}

struct point pop(){
    return queue[front++];
}


void printdist(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}
void printchecked(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",checked[i][j]);
        }
        printf("\n");
    }
}

void find_short_len(int x, int y, int n, int m){

    if(checked[x][y]==1)
        return;

    checked[x][y]=1;

    int len=0x7fffffff;

    // 범위 내이며, dist를 구했으면
    if(len>dist[x-1][y] && checked[x-1][y]==1){
        len=dist[x-1][y];
    }

    if(len>dist[x+1][y] && checked[x+1][y]==1){
        len=dist[x+1][y];
    }

    if(len>dist[x][y-1] && checked[x][y-1]==1){
        len=dist[x][y-1];
    }

    if(len>dist[x][y+1] && checked[x][y+1]==1){
        len=dist[x][y+1];
    }

    dist[x][y]=len+1;

    
    if(checked[x-1][y]==0)
        push(x-1,y,n,m);
    if(checked[x+1][y]==0)
        push(x+1,y,n,m);
    if(checked[x][y-1]==0)
        push(x,y-1,n,m);
    if(checked[x][y+1]==0)
        push(x,y+1,n,m);


}

void bfs(int x, int y, int n, int m){

    checked[x][y]=1;
    dist[x][y]==0;

    push(x-1,y,n,m);
    push(x+1,y,n,m);
    push(x,y-1,n,m);
    push(x,y+1,n,m);

    struct point tmp;

    while(front<rear){
        tmp = pop();
        find_short_len(tmp.x, tmp.y, n, m);
    }
}

void set_cant_reach_land_to_1(int n, int m){
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(checked[x][y]==0 && map[x][y]==1){
                dist[x][y]=-1;
            }
        }
    }
}
int main(void){

    int n,m;
    int x,y;
    int tmp;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&tmp);
            map[i][j]=tmp;

            if(tmp==2){//도착지점 저장
                x=i; y=j;
            }
        }
    }
    //BFS
    bfs(x,y,n,m);
    set_cant_reach_land_to_1(n,m);
    //print
    printdist(n,m);
    //printchecked(n,m);

}