#include<bits/stdc++.h>

using namespace std;

int main(){
  long long a,b,c;
  scanf("%lld%lld%lld",&a,&b,&c);
  if(b>a) printf("%lld\n",(2*c+2*a+1));
  else if(a>b) printf("%lld\n",(2*c+2*b+1));
  else printf("%lld\n",2*c+2*a);
}
