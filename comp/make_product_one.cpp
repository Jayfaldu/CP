#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n;
  ll n_one=0,n_zero=0;
  ll cnt=0;
  cin>>n;
  for(int i=0;i<n;i++){
    ll tmp;
    cin>>tmp;
    if(tmp<0){
      n_one++;
      cnt+=(-1-tmp);
    }
    if(tmp>0){
      cnt+=(tmp-1);
    }
    if(tmp==0) n_zero++;
  }
  // cout<<cnt<<" "<<n_one<<" "<<n_zero<<"\n";
  if(n_one%2==0){
    cout<<cnt+n_zero<<"\n";
  }
  else{
    if(n_zero==0){
      cout<<cnt+2<<"\n";
    }
    else{
      cout<<cnt+n_zero<<"\n";
    }
  }
}
