#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int test;
  cin>>test;
  while(test--){
    int n;
    map<int,int> freq;
    cin>>n;
    int a[n];
    int cum[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
      freq.insert(pair<int,int>(a[i],0));
    }
    cum[0]=1;
    freq[a[0]]++;
    for(int i=1;i<n;i++){
      if(freq[a[i]]==0){
        cum[i]=cum[i-1]+1;
        freq[a[i]]++;
      }
      else cum[i]=cum[i-1];
    }
    ll ans=n;
    for(int i=2;i<=n;i++){
      for(int j=0;j<n+1-i;j++){
        ans+=cum[j+i-1]-cum[j]+1;
      }
    }
    cout<<ans<<endl;
  }
}
