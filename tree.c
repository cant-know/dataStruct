#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode* leftNode;
  struct TreeNode* rightNode;
}TreeNode;

void createTree(TreeNode** T){
  int data;
  scanf("%d",&data);
  if(data == -1){
    // 此时为空节点
    *T = NULL;
  }
  else{
    // 不为空节点
    *T = (TreeNode*)malloc(sizeof(TreeNode));
    (*T)->data = data;
    createTree(&((*T)->leftNode));
    createTree(&((*T)->rightNode));
  }
}

void preOrder(TreeNode* T){
  if(T == NULL){
    return;
  }else{
    printf("%d ",T->data);
    preOrder(T->leftNode);
    preOrder(T->rightNode);
  }
}

void inOrder(TreeNode* T){
  if(T == NULL){
    return;
  }else{
    inOrder(T->leftNode);
    printf("%d ",T->data);
    inOrder(T->rightNode);
  }
}

void afterOrder(TreeNode* T){
  if(T == NULL){
    return;
  }else{
    afterOrder(T->leftNode);
    afterOrder(T->rightNode);
    printf("%d ",T->data);
  }
}

int main(){
  TreeNode* T;
  createTree(&T); 
  preOrder(T);
  printf("\n");
  inOrder(T);
  printf("\n");
  afterOrder(T);
  system("pause");
  return 0;
}