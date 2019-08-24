#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n,I;
  cin>>n>>I;
  int a[n];
  map<int,int> mp;
  for(int i=0;i<n;i++){
    cin>>a[i];
    mp[a[i]]++;
  }

  I=8*I/n;
  ll count=0;
  int dis=mp.size();
  if(I>=ceil(log2(double(dis)))){
    cout<<count<<endl;
    return 0;
  }
  ll max=pow(2,I);
  int del=dis-max;
  int cum[dis+2];
  cum[0]=0;
  int z=1;
  for(auto j=mp.begin();j!=mp.end();j++){
    cum[z]=cum[z-1]+j->second;
    z++;
  }
  int ans=min(cum[del],cum[dis]-cum[dis-del]);
  for(int i=1;i<del;i++){
    ans=min(cum[i]+cum[dis]-cum[dis-del+i],ans);
  }
  cout<<ans<<endl;
}
