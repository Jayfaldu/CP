#include<bits/stdc++.h>

using namespace std;

int x_to_y(int x,int y,int num){
  int i=0;
  int dec_num=0;
  int rem;
  while(num!=0){
    rem=num%10;
    num/=10;
    dec_num+=rem*pow(x,i++);
  }
  int a[10];
  i=0;
  while(dec_num>0){
    a[i]=dec_num%y;
    dec_num/=y;
    i++;
  }
  int ans=0;
  for(int j=i-1;j>=0;j--) ans+=a[j]*pow(10,j);
  return ans;
}

int main(){
  int a[2];
  cin>>a[0]>>a[1];
  sort(a,a+2);
  for(int i=10;i>1;i--){
    for(int j=2;j<=i;j++){
      if(a[1]==x_to_y(i,j,a[0])){
        cout<<i<<" "<<j<<endl;
        return 0;
      }
    }
  }
}
