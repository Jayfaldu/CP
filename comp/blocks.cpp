#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)

using namespace std;
typedef long long ll;

int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    ll a[n];
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    int flag=0;
    for(int i=0;i<n-1;i++){
      ll tmp=a[i+1]-a[i];
      if(tmp>0){
        if(tmp<=k){
          if(k-tmp<=a[i]) m+=(k-tmp);
          else m+=a[i];
        }
        else if(tmp>k){
          if(tmp-k>m){
            printf("NO\n");
            flag=1;
            break;
          }
          else m-=(tmp-k);
        }
      }
      else if(tmp<=0){
        if(k-tmp<=a[i]) m+=(k-tmp);
        else m+=a[i];
      }
    }
    if(flag==0) printf("YES\n");
  }

}
