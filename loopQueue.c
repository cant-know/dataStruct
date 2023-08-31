#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef struct Node{
  int data[MAXSIZE];
  int front;
  int rear;
}Node;

Node* initQueue(){
  Node* queue = (Node*)malloc(sizeof(Node));
  queue->rear=queue->front = 0;
  return queue;
}

int isEmpty(Node* queue){
  if(queue->rear == queue->front){
    return 1;
  }else{
    return 0;
  }
}
int isFull(Node* queue){
  if((queue->rear + 1) % MAXSIZE == queue->front){
    return 1;
  }else{
  }
}

int pushQueue(Node* queue,int data){
  if(isFull(queue)){
    return 0;
  }else{
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return 1;
  }
}

int shiftQueue(Node* queue){
  if(isEmpty(queue)){
    return 0;
  }else{
    int data = queue->data[queue->front];
    queue->front = (queue->front+1) % MAXSIZE;
    return data;
  }
}

void printQueue(Node* queue){
  int length = (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
  int index = queue->front;
  for(int i = 0;i<length;i++){
    printf("%d ",queue->data[index]);
    index = (index + 1) % MAXSIZE;
  }
  printf("NULL");
}

int main(){
  Node* queue = initQueue();
  pushQueue(queue,1);
  pushQueue(queue,2);
  pushQueue(queue,3);
  pushQueue(queue,4);
  shiftQueue(queue);
  printQueue(queue);
  system("pause");
  return 0;
}