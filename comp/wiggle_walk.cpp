#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

map<int,ll> mp;
vector<ll> arr;

ll get_count(int s){
  ll cnt=0;
  for(auto elem : mp){
    if(elem.second<=s) cnt+=elem.second;
  }
  return cnt;
}

int main(){
  int test;
  scanf("%d",&test);
  for(int i=1;i<=test;i++){
    int n,s;
    ll ans=0;
    scanf("%d%d",&n,&s);
    arr.clear();
    arr.resize(n);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    for(int i=0;i<n;i++){
      mp.clear();
      for(int j=i;j<n;j++){
        mp[arr[j]]+=1;
        ans=max(ans,get_count(s));
      }
    }
    printf("Case #%d: %lld\n",i,ans);
  }
  return 0;
}
