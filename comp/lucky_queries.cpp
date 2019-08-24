#include<bits/stdc++.h>

using namespace std;


int n4[4000003],n7[4000003],n47[4000003],n74[4000003];
char given[1000009];
int lazy[4000003];

void build(int node,int start,int end){
  if(start==end){
    if(given[start]=='4') n4[node]=1;
    else n7[node]=1;
    n47[node]=1;
    n74[node]=1;
    return;
  }
  int mid=(start+end)/2;
  build(2*node,start,mid);
  build(2*node+1,mid+1,end);
  n4[node]=n4[2*node]+n4[2*node+1];
  n7[node]=n7[2*node]+n7[2*node+1];
  n47[node]=max(n4[2*node]+n47[2*node+1],n47[2*node]+n7[2*node+1]);
  n74[node]=max(n7[2*node]+n74[2*node+1],n74[2*node]+n4[2*node+1]);
}

void upd(int node){
  lazy[node] ^=1;
  swap(n4[node],n7[node]);
  swap(n47[node],n74[node]);
}

void push(int node){
  if(lazy[node]){
    upd(2*node);
    upd(2*node+1);
    lazy[node]=0;
  }
}

void upd(int node,int start,int end,int l,int r){
  if(start>end || l>end || r<start) return;
  if(start>=l && end<=r){
    upd(node);
    return;
  }
  push(node);
  int mid=(start+end)/2;
  upd(2*node,start,mid,l,r);
  upd(2*node+1,mid+1,end,l,r);
  n4[node]=n4[2*node]+n4[2*node+1];
  n7[node]=n7[2*node]+n7[2*node+1];
  n47[node]=max(n4[2*node]+n47[2*node+1],n47[2*node]+n7[2*node+1]);
  n74[node]=max(n7[2*node]+n74[2*node+1],n74[2*node]+n4[2*node+1]);
}
int main(){

  int n,m;
  cin>>n>>m;
  getchar();
  for(int i=1;i<=n;i++) cin>>given[i];
  build(1,1,n);
  getchar();
  while(m--){
    string tmp;
    cin>>tmp;
    if(tmp[0]=='count') cout<<n47[1]<<endl;
    else{
      int l,r;
      cin>>l>>r;
      upd(1,1,n,l,r);
    }
  }
}
