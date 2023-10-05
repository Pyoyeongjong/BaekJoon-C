// 실패 - 시간초과
#include <stdio.h>
#include <stdlib.h>

//linked list 이용
struct time{
    unsigned int st;
    unsigned int et;
    struct time *next;
};

struct time *root=NULL;

void insertnode(unsigned int st, unsigned int et){
    struct time* pt;
    struct time* temp = (struct time*)malloc(sizeof(struct time));

    temp->st=st;
    temp->et=et;
    temp->next=NULL;

    // empty
    if(root==NULL){
        root=temp;
        return;
    }else{
        // not empty
        // insert front
        if(root->st==temp->st){
            if(root->et>temp->et){
                root->et=temp->et;
            }
            return;
        }
        if(root->st>temp->st){
            temp->next=root;
            root = temp;
            return;
        }
        // insert middle
        for(pt=root;pt->next;pt=pt->next){
            if(pt->st==temp->st){
                if(pt->et > temp->et){
                    pt->et=temp->et;
                }
                return;
            }
            if(pt->st < temp->st && pt->next->st > temp->st){
                temp->next=pt->next;
                pt->next=temp;
            }
        }
        // insert end
        if(pt->st==temp->st){
            if(pt->et > temp->et){
                pt->et=temp->et;
            }
            return;
        }else{
            pt->next=temp;
        }
    }
}

void printlist(){
    struct time* pt = root;
    while(pt!=NULL){
        pt=pt->next;
    }
    return;
}

unsigned int loweset_et(int bound){
    struct time *pt = root;
    unsigned int min = 0xffffffff;
    while(pt!=NULL){
        if(bound > pt->st){
            pt=pt->next;
            continue;
        }

        if(pt->et<min){
            min=pt->et;
        }
        pt=pt->next;
    }
    return min;
}

int greedy(){
    int result = 0;
    // 가장 et가 낮은 노드 고르기.
    
    unsigned int temp = loweset_et(0);

    while(1){
        if(temp==0xffffffff){
            return result;
        }
        else{
            result++;
            temp = loweset_et(temp);
        }
    }

    return result;
}


int main(void){

    int N;
    unsigned int st,et;

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d %d",&st, &et);
        insertnode(st, et);
    }

    printlist();

    //greedy
    
    int result = greedy();
    printf("%d",result);
}