#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
void heapify_down (int arr[],int i,int N)
{
    int left=2*i;
    int right=2*i+1;
    int smallest=i;
    if(left<=N && arr[left]<arr[smallest]){
      smallest = left;
    }
    if(right<=N && arr[right]<arr[smallest]){
      smallest = right;
    }
    if(smallest != i){
      printf("swapping %d and %d\n",i,smallest);
      int tmp=arr[smallest];
      arr[smallest]=arr[i];
      arr[i]=tmp;
      heapify_down(arr,smallest,N);
    }
}

void build_heap(int arr[],int N){
  for(int i=N/2;i>=1;i--){
    heapify_down(arr,i,N);
  }
}

void update_heap(int arr[],int i){
  int parent=i/2;
  if(arr[parent]>arr[i]){
    int tmp=arr[parent];
    arr[parent]=arr[i];
    arr[i]=tmp;
    update_heap(arr,parent);
  }
}

// void heap_sort(int arr[],int N){
//   int heap_size=N;
//   build_heap(arr,heap_size);
//   for(int i=heap_size;i>=2;i--){
//     int tmp=arr[1];
//     arr[1]=arr[i];
//     arr[i]=tmp;
//     heap_size=heap_size-1;
//     heapify_down(arr,1,heap_size);
//   }
// }

int extract_min(int arr[],int N){
  if(N==0){
    printf("Element cannot be removed");
  }
  int min=arr[1];
  arr[1]=arr[N];
  N=N-1;
  heapify_down(arr,1,N);
  return min;
}

void increase_value (int arr[],int i,int val,int n){
  if(val > arr[i]){
    arr[i]=val;
    heapify_down(arr,i,n);
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
  increase_value(arr,2,30,n);
  for(int i=1;i<=n;i++){
    printf("%d   ",arr[i]);
   }

}
