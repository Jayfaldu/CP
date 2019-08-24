#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct min_distance{
  int distance;
  int papa;
};

struct edges{
  int to_node;
  int cost;
};

void initialize(min_distance nodes[],int no_nodes,int source){
  for(int i=1;i<=no_nodes;i++){
    nodes[i].distance=100000;
    nodes[i].papa=0;
  }
  nodes[source].distance=0;
}

void relax(int node_from,int node_to,int weight,min_distance nodes[]){
  int distance_from_to=nodes[node_to].distance;
  if(nodes[node_from].distance>distance_from_to+weight){
    nodes[node_from].distance=distance_from_to+weight;
    nodes[node_from].papa=node_to;
  }
}

bool bellmen_ford(vector< vector <edges> > graph,int source,min_distance nodes[],int no_nodes){
  initialize(nodes,no_nodes,source);
  for(int i=1;i<=no_nodes;i++){
    for(int i=1;i<=no_nodes;i++){
      for(int j=0;j<graph[i].size();j++){
        relax(i,graph[i][j].to_node,graph[i][j].cost,nodes);
      }
    }
  }
  for(int i=1;i<=no_nodes;i++){
    for(int j=0;j<graph[i].size();j++){
      int present_node=graph[i][j].to_node;
      if(nodes[i].distance>nodes[present_node].distance+graph[i][j].cost){
        return false;
      }
    }
  }
  return true;
}

void print_path(int source,int destination,min_distance nodes[]){
  printf("%d   ",source)
  if(nodes[source].papa!=0){
      printf("%d   ",nodes[source].papa);
      print_path(nodes[source].papa,destination,nodes);
  }
}

int main()
{
  vector< vector <edges> > graph;
  int no_node;
  printf("enter the number of nodes:");
  scanf("%d",&no_node);
  printf("Enter edges and cost\n");
  min_distance nodes[no_node+1];
  printf("Enter the number of edges:");
  int no_edge;
  scanf("%d",&no_edge);
  for(int i=0;i<=no_node;i++){
    graph.push_back({});
  }
  for(int i=1;i<=no_edge;i++){
    printf("from:");
    int p,q,r;
    scanf("%d",&p);
    printf("to:");
    scanf("%d",&q);
    printf("cost:");
    scanf("%d",&r);
    edges s1;
    s1.to_node=q;
    s1.cost=r;
    graph[p].push_back(s1);
  }
  int source;
  int destination;
  printf("enter the destination node and source node:");
  scanf("%d%d",&source,&destination);
  if(bellmen_ford(graph,source,nodes,no_node)){
    printf("sortest distance is %d\n",nodes[destination].distance);
    print_path(destination,source,nodes);
  }
  else{
    printf("there is a negative cycle\n");
  }
}
