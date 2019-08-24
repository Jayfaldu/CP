#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<b;i++)
#define ro(i,a,b) for(int i=a;i>b;i--)

typedef long long ll;
using namespace std;

int main(){
  int test;
  cin>>test;
  while(test--){
    int n,k,d;
    cin>>n>>k>>d;
    int c[n];
    fo(i,0,n) cin>>c[i];
    // cout<<"HEE";
    vector<vector<int>> a;
    a.push_back({});
    a.push_back({});
    fo(i,0,n){
      int tmp;
      cin>>tmp;
      if(tmp==1) a[0].push_back(c[i]);
      else a[1].push_back(c[i]);
    }
    if(a[0].empty() && a[1].empty()){
      cout<<k<<endl;
      continue;
    }
    int pos=0;
    bool cur_lan=(a[0][0]>a[1][0])?(0):(1);
    auto j=(a[cur_lan].begin());
    // cout<<cur_lan<<"    "<<*j<<endl;
    while(1){
      int x=cur_lan^1;
      auto it=upper_bound(a[x].begin(),a[x].end(),*j);
      if(it==a[x].end() &&  *(it-1)+1!=*j){
        cout<<k<<endl;
        break;
      }
      it--;
      int l=*(it);
      if(l+1==*j){
        cout<<l+1<<endl;
        break;
      }
      cur_lan^=1;
      pos=max(l+1,pos);
      it++;
      if(*it<=*j+1){
        cout<<*it<<endl;
        break;
      }
      if((*it)-pos<d){
        cout<<(*it)<<endl;
        break;
      }
      pos=pos+d;
      j=it;
    }
  }
}
