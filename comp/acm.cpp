#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)

using namespace std;
typedef long long ll;

int main(){
  int test;
  scanf("%d",&test);
  getchar();
  while(test--){
    char s[100002],k[100002];
    scanf("%s%s",s,k);
    int tmp=0;
    for(int i=strlen(k)-1;i>=0;i--){
      if(k[i]=='1'){
        tmp=strlen(k)-i-1;
        break;
      }
    }
    for(int i=strlen(s)-1-tmp;i>=0;i--){
      if(s[i]=='1'){
        printf("%d\n",int(strlen(s))-tmp-1-i);
        break;
      }
    }
  }
}
