#include<iostream>
#include<cstring>
#define mod 1e9+7
typedef long long ll;

using namespace std;

ll fun(ll m){
  char a[100009];
  cin>>a;
  ll b=0,s=strlen(a);
  for(int i=0;i<s;i++){
    b=(b*10+a[i]-'0')%m;
  }
  return b;
}

ll mod_exp(ll x,ll m,ll n){
  if(m==0) return 1;
  else if(m%2)  return (x*mod_exp((x*x)%n,(m-1)/2,n))%n;
  else return mod_exp((x*x)%n,m/2,n);
}

int main(){
  int test;
  cin>>test;
  while(test--){
    ll a1,b1;
    a1=fun(mod);
    b1=fun(mod-1);
    cout<<mod_exp(a1,b1,mod)<<endl;
  }
}
