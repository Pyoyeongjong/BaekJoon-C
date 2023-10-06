#include <stdio.h>
#include <malloc.h>
#define INF 999999999
typedef struct _node{
    int n;
    int w;
    struct _node* next;
}node;

node* arr[20001];

void insert(int u,int v,int w){
    node* tmp=(node *)malloc(sizeof(node));
    tmp->n=v; tmp->w=w; tmp->next=NULL;
    if(arr[u]==NULL){
        arr[u]=tmp; return;
    }
    tmp->next=arr[u];
    arr[u]=tmp;
    return;
}
int visited[20001];
int min_weight[20001];
void dijkstra(int k, int v){
    //초기화
    for(int i=1;i<=v;i++){
        min_weight[i]=INF;
    }
    //시작 노드
    visited[k]=1;
    min_weight[k]=0;
    node* p=arr[k];
    while(p!=NULL){
        min_weight[p->n]=p->w;
        p=p->next;
    }
    int tmp_min; int next; node* pp;
    while(1){
        tmp_min=INF;
        for(int i=1;i<=v;i++){
            if(visited[i]==0){
                if(tmp_min>min_weight[i]){
                    tmp_min=min_weight[i];
                    next=i;
                }
            }
        }
        if(tmp_min==INF)
            break;

        visited[next]=1;
        pp=arr[next];
        while(pp!=NULL){
            if(min_weight[pp->n]>min_weight[next]+pp->w)
                min_weight[pp->n]=min_weight[next]+pp->w;
            pp=pp->next;
        }
    }
}

void printweight(int v){
    for(int i=1;i<=v;i++){
        if(min_weight[i]==INF)
            printf("INF\n");
        else
            printf("%d\n",min_weight[i]);
    }
}
int main(void){
    int V,E,K;
    scanf("%d %d",&V,&E);
    scanf("%d",&K);
    int u,v,w;
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&u,&v,&w);
        insert(u,v,w);
    }
    dijkstra(K, V);
    printweight(V);
}