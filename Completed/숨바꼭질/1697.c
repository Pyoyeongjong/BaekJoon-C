#include <stdio.h>

struct node{
    int n;
    int h;
};

struct node queue[10000000];
int front=0; int rear=0;
int visited[200001];

void push(int n, int h){
    if(visited[n]==1 || n < 0) // <- 이게 중요하네~~
        return;
    
    struct node tmp={n, h};
    queue[rear++]=tmp;
    visited[n]=1;
}

struct node pop(){
    return queue[front++];
}

void bfs(int n){
    
    struct node k;

    while(front<rear){
        k=pop();

        if(n==(k.n)){
            printf("%d",k.h);
            return;
        }

        push((k.n)-1, (k.h)+1);
        push((k.n)+1, (k.h)+1);

        if((k.n)%2==0){
            push((k.n)/2 , (k.h)+1);
        }       
    }

    return;
}

//BFS
int main(void){

    int n, k;
    scanf("%d %d",&n,&k);

    push(k,0);
    bfs(n);
    return 0;
}