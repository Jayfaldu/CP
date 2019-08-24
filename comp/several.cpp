#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  int m;
  int h;
  scanf("%d %d %d",&n,&m,&h);
  int row[n];
  int col[m];
  int height[n][m];
  for(int i=0;i<m;i++){
    scanf("%d",&col[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%d",&row[i]);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&height[i][j]);
      if(height[i][j]==1){
        height[i][j]=min(row[i],col[j]);
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%d ",height[i][j]);
    }
    printf("\n");
  }
}
