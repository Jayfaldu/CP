#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;



set<ll> find_ans(ll cypher[],ll ans[],ll len,ll n){
  ll i=0;
  set<ll>primes;
  while(cypher[i]==cypher[i+1]){
  i++;
  }
  ll tmp1,tmp2;
  ll tmp=sqrt(cypher[i]);
  for(ll j=3;j<=tmp;j++){
    if(cypher[i]%j==0){
      tmp1=j;
      tmp2=cypher[i]/tmp1;
    }
  }
  if(cypher[i+1]%tmp1==0){
    ans[i]=tmp2;
    ans[i+1]=tmp1;
    primes.insert(tmp1);
    primes.insert(tmp2);
    for(ll j=i-1;j>=0;j--){
      ans[j]=cypher[j]/ans[j+1];
      primes.insert(ans[j]);
    }
  }
  else{
    ans[i]=tmp1;
    ans[i+1]=tmp2;
    primes.insert(tmp1);
    primes.insert(tmp2);
    for(ll j=i-1;j>=0;j--){
      ans[j]=cypher[j]/ans[j+1];
      primes.insert(ans[j]);
    }
  }
  for(ll j=i+2;j<=len;j++){
    ans[j]=cypher[j-1]/ans[j-1];
    primes.insert(ans[j]);
  }
  return primes;
}


int main(){
  ll test;
  scanf("%lld",&test);
  for(ll i=0;i<test;i++){
    ll n;
    ll len;
    char s[100000];
    set<ll> primes;
    scanf("%lld %lld",&n,&len);
    ll cypher[150];
    ll ans[150];
    for(ll j=0;j<len;j++){
      scanf("%lld",&cypher[j]);
    }
    primes=find_ans(cypher,ans,len,n);
    set<ll> ::iterator it;
    ll k=0;
    for(it=primes.begin();it!=primes.end();it++){
      s[*it]='A'+k;
      k++;
    }
    printf("Case #%lld: ",i+1);
    for(ll j=0;j<=len;j++){
      printf("%c",s[ans[j]]);
    }
    printf("\n");
  }
}
