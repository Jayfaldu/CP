#include<stdio.h>
int merge(int arr[],int start, int mid,int end){
  int count=0;
  int tmp[end-start+1];
  int l=start,m=end,n=mid+1;
  int k=0;
  for(int i=start;i<=end;i++){
    if(l>mid){
      tmp[k++]=arr[n++];
    }
    else if(n>end){
      tmp[k++]=arr[l++];
    }
    else if(arr[l]<arr[n]){
      tmp[k++]=arr[l++];
    }
    else{
      tmp[k++]=arr[n++];
      count++;
    }
  }

  for(int i=0;i<k;i++){
    arr[start++]=tmp[i];
  }
  return count;
}

int merge_sort(int arr[], int start,int end){
  int r1,r2,r3;
  if(start<end){
    int mid=(start+end)/2;
    r1=merge_sort(arr,start,mid);
    r2=merge_sort(arr,mid+1,end);
    r3=merge(arr,start,mid,end);
  }
  return r1+r2+r3;
}

int main(){
  int n;
  printf("Enter the number of numbers:\n");
  scanf("%d",&n);
  int arr[n];
  printf("enter the elements in the array:\n");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
printf("\n%d\n",merge_sort(arr,0,n));
  for(int i=0;i<n;i++){
    printf("%d   ",arr[i]);
  }

}
