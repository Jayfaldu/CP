#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct track{
  int papa;
  int color;
  int cycle;
  int distance;
  int visited;
};

void initialize(track parents[],int n){
  for(int i=1;i<=n;i++){
    parents[i].color=0;
    parents[i].cycle=0;
    parents[i].visited=0;
  }
}

void dfs_visit(vector< vector< int > > graph,int node,track parents[]){
  parents[node].color=1;
  for(int i=0;i<graph[node].size();i++){
    int k=graph[node][i];
    if(parents[k].color==0){
      parents[k].papa=node;
      dfs_visit(graph,k,parents);
    }
    if(parents[k].color==1 && parents[node].papa!=k){
      int l=node;
      while(parents[l].papa!=k){
        parents[l].cycle=1;
        parents[l].distance=0;
        parents[l].visited=1;
        l=parents[l].papa;
      }
      parents[l].cycle=1;
      parents[l].visited=1;
      parents[l].distance=0;
      parents[k].cycle=1;
      parents[k].distance=0;
      parents[k].visited=1;
    }
  }
  parents[node].color=2;
}

void dfs_find_cycle(vector< vector< int > > graph,track parents[],int n){
  initialize(parents,n);
  parents[1].papa=-1;
  for(int i=1;i<=n;i++){
    if(parents[i].color==0){
      dfs_visit(graph,i,parents);
    }
  }
}

void find_distance(vector< vector < int > > graph,track parents[],int cycle[],int len_cycle){
  queue<int> visiting;
  for(int i=0;i<len_cycle;i++){
    int count=1;
    visiting.push(cycle[i]);
    while(!visiting.empty()){
      int now=visiting.front();
      visiting.pop();
      for(int j=0;j<graph[now].size();j++){
        int tmp=graph[now][j];
        if(parents[tmp].visited==0){
          visiting.push(tmp);
          parents[tmp].distance=count;
          parents[tmp].visited=1;
        }
      }
      count++;
    }
  }
}

int main()
{
  int test;
  scanf("%d",&test);
  for(int j=0;j<test;j++){
    vector< vector< int > > graph;
    //printf("Enter the number of nodes:\n");
    int n;
    scanf("%d",&n);
    track parents[n+1];
    for(int i=0;i<=n;i++){
      graph.push_back({});
    }
    //printf("Enter the number of edges:\n");
    //scanf("%d",&m);
    //printf("Enter the nodes between whoch there are edges:\n");
    for(int i=0;i<n;i++){
      int p,q;
      scanf("%d%d",&p,&q);
      graph[p].push_back(q);
      graph[q].push_back(p);
    }

    dfs_find_cycle(graph,parents,n);

    int len_cycle=0;
    int cycle[n];

    for(int i=1;i<=n;i++){
      if(parents[i].cycle==1){
        cycle[len_cycle++]=i;
      }
    }

    find_distance(graph,parents,cycle,len_cycle);
    printf("Case #%d: ",j+1);
    for(int i=1;i<=n;i++){
      printf("%d ",parents[i].distance);
    }
    printf("\n");
  }
}
