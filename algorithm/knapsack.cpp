#include<stdio.h>
#include<algorithm>
using namespace std;

int ans[1000][1000];

void knapsack(int weight[],int ans[][1000],int no_items,int max_weight){

  for(int i=0;i<=max_weight;i++){
    ans[0][i]=0;
  }
  for(int i=0;i<=no_items;i++){
    ans[i][0]=0;
  }
  int W=max_weight;
  for(int i=1;i<=no_items;i++){

    for(int j=1;j<=max_weight;j++){

      if(weight[i]>j){
        ans[i][j]=ans[i-1][j];
      }
      else{
        ans[i][j]=max(ans[i-1][j-weight[i]]+weight[i],ans[i-1][j]);
      }
    }
  }
}


int main(){
  int no_items;
  int max_weight;
  printf("enter the number of items:");
  scanf("%d",&no_items);
  printf("enter maximum weight");
  scanf("%d",&max_weight);
  printf("Enter the weight of each item:");
  int weight[no_items+1];
  for(int i=1;i<=no_items;i++){
    scanf("%d",&weight[i]);
  }
  knapsack(weight,ans,no_items,max_weight);
  printf("%d",ans[no_items][max_weight]);
}
