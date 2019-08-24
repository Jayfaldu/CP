#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

bool check(int m,int l,int r,int k,int x){
  if(x>k){
    x=max(k,x-m);
  }
  else x=min(x+m,k);
  if(x>=l && x<=r) return 1;
  else return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  int test;
  scanf("%d",&test);
  while(test--){
    int n,m,k,l,r;
    scanf("%d%d%d%d%d",&n,&m,&k,&l,&r);
    pair<int,int> a[n];
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].s,&a[i].f);
    sort(a,a+n);
    int flag=0;
    for(int i=0;i<n;i++){
      if(check(m,l,r,k,a[i].s)){
        printf("%d\n",a[i].f);
        flag=1;
        break;
      }
    }
    if(flag==0) printf("-1\n");
  }
}
