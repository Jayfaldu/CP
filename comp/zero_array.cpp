#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)

using namespace std;
typedef long long ll;

int main(){
  syn;
  int n;
  cin>>n;
  int carry=0;
  int tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    carry=abs(tmp-carry);
  }
  if(carry==0) cout<<"YES"<<"\n";
  else cout<<"NO"<<"\n";
}
