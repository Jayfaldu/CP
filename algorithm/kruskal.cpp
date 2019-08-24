#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

struct comp{
   ll node1;
   ll node2;
};

struct cost{
  ll from,to,weight;
};

bool compare(cost s1,cost s2){
  return (s1.weight < s2.weight);
}

ll find(ll node, ll tree[]){
  if(tree[node] == node){
    return node;
  }else{
    return (tree[node] = find(tree[node], tree));
  }
}

void change_comp(ll from_node,ll to_node,ll tree[]){
    tree[find(from_node,tree)]=find(to_node,tree);
}

int main(){
  vector< pair<ll,ll> > result;
  ll node,edges;
  ll k;
  ll component;
  scanf("%lld%lld%lld",&node,&edges,&k);
  cost graph[edges];
  ll tree[node+1];
  for(ll i=0;i<edges;i++){
    scanf("%lld%lld%lld",&graph[i].from,&graph[i].to,&graph[i].weight);
    if(i+1<=node) tree[i+1]=i+1;
  }
  sort(graph,graph + edges,compare);
  ll cost=0;
  ll cnt=0;
  vector<ll> ans;
  for(ll i=0;i<edges;i++){
    if(find(graph[i].from,tree)!=find(graph[i].to,tree)){
      ans.push_back(graph[i].weight);
      cost+=graph[i].weight;
      change_comp(graph[i].from,graph[i].to,tree);
    }
  }
  set<ll> uni;
  for(ll i=1;i<=node;i++){
    find(i,tree);
  }
  for(ll i=1;i<=node;i++) uni.insert(tree[i]);
  // printf("%d  ",uni.size());
  if(uni.size()>1) printf("-1\n");
  else {
    for(int j=ans.size()-1;j>=0;j--){
      if(cost>k) {cost=cost-ans[j]+1;
        cnt++;}
    }
    printf("%lld\n",cnt);
  }
}
