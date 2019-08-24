#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;

int main(){
  syn;
  int test;
  scanf("%d",&test);
  while(test--){
    ll xf;
    scanf("%lld",&xf);
    ll x=0;
    ll y=0;
    ll moves=0;
    xf=xf*xf;
    while(xf>y){
      x=sqrt(y)+1;
      y+=(x*x);
      moves++;
    }
    printf("%lld\n",moves);
  }
}
