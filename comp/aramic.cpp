#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  set<set<char>> diff_set;
  for(int i=0;i<n;i++){
    char c[1001];
    cin>>c;
    set<char> tmp;
    for(int j=0;j<strlen(c);j++){
      tmp.insert(c[j]);
    }
    diff_set.insert(tmp);
  }
  int z=diff_set.size();
  cout<<z;
}
