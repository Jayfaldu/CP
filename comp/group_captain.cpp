#include<bits/stdc++.h>

bool prime[1000001];

void mark_prime(){
  memset(prime,1,sizeof(prime));
  for(int i=2;i*i<=1e6;i++){
    if(prime[i]==true){
      for(int j=i*i;j<=1e6;j+=i){
        prime[j]=0;
      }
    }
  }
  prime[1]=0;
}

void find_div(int n){
  int tmp=sqrt(n);
  int cnt=0;
  for(int i=1;i<=tmp;i++){
    if(n%i==0){
      if(n/i == i) cnt++;
      else cnt+=2;
    }
  }
  printf("%d\n",cnt);
}

int main(){
  mark_prime();
  int test;
  scanf("%d",&test);
  while(test--){
    int l,r,x,cnt=0;
    scanf("%d%d%d",&l,&r,&x);
    for(int i=l;i<=r;i++){
      if(prime[i]) {
        cnt++;
        if(cnt==x) printf("%d ",i);
      }
    }
    if(cnt<x) printf("-1 ");
    find_div(cnt);
  }
}
