#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n;
  scanf("%d",&n);
  vector<pair<int,int>> x,y;
  for(int i=1;i<=n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b) x.push_back(make_pair(b,i));
    else y.push_back(make_pair(b,i));
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end(),greater<>());
  int flag=0;
  if(x.size()>y.size()) flag=1;
  if(flag==1){
    printf("%d\n",x.size());
    for(int i=0;i<x.size();i++){
      printf("%d ",x[i].second);
    }
    printf("\n");
  }
  else{
    printf("%d\n",y.size());
    for(int i=0;i<y.size();i++){
      printf("%d ",y[i].second);
    }
    printf("\n");
  }
}
