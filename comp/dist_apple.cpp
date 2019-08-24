#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    ll n,k;
    scanf("%lld%lld",&n,&k);
    n/=k;
    if(n%k==0){
      printf("NO\n");
    }
    else{
      printf("YES\n");
    }
  }
}
