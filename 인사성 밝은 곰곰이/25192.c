#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct TreeNode{
    char element[20];
    struct TreeNode *left, *right;
}TreeNode;

int treesort(struct TreeNode *root, struct TreeNode *node){

    int result = strcmp(root->element,node->element);
    if(result==0){
        return 1;//같은 걸 찾음
    }
    else{
        if(result<0){
            if(!root->left){
                root->left = node;
                return 0;
            }
            else{
                treesort(root->left,node);
            }
                
        }else{
            if(!root->right){
                root->right = node;
                return 0;
            }
            else{
                treesort(root->right,node);
            }
                
        }
    }
}

int main(void){
    
    int N;
    int emocount = 0;
    char input[20];

    struct TreeNode *root = NULL;

    scanf("%d",&N);

    while(N--){
        scanf("%s",input);
        // ENTER 입력 시 초기화
        if (strcmp(input,"ENTER")==0){
            //Tree 초기화
            root = NULL;
            continue;
        }
        // Node 생성
        struct TreeNode *temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        strcpy(temp->element,input);
        temp->left=NULL;
        temp->right=NULL;
        if(!root){
            root = temp;
            emocount++;
            continue;
        }
        int result = treesort(root, temp);
        if(result==0)
            emocount++;
    }
    // 출력
    printf("%d",emocount);
    return 0;
}