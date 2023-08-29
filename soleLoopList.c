#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* initList() {
	Node* list = (Node*)malloc(sizeof(Node));
	//记录总节点数
	list->data = 0;
	list->next = list;
	return list;
}

void headInsert(Node* list,int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = list->next;
	node->data = data;
	list->next = node;
	list->data++;
}

void tailInsert(Node* list, int data) {
  list->data++;
	Node* n = list;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (n->next != list) {
		n = n->next;
	}
	node->next = list;
	n->next = node;
}

void deleteList(Node* list, int data) {
	Node* pre = list;
	Node* cur = list->next;
	while (cur) {
		if (cur->data == data) {
			pre->next = cur->next;
			free(cur);
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	list->data--;
}

void printList(Node* list) {
	Node* node = list->next;
	while (node != list) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("NULL");
}

int main() {
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