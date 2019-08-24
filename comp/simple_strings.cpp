#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  getchar();
  int a[n];
  for(int i=0;i<n;i++){
    char tmp;
    scanf("%c",&tmp);
    a[i]=tmp-'a';
  }
  for(int i=0;i<q;i++){
    int l,m,n;
    scanf("%d %d %d",&l,&m,&n);
    if(n==1) sort(a+l,a+m);
    else sort(a+l,a+m,greater<int>());
  }
  for(int i=0;i<n;i++){
    printf("%c",a[i]+'a');
  }
}
