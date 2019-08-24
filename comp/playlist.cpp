#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

pair<ll,ll> det[3*100006];

int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++)
    scanf("%lld%lld",&det[i].second,&det[i].first);
  sort(det,det+n);
  ll ans=0;
  ll sum=0;
  set<pair<ll,ll>> a;
  for(int i=n-1;i>=0;i--){
    a.insert(make_pair(det[i].second,i));
    sum+=det[i].second;
    while(a.size()>k){
      auto it=a.begin();
      sum-=(it->first);
      a.erase(it);
    }
    ans=max(ans,sum*(det[i].first));
  }
  printf("%lld\n",ans);
}
