#include <stdio.h>
#define Size 1048576



//candy개수가
int segtree[Size*2+1];
int arr[Size+1];

void printarr(int size){
    for(int i=1;i<size;i++){
        printf("%d ",segtree[i]);
    }
    printf("\n");
    return;
}

int init(int node, int st, int ed){
    if(st==ed)
        return segtree[node]=arr[st];
    int mid= (st+ed)/2;
    return segtree[node]=init(node*2,st,mid)+init(node*2+1,mid+1,ed);

}

void update(int node, int st, int ed, int t, int diff){
    if(st>t || ed<t)
        return;

    segtree[node]+=diff;
    if(st==ed)
        return;
    int mid = (st+ed)/2;
    update(node*2,st,mid,t,diff);
    update(node*2+1,mid+1,ed,t,diff);
}

int sum(int l, int r, int node, int st, int ed){
    if(l<=st && ed<=r)
        return segtree[node];
    if(r<st||ed<l)
        return 0;
    int mid=(st+ed)/2;
    return sum(l,r,node*2,st,mid)+sum(l,r,node*2+1,mid+1,ed);

}

int search(int num, int st, int ed){
    //printf("%d %d\n",st,ed);
    if(st==ed)
        return st;

    int mid=(st+ed)/2;
    int a = sum(1,mid,1,1,Size); //mid가 arr num
    //printf("mid=%d num=%d a=%d\n",mid, num, a);

    if(num<=a)
        return search(num, st, mid);
    else
        return search(num,mid+1,ed);
    
}

//이분탐색
int main(void){
    int n;
    int a,b,c;
    int result;
    int count=0;
    scanf("%d",&n);
    while(n--){
        //printarr(20);
        scanf("%d %d",&a, &b);

        if(a==1)
        {
            if(b>count){
                result=search(count,1,Size);
                printf("%d\n",result);
                update(1,1,Size,result,-1);
                count--;
            }else{
                result=search(b,1,Size);
                printf("%d\n",result);
                update(1,1,Size,result,-1);
                count--;
            }

        }
        else if(a==2)
        {
            scanf("%d",&c);
            update(1,1,Size,b,c);
            count+=c;
        }

    }

}