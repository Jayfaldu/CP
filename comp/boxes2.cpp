#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 30;

int main() {
  int n;
  cin >> n;
  vector<int> v;

  int a = 1;
  while (a <= n) {
    v.push_back(a);
    a *= 6;
  }
  a = 9;
  while (a <= n) {
    v.push_back(a);
    a *= 9;
  }
  int dp[n + 1];
  for (int i = 0; i <= n; i++) dp[i] = INF;
  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    for (auto x : v) {
      if (i + x <= n) {
        dp[i + x] = min(dp[i + x], dp[i] + 1);
      }
    }
  }
  cout << dp[n] << endl;
}
