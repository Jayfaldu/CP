#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9 + 7;

long long mod_exp(ll x,ll m,ll n){
  if(m==0) return 1;
  else if(m%2)  return (x*mod_exp((x*x)%n,(m-1)/2,n))%n;
  else return mod_exp((x*x)%n,m/2,n);
}

int main(){
  string s;
  cin>>s;
  ll ans=0,cnt=0;
  for(ll i=0;i<s.size();i++){
    if(s[i]=='b'){
      if(cnt){
        ans+=((mod_exp(2,cnt,mod)-1)%mod);
      }
    }
    else{
      while(s[i]=='a'){
        cnt++,i++;
      }
      i--;
    }
  }
  cout<<(ans%mod)<<endl;
}
