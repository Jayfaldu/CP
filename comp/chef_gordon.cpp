//star graph only
#include<bits/stdc++.h>
using namespace std;
#define s second
#define f first
#define syn ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
  syn;
  ll test;
  scanf("%lld",&test);
  while(test--){
    ll n;
    scanf("%lld",&n);
    int a[3];
    for(ll i=0;i<3;i++) scanf("%d",&a[i]);
    pair<ll,ll> max_deg={0,0};
    ll deg[n+1];
    memset(deg,0,sizeof(deg));
    for(ll i=0;i<n-1;i++){
      ll l,m;
      scanf("%lld%lld",&l,&m);
      deg[l]++;
      deg[m]++;
      if(max_deg.f<deg[l]){
        max_deg.f=deg[l];
        max_deg.s=l;
      }
      if(max_deg.f<deg[m]){
        max_deg.f=deg[m];
        max_deg.s=m;
      }
    }
    if(a[1]==1) printf("%lld\n",(n-max_deg.s)*(n-max_deg.s-1)/2);
    if(a[1]==2) printf("%lld\n",(max_deg.s-1)*(n-max_deg.s));
    if(a[1]==3) printf("%lld\n",(max_deg.s-1)*(max_deg.s-2)/2);
  }
}
