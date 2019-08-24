#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
  ll n,k;
  cin>>n>>k;
  for(int i=n;i>=1;i--){
    if((i*(i+1)/2)-(n-i)==k){
      cout<<n-i<<endl;
      return 0;
    }
  }
}
