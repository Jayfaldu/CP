#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[101];

int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    ll b;
    cin>>b;
    ll ans=0;
    ll req=m-b;
    for(int j=1;j<=100;j++){
      ll z=min(req/j,a[j]);
      ans+=z;
      req-=z*j;
    }
    a[b]++;
    cout<<i-ans<<" ";
  }
  cout<<endl;
}
