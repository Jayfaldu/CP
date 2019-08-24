#include<stdio.h>
#include<algorithm>

using namespace std;

long long int tmp=0;
long long int index=0;

bool powerful(long long int n,long long int power[],long long int i,long long int current){
  current=current + tmp;
  if(i+1>=n){
    return true;
  }
  else if(current*2>=power[i+1]){
    //current+=power[i-1];
    tmp+=power[i];
    return (true && powerful(n,power,i+1,power[i+1]));
  }
  else{
    tmp+=current;
    return false;
  }
}

int main(){
  long long int n;
  scanf("%lld",&n);
  long long int power[n];
  for(int i=0;i<n;i++){
    scanf("%lld",&power[i]);
  }
  sort(power,power+n);
  int i=0;
  for(;i<n;i++){
//    printf("%lld  ",tmp);
    if(powerful(n,power,i,power[i])){
      break;
    }
  }
  printf("%lld",n-i);
}
