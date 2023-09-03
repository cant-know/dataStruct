#include<stdio.h>
#include<stdlib.h>

#define NUM 10

typedef struct HashList{
  int num;
  char* data;
}HashList;

HashList* initList(){
  HashList* list = (HashList*)malloc(sizeof(HashList));
  list->num = 0;
  list->data = (char*)malloc(sizeof(char) * NUM);
  for(int i = 0;i<NUM;i++){
    list->data[i] = 0;
  }
  return list;
}

int hash(int data){
  return data % NUM;
}

void putList(HashList* list, char data){
  int index = hash(data);
  if(list->data[index] != 0) {
    int count = 1;
    while (list->data[index] != 0)
    {
      index = hash(hash(data) + count);
      count++;
    }
  }
  list->data[index] = data;
}

int main(){
  HashList* list = initList();
  putList(list, 'A');
  putList(list, 'F');
  putList(list, 'B');
  putList(list, 'E');
  putList(list, 'D');
  for(int i=0;i<NUM;i++){
    printf("%c",list->data[i]);
  }
  system("pause");
  return 0;
}
