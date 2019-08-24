#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)

using namespace std;
int change[2*100002];

int main(){
  int n;
  scanf("%d",&n);
  pair<int,int> a[n];
  for(int i=0;i<n;i++){
    int tmp;
    scanf("%d",&tmp);
    a[i]={tmp,0};
  }
  int q;
  scanf("%d",&q);

  for(int i=0;i<q;i++){
    int tmp;
    scanf("%d",&tmp);
    if(tmp==1){
      int l,k;
      scanf("%d%d",&l,&k);
      a[l-1]={k,i+1};
    }
    else{
      scanf("%d",&change[i+1]);
    }
  }
  // for(int i=0;i<n;i++) printf("%d ",a[i].first);
  // printf("\n");
  for(int i=q-1;i>=0;i--) change[i]=max(change[i],change[i+1]);
  // for(int i=0;i<q;i++){
  //   printf("%d ",change[i]);
  // }
  // printf("\n");
  for(int i=0;i<n;i++){
    int ind=a[i].second;
    if(a[i].first<change[ind]) a[i].first=change[ind];
    printf("%d ",a[i].first);
  }
  printf("\n");
  return 0;
}
