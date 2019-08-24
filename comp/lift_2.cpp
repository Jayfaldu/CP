#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll dp[5005][5005];

int main(){
  int n,a,b,k;
  scanf("%d%d%d%d",&n,&a,&b,&k);
  dp[0][a]=1;
  for(int i=1;i<=n;i++) dp[0][i]+=dp[0][i-1];
  for(int i=1;i<=k;i++){
    for(int j=1;j<=n;j++){
      if(j<b)dp[i][j]=dp[i-1][(j+b-1)/2]-(dp[i-1][j]-dp[i-1][j-1]);
      if(j>b)dp[i][j]=dp[i-1][n]-dp[i-1][(j+b)/2]-(dp[i-1][j]-dp[i-1][j-1]);
    }
    for(int j=1;j<=n;j++)dp[i][j]+=dp[i][j-1],dp[i][j]%=mod;
  }
  printf("%lld\n",(dp[k][n]+mod)%mod);
}
