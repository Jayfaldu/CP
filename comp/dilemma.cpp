#include<bits/stdc++.h>

using namespace std;

int main(){
  int test;
  cin>>test;
  getchar();
  while(test--){
    int cnt=0;
    string c;
    cin>>c;
    // cout<<c<<endl;
    for(int i=0;i<c.size();i++){
      if(c[i]=='1') cnt++;
    }
    if(cnt%2) cout<<"WIN"<<endl;
    else cout<<"LOSE"<<endl;
  }
}
