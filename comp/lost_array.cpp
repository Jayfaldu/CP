#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n,l,r;
  cin>>n>>l>>r;
  ll max_sum,min_sum;
  max_sum=(1<<r)-1+(1<<(r-1))*(n-r);
  min_sum=(1<<l)-1+n-l;
  cout<<min_sum<<" "<<max_sum<<"\n";
  return 0;
}
