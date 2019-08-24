#include<bits/stdc++.h>

typedef long long ll;
const ll mod=1e9+7;
using namespace std;
vector<ll> ans;
vector<ll> cum;

int main(){
  int test;
  cin>>test;
  ans.push_back(0);
  ans.push_back(1);
  cum.push_back(0);
  cum.push_back(1);
  for(int j=0;j<test;j++){
    ll N;
    ll prev_N;
    if(j==0){
      cin>>N;
      for(ll i=2;i<=N;i++){
        ans.push_back(((2*cum[N-2])%mod+6)%mod);
        cum.push_back((ans[i]+cum[i-1])%mod);
      }
      cout<<ans[N]<<endl;
      prev_N=N;
    }
    else{
      cin>>N;
      if(N>prev_N){
        for(ll i=prev_N+1;i<=N;i++){
          ans.push_back(((2*cum[N-2])%mod+6)%mod);
          cum.push_back((ans[i]+cum[i-1])%mod);
        }
        cout<<ans[N];
        prev_N=N;
      }
      else{
        cout<<ans[N];
      }
    }
  }
}
