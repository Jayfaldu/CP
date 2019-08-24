#include<bits/stdc++.h>


int min(int x,int y){
  return (x>y)?(y):(x);
}

long long int select(int n, int r)
{
    long long int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    return C[r];
}

int fast_exp(int x,int n){
  if(n==0){
    return 1;
  }
  else if(n%2==0){
    return fast_exp(x*x,n/2);
  }
  else{
    return x*fast_exp(x*x,(n-1)/2);
  }
}

int fast_modulo(int x,int n, int p){
  if(n==0){
    return 1;
  }
  else if(n%2==0){
    return fast_modulo((x*x)%p,n/2,p);
  }
  else{
    return (x*fast_modulo((x*x)%p,(n-1)/2,p))%p;
  }
}


int main(){
  printf("%lld",select(5,3));
}
