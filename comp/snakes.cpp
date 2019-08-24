#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int test;
  cin>>test;
  // cout<<test;
  while(test--){
    int n,m;
    cin>>n>>m;
    char x[n+1][m+1];
    getchar();
    vector<pair<int,int>> p[26];
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin>>x[i][j];
        if(x[i][j]>='a' && x[i][j]<='z')
        p[int(x[i][j]-'a')].push_back(make_pair(i,j));
      }
      getchar();
    }
    int cnt=0;
    for(int i=0;i<26;i++){
      int tmp=p[i].size();
      if(tmp){cnt=max(i+1,cnt);
        if(p[i][0].first==p[i][tmp-1].first){
          for(int j=p[i][0].second+1;j<p[i][tmp-1].second;j++){
            if(x[p[i][0].first][j]<'a'+i){
              printf("NO\n");
              return 0;
            }
          }
        }
        else if(p[i][0].second==p[i][tmp-1].second){
          for(int j=p[i][0].first+1;j<p[i][tmp-1].first;j++){
            if(x[j][p[i][0].second]<'a'+i){
              printf("NO\n");
              return 0;
            }
          }
        }
        else{

        }
      }
    }
    printf("YES\n%d\n",cnt);
    for(int i=0;i<cnt;){
      int tmp=p[i].size();
      if(tmp){
        cout<<p[i][0].first<<" "<<p[i][0].second<<" ";
        cout<<p[i][tmp-1].first<<" "<<p[i++][tmp-1].second<<endl;
      }
      else{
        int j=i+1;
        while(!p[j].size() && j<cnt)j++;
        if(j>=cnt) return 0;
        int k=p[j].size()-1;
        while(i<=j){
          cout<<p[j][0].first<<" "<<p[j][0].second<<" ";
          cout<<p[j][k].first<<" "<<p[j][k].second<<endl;
          i++;
        }
      }
    }
  }
}
