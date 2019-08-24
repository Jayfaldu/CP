#include<stdio.h>
#include<algorithm>

using namespace std;

int rod_cut(int price[],int opt_sol[],int rods){
  opt_sol[0]=0;
  opt_sol[1]=price[1];
  for(int i=2;i<=rods;i++){
    int value=0;
      for(int j=0;j<=i/2;j++){
        int temp;
        if(j==0){
          temp=price[i];
        }
        else{
          temp=opt_sol[j] + opt_sol[i-j];
        }
        value=max(temp,value);
      }
      opt_sol[i]=value;
  }
  return opt_sol[rods];
}

int main(){
  printf("enter the number of rods:");
  int rods;
  scanf("%d",&rods);
  int prices[rods+1];
  prices[0]=0;
  printf("Enter the prices for rods:");
  for(int i=1;i<=rods;i++){
    scanf("%d",&prices[i]);
  }
  int opt_sol[rods+1];
  printf("Maximum price is :%d\n",rod_cut(prices,opt_sol,rods));
}
