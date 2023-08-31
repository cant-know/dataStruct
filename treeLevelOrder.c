#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
}TreeNode;

typedef struct QueueNode
{
  TreeNode* data;
  struct QueueNode* pre;
  struct QueueNode* next;
}QueueNode;

void createTree(TreeNode** T){
  int data;
  scanf("%d",&data);
  if(data == -1){
    *T = NULL;
  }else{
    *T = (TreeNode*)malloc(sizeof(TreeNode));
    (*T)->data = data;
    createTree(&((*T)->left));
    createTree(&((*T)->right));
  }
}

void preTree(TreeNode* T){
  if(T == NULL){
    return;
  }else{
    printf("%d",T->data);
    preTree(T->left);
    preTree(T->right);
  }
}

QueueNode* initQueue(){
  QueueNode* queue = (QueueNode*)malloc(sizeof(QueueNode));
  queue->data = NULL;
  queue->pre = queue;
  queue->next = queue;
  return queue;
}

void pushQueue(QueueNode* queue,TreeNode* data){
  QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
  node->data = data;
  node->pre = queue;
  node->next = queue;
  queue->pre = node;
  queue->pre->next = node;
}

int isEmpty(QueueNode* queue){
  if(queue->next == queue){
    return 1;
  }else{
    return 0;
  }
}

QueueNode* shiftQueue(QueueNode* queue){
  if(isEmpty(queue)){
    return NULL;
  }else{
    QueueNode* node = queue->next;
    queue->next->next->pre = queue;
    queue->next = queue->next->next;
    return node;
  }
}

void levelOrder(QueueNode* queue,TreeNode* T){
  pushQueue(queue,T);
  while (!isEmpty(queue))
  {
    QueueNode* node = shiftQueue(queue);
    printf("%d ",node->data->data);
    if(node->data->left){
      pushQueue(queue,node->data->left);
    }
    if(node->data->right){
      pushQueue(queue,node->data->right);
    }
  }
  
}

int main(){
  QueueNode* Q = initQueue();
  TreeNode* T;
  createTree(&T);
  preTree(T);
  printf("\n");
  levelOrder(Q,T);
  printf("\n");
  system("pause");
  return 0;
}

