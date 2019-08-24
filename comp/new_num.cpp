#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int a,b,m,n;
  cin>>n>>m>>a>>b;
  ll x,y,z;
  ll g[n*m+1];
  cin>>g[0]>>x>>y>>z;
  y=y%z;
  x=x%z;
  for(int i=1;i<=n*m;i++){
    g[i]=((g[i-1]*x)%z+y)%z;
  }
  ll h[n+1][m+1];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      h[i][j]=g[(i-1)*m+j-1];
    }
  }
  ll ans=0;
  ll height[n+1][m-b+2];
  int k=1;
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=m;j++){
  //     cout<<h[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  deque<ll> mn;
  for(int i=1;i<=n;i++){
    // cout<<h[i][1]<<"hell ";
    int j;
    for(j=1;i<=b;j++){
      while((!mn.empty())&&h[i][j]<=h[i][mn.front()])
        mn.pop_back();
      mn.push_back(j);
    }
    k=1;
    for(;j<=m;j++){
      height[i][k++]=h[i][mn.front()];
      while((!mn.empty())&& mn.front()<=j-b)
        mn.pop_front();
      while((!mn.empty()) && h[i][j]<=h[i][mn.front()])
        mn.pop_back();
      mn.push_back(j);
    }
    height[i][k++]=h[i][mn.front()];
    while(!mn.empty()) mn.pop_back();
  }
  while(!mn.empty()) mn.pop_back();
  for(int j=1;j<k;j++){
    int i;
    for(i=1;i<=a;i++){
      while((!mn.empty())&&height[i][j]<=height[mn.front()][j])
        mn.pop_back();
      mn.push_back(i);
    }
    k=1;
    for(;i<=n;i++){
      ans+=height[mn.front()][j];
      while((!mn.empty())&& mn.front()<=i-a)
        mn.pop_front();
      while((!mn.empty()) && height[i][j]<=h[mn.front()][j])
        mn.pop_back();
      mn.push_back(i);
    }
    ans+=height[mn.front()][j];
    while(!mn.empty()) mn.pop_back();
  }
  cout<<ans<<endl;
}
