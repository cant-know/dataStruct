#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
}Node;

Node* initList(){
  Node* list = (Node*)malloc(sizeof(Node));
  list->data = 0;
  list->next = list;
  return list;
}

void headInsert(Node* list,int data){
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = list->next;
  list->next = node;
  list->data++;
}

void tailInsert(Node* list,int data){
  list->data++;
  Node* n = list;
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  while (n->next != list)
  {
    n = n->next;
  }
  node->next = list;
  n->next = node;
}

void deleteInsert(Node* list,int data){
  Node* pre = list;
  Node* cur = list->next;
  while (cur)
  {
    if(cur->data == data){
      pre->next = cur->next;
      free(cur);
      break;
    }
    pre->next = cur;
    cur = cur->next;
  }
  list->data--;
}

void printList(Node* list){
  Node* node = list->next;
  while (node != list)
  {
    printf("%d",node->data);
    node = node->next;
  }
  printf("NULL");
}

int main(){
  system("pause");
  return 0;
}