#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int test;
  cin>>test;
  while(test--){
    ll n;
    cin>>n;
    ll a[n];
    ll b[n],c[n];
    for(int i=0;i<n;i++) cin>>a[i];
    b[0]=c[0]=a[0];
    for(int i=1;i<n;i++){
      b[i]=max(b[i-1],c[i-1])+a[i]*(i+1);
      c[i]=max(b[i-1]+a[i]*(i+1),b[i-1]-a[i-1]*(i)+a[i-1]*(i+1)+a[i]*(i));
    }
    cout<<max(b[n-1],c[n-1])<<endl;
  }
}
