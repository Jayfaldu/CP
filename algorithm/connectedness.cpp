#include<bits/stdc++.h>

using namespace std;
int main()
{
  vector< vector< int > > graph;
  printf("Enter the number of nodes:\n");
  int n;
  scanf("%d",&n);
  int visited[n+1];
  for(int i=0;i<=n;i++){
    graph.push_back({});
    visited[i]=0;
  }
  printf("Enter the number of edges:\n");
  int m;
  scanf("%d",&m);

  printf("Enter the nodes between whoch there are edges:\n");
  for(int i=0;i<m;i++){
    int p,q;
    scanf("%d%d",&p,&q);
    graph[p].push_back(q);
    graph[q].push_back(p);
  }
  int count=0;
  for(int i=1;i<=n;i++){
    if(visited[i]==1){
      continue;
    }
    else{
      queue<int> visiting;
      visiting.push(i);
      visited[i]=1;
      while(!visiting.empty()){
        int now=visiting.front();
        visiting.pop();
          for(int j=0;j<graph[now].size();j++){
            int tmp=graph[now][j];
            if(visited[tmp]==0){
              visiting.push(tmp);
              visited[tmp]=1;
            }
          }
      }
    }
    count++;
  }
  printf("%d",count);
}
