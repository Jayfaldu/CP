#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll arr[200002],tree[800004],lazy[800004];

void build(int node,int start,int end){
  if(start==end) tree[node]=arr[start];
  else{
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]=min(tree[2*node],tree[2*node+1]);
  }
}

void update_range(int node,int start,int end,int l,int r,ll val){
  if(lazy[node]!=0){
    tree[node]+=lazy[node];
    if(start!=end){
      lazy[node*2]+=lazy[node];
      lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
  }
  if(start>end || start>r || end<l) return;
  if(start>=l && end<=r){
    tree[node]+=val;
    if(start!=end){
      lazy[node*2]+=val;
      lazy[node*2+1]+=val;
    }
    return;
  }
  int mid=(start+end)/2;
  update_range(2*node,start,mid,l,r,val);
  update_range(2*node+1,mid+1,end,l,r,val);
  tree[node]=min(tree[node*2],tree[node*2+1]);
}
//
// void update_range(int node,int start,int end,int l,int r,int val){
//   if(start>r || end<l || start>end) return;
//   if(start==end){
//     tree[node]+=val;
//     return;
//   }
//   int mid=(start+end)/2;
//   update_range(2*node,start,mid,l,r,val);
//   update_range(2*node+1,mid+1,end,l,r,val);
//   (tree[2*node]>tree[2*node+1])?(tree[node]=tree[2*node+1]):(tree[node]=tree[2*node]);
// }



ll query_range(int node,int start,int end,int l,int r){
  if(start > end || start>r || end<l) return pow(10,9);
  if(lazy[node]!=0){
    tree[node]+=lazy[node];
    if(start!=end){
      lazy[2*node]+=lazy[node];
      lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
  }
  if(start>=l && end<=r) return tree[node];
  int mid=(start+end)/2;
  // cout<<mid<<endl;
  return min(query_range(2*node,start,mid,l,r),query_range(2*node+1,mid+1,end,l,r));
}


int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>arr[i];
  int query;
  cin>>query;
  build(1,0,n-1);
  getchar();
  // for(int i=1;i<=3;i++) cout<<tree[i]<<" "<<endl;
  while(query--){
    string tmp;
    getline(cin,tmp);
    // cout<<tmp<<" "<<tmp.size()<<endl;
    int cnt=0;
    for(int j=0;j<tmp.size();j++){
      if(tmp[j]==' ') cnt++;
    }
    // cout<<cnt<<endl;s
    if(cnt==1){
    // cout<<"hekko";
      int a=0;
      int b=0;
      ll z=0;
      while(z<tmp.size() && tmp[z]!=' ') a=10*a+tmp[z++]-'0';
      z++;
      while(z<tmp.size() && tmp[z]!=' ' && tmp[z]!='\n') b=10*b+tmp[z++]-'0';
      // cout<<a<<" "<<b<<endl;
      if(a>b) cout<<min(query_range(1,0,n-1,a,n-1),query_range(1,0,n-1,0,b))<<endl;
      else {
        // cout<<"he";
        cout<<query_range(1,0,n-1,a,b)<<endl;}
    }
    else{
      int a=0;
      int b=0;
      ll val=0;
      int z=0;
      int flag=0;
      while(z<tmp.size() && tmp[z]!=' ') a=10*a+tmp[z++]-'0';
      z++;
      while(z<tmp.size() && tmp[z]!=' ') b=10*b+tmp[z++]-'0';
      z++;
      while(z<tmp.size() && tmp[z]!=' ' && tmp[z]!='\n'){
      if(tmp[z]=='-') flag=1;
      else val=10*val+tmp[z]-'0';
      z++;}
      if(flag==1) val=val*(int(-1));
      // cout<<a<<" "<<b<<" "<<val<<endl;
      if(a>b){
        update_range(1,0,n-1,a,n-1,val);
        update_range(1,0,n-1,0,b,val);
      }
      else update_range(1,0,n-1,a,b,val);
      // for(int i=1;i<=3;i++) cout<<tree[i]<<endl;
    }
  }
}
