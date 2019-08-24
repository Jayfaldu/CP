#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;

int lazy[400005];

void update_range(int node,int start,int end,int l,int r){
  if(start>end or start >r or end<l) return;
  if(start>=l and end<=r){
    // tree[node]+=1;
    lazy[node]+=1;
    return;
  }
  int mid=(start+end)/2;
  update_range(2*node,start,mid,l,r);
  update_range(2*node+1,mid+1,end,l,r);
}

int query(int node,int start,int end,int l){
  if(start>end or start>l or end<l) return 0;
  if(lazy[node]!=0){
    if(start!=end){
      lazy[node*2]+=lazy[node];
      lazy[node*2+1]+=lazy[node];
      lazy[node]=0;
    }
  }
  if(start==l && end==l) return lazy[node];
  int mid=(start+end)/2;
  if(l<=mid && l>=start) return query(2*node,start,mid,l);
  else if(l>=mid+1 && l<=end) return query(2*node+1,mid+1,end,l);
}


int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    int n;
    scanf("%d",&n);
    memset(lazy,0,sizeof(lazy));
    int zom[n],act[n];
    for(int i=0;i<n;i++){
      scanf("%d",&act[i]);
      update_range(1,0,n-1,max(0,i-act[i]),min(n-1,i+act[i]));
    }
    for(int i=0;i<n;i++){
      act[i]=query(1,0,n-1,i);
    }
    for(int i=0;i<n;i++) scanf("%d",&zom[i]);
    map<int,int> c,b;
    for(int i=0;i<n;i++){
      c[act[i]]++;
      b[zom[i]]++;
    }
    int flag=0;
    auto it=c.begin();
    auto k=b.begin();
    for(;it!=c.end() && k!=b.end();){
      if(*it!=*k){
        printf("NO\n");
        flag=1;
        break;
      }
      it++;
      k++;
    }
    if(flag==0) printf("YES\n");

  }
}
