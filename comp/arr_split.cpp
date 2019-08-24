#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  int diff[n];
  cin>>a[0];
  for(int i=1;i<n;i++){
    cin>>a[i];
    diff[i]=a[i]-a[i-1];
  }
  sort(diff+1,diff+n);
  ll ans=a[n-1]-a[0];
  for(int i=0;i<k-1;i++){
    ans=ans-diff[n-1-i];
  }
  cout<<ans<<endl;
}
