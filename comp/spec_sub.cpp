#include<bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin>>s;
  int n;
  cin>>n;
  getchar();
  char a[n];
  int mx=0;
  int end[n];
  memset(end,0,sizeof(end));
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<s.size();i++){
    for(int j=0;j<n;j++){
      // cout<<"jek";
      if(s[i]==a[j]){

        int tmp=0;
        for(int k=0;k<=j;k++){
          if(a[k]!=a[j] || j==k) tmp=max(tmp,end[k]);
        }
        end[j]=max(end[j],tmp+1);
        // cout<<end[j]<<" "<<j<<endl;
      }
    }
  }
  // cout<<endl;
  int ans=0;
  for(int i=0;i<n;i++) ans=max(ans,end[i]);
  cout<<ans<<endl;
}
