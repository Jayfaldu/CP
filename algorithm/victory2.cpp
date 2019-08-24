#include<bits/stdc++.h>

using namespace std;

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

int main(){
  int x[5];
  for(int i=0;i<5;i++){
    x[i]=0;
  }
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    char a[11];
    cin>>a;
    if(a[0]=='R'){
      x[0]++;
    }
    else if(a[0]=='A'){
      x[1]++;
    }
    else if(a[0]=='M'){
      x[2]++;
    }
    else if(a[0]=='H'){
      x[3]++;
    }
    else if(a[0]=='C'){
      x[4]++;
    }
  }
  int sum=0;
  for(int i=0;i<5;i++){
    sum+=x[i];
  }
  long long int ans=select(sum,3);
  for(int i=0;i<5;i++){
    if(x[i]>=3){
      ans=ans-1-select(x[i],2)*(sum-x[i]);
    }
    else if(x[i]>=2){
      ans=ans-(sum-x[i]);
    }
  }
  cout<<ans<<endl;
}
