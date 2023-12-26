#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pkmon{
    int n;
    char name[21];
};
struct pkmon dogam[100001];
struct pkmon sorted[100001];

void printsorted(int n){
    printf("-----------printsorted----------\n");
    for(int i=1;i<=n;i++){
        printf("%2d %s\n",sorted[i].n,sorted[i].name);
    }
}

int compare(const void* a, const void* b){
    struct pkmon A=*(struct pkmon*)a;
    struct pkmon B=*(struct pkmon*)b;

    if(strcmp(A.name,B.name)>0)
        return 1;
    else
        return -1;
}

int main(void){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        scanf("%s",dogam[i].name);
        strcpy(sorted[i].name,dogam[i].name);
        dogam[i].n=i;
        sorted[i].n=dogam[i].n;
    }

    qsort(sorted+1, n, sizeof(struct pkmon), compare);
    //printsorted(n);

    char q[21];
    int qq;
    int f,e,mid;
    int res;
    for(int i=0;i<m;i++){
        scanf("%s",q);
        if(q[0]>='1' && q[0]<='9'){
            qq=atoi(q);
            printf("%s\n",dogam[qq].name);
        }else{
            f=1;
            e=n;
            while(f<=e){
                mid=(f+e)/2;
                res= strcmp(q,sorted[mid].name);
                if(res==0){
                    printf("%d\n",sorted[mid].n);
                    break;
                }else if(res<0){
                    e=mid-1;
                }else{
                    f=mid+1;
                }
            }
        }
    }

}