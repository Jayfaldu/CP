#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100003
#define INF 0x3f3f3f3f


ll djk(ll src,vector<vector<ll>> arr,ll n,int path[],ll dest){
  ll dist[n];
  int done[n];
	for(ll i=0;i<n;i++) dist[i] = INF, done[i] = false;
	dist[src] = 0;
    path[src]=src;
	while(1) {
		ll u = -1;
    ll best_dist = INF;
		for(ll i=0;i<n;i++) {
			if(!done[i] && dist[i] < best_dist) {
				u = i;
				best_dist = dist[i];
			}
		}
		if(best_dist >= INF) break;

		for(ll v=0;v<n;v++) {
			if(!done[v] && arr[u][v] != INF && u != v) {
				if(dist[v] > dist[u] + arr[u][v]) {
					dist[v] = dist[u] + arr[u][v];
					path[v]=u;
				}
			}
		}
		done[u] = true;
	}
  return dist[dest];
}

int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<vector<ll>> graph;
    for(int i=0;i<n;i++) graph.push_back({});
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        graph[i].push_back(INF);
      }
    }
    for(int i=0;i<k;i++){
      int l,m;
      ll dista;
      scanf("%d%d%lld",&l,&m,&dista);
      l-=1;
      m-=1;
      graph[l][m]=dista;
      graph[m][l]=dista;
    }
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a-=1;
    b-=1;
    c-=1;
    int path1[n];
    int path2[n];
    ll dist_b=djk(c,graph,n,path1,b);
    ll tmp_dist[n+1];
    ll dist_c=djk(b,graph,n,path2,a);
    if(dist_b+dist_c>=INF) printf("No Train Found.\n");
    else{
      printf("%lld\n",dist_b+dist_c);
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
