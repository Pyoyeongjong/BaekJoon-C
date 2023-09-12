#include <stdio.h>

int num[12]; // 1번부터 저장
int result[12]; // 1번부터 저장

int min=1000000001;
int max=-1000000001;

void cal_min(int num){
    if(num<min)
        min=num;
    return;
}
void cal_max(int num){
    if(max<num)
        max=num;
    return;
}
void cal_min_max(int num){
    cal_max(num);
    cal_min(num);
    return;
}
void DFS(int N, int cur, int pl, int mi, int mx, int dv){
    if(cur==1){
        result[cur]=num[cur];
        DFS(N, cur+1, pl, mi, mx, dv);
    }
    else{
        if(pl>0){
            // 덧셈
            result[cur]=result[cur-1]+num[cur];
            // 종료
            if(cur==N){
                cal_min_max(result[cur]);
                return;
            }
            // 종료 아님
            DFS(N, cur+1, pl-1, mi, mx, dv);
        }
        if(mi>0){
            // 뺄셈
            result[cur]=result[cur-1]-num[cur];
            // 종료
            if(cur==N){
                cal_min_max(result[cur]);
                return;
            }
            // 종료 아님
            DFS(N, cur+1, pl, mi-1, mx, dv);
        }
        if(mx>0){
            // 곱셈
            result[cur]=result[cur-1]*num[cur];
            // 종료
            if(cur==N){
                cal_min_max(result[cur]);
                return;
            }
            // 종료 아님
            DFS(N, cur+1, pl, mi, mx-1, dv);
        }
        if(dv>0){
            // 나눗셈
            result[cur]=result[cur-1]/num[cur];
            // 종료
            if(cur==N){
                cal_min_max(result[cur]);
                return;
            }
            // 종료 아님
            DFS(N, cur+1, pl, mi, mx, dv-1);
        }
        return;
    }
}

int main(void){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&num[i]);
    }
    int pl, mi, mx, dv;
    scanf("%d %d %d %d",&pl, &mi, &mx, &dv);

    DFS(N, 1, pl, mi, mx, dv);

    printf("%d\n%d",max,min);
}