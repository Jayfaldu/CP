#include<stdio.h>
#include<algorithm>

using namespace std;

int cost[1000][1000],alpha[1000][1000];

int compare(int x,int y,int z){
  if(x>y){
    return min(y,z);
  }
  else{
    return min(x,z);
  }
}

int min_cost(int cost[][1000],int alpha[][1000],int mis_cost,char word1[],char word2[],int length1,int length2){

  for(int i=0;i<=length1;i++){
    cost[i][0]=i*mis_cost;
  }
  for(int j=0;j<=length2;j++){
    cost[0][j]=j*mis_cost;
  }
  for(int i=1;i<=length1;i++){
    for(int j=1;j<=length2;j++){
      cost[i][j]=compare(alpha[i][j] + cost[i-1][j-1],cost[i-1][j] + mis_cost,cost[i][j-1] + mis_cost);
    }
  }
  return cost[length1][length2];
}

int main(){


}
