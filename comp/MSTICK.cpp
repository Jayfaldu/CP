#include<stdio.h>

double time[100000],min[400000],max[400000];

void mint(int node,int start,int end){
  if(start==end){
    min[node]=time[start];
  }
  else{
    int mid=(start+end)/2;
    mint(2*node,start,mid);
    mint(2*node+1,mid+1,end);
    min[node]=(min[2*node]>min[2*node+1])?(min[2*node+1]):(min[2*node]);
    }
  }

void maxt(int node,int start,int end){
  if(start==end){
    max[node]=time[start];
  }
  else{
    int mid=(start+end)/2;
    maxt(2*node,start,mid);
    maxt(2*node+1,mid+1,end);
    max[node]=(max[2*node]<max[2*node+1])?(max[2*node+1]):(max[2*node]);
    }
}

double minimum(int node,int start,int end,int l,int r){
  if(l>end || r<start){
    return 10000000;
  }
  else if(l<=start && end<=r){
    return min[node];
  }
  int mid=(start+end)/2;
  double p1=minimum(2*node,start,mid,l,r);
  double p2=minimum(2*node+1,mid+1,end,l,r);
  return (p1>p2)?(p2):(p1);
}

double maximum(int node,int start,int end,int l,int r){
  if(l>end || r<start){
    return 0;
  }
  else if(l<=start && end<=r){
    return max[node];
  }
  int mid=(start+end)/2;
  double p1=maximum(2*node,start,mid,l,r);
  double p2=maximum(2*node+1,mid+1,end,l,r);
  return (p1>p2)?(p1):(p2);
}

double max_val(double x,double y){
  return (x>y)?(x):(y);
}

int main()
{
  int x;
  //printf("Enter the number of matchsticks:\n");
  scanf("%d",&x);
  //printf("Enter the time for each matchsticks:\n");
  for(int i=0;i<x;i++){
    scanf("%lf",&time[i]);
  }
  mint(1,0,x-1);
  maxt(1,0,x-1);
  // printf("%lf\n",maximum(1,0,x-1,2,7));
  // printf("%lf\n",minimum(1,0,x-1,0,1));
  // printf("%lf\n",maximum(1,0,x-1,0,1));
  // printf("%lf\n",minimum(1,0,x-1,2,7));

  int query;
  scanf("%d",&query);
  for(int i=0;i<query;i++){
    int l,r,mn,mx,lmx=0,rmx=0;
    double ans;
    scanf("%d%d",&l,&r);
    mn=minimum(1,0,x-1,l,r);
    mx=maximum(1,0,x-1,l,r);
    if(l>0) lmx=maximum(1,0,x-1,0,l-1);
    if(r<x-1) rmx=maximum(1,0,x-1,r+1,x-1);
    ans=max_val(double(mn)+double(lmx),double(mn)+double(rmx));
    ans=max_val(ans,double(mn)+double((double(mx)-double(mn)))/2);
    printf("%.1f",ans);
//     if(l==0){
//       if(r==x-1){
//         double minlr=minimum(1,0,x-1,l,r);
//         double maxlr=maximum(1,0,x-1,l,r);
//         printf("%.1lf",(minlr+maxlr)/2);
//       }
//       else{
//         double max=maximum(1,0,x-1,r+1,x-1);
//         double minlr=minimum(1,0,x-1,l,r);
//         double maxlr=maximum(1,0,x-1,l,r);
//         if(minlr+max>(maxlr+minlr)/2){
//           printf("%.1lf\n",minlr+max);
//         }
//         else{
//           printf("%.1lf\n",(maxlr+minlr)/2);
//         }
//       }
//     }
//     else if(r==x-1){
//       double max=maximum(1,0,x-1,0,l-1);
//       double minlr=minimum(1,0,x-1,l,r);
//       double maxlr=maximum(1,0,x-1,l,r);
//       if(minlr+max>(maxlr+minlr)/2){
//         printf("%.1lf\n",minlr+max);
//       }
//       else{
//         printf("%.1lf\n",(maxlr+minlr)/2);
//       }
//     }
//     else{
//       double max;
//       double maxl=maximum(1,0,x-1,0,l-1);
//       double maxr=maximum(1,0,x-1,r+1,x-1);
//       double minlr=minimum(1,0,x-1,l,r);
//       double maxlr=maximum(1,0,x-1,l,r);
//       (maxl>maxr)?(max=maxl):(max=maxr);
//       if(minlr+max>(maxlr+minlr)/2){
//         printf("%.1lf\n",minlr+max);
//       }
//       else{
//         printf("%.1lf\n",(maxlr+minlr)/2);
//     }
//   }
//  }
  return 0;
}
