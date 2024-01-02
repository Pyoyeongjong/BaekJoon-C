// 45:14

#include <stdio.h>

int cheeze[101][101];
int count = 0;
int visited[101][101];
int deletecheezemark[101][101];

int findcheeze(int n, int m){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cheeze[i][j]==1){
                return 1; //치즈가 있다
            }
        }
    }
    return 0;//치즈가 더 이상 없다.
}

void clearvisited(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
}

void cleardcm(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            deletecheezemark[i][j]=0;
        }
    }
}

void dfs(int x, int y, int n, int m){

    visited[x][y]=1;

    if(cheeze[x][y]==1)
    {
        return;
    }

    cheeze[x][y]=2;

    if(x-1>=0 && visited[x-1][y]==0){
        dfs(x-1,y,n,m);
    }
    if(x+1<n && visited[x+1][y]==0){
        dfs(x+1,y,n,m);
    }
    if(y-1>=0 && visited[x][y-1]==0){
        dfs(x,y-1,n,m);
    }
    if(y+1<m && visited[x][y+1]==0){
        dfs(x,y+1,n,m);
    }
}

void outsideair(int n, int m){
    
    // 바깥공기는 2로 하자. + DFS
    dfs(0,0,n,m);
    
}

void marking(int x, int y, int n, int m){
    int ccount = 0;

    if(x-1>=0){
        if(cheeze[x-1][y]==2)
            ccount++;
    }
    if(x+1<n){
        if(cheeze[x+1][y]==2)
            ccount++;
    }
    if(y-1>=0){
        if(cheeze[x][y-1]==2)
            ccount++;
    }
    if(y-1<m){
        if(cheeze[x][y+1]==2)
            ccount++;
    }

    if(ccount>=2){
        deletecheezemark[x][y]=1;
    }
}

void deletecheeze(int n, int m){
    // deletecheezemark 0으로 초기화
    cleardcm(n,m);
    // marking
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            marking(i,j,n,m);
        }
    }
    // 반영
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(deletecheezemark[i][j]==1){
                cheeze[i][j]=0;
            }
        }
    }
    return;
}


int main(void){

    //입력
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&cheeze[i][j]);
        }
    }

    while(1){
        // 0. 치즈가 남았는지 확인
        if(findcheeze(n,m)==0){
            break;
        }
        // 1. 외부 공기를 표현하기
        clearvisited(n,m);
        outsideair(n,m);
        // 2. 치즈 제거
        deletecheeze(n,m);
        // 3. 카운트 올리기
        count++;
    }

    printf("%d",count);
    

}