#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  pair<int,int> deg[n];
  vector<vector<int>> graph;
  for(int i=0;i<=n-1;i++){
    graph.push_back({});
    deg[i].first=0;
    deg[i].second=i;
  }
  for(int i=0;i<n-1;i++){
    int p,q;
    cin>>p>>q;
    graph[p].push_back(q);
    graph[q].push_back(p);
    deg[p].first++;
    deg[q].first++
  }
  sort(deg,deg+n);
  int edges=n-1;
  for(int i=0;;i++){
    if(edges<=0) break;
    else
  }
}
