#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  while(n--){
    int n,m;
    scanf("%d%d",&n,&m);
    int army[n+1][m+1];
    memset(army,0,sizeof(army));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        scanf("%d",&army[i][j]);
      }
    }
    int max_size=0;
    int cnt=0;
    bool visited[n][m];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(army[i][j]==1 && visited[i][j]==0){
          int tmp_max=1;
          visited[i][j]=1;
          queue<pair<int,int>> visiting;
          visiting.push(make_pair(i,j));
          while(visiting.size()!=0){
            // pair<int,int> cur=visiting.front();
            int x,y;
            x=visiting.front().first;
            y=visiting.front().second;
            visiting.pop();
            if(army[x][y+1]==1 && visited[x][y+1]==0){
              visiting.push(make_pair(x,y+1));
              visited[x][y+1]=1;
              tmp_max++;
            }
            if(army[x][y-1]==1 && visited[x][y-1]==0){
              visiting.push(make_pair(x,y-1));
              visited[x][y-1]=1;
              tmp_max++;
            }
            for(int i=0;i<3;i++){
              if(army[x+1][y-1+i]==1 && visited[x+1][y-1+i]==0){
                visiting.push(make_pair(x+1,y-1+i));
                visited[x+1][y-1+i]=1;
                tmp_max++;
              }
            }
            for(int i=0;i<3;i++){
              if(army[x-1][y-1+i]==1 && visited[x-1][y-1+i]==0){
                visiting.push(make_pair(x-1,y-1+i));
                visited[x-1][y-1+i]=1;
                tmp_max++;
              }
            }
          }
          max_size=max(tmp_max,max_size);
          cnt++;
        }
      }
    }
    printf("%d %d\n",cnt,max_size);
  }
}
