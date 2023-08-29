#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* initStack(){
  Node* stack = (Node*)malloc(sizeof(Node));
  stack->data = 0;
  stack->next = NULL;
  return stack;
}

int isEmpty(Node* stack){
  if(stack->next == NULL){
    return 1;
  }else{
    return 0;
  }
}

int pop(Node* stack){
  if(isEmpty(stack)){
    return -1;
  }else{
    Node* node = stack->next;
    stack->data--;
    stack->next = node->next;
    free(node);
    return stack->data;
  }
}

void push(Node* stack,int data){
  Node* node = (Node*)malloc(sizeof(Node));
  stack->data++;
  node->data = data;
  node->next = stack->next;
  stack->next = node;
}

void printStack(Node* stack){
  Node* node = stack->next;
  while (node)
  {
    printf("%d ",node->data);
    node=node->next;
  }
  printf("NULL");
}

int main(){
  Node* stack = initStack();
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  pop(stack);
  printStack(stack);
  system("pause");
  return 0;
}