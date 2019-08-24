#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=998244353;

ll fast_mod(ll x,ll n){
  if(n==0) return 1;
  if(n%2==0) return fast_mod((x*x)%mod,n/2);
  else return (x*fast_mod((x*x)%mod,(n-1)/2))%mod;
}


int main(){
  ll w,h;
  cin>>w>>h;
  cout<<fast_mod(2,w+h)<<endl;
}
