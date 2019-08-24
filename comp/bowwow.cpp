#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  string s;
  cin>>s;
  int ans=(s.size()-1)/2;
  if(ans<(s.size()-1)/2.0){
    cout<<ans+1<<"\n";
    return 0;
  }
  for(int i=1;i<s.size();i++){
    if(s[i]=='1'){
      ans+=1;
      break;
    }
  }
  cout<<ans<<"\n";
}
