#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

void heapify_down (int nodes[],int temp_distance[], int i ,int N)
{
    int left=2*i;
    int right=2*i+1;
    int smallest=i;
    if(left<=N && temp_distance[nodes[left]]<temp_distance[nodes[smallest]]){
      smallest = left;
    }
    if(right<=N && temp_distance[nodes[right]]<temp_distance[nodes[smallest]]){
      smallest = right;
    }
    if(smallest != i){
      printf("swapping %d and %d\n",i,smallest);
      int tmp=nodes[smallest];
      nodes[smallest]=nodes[i];
      nodes[i]=tmp;
      heapify_down(nodes,temp_distance,smallest,N);
    }
}

void build_heap(int nodes[],int temp_distance[],int N){
  for(int i=N/2;i>=1;i--){
    heapify_down(nodes,temp_distance,i,N);
  }
}

void update_heap(int nodes[],int temp_distance[],int i){
  int parent=i/2;
  if(parent>0){
    if(temp_distance[nodes[parent]]>temp_distance[nodes[i]]){
      int tmp=nodes[parent];
      nodes[parent]=nodes[i];
      nodes[i]=tmp;
      update_heap(nodes,temp_distance,parent);
    }
  }
}

int extract_min(int nodes[],int temp_distance[],int N){
  if(N==0){
    printf("Element cannot be removed");
  }
  int min=temp_distance[nodes[1]];
  int tmp=nodes[1];
  nodes[1]=nodes[N];
  nodes[N]=tmp;
  temp_distance[nodes[N]]=1000000;
  N=N-1;
  heapify_down(nodes,temp_distance,1,N);
  return min;
}

int search_index(int nodes[],int index,int n){
  for(int i=1;i<=n;i++){
    if(nodes[i]==index){
      return i;
    }
  }
}
// void change_value (int nodes[],int temp_distance[],int i,int val,int n){
//  if(val > temp_distance[nodes[i]]){
//    arr[i]=val;
//    heapify_down(arr,i,n);
//  }vector< pair< int , int > > test;
//   test.push_back(make_pair(10,20));
//   test.push_back(make_pair(30,20));
//   test.push_back(make_pair(10,10));
//  test.push_back(make_pair(30,10));
//   int x=test[0][1].first;
//   int y=test[1][0].second;
//   printf("%d ",test.size());
//  else{
//     temp_distance[nodes[i]]=val;
//     update_heap(nodes,temp_distance,i);
//   }
// }

int main()
{

  vector< vector< pair< int , int > > > graph;
  printf("Enter the number of nodes:\n");
  int n;
  scanf("%d",&n);
  vector< pair<int,int> > final_distance;
  int app_distance[n+1];
  int nodes[n+1];
  int visited[n+1];
  for(int i=0;i<=n;i++){
    graph.push_back({});
    visited[i]=0;

  }
  for(int i=0;i<=n;i++){
    nodes[i]=i;
    app_distance[i]=1000;
  }
  printf("Enter the number of edges:\n");
  int m;
  scanf("%d",&m);

  printf("Enter the nodes between which there are edges and weights:\n");
  for(int i=0;i<m;i++){
    int p,q,r;
    printf("from:");
    scanf("%d",&p);
    printf("to:");
    scanf("%d",&q);
    printf("weight:");
    scanf("%d",&r);
    graph[p].push_back(make_pair(q,r));
  }
  int root;
  printf("Enter the node from which you want to find the distance:");
  //printf("reached");
  scanf("%d",&root);
  //printf("reached\n");
  final_distance.push_back(make_pair(root,0));

  app_distance[root]=0;
  visited[root]=1;
  build_heap(nodes,app_distance,n);
  int unknown=extract_min(nodes,app_distance,n);
  //for(int i=1;i<=n;i++){
  //  printf("%d  ",nodes[i]);
  //}
  //printf("\n");
  while(final_distance.size() != n){
  //  printf("size:%lu\n",final_distance.size());
    static int present_node=n-1;
    for(int i=0;i<final_distance.size();i++){
      int x=final_distance[i].first;
      //printf("neighbours : %lu\n",graph[x].size());
      for(int j=0;j<graph[x].size();j++){
        int temp_node=graph[x][j].first;
        if(visited[temp_node]==0){
          int temp_weight=graph[x][j].second;
          int temp_distance=final_distance[i].second + temp_weight;
          //printf("app_distance is %d",app_distance[temp_node]);
          //printf("temp_distance : %d\n",temp_distance);
          //printf("temp_node is %d and its distance is %d\n",temp_node,temp_distance);
          if(app_distance[temp_node]>temp_distance){
            app_distance[temp_node]=temp_distance;
            int index=search_index(nodes,temp_node,n);
            //printf("index is %d  ",index);
            update_heap(nodes,app_distance,index);
            //printf("min is %d and node is %d\n",temp_distance,nodes[1]);
          }
        }
      }
    }
    final_distance.push_back(make_pair(nodes[1],app_distance[nodes[1]]));
    visited[nodes[1]]=1;
    int min=extract_min(nodes,app_distance,present_node--);
    //printf("after removal %d\n",nodes[1]);
  }
for(int i=0;i<final_distance.size();i++){
  printf("distance of %d is %d\n",final_distance[i].first,final_distance[i].second);
}
//  printf("%d  %d  %d",1,graph[1][1].first,graph[1][1].second);
//  vector< int > distance
}
