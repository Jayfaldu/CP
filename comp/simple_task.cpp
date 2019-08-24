#include<bits/stdc++.h>

using namespace std;
int a[26][400010];
int lazy[26][400010];
char given[100010];
char ans[100010];

void build(int n,int start,int end){
  if(start==end){
    a[given[start]-'a'][n]=1;
    for(int i=0;i<26;i++) lazy[i][n]=-1;
    return;
  }
  int mid=(start+end)/2;
  build(2*n,start,mid);
  build(2*n+1,mid+1,end);
  for(int i=0;i<26;i++){
    lazy[i][n]=-1;
    a[i][n]=a[i][2*n]+a[i][2*n+1];
  }
}

void update_range(int z,int n,int start,int end,int l,int r,int val){
  if(lazy[z][n]!=-1){
    a[z][n]=lazy[z][n]*(end-start+1);
    if(start!=end){
      lazy[z][2*n+1]=lazy[z][n];
      lazy[z][2*n]=lazy[z][n];
    }
    lazy[z][n]=-1;
  }
  if(start>=l && end<=r){
    lazy[z][n]=val;
    a[z][n]=lazy[z][n]*(end-start+1);
    if(start!=end){
      lazy[z][2*n]=lazy[z][n];
      lazy[z][2*n+1]=lazy[z][n];
    }
    lazy[z][n]=-1;
    return;
  }
  if(start>r || end<l) return;
  int mid=(start+end)/2;
  update_range(z,2*n,start,mid,l,r,val);
  update_range(z,2*n+1,mid+1,end,l,r,val);
  a[z][n]=a[z][2*n]+a[z][2*n+1];
}

int count(int z,int n,int start,int end,int l,int r){
  if(lazy[z][n]!=-1){
    a[z][n]=lazy[z][n]*(end-start+1);
    if(start!=end){
      lazy[z][2*n+1]=lazy[z][n];
      lazy[z][2*n]=lazy[z][n];
    }
    lazy[z][n]=-1;
  }
  if(r<start || end<l) return 0;
  if(start>=l && end<=r) return a[z][n];
  int mid=(start+end)/2;
  return count(z,2*n+1,mid+1,end,l,r)+count(z,2*n,start,mid,l,r);
}

void get(int n,int start,int end,int i){
  if(lazy[i][n]!=-1){
    a[i][n]=lazy[i][n];
    if(start!=end){
      lazy[i][2*n]=lazy[i][n];
      lazy[i][2*n+1]=lazy[i][n];
    }
    lazy[i][n]=-1;
  }
  if(a[i][n]==0) return;
  if(start==end){
    if(a[i][n]==1){
      ans[start]='a'+i;
    }
    return;
  }
  int mid=(start+end)/2;
  get(2*n,start,mid,i);
  get(2*n+1,mid+1,end,i);
}

int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  getchar();
  for(int i=1;i<=n;i++){
    given[i]=getchar();
  }
  build(1,1,n);
  // for(int i=0;i<26;i++){
  //   for(int j=1;j<=26;j++) printf("%d ",a[i][j]);
  //   printf("\n");
  // }
  int cnt[26];
  while(q--){
    int x,y,up;
    scanf("%d %d %d", &x, &y, &up);
    for(int j=0;j<26;j++)
      cnt[j] = count(j,1, 1, n, x, y);
    int curr = x;
    if(!up) curr = y;
    for(int j=0;j<26;j++)
    {
      if(!cnt[j]) continue;
      update_range(j,1, 1, n , x, y, 0);
      if(up)
      {
        update_range(j,1, 1, n , curr, curr + cnt[j] - 1, 1);
        curr+=cnt[j];
      }
      else
      {
        update_range(j,1, 1, n , curr - cnt[j] + 1, curr, 1);
        curr-=cnt[j];
      }
    }
  }
  // for(int i=0;i<26;i++){
  //   for(int j=1;j<=26;j++) printf("%d ",a[i][j]);
  //   printf("\n");
  // }
  for(int i=0;i<26;i++) get(1,1,n,i);
  for(int i=1;i<=n;i++){
    printf("%c",ans[i]);
  }
  return 0;
}
