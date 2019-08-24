#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll dp[2*100009][10];
vector<ll> cost[2*100009];

ll cal(int i,int no,int on){
  if(no==1){
    return (max(max(cost[i][2],cost[i][3]),cost[i][4]))*on;
  }
  if(no==2){
    ll ans;
    if(cost[i][3]==0 && cost[i][2]==0) return -1;
    if(cost[i][3]==0 && (cost[i][2]>0 && cost[i][1]>0)) return (cost[i][2]*on+cost[i][1]);
    if(cost[i][3]>0 && cost[i][2]==0) return -1;
    ans=max(cost[i][2],cost[i][3])*on+min(cost[i][2],cost[i][3]);
    return max(ans,cost[i][2]*on+cost[i][1]);
  }
  if(no==3){
    if(cost[i][2] && cost[i][1] && cost[i][0])
      return (cost[i][2]*on+cost[i][1]+cost[i][0]);
    return -1;
  }
}

ll fin(int x){
  if(x<0) return 10+x;
  return x;
}


int main(){
  memset(dp,-1,sizeof(dp));
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    int k;
    cin>>k;
    vector<ll> bx;
    ll min2=0,min3=0;
    while(k--){
      int c,dam;
      cin>>c>>dam;
      if(c==1){
        if(bx.size()==3){
          sort(bx.begin(),bx.end());
          if(dam>bx[0]){
            bx.pb(dam);
            bx.erase(bx.begin());
          }
        }
        else bx.pb(dam);
      }
      if(c==2) if(dam>min2) min2=dam;
      if(c==3) if(dam>min3) min3=dam;
    }
    if(bx.size()<3){
      while(bx.size()<3) bx.push_back(0);
    }
    sort(bx.begin(),bx.end());
    cost[i].pb(bx[0]);
    cost[i].pb(bx[1]);
    cost[i].pb(bx[2]);
    cost[i].pb(min2);
    cost[i].pb(min3);
  }
  for(int i=1;i<=n;i++) dp[i][0]=0;
  // for(int i=1;i<=n;i++){
  //   printf("%lld %lld %lld %lld %lld\n",cost[i][0],cost[i][1],cost[i][2],cost[i][3],cost[i][4]);
  // }
  dp[1][1]=cal(1,1,1);
  dp[1][2]=cal(1,2,1);
  dp[1][3]=cal(1,3,1);
  // printf("%lld %lld %lld\n",dp[1][1],dp[1][2],dp[1][3]);
  for(int i=2;i<=n;i++){
    for(int j=0;j<=9;j++){
      ll mx=dp[i-1][j];
      if(dp[i-1][fin(j-1)%10]!=-1){
        ll tmp=cal(i,1,(j==0)?(2):(1));
        mx=max(mx,dp[i-1][fin(j-1)%10]+tmp);
       }
      if(dp[i-1][fin(j-2)%10]!=-1){
        ll tmp=cal(i,2,(j==0||j==1)?(2):(1));
        if(tmp>0)
        mx=max(mx,dp[i-1][fin(j-2)%10]+tmp);
      }
      if(dp[i-1][fin(j-3)%10]!=-1){
        ll tmp=cal(i,3,(j>=0 && j<=2)?(2):(1));
        if(tmp>0)
        mx=max(mx,dp[i-1][fin(j-3)%10]+tmp);
      }
      dp[i][j]=mx;
    }
  }
  // for(int i=1;i<=5;i++){
  //   for(int j=0;j<=9;j++){
  //     printf("%lld ",dp[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("%lld %lld\n\n",dp[4][9],cal(5,1,2));
  ll abx=dp[n][0];
  for(int i=1;i<=9;i++){
    abx=max(dp[n][i],abx);
  }
  cout<<abx<<endl;
}
