#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int binary search(long double weight[],long double expected,int n){
  int start=0;
  int end=n;
  int mid=(start+end)/2;
  while(start>=end || expected == weight[mid]){
    if(expected>weight[mid]){
      start=mid+1;
      mid=(start+end)/2;
    }
    else{
      end=mid-1;
      mid=(start+end)/2;
    }
  }
  if(expected==weight[mid]){
    return mid;
  }
  else{
    return (start-1);
  }
}

bool sort_order(int x,int y){
  return (x>y);
}


int main(){
  int l;
  scanf("%d",&l);
  for(int z=0;z<l;z++){
    float n,k;
    scanf("%f%f",&n,&k);
    long double weight[int(n)];
    for(int i=0;i<n;i++){
      scanf("%Lf",&weight[i]);
    }
    long double sum=0;
    long double expected;
    for(int i=0;i<n;i++){
      sum+=weight[i];
    }
    sum=sum/n;
    expected=sum;
    sum=0;
    for(int i=1;i<=k;i++){
      for(int j=0;j<n;j++){
        if(weight[j]>expected){
          sum+=weight[j];
        }
        else{
          sum+=expected;
        }
        if(j==n-1){
          expected=sum/n;
          sum=0;
        }
      }
    }
    printf("case #%d: %Lf\n",z+1,expected);
  }
  return 0;
}
