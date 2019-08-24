#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int tree[4*100002];
bool b[100000];

void build_tree(int n,int start,int end){
  if(start==end) tree[n]=b[start];
  else{
    int mid=(start+end)/2;
    build_tree(2*n,start,mid);
    build_tree(2*n+1,mid+1,end);
    tree[n]=(tree[2*n]|tree[2*n+1]);
  }
}

int query(int n,int start,int end,int l,int r){
  if(r<start || end<l) return 0;
  if(l<=start && r>=end) return tree[n];
  int mid=(start+end)/2;
  return (query(2*n,start,mid,l,r)|query(2*n+1,mid+1,end,l,r));
}

int main(){
  ios_base::sync_with_stdio(false);
  int test;
  scanf("%d",&test);
  while(test--){
    int n,q;
    scanf("%d%d",&n,&q);
    getchar();
    char a[n];
    scanf("%s",a);
    memset(b,0,sizeof(b));
    for(int i=0;i<n-2;i++){
      if(a[i]==a[i+2]||a[i]==a[i+1]||a[i+1]==a[i+2]){
        b[i]=1;
      }
    }
    // for(int i=0;i<n-2;i++) printf("%d ",b[i]);
    // printf("\n");
    build_tree(1,0,n-3);
    while(q--){
      int l,r;
      scanf("%d%d",&l,&r);
      if(query(1,0,n-3,l-1,r-3)) printf("YES\n");
      else printf("NO\n");
    }
  }
}
