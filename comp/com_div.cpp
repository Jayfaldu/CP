#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;

ll find_divisor(ll x){
  // printf("%lld\n",x);
  ll cnt=0;
  for(int i=1;i<=sqrt(x);i++){
    if(x%i==0){
      if(x/i==i) cnt++;
      else cnt+=2;
    }
  }
  printf("%lld\n",cnt);
}

int main(){
  syn;
  int n;
  scanf("%d",&n);
  set<ll> a;
  for(int i=0;i<n;i++){
    ll tmp;
    scanf("%lld",&tmp);
    a.insert(tmp);
  }
  auto it=a.begin();
  ll x=*it;
  // printf("%lld ",x);
  for(;it!=a.end();it++){
    x=__gcd(x,*it);
    // printf("%lld ",x);
  }
  // printf("\n");
  find_divisor(x);
}
