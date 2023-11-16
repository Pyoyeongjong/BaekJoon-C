#include <stdio.h>
#include <math.h>


/*
//하나씩 지우고 계산하는 건 말이 안됨. 규칙 있을 듯
// 최대 집 개수 = 100개, 최대 치킨집 개수 = 13개
// 6개를 살려야 할 때 최대 필드 계산 횟수 : 
// C(13,6)=1716개 많긴하다잉
총 계산 횟수 = 1716*100* = 약 100만.
// 가장 가능성 있는 것부터 해야할 것 같음. <- greedy
가 아닌 브루트포스였음..!
*/

struct point{
    int r;
    int c;
};

struct point home[101];
int hl=0;
struct point chick[15];
int cl=0;
int cmb[14]; // stack마냥 운영함.
int top=-1;
int min=0x7fffffff;

void push(int a){
    cmb[++top]=a;
}
int pop(){
    if(top==-1)
        return -1;
    return cmb[top--];
}

int dist(struct point x, struct point y){
    return abs(x.r-y.r)+abs(x.c-y.c);
}

int combination(int cnt, int next, int n, int m){
    
    int hmin, tmp;
    int sum=0;

    if(cnt==m){
        // 거리 측정
        for(int i=0;i<hl;i++){
            hmin=0x7fffffff;
            for(int j=0;j<cnt;j++){
                tmp = dist(chick[cmb[j]],home[i]);
                if(hmin>tmp){
                    hmin=tmp;
                }
            }
            sum+=hmin;
        }
        
        if(sum<min){
            min=sum;
            return 0;
        }
        // cmb에서 빼주기
        return 0;
    }

    if(cnt<m){
        for(int i=next;i<cl;i++){
            push(i);
            combination(cnt+1,i+1, n, m);
            pop();
        }
    }
    return 0;
}

int main(void){
    int n, m;
    scanf("%d %d",&n,&m);

    int tmp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&tmp);
            if(tmp==1){
                home[hl].r=i;
                home[hl].c=j;
                hl++;
            }else if(tmp==2){
                chick[cl].r=i;
                chick[cl].c=j;
                cl++;
            }
        }
    }

    combination(0, 0, n, m);
    printf("%d",min);
}