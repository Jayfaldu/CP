#include<bits/stdc++.h>

typedef long long ll;

int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  ll a[n];
  for(int i=0;i<n;i++) scanf("%lld",&a[i]);
  while(q--){
    int l,r;
    scanf("%d%d",&l,&r);
    double no=(r-l+1)/2.0;
    ll ans=0;
    for(int i=0;i<31;i++){
      int cnt=0;
      for(int j=l-1;j<r;j++){
        if(a[j]&(1<<i)) cnt++;
      }
      if(cnt>no);
      else{
       ans|=(1<<i);
     }
    }
  //  printf("\n");
    printf("%lld\n",ans);
  }

}
