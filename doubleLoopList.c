#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
  int data;
  struct Node* pre;
  struct Node* next;
}Node;

Node* initList(){
  Node* list = (Node*)malloc(sizeof(Node));
  list->data = 0;
  list->pre = list;
  list->next = list;
  return list;
}

void headInsert(Node* list,int data){
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  if(list->next == list){
    list->data++;
    node->pre = list;
    node->next = list->next;
    list->next = node;
    list->pre = node;
  }else{
    list->data++;
    node->next = list->next;
    node->pre = list;
    list->next = node;
    list->next->pre = node;
  }
}

void tailInsert(Node* list,int data){
  Node* n = list;
  Node* node = (Node*)malloc(sizeof(Node));
  list->data++;
  node->data = data;
  while(n->next != list){
    n=n->next;
  }
  n->next = node;
  node->next = list;
  node->pre = n;
  list->pre = node;
}

int deleteList(Node* list,int data){
  Node* node = list->next;
  while(node != list){
    if(node->data == data){
      if(node->next == NULL){
        node->pre->next = list;
        free(node);
        list->data--;
        return TRUE;
      }else{
        node->pre->next = node->next;
        node->next->pre = node->pre;
        free(node);
        list->data--;
        return TRUE;
      }
    }
    node=node->next;
  }
  return FALSE;
}

void printList(Node* list){
  Node* node = list->next;
  while (node != list)
  {
    printf("%d ",node->data);
    node=node->next;
  }
  printf("NULL");
}

int main(){
  Node* list = initList();
	headInsert(list, 5);
	headInsert(list, 10);
	headInsert(list, 15);
	headInsert(list, 20);
	headInsert(list, 25);
  tailInsert(list, 100);
  tailInsert(list, 200);
  deleteList(list, 200);
  tailInsert(list, 300);
  headInsert(list, 5);
  deleteList(list, 300);
	printList(list);
  system("pause");
  return 0;
}
