#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)
using namespace std;
typedef long long ll;


int main(){
  syn;
  ll n,k;
  cin>>n>>k;
  ll arr[n];
  for(ll i=0;i<n;i++) cin>>arr[i];
  sort(arr,arr+n);
  ll prev=arr[n/2];
  ll count=1;
  for(ll i=n/2+1;i<n;i++){
    ll tmp=arr[i]-prev;
    if(tmp*count<=k){
      prev=arr[i];
      k-=tmp*count;
      count++;
    }
    else{
      prev+=k/count;
      cout<<prev<<"\n";
      return 0;
    }
  }
  if(k>0){
    // cout<<count<<" "<<prev<<" "<<k<<endl;
    prev+=(k/count);
    // cout<<"HEl";
    cout<<prev<<"\n";
    return 0;
  }
  cout<<prev<<"\n";
}
