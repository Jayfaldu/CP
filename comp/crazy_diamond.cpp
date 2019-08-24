#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n+1];
  int b[n+1];
  vector<pair<int,int>> ans;
  for(int i=1;i<=n;i++){
    cin>>b[i];
    a[b[i]]=i;
  }
  for(int i=n;i>n/2;i++){
    cout<<"hakk";
    if(a[i]!=i){
      if(2*abs(i-a[i])>=n){
        ans.push_back(make_pair(i,a[i]));
        a[b[i]]=a[i];
        b[a[i]]=b[i];
        a[i]=i;
        b[i]=i;
      }
      else{
        int x=i-n/2;
        ans.push_back(make_pair(a[i],x));
        a[b[x]]=a[i];
        b[a[i]]=b[x];
        a[i]=x;
        b[x]=i;
        ans.push_back(make_pair(x,i));
        a[b[i]]=x;
        b[x]=b[i];
        a[i]=i;
        b[i]=i;
      }
    }
    int tmp=i-n/2;
    if(a[tmp]!=tmp){
      if(2*abs(tmp-a[tmp])>=n){
        ans.push_back(make_pair(tmp,a[tmp]));
        a[b[i]]=a[i];
        b[a[i]]=b[i];
        a[i]=i;
        b[i]=i;
      }
      else{
        int x=tmp+n/2;
        ans.push_back(make_pair(a[tmp],x));
        a[b[x]]=a[tmp];
        b[a[tmp]]=b[x];
        a[tmp]=x;
        b[x]=tmp;
        ans.push_back(make_pair(x,i));
        a[b[tmp]]=x;
        b[x]=b[tmp];
        a[tmp]=tmp;
        b[tmp]=tmp;
      }
    }
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  }
}
