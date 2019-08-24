#include<stdio.h>
#include<vector>
#include<queue>
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
  // printf("Enter the number of edges:\n");
  int m;
  scanf("%d",&m);
  // printf("Enter the nodes between whoch there are edges:\n");
  for(int i=0;i<m;i++){
    int p,q;
    scanf("%d%d",&p,&q);
    graph[p].push_back(q);
    graph[q].push_back(p);
  }
  int happy=0;
  for(int i=1;i<=n;i++){
    if(visited[i]==0){
      int root=i;
      queue<int> visiting;
      visiting.push(root);
      visited[root]=1;
      while(!visiting.empty()){
        int now=visiting.front();
        visiting.pop();
        for(int j=0;j<graph[now].size();j++){
          if(visited[graph[now][j]]==0){
            if(graph[graph[now][j]].size()>=2) happy++;
            visiting.push(graph[now][j]);
            visited[graph[now][j]]=1;
          }
        }
      }
    }
  }
  printf("%d\n",happy);
}
