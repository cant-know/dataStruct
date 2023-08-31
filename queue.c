#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
}Node;

Node* initQueue(){
  Node* queue = (Node*)malloc(sizeof(Node));
  queue->data = 0;
  queue->next = NULL;
}

void tailInsert(Node* queue,int data){
  Node* node = (Node*)malloc(sizeof(Node));
  queue->data++;
  node->data = data;
  while (queue->next)
  {
    queue=queue->next;
  }
  queue->next=node;
  node->next=NULL;
}

void printQueue(Node* queue){
  queue = queue->next;
  while(queue){
    printf("%d ",queue->data);
    queue = queue->next;
  }
  printf("NULL");
}

int isEmpty(Node* queue){
  if(queue->next==NULL){
    return 1;
  }else{
    return 0;
  }
}

// 出队列的方法
int shiftQueue(Node* queue){
  if(isEmpty(queue)){
    return -1;
  }else{
    Node* node = queue->next;
    queue->data--;
    queue->next = node->next;
    free(node);
    return 0;
  }
}

int main(){
  Node* queue = initQueue();
  tailInsert(queue,1);
  tailInsert(queue,2);
  tailInsert(queue,3);
  tailInsert(queue,4);
  shiftQueue(queue);
  printQueue(queue);
  system("pause");
  return 0;
}