#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pi;

int main(){
  int n,k;
  scanf("%d%d",&n,&k);
  int a[n][k];
  priority_queue<pi,vector<pi>,greater<pi>> p;
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++) scanf("%d",&a[i][j]);
    p.push(make_pair(a[i][0],i));
  }
  int cnt[n];
  for(int i=0;i<n;i++) cnt[i]=1;
  // printf("\n");
  for(int i=0;i<n*k;i++){
    pi tmp=p.top();
    p.pop();
    printf("%d ",tmp.first);
    int x=tmp.second;
    if(cnt[x]<k){
      // printf("%d %d\n",x,a[x][cnt[x]]);
      p.push(make_pair(a[x][cnt[x]++],x));
    }
  }
}
