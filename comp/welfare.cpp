#include<bits/stdc++.h>

using namespace std;
set<<pair<int,int>> p;

int main(){
  int n;
  cin>>n;
  int a[n+1]
  for(int i=1;i<=n;i++){
    cin>>a[i];
    p.insert({a[i],p});
  }
  int q;
  cin>>q;
  while(q--){
    int tmp;
    cin>>tmp;
    if(tmp==1){
      int z,x;
      cin>>z>>x;
      pair<int,int> lx={x,z}
      auto it=p.find(lx);
      p.erase(it);
      p.insert(lx);
    }
    else{
      int x;
      cin>>x;
      ``
    }
  }
}
