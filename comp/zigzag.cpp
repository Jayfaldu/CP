#include<bits/stdc++.h>
using namespace std;
struct sign{
  int cnt;
  char x;
};

int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  sign dp[n];
  dp[0].cnt=1;
  dp[0].x='*';
  int tmp=dp[0].cnt;
  for(int i=1;i<n;i++){
    if(a[i]>a[0]){
      dp[i].cnt=2;
      dp[i].x='-';
    }
    else if(a[i]<a[0]){
      dp[i].cnt=2;
      dp[i].x='+';
    }
    for(int j=1;j<i;j++){
      if(a[i]>a[j] && dp[j].x=='+'){
        dp[i].cnt=max(dp[i].cnt,dp[j].cnt+1);
        dp[i].x='-';
      }
      else if(a[i]<a[j] && dp[j].x=='-'){
        dp[i].cnt=max(dp[i].cnt,dp[j].cnt+1);
        dp[i].x='+';
      }
    }
  }
  for(int i=1;i<n;i++){
    tmp=max(tmp,dp[i].cnt);
  }
  printf("%d\n",tmp);
  printf("%c  ",dp[2].x);
  for(int i=0;i<n;i++){
    printf("%d  ",dp[i].cnt);
  }
}
