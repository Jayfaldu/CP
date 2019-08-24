#include <stdio.h>
#include <math.h>


int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    long long int x;
    scanf("%lld",&x);
    char value[x];
    getchar();
    for(int j=0;j<x;j++){
      scanf("%c",&value[j]);
    }
    long long int cum_sum[x];
    cum_sum[0]=value[0]-48;
    for(int j=1;j<x;j++){
      cum_sum[j]=cum_sum[j-1]+value[j]-48;
    }
    int k;
    if((x/2)*2==x){
      k=x/2;
    }
    else{
      k=(x/2)+1;
    }
    long long int max=cum_sum[k-1];
    for(int j=1;j<x-k;j++){
      long long int tmp=cum_sum[j+k-1]-cum_sum[j-1];
      if(tmp>max){
        max=tmp;
      }
    }
    printf("Case #%d: %lld\n",i+1,max);
  }
  return 0;
}
