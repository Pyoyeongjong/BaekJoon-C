#include <stdio.h>
#include <string.h>
#include <math.h>

int isbroken[10];
int count=0;
int leftcount;
int rightcount;
int find=0;

int can_make(int n){

    if(n==100){
        find=1;
        count++;
        return 0;
    }

    if(n==0){
        if(isbroken[0]==0){
            find=1;
            count++;
            return 0;
        }
        else{
            count++;
            return 1;
        }
    }

    int tmp = n;
    int a;
    int ln=0;

    while(tmp>0){
        a = tmp%10;
        ln++;
        tmp = tmp/10;

        if(isbroken[a]==1){
            count++;
            return 1;
        }
    }
    find=1;
    count+=ln;
    return 0;
}

void leftfind(int n){
    count = 0;
    int a=n;
    while(can_make(a)==1){
        //printf("%d is false\n",a-1);
        a=a-1;
        if(a<0)
            break;
    }
    if(find==1)
        leftcount=count;
    else 
        leftcount=0x7fffffff;
}

void rightfind(int n){
    count = 0;
    int a=n;
    while(can_make(a)==1){
        //printf("%d is false\n",a+1);
        a=a+1;
        if(a>1000000)
            break;
    }
    rightcount=count;
}
int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

int main(void){

    int now=100;

    int n, b, t;
    scanf("%d",&n);
    scanf("%d",&b);
    for(int i=0;i<b;i++){
        scanf("%d",&t);
        isbroken[t]=1;
    }

    if(n==100){
        printf("0\n");
        return 0;
    }


    //왼쪽부터 쭉쭉
    leftfind(n);
    rightfind(n);
    if(b==10){
        leftcount=0x7fffffff;
        rightcount=0x7fffffff;
    }
    //printf("hello:%d %d %d\n",now-n,leftcount,rightcount);
    printf("%d",min(abs(now-n),min(leftcount,rightcount)));
}