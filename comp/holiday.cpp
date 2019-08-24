#include<bits/stdc++.h>
#define ll long long;
#define syn ios_base::sync_with_stdio(false)
#define vi vector<int>
#define pii pair<int,int>
#define vl vector<ll>
#define vpi vector<pii>

using namespace std;
int a[101];

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    for(int j=l;j<=r;j++) a[j]++;
  }
  for(int i=1;i<=n;i++){
    if(a[i]!=1){
      printf("%d %d\n",i,a[i]);
      return 0;
    }
  }
  printf("OK\n");
}
