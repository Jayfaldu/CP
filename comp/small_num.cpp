#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

ll min(ll x,ll y){
  return (x>y)?(y):(x);
}


int main(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  getchar();
  char x[3];
  cin>>x[0]>>x[1]>>x[2];
  sort(x,x+3);
  if(x[0]=='*' && x[1]=='*'){
    if(x[2]=='+'){
      ll mn=10000000000;
      mn=min(mn,(a*b)+(c*d));
      mn=min(mn,(a*c)+(b*d));
      mn=min(mn,(a*d)+(c*b));
      cout<<mn<<endl;
    }

    else {
      // printf("hello");
      ll mn=a*b*c*d;
      cout<<a*b*c*d<<endl;
    }
  }
  else{
    if(x[0]=='*'){
      ll mn=(a+b+c)*d;
      mn=min(mn,(a+b+c)*d);
      mn=min(mn,(d+b+c)*a);
      mn=min(mn,(a+d+c)*b);
      mn=min(mn,(a+b+d)*c);
      mn=min(mn,(a*c)+b+d);
      mn=min(mn,(b*c)+a+d);
      mn=min(mn,(d*c)+b+a);
      mn=min(mn,(a*b)+c+d);
      mn=min(mn,(a*d)+b+c);
      mn=min(mn,(b*d)+a+c);
      cout<<mn<<endl;
    }
    else {
      ll mn=a+b+c+d;
      cout<<mn<<endl;
    }
  }
  return 0;
}
