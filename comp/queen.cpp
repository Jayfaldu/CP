#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> board;

bool is_valid(){
  int cur_row=board.size()-1;
  int cur_col=board[cur_row];
  for(int j=0;j<board.size()-1;j++){
    int diff=abs(cur_col-board[j]);
    if(diff==0 || diff==cur_row-j) return false;
  }
  return true;
}

ll n_queens(int n){
  if(n==board.size()) return 1;
  ll count=0;
  for(int i=0;i<n;i++){
    board.push_back(i);
    if(is_valid()) count+=n_queens(n);
    board.pop_back();
  }
  return count;
}



int main(){
  int n;
  cin>>n;
  cout<<n_queens(n)<<endl;
}
