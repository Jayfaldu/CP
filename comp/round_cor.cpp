#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)
#define s second
#define f first
using namespace std;
typedef long long ll;

int main(){
  ll n,m,q;
  scanf("%lld%lld%lld",&n,&m,&q);
  ll x=__gcd(n,m);
  ll in_gap=n/x;
  ll out_gap=m/x;
  // printf("%lld %lld",in_gap,out_gap);
  while(q--){
    if(n==1 || m==1){
      int tmp;
      cin>>tmp>>tmp>>tmp>>tmp;
      printf("YES\n");
      continue;
    }
    pair<double,double> a[2];
    scanf("%lf%lf%lf%lf",&a[0].s,&a[0].f,&a[1].s,&a[1].f);
    if(a[0].s==a[1].s){
      if(a[0].s==1){
        // printf("%lf %lf  ",a[1].f,a[0].f);
        if(ceil(a[1].f/in_gap)!=ceil(a[0].f/in_gap)){
          printf("NO\n");
        }
        else printf("YES\n");
      }
      else{
        // printf("%lf %lf  ",a[1].f,a[0].f);
        if(ceil(a[1].f/out_gap)!=ceil(a[0].f/out_gap)){
          printf("NO\n");
        }
        else printf("YES\n");
      }
    }
    else{
      if(a[0].s==1){
        // printf("%lf %lf  ",a[1].f,a[0].f);
        if(ceil(a[1].f/out_gap)!=ceil(a[0].f/in_gap)){
          printf("NO\n");
        }
        else printf("YES\n");
      }
      else{
        // printf("%lf %lf  ",a[1].f,a[0].f);
        if(ceil(a[1].f/in_gap)!=ceil(a[0].f/out_gap)){
          printf("NO\n");
        }
        else printf("YES\n");
      }
    }
  }
}
