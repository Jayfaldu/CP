#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;
  cin>>n;
  for(int i=0;i<n;i++){
    long long int l,r;
    cin>>l>>r;
    for(long long int j=1;(j|l)<=r;j=j<<1)l|=j;
    cout<<l<<endl;
  }
  return 0;
}
