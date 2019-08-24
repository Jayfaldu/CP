#include<stdio.h>
#include<math.h>


long long int mod_exp(long long int x,long long int n,long long int M)
{
    if(n==0){
      return 1;
    }
    else if(n%2 == 0){
      long long int tmp = x%M;
      return mod_exp((tmp*tmp)%M,n/2,M);
    }
    else{
      long long int tmp = x%M;
      return (x*mod_exp((tmp*tmp)%M,(n-1)/2,M))%M;
    }
}
int main(){
  int n;
  const long long int modulo=(7 + pow(10,9));
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    long long int l;
    int k;
    int x1;
    int y1;
    int c,d,e1,e2,f;
    scanf("%lld%d%d%d%d%d%d%d%d",&l,&k,&x1,&y1,&c,&d,&e1,&e2,&f);
    long long int a[l+1];
    a[1]=x1+y1;
    long long int x_1=x1;
    long long int y_1=y1;

    for(int j=2;j<=l;j++){
      x_1=( ((c%f)*(x1%f))%f + ((d%f)*(y1%f))%f + (e1%f) )%f;
      y_1=( ((d%f)*(x1%f))%f + ((c%f)*(y1%f))%f + (e2%f) )%f;
      a[j]=(x_1+y_1)%f;
      x1=x_1;
      y1=y_1;
    }
    long long int sum=0;
    long long int power[l+1][k+1];

    for(int j=1;j<=l;j++){
      int tmp=a[j]%modulo;
      for(int z=1;z<=k;z++){
        power[j][z]=tmp;
        sum=(sum+power[j][z])%modulo;
      }
    }
    for(int j=1;j<=k;j++){
      for(int q=2;q<=l;q++){
        for(int p=1;p<=l-q+1;p++){
        long long int x=((a[p+q-1]%modulo)*mod_exp(q,j,modulo))%modulo;
        power[p][j]=(power[p][j]+x)%modulo;
        sum=(sum + power[p][j])%modulo;
        }
      }
    }
    printf("Case #%d: %lld\n",i+1,sum);
  }
  return 0;
}
