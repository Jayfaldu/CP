#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,x,y;
  cin>>n>>x>>y;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++){
    int flag=0;
    int tmp=i-1,j=x;
    while(j>0 && tmp>=0){
      if(a[i]>a[tmp]){
        flag=1;
        break;
      }
      j--;
      tmp--;
    }
    j=y;
    tmp=i+1;
    while(j>0 && tmp<=n-1){
      if(a[i]>a[tmp]){
        flag=1;
        break;
      }
      j--;
      tmp++;
    }
    if(flag==0){
      cout<<i+1<<endl;
      return 0;
    }
  }
}
