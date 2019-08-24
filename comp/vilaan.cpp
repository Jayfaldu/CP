#include<stdio.h>
#include<algorithm>

struct s{
  int first;
  int second;
  int sum;
}

using namespace std;
int main(){
  int test;
  cin>>test;
  while(test--){
    int n;
    int max=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
      if(a[i]>max){
        max=a[i];
      }
    }
    s b;
    b.sum=a[0]+a[2];
    (a[0]>a[2])?(b.first=a[0],b.second=a[2]):(b.first=a[2],b.second=a[0]);
    for(int i=1;i<n-1;i++){
      if(a[i]+a[i+2]>b.sum){
        b.sum=a[i]+a[i+2];
        (a[i]>a[i+2])?(b.first=a[i],b.second=a[i+2]):(b.first=a[i+2],b.second=a[i]);
      }
      else if(b.sum==a[i]+a[i+2]){
        if()
      }
    }
  }
}
