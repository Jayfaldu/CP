#include<bits/stdc++.h>
#define MAXN 20
using namespace std;
typedef long long ll;

ll dp[1<<MAXN][MAXN];
ll ben[MAXN][MAXN];
int n,m,k;
ll a[MAXN];

ll solve(int mask,int pre){
  if(__builtin_popcount(mask)==m) return 0;
  if(dp[mask][pre]!=-1) return dp[mask][pre];
  ll ans=-1;
  for(int i=0;i<n;i++){
    if(mask&(1<<i)==0)
      ans=max(ans,solve(mask|(1<<i),i)+ben[pre][i]+a[i]);
  }
  return dp[mask][pre]=ans;
}

int main(){
  memset(dp,-1,sizeof(dp));
  cin>>n>>m>>k;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<endl;
  for(int i=0;i<k;i++){
    int x,y;
    cin>>x>>y;
    cin>>ben[x-1][y-1];
  }
  for(int i=0;i<(1<<n);i++){
    solve(1<<i,i);
  }
  ll ans=-1;
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<n;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) ans=max(ans,dp[1<<i][j]);
  }
  cout<<ans<<endl;
  return 0;
}
