#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
void max_heapify (int arr[],int i,int N)
{
    int left=2*i;
    int right=2*i+1;
    int largest=i;
    if(left<=N && arr[left]>arr[largest]){
      largest = left;
    }
    if(right<=N && arr[right]>arr[largest]){
      largest = right;
    }
    if(largest != i){
      printf("swapping %d and %d\n",i,largest);
      int tmp=arr[largest];
      arr[largest]=arr[i];
      arr[i]=tmp;
      max_heapify(arr,largest,N);
    }
}

void build_heap(int arr[],int N){
  for(int i=N/2;i>=1;i--){
    max_heapify(arr,i,N);
  }
}

void update_heap(int arr[],int i){
  int parent=i/2;
  if(arr[parent]<arr[i]){
    int tmp=arr[parent];
    arr[parent]=arr[i];
    arr[i]=tmp;
    update_heap(arr,parent);
  }
}

void heap_sort(int arr[],int N){
  int heap_size=N;
  build_heap(arr,heap_size);
  for(int i=heap_size;i>=2;i--){
    int tmp=arr[1];
    arr[1]=arr[i];
    arr[i]=tmp;
    heap_size=heap_size-1;
    max_heapify(arr,1,heap_size);
  }
}

int extract_max(int arr[],int N){
  if(N==0){
    printf("Element cannot be removed");
  }
  int max=arr[1];
  arr[1]=arr[N];
  N=N-1;
  max_heapify(arr,1,N);
  return max;
}

void increase_value (int arr[],int i,int val,int n){
  if(val < arr[i]){
    arr[i]=val;
    max_heapify(arr,i,n);
  }
  else{
    arr[i]=val;
    update_heap(arr,i);
  }
}

int main(){
  printf("Enter the number of element in array:\n");
  int n;
  scanf("%d",&n);
  int arr[n+1];
  printf("Enter the array element:\n");
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  // heap_sort(arr,n);
  // for(int i=1;i<=n;i++){
  //   printf("%d   ",arr[i]);
  // }
  // printf("\n");
  // update_heap(arr,n);
  // for(int i=1;i<=n;i++){
  //   printf("%d   ",arr[i]);
  // }
  build_heap(arr,n);
  for(int i=1;i<=n;i++){
    printf("%d   ",arr[i]);
   }
  // int j=extract_max(arr,n);
  // for(int i=1;i<=n;i++){
  //   printf("%d   ",arr[i]);
  //  }
  increase_value(arr,2,0,n);
  for(int i=1;i<=n;i++){
    printf("%d   ",arr[i]);
   }

}
