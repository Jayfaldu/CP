#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d",&n);
    m=n-1;
    vector<vector<int>> graph;
    for(int i=0;i<=n;i++) graph.push_back({});
    for(int i=0;i<m;i++){
      int q,p;
      scanf("%d%d",&p,&q);
      graph[p].push_back(q);
      graph[q].push_back(p);
    }
    bool visited[n+1];
    memset(visited,0,sizeof(visited));
    visited[1]=1;
    long long distance[n+1];
    for(int i=0;i<=n;i++) distance[i]=1000000;
    distance[1]=0;
    // printf("%lld\n",distance[1]);
    queue<int>visiting;
    visiting.push(1);
    while(visiting.size()!=0){
      int tmp=visiting.front();
      // printf("%d  ",tmp);
      visiting.pop();
      for(int i=0;i<graph[tmp].size();i++){
        int l=graph[tmp][i];
        // printf("-%d",l);
        distance[l]=min(distance[tmp]+1,distance[l]);
        if(visited[l]==0) {
          visited[l]=1;
          visiting.push(l);
        }
      }
      // printf("\n");
    }
    int q;
    pair<int,int> prop;
    scanf("%d",&q);
    int tmp;
    scanf("%d",&tmp);
    prop.first=distance[tmp];
    prop.second=tmp;
    for(int i=1;i<q;i++){
      scanf("%d",&tmp);
      if(distance[tmp]<prop.first){
        prop.first=distance[tmp];
        prop.second=tmp;
      }
      else if(prop.first==distance[tmp]){
        if(prop.second>tmp) prop.second=tmp;
      }
    }
    printf("%d\n",prop.second);
}
