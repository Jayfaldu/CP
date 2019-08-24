#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  long long int a[n];
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }
  long long sum;
  long long tmp;
  sum=a[n-1];
  tmp=a[n-1];
  for(int i=n-2;i>=0;i--){
    if(tmp<=0){
      break;
    }
    if(a[i]>=tmp){
      sum+=tmp-1;
      tmp=tmp-1;
    }
    else{
      sum+=a[i];
      tmp=a[i];
    }
  }
  printf("%lld\n",sum);
}
