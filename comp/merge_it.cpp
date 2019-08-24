#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx=2*100005;


int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    bool visited[mx];
    memset(visited,false,sizeof visited);
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>graph[n+1];
    multimap<int,int>mp;

    for(int i=0;i<m;i++){
      int p,q;
      scanf("%d%d",&p,&q);
      graph[p].push_back(q);
      graph[q].push_back(p);
    }
    for(int i=1;i<=n;i++){
			mp.insert({graph[i].size(),i });
    }
    vector<int> ans;
    for(auto it=mp.rbegin();it!=mp.rend();it++){
      if(visited[it->second]==0){
        visited[it->second]=1;
        ans.push_back(it->second);
        for(auto j:graph[it->second]){
          visited[j]=1;
        }
      }
    }
    if(ans.size()<=n/2){
      printf("%lu\n",ans.size());
      for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
      printf("\n");
    }
    else{
      set<int>s;
			for(int i=0;i<ans.size();i++){
				s.insert(ans[i]);
			}
			cout<<n-ans.size()<<endl;
			for(int i=1;i<=n;i++){
				if(s.find(i)==s.end())
					cout<<i<<" ";
			}
    }
  }
}
