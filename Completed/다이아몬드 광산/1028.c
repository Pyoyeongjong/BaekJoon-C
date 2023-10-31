#define min(x,y) x > y ? y : x
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool find=false;
int mine[752][752];
//보고 베꼈다. Dp생각도 못함.
int max=0;

int ld[752][752];
int rd[752][752];
int lu[752][752];
int ru[752][752];

int main(void){
    int R, C;
    scanf("%d %d",&R, &C);

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            scanf("%1d",&mine[i][j]);
        }
    }

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(mine[i][j]==1){
                   lu[i][j]=lu[i-1][j-1]+1;
                   ru[i][j]=ru[i-1][j+1]+1;
            }
        }
    }

    for(int i=R;i>=1;i--){
        for(int j=C;j>=1;j--){
            if(mine[i][j]==1){
                   ld[i][j]=ld[i+1][j-1]+1;
                   rd[i][j]=rd[i+1][j+1]+1;
            }
        }
    }

    int k;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(mine[i][j]==1){
                k=min(ld[i][j],rd[i][j]);
                for(int a=1;a<=k;a++){
                    if(i+2*(a-1)<=750){
                        if(mine[i+2*(a-1)][j] && lu[i+2*(a-1)][j]>=a && ru[i+2*(a-1)][j]>=a){
                            if(max<a){
                                //printf("i=%d j=%d k(max)=%d\n",i,j,k);
                                max=a;
                            }
                                
                        }
                    }
                }
            }
        }
    }

    printf("%d",max);
    return 0;
}