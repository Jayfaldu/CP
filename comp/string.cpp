#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[3*100005],b[3*100005];

int main(){
 ll n,p,k;
 ll cnt=0;
 cin>>n>>p>>k;
 for(int i=0;i<n;i++){
   cin>>a[i];
   b[i]=(a[i]*a[i])%p;
 }
 for(int i=0;i<n;i++){
   for(int j=i+1;j<n;j++){
     if(((((a[i]+a[j])%p)*(b[i]+b[j]))%p)==k) cnt++;
   }
 }
 cout<<cnt<<endl;
}
