#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int test;
  cin>>test;
  while(test--){
    int n;
    cin>>n;
    int x=0,y=0,flag=0;
    int right_x,left_x,up_y,down_y;
    right_x=(-100000);
    left_x=100000;
    up_y=(-100000);
    down_y=100000;
    int x1,y1,f[4];
    for(int i=0;i<n;i++){
      cin>>x1>>y1>>f[0]>>f[1]>>f[2]>>f[3];
      if(!f[0] && right_x<x1) right_x=x1;
      if(!f[1] && down_y>y1) down_y=y1;
      if(!f[2] && left_x>x1) left_x=x1;
      if(!f[3] && up_y<y1) up_y=y1;
    }
    if(right_x<=left_x && up_y<=down_y) cout<<"1 "<<(right_x+left_x)/2<<" "<<(up_y+down_y)/2<<endl;
    else cout<<"0"<<endl;
  }
}
