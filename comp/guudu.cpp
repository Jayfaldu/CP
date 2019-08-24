#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct p{
  ll f;
  ll s;
  ll t;
};

long long subarrayXor(ll arr[], ll n)
{
  long long ans = 0;
  ll* cum = new ll[n];
  vector<p> mp;
  p tmp;
  tmp.f=-1;
  tmp.s=0;
  tmp.t=0;
  for(ll i=0;i<=1000002;i++) mp.push_back(tmp);
  cum[0]=arr[0];
  for(ll i=1;i<n;i++) cum[i] = cum[i-1]^arr[i];
  mp[cum[0]].f=0;
  mp[cum[0]].s++;
  mp[cum[0]].t=0;
  for (ll i=1;i<n;i++){
    ll lol=0;
    ll tmp=cum[i];
    if(mp[cum[i]].s>0){
      // cout<<i<<" ";
      lol=(i-mp[cum[i]].f-1)*mp[cum[i]].s;
      if(mp[cum[i]].t>0) lol+=(mp[cum[i]].t+mp[cum[i]].s-1);
      ans+=lol;
      // cout<<lol<<" ";
    }
    if (cum[i]==0) ans+=(i);
    mp[cum[i]].f=i;
    mp[cum[i]].s++;
    mp[cum[i]].t=lol;
    // cout<<ans<<endl;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  ll test;
  cin>>test;
  while(test--){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++) cin>>arr[i];
    cout<<subarrayXor(arr,n)<<"\n";
  }
    return 0;
}
