#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)
typedef long long ll;
using namespace std;

int main(){
  int test;
  scanf("%d",&test);
  getchar();
  while(test--){
    ll right=0,left=0,up=0,down=0;
    char s[2*100002];
    char c;
    ll net_hor=0;
    ll net_up=0;
    while((c=getchar())!='\n'){
      if(c=='D') net_hor++;
      else if(c=='A') net_hor--;
      else if(c=='W') net_up++;
      else if(c=='S') net_up--;
      right=max(net_hor,right);
      left=min(net_hor,left);
      up=max(net_up,up);
      down=min(net_up,down);
    }
    ll tmp1=right-left+1;
    ll tmp2=up-down+1;
    // printf("%lld %lld\n",tmp1,tmp2);
    if(tmp1==2 && tmp2==2){
      printf("%lld\n",tmp1*tmp2);
    }
    else if(tmp1==1 && tmp2==2) printf("%lld\n",tmp2);
    else if(tmp1==1 && tmp2>2) printf("%lld\n",tmp2-1);
    else if(tmp2==1 && tmp1==2) printf("%lld\n",tmp1);
    else if(tmp2==1 && tmp1>2) printf("%lld\n",tmp1-1);
    else if(tmp1==1 && tmp2==1) printf("1\n");
    else if(tmp1==2 && tmp2>2) printf("%lld\n",(tmp2-1)*2);
    else if(tmp2==2 && tmp1>2) printf("%lld\n",(tmp1-1)*2);
    else {
      printf("%lld\n",min(tmp1*(tmp2-1),(tmp1-1)*tmp2));
    }
  }
}
