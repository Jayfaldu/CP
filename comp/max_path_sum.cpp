#include<bits/stdc++.h>


using namespace std;

int main(){
    int test;
    scanf("%d",&test);
    for(int k=0;k<test;k++){
      int n;
      scanf("%d",&n);
      vector<vector<int>> dp;
      vector<vector<int>> data;
      for(int i=0;i<n;i++) data.push_back({}),dp.push_back({});
      for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
          i nt tmp;
          scanf("%d",&tmp);
          data[i].push_back(tmp);
        }
      }
      dp[0].push_back(data[0][0]);
      for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
          int tmp;
          if(j==0) tmp=data[i][j]+dp[i-1][j];
          else if(j==i) tmp=data[i][j]+dp[i-1][j-1];
          else{
            tmp=max(data[i][j]+dp[i-1][j],data[i][j]+dp[i-1][j-1]);
          }
          dp[i].push_back(tmp);
        }
      }
      int tmp=dp[n-1][0];
      for(int i=1;i<n;i++){
        if(dp[n-1][i]>tmp) tmp=dp[n-1][i];
      }
      printf("%d\n",tmp);
    }
}
