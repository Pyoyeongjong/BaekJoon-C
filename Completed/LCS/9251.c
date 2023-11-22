#include <stdio.h>
#include <string.h>
#define max(x,y) x > y ? x : y
char one[1002];
char two[1002];

//backtracking 용int dp[1001][1001];
int two_iter=0;
int result_len=0;
int max=0;
int one_len;
int two_len;

void backtracking(int x){
    int tmp_two_iter=two_iter;
    for(int i=x;i<one_len;i++){
        //유망하지 않을 때
        if(one_len-i <= max-result_len)
            break;
        for(int j=two_iter;j<two_len;j++){
            //유망하지 않을 때
            if(two_len-j <= max-result_len)
                break;
            else//유망할 때
            {
                if(one[i]==two[j]){
                    result_len++;
                    if(result_len>max)
                        max=result_len;
                    two_iter=j+1;
                    backtracking(i+1);
                    two_iter=tmp_two_iter;
                    result_len--;
                }
            }
            
        }
    }
}
//dp 용
int dp[1002][1002];

void ddp(){
    for(int i=1;i<=one_len;i++){
        for(int j=1;j<=two_len;j++){
            if(one[i]==two[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
            //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        }
    }
}

int main(void){

    scanf("%s",one+1);
    scanf("%s",two+1);

    one_len=strlen(one+1);
    two_len=strlen(two+1);

    //backtracking(0);
    //printf("%d",max);

    ddp();
    printf("%d",dp[one_len][two_len]);

}