#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int arr[1003][5];

int main(){
  ios_base::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  char a[n][1002];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      arr[j][int(a[i][j]-'A')]++;
    }
  }

  int point[m];
  ll ans=0;
  for(int i=0;i<m;i++) cin>>point[i];
  for(int i=0;i<m;i++){
    int tmp=0;
    for(int j=0;j<5;j++){
      tmp=max(tmp,arr[i][j]);
    }
    ans+=(tmp*point[i]);
  }
  cout<<ans<<"\n";
}
