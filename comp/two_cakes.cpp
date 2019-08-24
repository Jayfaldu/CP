#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int mod(int x,int y){
  if(x-y>0) return x-y;
  else return (y-x);
}

int main(){
  int n;
  vector<int> :: iterator it;
  scanf("%d",&n);
  vector<vector<int>> a(n+1);
  //for(int i=0;i<=n;i++) a[i]=vector<int>(2);
  // printf("hii");
  for(int i=1;i<=2*n;i++){
    int tmp;
    scanf("%d",&tmp);
    //printf("  %d  ",tmp);
    a[tmp].push_back(i-1);
    printf("%d  ",a[tmp][1]);
  }
  printf("\n%d\n",a[1][0]);
  printf("\n");
  ll ans=0;
  int tmp1=a[1][0];
  int tmp2=0;
  it=a[1].begin();
  a[1].erase(it);
  printf("%d\n",a[1][0]);
  for(int i=2;i<=n;i++){
    ans+=mod(tmp1-tmp2);
    printf("%lld  ",ans);
    tmp2=tmp1;
    if(mod(a[i][0]-tmp2)>mod(a[i][1]-tmp2)){
      tmp1=a[i][1];
      it=a[i].end();
      a[i].erase(it);
    }
    else if(mod(a[i][0]-tmp2)<mod(a[i][1]-tmp2)){
      tmp1=a[i][0];
      it=a[i].begin();
      a[i].erase(it);
    }
    else{
      if(mod(a[i-1][0]-a[i][0])>mod(a[i-1][0]-a[i][1])){
        tmp1=a[i][0];
        it=a[i].begin();
        a[i].erase(it);
      }
      else{
        tmp1=a[i][1];
        it=a[i].end();
        a[i].erase(it);
      }
    }
  }
  ans+=mod(tmp1-tmp2);
  //printf("\n");
  //printf("%d  ",ans);
  ans+=a[1][0];
  for(int i=2;i<=n;i++) ans+=mod(a[i][0]-a[i-1][0]);
  printf("%lld\n",ans);
}
