#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n;
  scanf("%d",&n);
  getchar();
  while(n--){
    char c,d;
    c='0';
    d='0';
    ll i=0;
    ll j=0;
    ll cnt1=0;
    ll cnt2=0;
    int flag=0;
    char s1[1000000],s2[1000000];
    while(true){
      c=getchar();
      cnt1++;
      if(c=='\n') break;
      if(c!=d) s1[i++]=c;
      d=getchar();
      cnt1++;
      while(d==c){
        d=getchar();
        cnt1++;
      }
      if(d=='\n') break;
      s1[i++]=d;
    }
    s1[i]='\n';
    c='0';
    d='0';
    while(true){
      c=getchar();
      cnt2++;
      if(c=='\n') break;
      if(c!=d) s2[j++]=c;
      d=getchar();
      cnt2++;
      while(d==c){
        d=getchar();
        cnt2++;
      }
      if(d=='\n') break;
      s2[j++]=d;
    }
    s2[j]='\n';
    printf("%s\n",s1);
    printf("%s\n",s2);
    if(i!=j || cnt1>cnt2){
      printf("NO\n");
      continue;
    }
    for(int k=0;k<i;k++){
      if(s1[k]!=s2[k]){
        printf("NO\n");
        flag=1;
        break;
      }
    }
    if(flag==0)printf("YES\n");
  }
}
