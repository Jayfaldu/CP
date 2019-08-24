#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int search(ll b[],ll tmp,ll start,ll end){
  while(start!=end && end>start){
    int mid=(start+end)/2;
    if(tmp>b[mid]) start=mid+1;
    else if(tmp<b[mid]) end=mid-1;
    else return mid;
  }
  return start;
}

int main(){
  int n,m,ta,tb,k;
  cin>>n>>m>>ta>>tb>>k;
  ll a[n],b[m];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  ll ans=0;
  if(k>=n || k>=m){
    cout<<"-1"<<endl;
    return 0;
  }
  for(int i=0;i<=k;i++){
    int j=lower_bound(b,b+m,a[i]+ta)-b;
    if(j+k-i>m-1) {
      ans=-1;
      break;
    }
    ans=max(ans,b[j+k-i]+tb);
  }
  cout<<ans<<endl;
}
