#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll cum_sum[2002][2002];

int main(){
  int n;
  ll z;
  cin>>n>>z;
  ll a[n+1][n+1];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>a[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cum_sum[i][j]=cum_sum[i][j-1]+cum_sum[i-1][j]-cum_sum[i-1][j-1]+a[i][j];
    }
  }
  int flag=0;
  int order=3000;
  for(int i=1;i<=n;i++){
    for(int k=i;k<=n;k++){
      for(int j=i;j<=n;j++){
        if(cum_sum[k][j]-cum_sum[k][j-i]-cum_sum[k-i][j]+cum_sum[k-i][j-i]>=z){
          order=min(order,i);
          flag=1;
        }
      }
      if(flag==1) break;
    }
    if(flag==1) break;
  }
  if(order>2000) cout<<"-1"<<endl;
  else cout<<order<<endl;
}
