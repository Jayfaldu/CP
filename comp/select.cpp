#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  ll h1[n+1];
  ll h2[n+1];
  ll dp[n+1][2];
  dp[0][1]=0;
  dp[0][0]=0;
  for(int i=1;i<=n;i++) cin>>h1[i];
  for(int i=1;i<=n;i++) cin>>h2[i];
  for(int i=1;i<=n;i++){
    dp[i][1]=max(dp[i-1][0]+h2[i],dp[i-1][1]);
    dp[i][0]=max(dp[i-1][1]+h1[i],dp[i-1][0]);
    // cout<<dp[i][1]<<" "<<dp[i][0]<<endl;
  }

  cout<<max(dp[n][1],dp[n][0])<<endl;
}
