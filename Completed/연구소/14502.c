#include <stdio.h>

struct point{
    int x;
    int y;
};

int map[8][8];
int tmp_map[8][8];
struct point zero[65];
struct point two[65];
int ztop=0;
int ttop=0;

void copy_map(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp_map[i][j]=map[i][j];
        }
    }
    return;
}

void mapping(struct point x, struct point y, struct point z){
    tmp_map[x.x][x.y]=1;
    tmp_map[y.x][y.y]=1;
    tmp_map[z.x][z.y]=1;
    return;
}

void spreadvirus(int x, int y, int n, int m){

    if(x-1>=0){
        if(tmp_map[x-1][y]==0){
            tmp_map[x-1][y]=2;
            spreadvirus(x-1,y,n,m);
        }
    }
    if(y-1>=0){
        if(tmp_map[x][y-1]==0){
            tmp_map[x][y-1]=2;
            spreadvirus(x,y-1,n,m);
        }
    }
    if(x+1<n){
        if(tmp_map[x+1][y]==0){
            tmp_map[x+1][y]=2;
            spreadvirus(x+1,y,n,m);
        }
    }
    if(y+1<m){
        if(tmp_map[x][y+1]==0){
            tmp_map[x][y+1]=2;
            spreadvirus(x,y+1,n,m);
        }
    }
    return;
}

int calculate(int n, int m){

    int count = 0;
    for(int i=0;i<ttop;i++){
        spreadvirus(two[i].x, two[i].y, n, m);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp_map[i][j]==0)
                count++;
        }
    }

    return count;

}

int main(void){
    int n, m;
    scanf("%d %d",&n, &m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==0){
                zero[ztop].x=i;
                zero[ztop].y=j;
                ztop++;
            }
            if(map[i][j]==2){
                two[ttop].x=i;
                two[ttop].y=j;
                ttop++;
            }
        }
    }

    copy_map(n,m);

    int max=0, tmp;
    for(int i=0;i<ztop;i++){
        for(int j=i+1;j<ztop;j++){
            for(int k=j+1;k<ztop;k++){
                mapping(zero[i],zero[j],zero[k]);
                tmp=calculate(n,m);
                if(tmp > max)
                    max = tmp;
                copy_map(n,m);
            }
        }
    }

    printf("%d",max);

}