#include<bits/stdc++.h>

using namespace std;

struct ans{
  char a;
  int index;
  int delta;
};

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  int b[n];
  int cnt=0;
  scanf("%d",&b[0]);
  vector<ans> f;
  for(int i=1;i<n;i++){
    ans tmp;
    scanf("%d",&b[i]);
    int t=b[i]-b[i-1];
    if(t<k){
      tmp.a='+';
      tmp.index=i+1;
      tmp.delta=k-t;
      b[i]=b[i-1]+k;
      f.push_back(tmp);
    }
    else if(t>k){
      tmp.a='-';
      tmp.index=i+1;
      tmp.delta=t-k;
      b[i]=b[i-1]+k;
      f.push_back(tmp);
    }
  }
  printf("%lu\n",f.size());
  for(int i=0;i<f.size();i++){
    printf("%c %d %d\n",f[i].a,f[i].index,f[i].delta);
  }
}
