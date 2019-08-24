#include<bits/stdc++.h>

using namespace std;

int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    int n;
    scanf("%d",&n);
    int points[n];
    for(int i=0;i<n;i++){
      scanf("%d",&points[i]);
      points[i]*=20;
    }
    int ans=0;
    for(int i=0;i<n;i++){
      int tmp;
      scanf("%d",&tmp);
      points[i]-=(tmp*10);
      ans=max(ans,points[i]);
    }
    printf("%d\n",ans);
  }
}
