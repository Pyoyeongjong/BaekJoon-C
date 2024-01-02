//걸린 시간 : 01:44:59
#include <stdio.h>
#define min(x,y) x < y ? x : y

int cost[1001][1001];

int dist[1001];
int visited[1001];

void printdist(int n){
    printf("dist : ");
    for(int i=1;i<=n;i++){
        printf("%d ",dist[i]);
    }
    printf("\n");
}

void dijkstra(int snode, int n){

    int visitcount = 0;
    int node = snode;

    while(visitcount<n){

        if(visitcount==0){
            //printf("picked : %d\n",node);
            visited[node]=1;
            int tmp;
            for(int i=1;i<=n;i++){
                tmp = cost[node][i];
                if(tmp<0){
                    dist[i]=0x7fffffff;
                }else{
                    dist[i]=tmp;
                }
            }
            visitcount++;
            //printdist(n);
            continue;
        }
        // dist 중 가장 작은 거 찾기.
        int smaller=0x7fffffff;
        int ssnode;
        for(int i=1;i<=n;i++){
            if(smaller>dist[i] && visited[i]==0){
                smaller=dist[i];
                ssnode=i;
            }
        }
        node = ssnode;
        visited[node]=1;
        //printf("picked : %d\n",node);
        for(int i=1;i<=n;i++){
            int tmp = cost[node][i];
            if(tmp<0){
                continue;
            }else{
                dist[i]=min(dist[i],dist[node]+tmp);
            }
        }

        visitcount++;
        //printdist(n);
    }
}

int main(void){

    int n, m;
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=-1;
        }
    }

    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(cost[a][b]>c || cost[a][b]<0)
            cost[a][b]=c;
    }

    int s, d;
    scanf("%d %d",&s,&d);

    if(s==d){
        printf("0");
        return 0;
    }
    //dijkstra
    dijkstra(s,n);

    //print
    printf("%d",dist[d]);

}