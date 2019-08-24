#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int degree[100005];
vector<vector<int>> graph;
bool visited[100005];
int cnt;
int parent[100005];

void dfs(int s){
  visited[s]=true;
  for(int i=0;i<graph[s].size();i++){
    if(visited[graph[s][i]]==false){
      parent[graph[s][i]]=s;
      dfs(graph[s][i]);
    }
  }
  if(degree[s]%2==0){
    cnt++;
    // printf("%d  %d  %d\n",s,degree[s],parent[s]);
    degree[parent[s]]--;
  }
}


int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<=n;i++) graph.push_back({});
  for(int i=1;i<n;i++){
    int p,q;
    scanf("%d%d",&p,&q);
    graph[p].push_back(q);
    graph[q].push_back(p);
    degree[p]++;
    degree[q]++;
  }
  if(n%2==0){
    dfs(1);
    printf("%d\n",cnt);
  }
  else printf("-1\n");

}
