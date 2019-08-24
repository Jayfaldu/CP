#include<bits/stdc++.h>

using namespace std;
long long dp[5003][5003];
const long long mod=1e9+7;

int main(){
  int n,ident;
  scanf("%d",&n);
  getchar();
  char a[n];
  for(int i=0;i<n;i++){
    scanf("%c",&a[i]);
    getchar();
  }
  dp[0][0]=1;
  ident=0;
  for(int i=1;i<=n;i++){
    if(a[i-1]=='f'){
      for(int j=0;j<=ident;j++) dp[i][j+1]=dp[i-1][j];
      ident++;
    }
    else{
      dp[i][ident]=dp[i-1][ident];
      for(int j=ident-1;j>=0;j--) dp[i][j]=(dp[i][j+1]+dp[i-1][j])%mod;
    }
  }
  long long ans=0;
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<=ident;j++){
  //     printf("%lld  ",dp[i][j]);
  //   }
  //   printf("\n");
  // }
  for(int i=0;i<=ident;i++) ans+=dp[n-1][i];ans%=mod;
  printf("%lld\n",ans);
}
