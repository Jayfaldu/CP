#include<bits/stdc++.h>

using namespace std;

int const oo=1e9+7;

int main(){
  int n,l,r,x,a[20],sum,mx,mn,cnt=0;
  cin>>n>>l>>r>>x;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<(1<<n);i++){
    sum=0;
    mx=0;
    mn=oo;
    for(int j=0;j<n;j++){
      if(i & (1<<j)){
        sum+=a[j];
        mx=max(mx,a[j]);
        mn=min(mn,a[j]);
      }
    }
    // cout<<sum<<" "<<mx<<" "<<mn<<" "<<endl;
    if(sum>=l && sum<=r && mx-mn>=x){
    // cout<<sum<<" "<<mx<<" "<<mn<<" ";
    cnt++;}
  }
  cout<<cnt<<endl;
}
