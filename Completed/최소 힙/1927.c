#include <stdio.h>

int heap[100001];
int size = 0;

void change_loc(int a, int b){
    int tmp=heap[a];
    heap[a]=heap[b];
    heap[b]=tmp;
    return;
}

int insert(int x){

    heap[++size]=x;
    
    int parent, tmp=size;
    while(tmp>1){
        parent=tmp/2;
        if(heap[parent]>heap[tmp]){
            change_loc(parent,tmp);
            tmp=tmp/2;
        }else{
            break;
        }
    }
}

int delete(){
    int result = heap[1];
    heap[1]=heap[size--];

    int tmp=1; int c1, c2;
    while(tmp<=size){
        c1=tmp*2;
        c2=tmp*2+1;
        if(heap[c1]<heap[tmp] && c1<=size && heap[c2]<heap[tmp] && c2<=size){
            if(heap[c1]<heap[c2]){
                change_loc(tmp, c1);
                tmp=c1;
                continue;
            }else{
                change_loc(tmp, c2);
                tmp=c2;
                continue;
            }

        }
        else if(heap[c1]<heap[tmp] && c1<=size){
            change_loc(tmp, c1);
            tmp=c1;
            continue;
        }
        else if(heap[c2]<heap[tmp] && c2<=size){
            change_loc(tmp, c2);
            tmp=c2;
            continue;
        }else{
            break;
        }
    }

    return result;
}

int main(void){
    int n, x;

    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x==0){
            if(size==0)
                printf("0\n");
            else
                printf("%d\n",delete());
        }else{
            insert(x);
        }
    }
}