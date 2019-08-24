#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=7+1e9;


ll fast_mod(ll x,ll n, ll p){
  if(n==0){
    return 1;
  }
  else if(n%2==0){
    return fast_mod((x*x)%p,n/2,p);
  }
  else{
    return (x*fast_mod((x*x)%p,(n-1)/2,p))%p;
  }
}



int main(){
  ll n,c;
  scanf("%lld",&n);
  ll f[n+1];
  ll x[n+1];
  scanf("%lld%lld%lld%lld",&f[1],&f[2],&f[3],&c);
  // printf("%lld\n",x[4]);
  x[3]=1;
  for(int i=4;i<=n;i++){
    x[i]=(((x[i-1]*c)%mod)*c)%mod;
    f[i]=(((x[i]*f[i-1])%mod)*((f[i-2]*f[i-3])%mod))%mod;
    // printf("%lld\n",f[i]);
  }
  printf("%lld\n",f[n]);
}
