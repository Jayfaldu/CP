#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> a[10];
  a[1].push_back(2);
  a[3].push_back(3);
  a[3].push_back(5);
  a[3].push_back(6);
  a[3].push_back(8);
  a[3].push_back(9);
  a[3].push_back(1);
  a[3].push_back(10);
  for(auto x:a[3]) cout<<x<<"  ";
}
