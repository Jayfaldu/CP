#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
  ll n,m;
  cin>>n;
  ll a[n];
  ll mx_a=0,mx_b=0;
  for(ll i=0;i<n;i++){
    cin>>a[i];
    mx_a=max(a[i],mx_a);
  }
  cin>>m;
  ll b[m];
  for(ll i=0;i<m;i++){
    cin>>b[i];
    mx_b=max(b[i],mx_b);
  }
  cout<<mx_a<<" "<<mx_b<<"\n";
}
