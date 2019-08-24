#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)
using namespace std;


int main(){
  int q;
  scanf("%d",&q);
  while(q--){
    int n;
    scanf("%d",&n);
    int a[n];
    int k=0;
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
      if(a[i]==1) k=i;
    }
    if(n==1 || n==2|| n==3){
      printf("YES\n");
      continue;
    }
    int l=(k+1<=n-1)?(k+1):(0);
    int j=(k-1>=0)?(k-1):(n-1);
    if(a[j]==2){
      int tmp=2;
      int flag=0;
      int z=(j==n-1)?(1):(0);
      for(int i=j;i>=z;i--){
        if(a[i]!=tmp){
          printf("NO\n");
          flag=1;
          break;
        }
        tmp++;
      }
      if(flag==0 && j!=n-1){
        for(int i=n-1;i>=k+1;i--){
          if(a[i]!=tmp){
            flag=1;
            printf("NO\n");
            break;
          }
          tmp++;
        }
      }
      if(flag==0) printf("YES\n");
    }
    else if(a[l]==2){
      // printf("hell");
      int tmp=2;
      int flag=0;
      int z=(l==0)?(n-1):(n);
      for(int i=l;i<z;i++){
        if(a[i]!=tmp){
            printf("NO\n");
            flag=1;
            break;
          }
          tmp++;
        }
        if(flag==0&&l!=0){for(int i=0;i<k;i++){
          if(a[i]!=tmp){
            printf("NO\n");
            flag=1;
            break;
          }
          tmp++;
        }}
        if(flag==0) printf("YES\n");
      }
      else {printf("NO\n");}
    }
}
