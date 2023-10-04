#include <stdio.h>
#define max 3*3*3*3*3*3*3*3

char board[max][max];

void printboard(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    return;
}

void erase_star(int n, int st1, int st2){
    
    int num = n/3;

    for(int i=st1 + num*1;i<st1+num*2;i++){
        for(int j=st2+num*1;j<st2+num*2;j++){
            board[i][j]=' ';
        }
    }

    if(num==1){
        return;
    }else{
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                erase_star(num, st1+num*i,st2+num*j);
            }
        }
        return;
    }
}

int main(void){
    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]='*';
        }
    }

    erase_star(N, 0, 0);
    printboard(N);
}