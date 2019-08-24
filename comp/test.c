#include<stdio.h>

typedef long long ll;

int min(int x,int y){
    return (x>y)?(y):(x);
}

int main(){
  int n;
  ll k;
  scanf("%d%lld",&n,&k);
  ll a[n+1][n+1];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      scanf("%lld",&a[i][j]);
    }
  }
  int left,right,order=3000;
  ll a1[n+1];
  for(left=1;left<=n;left++){
    for(int i=1;i<=n;i++) a1[i]=0;
    for(right=left;right<=n;right++){
      for(int i=1;i<=n;i++) a1[i]+=a[i][right];
      ll cum[n+1];
      cum[1]=a1[1];
      for(int i=2;i<=n;i++) cum[i]=a1[i]+cum[i-1];
      for(int i=1;i<=(n-(right-left));i++){
        if(cum[i]-cum[i-right+left-1]>=k)
          order=min(order,right-left+1);
      }
    }
  }
  if(order>2000) printf("-1\n");
  else printf("%d\n",order);
}
