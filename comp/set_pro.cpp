#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cout.precision(11);
  cin>>n;
  double a[n];
  double ans=0,pro;
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  ans=a[n-1];
  pro=1-a[n-1];
  for(int i=n-2;i>=0;i--){
      ans=max(ans,ans*(1-a[i])+a[i]*pro);
      pro*=(1-a[i]);
  }
  cout<<ans<<endl;
}
