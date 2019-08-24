#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100005],tree[400005];

void build(int node,int start,int end){
  if(start == end) tree[node]=a[start];
  else{
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]=tree[2*node]+tree[2*node+1];
  }
}

int query(int node,int start,int end,int l,int r){
  if(l>end || r<start) return 0;
  else if(l>=start && end<=r) return tree[node];
  int mid=(start+end)/2;
  return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}

void update(int node,int start,int end,int index,int val){
  if(start==end) a[index]=tree[node]=val;
  else{
    int mid=(start+end)/2;
    if(index>=start && index<=mid) update(2*node,start,mid,index,val);
    else update(2*node+1,mid+1,end,index,val);
    tree[node]=tree[2*node]+tree[2*node+1];
  }
}



int main(){
  char s[100005];
  scanf("%s",s);
  for(int i=0;i<strlen(s);i++) a[i+1]=s[i]-'0';
  int n;
  scanf("%d",&n);
  build(1,1,strlen(s));
  for(int i=0;i<n;i++){
    int type;
    scanf("%d",&type);
    if(type==1){
      int c,b,v;
      scanf("%d%d%d",&c,&b,&v);
      for(int j=c;j<=b;j++) update(1,1,n,c,(a[c]+v)%10);
    }
    else{
      int c,d;
      scanf("%d%d",&c,&d);
      if(query(1,1,n,c,d)%3==0) printf("Yes\n");
      else printf("No\n");
    }
  }
}
