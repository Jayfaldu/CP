#include<bits/stdc++.h>
#define s second
#define f first
using namespace std;
typedef long long ll;
typedef pair<double,double> pd;

ll a[100005];
double tre[400010];
pd lazy[400010];
int multi[400010];

void build(int n,int start,int end){
  multi[n]=end-start+1;
  lazy[n].s=0;
  lazy[n].f=1;
  if(start==end){
    tre[n]=a[start];
    return;
  }
  int mid=(start+end)/2;
  build(2*n,start,mid);
  build(2*n+1,mid+1,end);
  tre[n]=tre[2*n]+tre[2*n+1];
}

void push(int n,int start,int end){
  tre[n]=(tre[n]*lazy[n].f)+lazy[n].s*multi[n];
  if(start!=end){
    lazy[2*n].f*=lazy[n].f;
    lazy[2*n+1].f*=lazy[n].f;
    lazy[2*n].s=lazy[2*n].s*lazy[n].f+lazy[n].s;
    lazy[2*n+1].s=lazy[2*n+1].s*lazy[n].f+lazy[n].s;
  }
  lazy[n].s=0;
}

double query(int n,int start,int end,int l,int r){
  if(lazy[n].s!=0) push(n,start,end);
  if(start>=l && end<=r) return tre[n];
  if(start>r || end<l) return 0;
  int mid=(start+end)/2;
  return query(2*n,start,mid,l,r)+query(2*n+1,mid+1,end,l,r);
}

void update(int n,int start,int end,int l,int r,pd val){
  if(lazy[n].s!=0) push(n,start,end);
  if(l<=start && r>=end){
    lazy[n].f=val.f;
    lazy[n].s=val.s;
    push(n,start,end);
    return;
  }
  if(start>r || end<l) return;
  int mid=(start+end)/2;
  update(2*n,start,mid,l,r,val);
  update(2*n+1,mid+1,end,l,r,val);
  tre[n]=tre[2*n]+tre[2*n+1];
}

int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
  build(1,1,n);
  while(q--){
    int tmp;
    scanf("%d",&tmp);
    if(tmp==1){
      int l1,l2,r1,r2;
      scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
      double sum1=query(1,1,n,l1,r1);
      double sum2=query(1,1,n,l2,r2);
      pd val1,val2;
      val1.f=double(r1-l1)/double(r1-l1+1);
      val1.s=sum2/(double(r1-l1+1)*double(r2-l2+1));
      // printf("%lf %lf %lf\n",val1.f,val1.s,sum1);
      val2.f=double(r2-l2)/double(r2-l2+1);
      val2.s=sum1/(double(r1-l1+1)*double(r2-l2+1));
      update(1,1,n,l1,r1,val1);
      update(1,1,n,l2,r2,val2);
    }
    else{
      int l,r;
      scanf("%d%d",&l,&r);
      double ans=query(1,1,n,l,r);
      printf("%lf\n",ans);
    }
  }
}
