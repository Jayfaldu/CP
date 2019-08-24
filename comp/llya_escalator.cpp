#include<bits/stdc++.h>

using namespace std;
long long comp[2005][2005];

void binomial(int n,int k){
  int i,j;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=min(i,k);j++){
      if(j==0 || j==i) comp[i][j]=1;
      else comp[i][j]=comp[i-1][j-1]+comp[i-1][j];
    }
  }
}

double calc(int n,int t,double p,double q){
  double tmp=0;
  for(int i=t;i>0;i--){
    tmp+=pow(p,i)*i*pow(q,t-i)*comp[t][i];
  }
  return tmp;
}

int main(){
  int n,t;
  double p,q;
  scanf("%d %lf %d",&n,&p,&t);
  q=1-p;
  // printf("hello");
  for(int i=0;i<=n;i++){
    binomial(n,i);
  }
  if(n>=t) printf("%lf\n",calc(n,t,p,q));
  else{
    int r=t-n;
    double tmp=pow(q,r)*calc(n,n,p,q);
    tmp+=n*pow(p,n-1)*(1-pow(q,r));
    printf("%lf\n",tmp);
  }
}
