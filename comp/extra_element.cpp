#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d;
int n;
vector<pair<ll,int>> a;

void check(int k){
  int m=0;
  ll b[n];
  for(int i=0;i<n;i++){
    if(i!=k) b[m++]=a[i].first;
  }
  for(int i=1;i<m;i++){
    if(b[i]-b[i-1]!=b[1]-b[0]) return;
  }
  cout<<a[k].second<<endl;
  exit(0);
}



int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    ll x;
    cin>>x;
    a.push_back(make_pair(x,i));
  }
  sort(a.begin(),a.end());
  d=a[1].first-a[0].first;
  for(int i=2;i<n;i++){
    if(a[i].first-a[i-1].first!=d){
      check(i);
      break;
    }
  }
  check(1);
  check(0);
  cout<<"-1"<<endl;
}
