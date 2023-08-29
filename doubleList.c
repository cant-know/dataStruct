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
  list->next = NULL;
  list->pre = NULL;
}

void headInsert(Node* list,int data){
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  if(list->next == NULL){
    // 链表为空
    node->next = list->next;
    node->pre = list;
    list->next = node;
    list->data++;
  }else{
    list->data++;
    node->next = list->next;
    node->pre = list;
    list->next->pre = node;
    list->next = node;
  }
}

void tailInsert(Node* list,int data){
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  list->data++;
  while (list->next)
  {
    list=list->next;
  }
  list->next = node;
  node->next = NULL;
  node->pre = list;
}

int deleteNode(Node* list,int data){
	Node* curNode = list->next;
	while(curNode){
		if(curNode->data == data){
      //删除节点 
      if(curNode->next != NULL){
        curNode->pre->next = curNode->next; 
        curNode->next->pre = curNode->pre;
        free(curNode);
        list->data--;
      }else{
        curNode->pre->next = NULL; 
        free(curNode);
        list->data--;
      }
			return TRUE;	
		}
		curNode = curNode->next; 
	}
	return FALSE; 
}

void printList(Node*list){
  list=list->next;
  while (list)
  {
    printf("%d ",list->data);
    list=list->next;
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
  deleteList(list, 200);
  tailInsert(list, 300);
  headInsert(list, 5);
  deleteList(list, 300);
	printList(list);
  system("pause");
  return 0;
}
