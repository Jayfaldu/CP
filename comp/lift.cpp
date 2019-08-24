#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll dp[5005][5005],sum[5005];

int main(){
  int n,a,b,k;
  scanf("%d%d%d%d",&n,&a,&b,&k);
  for(int i=1;i<=n;i++) dp[0][i]=1;
  for(int j=1;j<=k;j++){
    for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+dp[j-1][i])%mod;
    for(int i=1;i<=n;i++){
      dp[j][i]=(sum[min(n,i+abs(b-i)-1)]-sum[max(1,i-abs(b-i)+1)-1]-dp[j-1][i]+mod)%mod;
      if(dp[j][i]<0) dp[j][i]+=mod;
    }
  }
  printf("%lld\n",dp[k][a]);
}
