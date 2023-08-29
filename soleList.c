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
  list->next = NULL;
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
  Node* node = (Node*)malloc(sizeof(Node));
  Node* head = list;
  node->data = data;
  node->next = NULL;
  while(list->next){
    list=list->next;
  }
  list->next = node;
  head->data++;
}

void deleteList(Node* list,int data){
  Node* pre = list;
  Node* cur = list->next;
  while(cur){
    if(cur->data == data){
      pre->next = cur->next;
      free(cur);
      break;
    }
    pre = cur;
    cur = cur->next;
  }
  list->data--;
}

void printList(Node* list){
  list = list->next;
  while(list){
    printf("%d ",list->data);
    list = list->next;
  }
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
	deleteList(list, 20);
	printList(list);
  system("pause");
  return 0;
}