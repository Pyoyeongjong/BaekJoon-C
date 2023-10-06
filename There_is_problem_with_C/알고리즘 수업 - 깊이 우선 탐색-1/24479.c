#include <stdio.h>
#include <stdlib.h>

struct node{
    int n;
    struct node* next;
};

struct node* list[100001];
int visited[100001];

void insert(int u, struct node* tmp){
    if(list[u]==NULL){
        list[u]=tmp;
        return;
    }else{
        struct node* p=list[u];
        if(tmp->n < p->n){ // tmp가 첫번쨰로 들어가야 할 때
            tmp->next=p;
            list[u]=tmp;
            return;
        }else{//아닐 때
            while(p!=NULL){
                if(p->next==NULL){//마지막에 넣을 때
                    p->next=tmp;
                    return;
                }else{//중간에 넣을 때
                    if(tmp->n < p->next->n){
                        tmp->next=p->next;
                        p->next=tmp;
                        return;
                    }else{
                        p=p->next;
                    }
                }
            }
        }
    }
}

void printlist(int i){
    struct node* p=list[i];
    printf("%d node: ",i);

    while(p!=NULL){
        printf("%d ",p->n);
        p=p->next;
    }
    printf("\n");
    return;
}

void listing(int u, int v){
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->n=v;
    tmp->next=NULL;

    insert(u, tmp);
    return;
}

void dfs(int n){

    static int order=1;

    //printf("hi %d\n",n);
    if(visited[n]<=0){
        visited[n]=order++;
    }else{
        return;
    }
    struct node* p=list[n];
    while(p!=NULL){
        dfs(p->n);
        p=p->next;
    }
    return;
}

void printvisited(int n){
    for(int i=1;i<=n;i++){
        printf("%d\n",visited[i]);
    }
    return;
}
int main(void){
    int N, M, R;
    scanf("%d %d %d",&N,&M,&R);

    for(int i=1;i<=N;i++){
        visited[i]=0;
    }

    int u,v;
    for(int i=0;i<M;i++){
        scanf("%d %d",&u,&v);
        listing(u,v);
        listing(v,u);
    }
    // for(int i=1;i<=N;i++){
    //     printlist(i);
    // }

    dfs(R);
    printvisited(N);
    return 0;
}