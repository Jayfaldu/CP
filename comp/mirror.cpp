#include<bits/stdc++.h>
using namespace std;

int degree[100005],visited[100005],dist[100005];

int main(){
  int n;
  scanf("%d",&n);
  vector<vector<int>> p;
  vector<vector<int>> dist_index;
  for(int i=0;i<=n+1;i++){
    p.push_back({});
    dist_index.push_back({});
  }
  int root;
  for(int i=0;i<n-1;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    p[x].push_back(y);
    p[y].push_back(x);
    degree[x]++;
    degree[y]++;
  }
  for(int i=1;i<=n;i++){
    if(degree[i]==1) {root=i;break;}
  }
  int max_dist=0;
  queue<int>visiting;
  visiting.push(root);
  visited[root]=1;
  dist_index[0].push_back(root);
  dist[root]=0;
  while(!visiting.empty()){
    int now=visiting.front();
    visiting.pop();
    int len=p[now].size();
    for(int j=0;j<len;j++){
      int tmp=p[now][j];
      if(visited[tmp]==0){
        visiting.push(tmp);
        dist[tmp]=dist[now]+1;
        max_dist=max(dist[tmp],max_dist);
        dist_index[dist[tmp]].push_back(tmp);
        visited[tmp]=1;
      }
    }
  }
  
  for(int i=1;i<=max_dist;i++){
    int len=dist_index[i].size();
    int tmp_deg=degree[dist_index[i][0]];
    for(int j=1;j<len;j++){
      if(tmp_deg!=degree[dist_index[i][j]]){
        printf("-1\n");
        return 0;
      }
    }
  }
  printf("%d\n",root);
}
