#include<bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef pair<ll,int> lp;
typedef pair<ll,ll> llp;

int main(){
  int n;
  scanf("%d",&n);
  vector<lp> stones;
  for(int i=1;i<=n;i++){
    ll tmp;
    scanf("%lld",&tmp);
    stones.pb(mk(tmp,i));
  }
  ll index[n];
  vector<tuple<int,int,ll>> ans;
  for(int i=0;i<n;i++) scanf("%lld",&index[i]);
  sort(index,index+n);
  sort(stones.begin(),stones.end());
  ll sum=0;
  vector<pair<int,ll>> left;
  vector<pair<int,ll>> right;
  for(int i=0;i<n;i++){
    ll tmp=index[i]-stones[i].first;
    if(tmp>0){
      right.push_back(mk(stones[i].second,tmp));
    }
    else left.push_back(mk(stones[i].second,(-1)*tmp));
    sum+=tmp;
    if(sum<0){
      printf("NO\n");
      return 0;
    }
  }
  if(sum!=0){
    printf("NO\n");
    return 0;
    }
  int x=left.size()-1,y=right.size()-1;
  while(x>=0 && y>=0){
    if(left[x].second>right[y].second){
      ans.pb(mt(left[x].first,right[y].first,right[y].second));
      left[x].second-=right[y].second;
      right[y].second=0;
      y--;
    }
    else if(left[x].second<right[y].second){
      ans.pb(mt(left[x].first,right[y].first,left[x].second));
      right[y].second-=left[x].second;
      left[x].second=0;
      x--;
    }
    else{
      ans.pb(mt(left[x].first,right[y].first,left[x].second));
      left[x].second=0;
      right[y].second=0;
      x--;
      y--;
    }
  }
  printf("YES\n%lu\n",ans.size());
  for(int i=0;i<ans.size();i++){
    printf("%d %d %lld\n",get<1>(ans[i]),get<0>(ans[i]),get<2>(ans[i]));
  }
}
