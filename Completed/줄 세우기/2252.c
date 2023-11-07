#include <stdio.h>
#include <stdlib.h>

struct list{
    int n;
    struct list* next;
};

struct list* after[32001];
int before[32001];

int queue[32001];
int front=0, rear=0;

void push(int a){
    queue[rear++]=a;
    return;
}
int pop(){
    if(front==rear)
        return -1;
    return queue[front++];
}


void reduceafter(int j){
    struct list *p = after[j];

    while(p!=NULL){
        before[p->n]-=1;
        p=p->next;
    }
    return;
}

int main(void){

    int n, m;
    scanf("%d %d",&n, &m);

    int a, b;
    for(int i=0;i<m;i++){
        scanf("%d %d",&a, &b);
        before[b]+=1;
        struct list* tmp =(struct list*)malloc(sizeof(struct list));
        tmp->n=b;
        tmp->next=after[a];
        after[a]=tmp;
    }

    int count=0;

    while(count<n){
        for(int j=1;j<=n;j++){
            if(before[j]==0){
                push(j);
                before[j]=-1;
            }
        }
        int a;
        while(1){
            a=pop();
            if(a==-1)
                break;
            printf("%d ",a);
            count++;
            reduceafter(a);
        }
    }

    return 0;

}