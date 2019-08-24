#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
typedef long long ll;
typedef pair<ll,int> lpair;
typedef pair<int,ll> pairl;

ll dij(int src, vector<vector<pairl>> graph,int n,int dest,int path[]){
  priority_queue<lpair,vector<lpair>,greater<lpair>> pq;
  pq.push(make_pair(0,src));
  ll dist[n+1];
  path[src]=src;
  for(int i=0;i<=n;i++) dist[i]=INF;
  dist[src]=0;
  while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();
    for(int i=0;i<graph[u].size();i++){
      int v=graph[u][i].first;
      ll weight=graph[u][i].second;
      if(dist[v]>dist[u]+weight){
        dist[v]=dist[u]+weight;
        pq.push(make_pair(dist[v],v));
        path[v]=u;
      }
    }
  }
  return dist[dest];
}

int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<vector<pairl>> graph;
    for(int i=0;i<=n;i++) graph.push_back({});
    for(int i=0;i<k;i++){
      int l,m;
      ll n;
      scanf("%d%d%lld",&l,&m,&n);
      graph[l].push_back(make_pair(m,n));
      graph[m].push_back(make_pair(l,n));
    }
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int path1[n+1],path2[n+1];
    ll dist_a=dij(c,graph,n,b,path1);
    ll dist_b=dij(b,graph,n,a,path2);
    if(dist_a+dist_b>=INF) printf("No Train Found.\n");
    else{
      printf("%lld\n",dist_a+dist_b);
      while(path2[a]!=a){
        printf("%d ",a);
        a=path2[a];
      }
      while(path1[a]!=a){
        printf("%d ",a);
        a=path1[a];
      }
      printf("%d\n",a);
    }
  }
}
