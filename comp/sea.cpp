#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n;
  int ans[50],a1[50];
  memset(ans,0,sizeof(ans));
  cin>>n;
  ll b[n+1];
  for(int i=0;i<n;i++) cin>>b[i];
  // for(int i=0;i<n;i++) cout<<b[i]<<" ";
  // cout<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ll x2=b[j];
      ll x1=b[i];
      memset(a1,0,sizeof(a1));
      int k=0,flag=0;
      while(1){
        a1[k++]=x2%10;
        a1[k++]=x1%10;
        x1/=10;
        x2/=10;
        if(x1==0){
          flag=1;break;
        }
        if(x2==0){
          flag=2;break;
        }
      }
      if(flag==1){
        if(x2) while(x2){
          a1[k++]=x2%10;
          x2/=10;
        }
      }
      if(flag==2){
        while(x1){
          a1[k++]=x1%10;
          x1/=10;
        }
      }
      int carry=0;
      for(int i=0;i<=28;i++){
        int tmp=ans[i];
        ans[i]=(a1[i]+ans[i]+carry)%10;
        carry=(a1[i]+tmp+carry)/10;
      }
      // for(int i=0;i<33;i++) cout<<a1[i]<<" ";
      // cout<<endl;
    }
  }
  // for(int i=0;i<33;i++) cout<<ans[i]<<" ";
  // cout<<endl;
  ll res=0;
  for(int i=28;i>=0;i--){
    res=(res*10+ans[i])%998244353;
  }
  cout<<res<<endl;
}
