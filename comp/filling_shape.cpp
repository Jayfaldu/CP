#include<bits/stdc++.h>
using namespace std;

bool visited[503][503];
char a[503][503];

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  getchar();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%c",&a[i][j]);
    }
    getchar();
  }
  int flag=0;
  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      if(a[i][j]=='*'){
        if(a[i-1][j]=='*' && a[i+1][j]=='*' && a[i][j-1]=='*' && a[i][j+1]=='*'){
          visited[i][j]=1;
          int z=i-1;
          while(a[z][j]=='*') visited[z--][j]=1;
          z=i+1;
          while(a[z][j]=='*') visited[z++][j]=1;
          z=j-1;
          while(a[i][z]=='*') visited[i][z--]=1;
          z=j+1;
          while(a[i][z]=='*') visited[i][z++]=1;
          flag=1;
          break;
        }
      }
    }
    if(flag==1) break;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(visited[i][j]==0 && a[i][j]=='*') {
        printf("NO\n");
        return 0;
      }
    }
  }
  if(flag==1) printf("YES\n");
}
