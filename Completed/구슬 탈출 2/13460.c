#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define L "left"
#define R "right"
#define U "up"
#define D "down"

// 노가다 뛰는 거같은데.
int rx, ry, bx, by;
char board[11][11];
int min=11;
bool redin = false;
bool bluein = false;
int count=0;

void change_item(int ax, int ay, int bx, int by){
    char temp;
    temp = board[ax][ay];
    board[ax][ay]=board[bx][by];
    board[bx][by]=temp;
    return;
}

int shift(int xx, int yy, char* dir, char color){
    if(color=='R'){
        if(redin)
            return 1;
    }
    if(color=='B'){
        if(bluein)
            return 1;
    }

    int x,y;

    if(strcmp(dir,"left")==0){
        x=xx; y=yy-1;
    }
    if(strcmp(dir,"right")==0){
        x=xx; y=yy+1;
    }
    if(strcmp(dir,"up")==0){
        x=xx-1; y=yy;
    }
    if(strcmp(dir,"down")==0){
        x=xx+1; y=yy;
    }

    // Shift 할 곳이 ...라면
    if(board[x][y]=='#'){
        return 1; // 갈 수 없다!
    }else if(board[x][y]=='O'){
        if(color=='R'){
            board[rx][ry]='.';
            redin = true;
            return 0;
        }else if(color=='B'){
            board[bx][by]='.';
            bluein = true;
            return 0;
        }
    }else if(board[x][y]=='R'){
        int tmp;
        if(shift(x,y,dir,'R')!=1){
            shift(xx,yy,dir,'B');
        }else
            return 1;
    }else if(board[x][y]=='B'){
        if(shift(x,y,dir,'B')!=1){
            shift(xx,yy,dir,'R');
        }else
            return 1;
    }else{
        if(color=='R'){
            change_item(x,y,rx,ry);
            rx=x; ry=y;
            return 0;
        }
        else if(color=='B'){
            change_item(x,y,bx,by);
            bx=x; by=y;
            return 0;
        }
    }
    
}

void printboard(int r, int c){
    printf("R=%d,%d B=%d,%d\n",rx,ry,bx,by);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    return;
}

int shifts(char* dir){
    int r=0, b=0;
    while(r==0 || b==0){
        r=shift(rx,ry,dir,'R');
        b=shift(bx,by,dir,'B');
    }

    count++;

    if(bluein==true){
        return -1;
    }else{
        if(redin==true){
            if(min>count){
                //printf("min=%d, count=%d\n",min,count);
                min=count;
            }
            return 1;
        }
    }

    return 0;
}
void undo(int prx, int pry, int pbx, int pby){
    count--;
    board[rx][ry]='.';
    board[bx][by]='.';
    board[prx][pry]='R';
    board[pbx][pby]='B';
    rx=prx; ry=pry; bx=pbx; by=pby;
    bluein=false; redin=false;
    return;
}
void find_RB(int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]=='R'){
                rx=i;
                ry=j;
            }
            if(board[i][j]=='B'){
                bx=i;
                by=j;
            }
        }
    }
    return;
}

void shifting(int n){
    if(n>=10){
        return;
    }
    int prx, pry, pbx, pby;
    prx=rx;pry=ry;pbx=bx;pby=by;

    if(shifts(U)==0){            
        shifting(n+1);
    }
    undo(prx,pry,pbx,pby);
    if(shifts(D)==0){
        shifting(n+1);
    }
    undo(prx,pry,pbx,pby);
    if(shifts(L)==0){
        shifting(n+1);
    }
    undo(prx,pry,pbx,pby);
    if(shifts(R)==0){
        shifting(n+1);
    }
    undo(prx,pry,pbx,pby);

    return;

}

int main(void){
    int N,M;
    scanf("%d %d",&N, &M);

    for(int i=0;i<N;i++){
        scanf("%s",board[i]);
    }
    find_RB(N,M);
    shifting(0);
    if(min<=10)
        printf("%d",min);
    else
        printf("-1");
}

