#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int test;
  cin>>test;
  while(test--){
    ll l,r;
    int count;
    cin>>l>>r;
    int i=0,j=0;
    int l1[64],r1[64];
    while(l>0){
      l1[i++]=l%2;
      l/=2;
    }
    while(r>0){
      r1[j++]=r%2;
      r/=2;
    }
    if(i==j){
      if(i%2){
        cout<<"0"<<endl;
        break;
      }
      else{
        int m=i-1,n=j-1;
        while(l1[m]!=1) m--;
        while(r1[n]!=1) n--;

      }
    }

  }

}
