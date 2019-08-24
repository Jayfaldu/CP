#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int test;
  cin>>test;
  while(test--){
    int n;
    cin>>n;
    int arr[n];
    int ans=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        int x=arr[i]*arr[j];
        int sum=0;
        while(x>0){
          sum+=x%10;x=x/10;
        }
        ans=max(sum,ans);
      }
    }
    cout<<ans<<endl;
  }
}
