#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int array[], int length){
  for (int i = 0; i < length - 1; i++)
  {
    for (int j = 0; j < length-1-i; j++)
    {
      if(array[j]>array[j+1]){
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

void insertSort(int array[], int length){
  for (int i = 1; i < length; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if(array[i]<array[j]){
        int temp = array[i];
        for (int k = i - 1; k >= j; k--)
        {
          array[k+1]=array[k];
        }
        array[j] = temp;
      }
    }
  }
}

int partition(int array[], int i, int j){
  int x = array[i];
  while (i<j)
  {
    while(i<j && array[j]>=x){
      j--;
    }
    if(i<j){
      array[i] = array[j];
      i++;
    }
    while (i<j && array[i]<x)
    {
      i++;
    }
    if(i<j){
      array[j] = array[i];
      j--;
    }
  }
  array[i] = x;
  return i;
}

void quickSort(int array[], int i, int j){
  if(i<j){
    int index = partition(array,i,j);
    quickSort(array,i,index-1);
    quickSort(array,index+1,j);
  }
}

void selectSort(int array[], int length){
  for (int i = 0; i < length; i++)
  {
    int k = i;
    for (int j = i+1; j < length; j++)
    {
      if (array[j]<array[k])
      {
        k=j;
      }
      int temp = array[i];
      array[i] = array[k];
      array[k] = temp;
    }
  }
}

void merge(int* array, int* temp, int arr1left, int arr2left, int arr2right){
  int p1 = arr1left,p2 = arr2left,p3 = p1,arr1right = p2 - 1;
  while (p1<=arr1right && p2<=arr2right)
  {
    if(array[p1]<array[p2]){
      temp[p3++] = array[p1++];
    }else{
      temp[p3++] = array[p2++];
    }
  }
  while (p1<=arr1right)
  {
    temp[p3++] = array[p1++];
  }
  while (p2<=arr2right)
  {
    temp[p3++] = array[p2++];
  }
  for (int i = arr1left; i <= arr2right; i++)
  {
    array[i] = temp[i];
  }
}

void mergeDivide(int* array, int* temp, int left, int right){
  if(left<right){
    int mid = (left+right) / 2;
    mergeDivide(array,temp,left,mid);
    mergeDivide(array,temp,mid+1,right);
    merge(array,temp,left,mid+1,right);
  }
}

void mergeSort(int* array, int length){
  int* temp = (int*)malloc(sizeof(int) * length);
  mergeDivide(array,temp,0,length-1);
  free(temp);
}

void printArray(int array[], int length){
  for (int i = 0; i < length; i++)
  {
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  int array[5] = {5,2,6,9,7};
  printArray(array,5);
  bubbleSort(array,5);
  printArray(array,5);
  insertSort(array,5);
  printArray(array,5);
  quickSort(array,0,4);
  printArray(array,5);
  selectSort(array,5);
  printArray(array,5);
  mergeSort(array,5);
  printArray(array,5);
  system("pause");
  return 0;

}