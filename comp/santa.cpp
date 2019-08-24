#include<stdio.h>
#include<algorithm>
using namespace std;

int ans[1005][1005],inc[1005][1005];

void knapsack(int weight[],int n){

  for(int i=0;i<=n;i++){
    ans[0][i]=0;
    inc[0][i]=0;
  }
  for(int i=0;i<=n;i++){
    ans[i][0]=0;
    inc[i][0]=0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(weight[i]>j){
        ans[i][j]=ans[i-1][j];
        inc[i][j]=inc[i-1][j];
        //printf("%d ",inc[i][j]);
      }
      else{
        ans[i][j]=max(ans[i-1][j-weight[i]]+1,ans[i-1][j]);
        if(ans[i-1][j-weight[i]]+1>=ans[i-1][j]) inc[i][j]=weight[i];
        else inc[i][j]=inc[i-1][j];
      //  printf("%d ",inc[i][j]);
      }
    }
    //printf("\n");
  }
}


int main(){
  int n;
  // printf("enter the number of items:");
  scanf("%d",&n);
  int weight[n+1];
  for(int i=1;i<=n;i++){
    weight[i]=i;
  }
  knapsack(weight,n);
  printf("%d\n",ans[n][n]);
  int tmp=n;
  for(int i=n;i>0 && tmp>0;i--){
    printf("%d ",inc[i][tmp]);
    tmp-=inc[i][tmp];
  }
}
