#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int of_len[13],MAXL=11;
const int mod=998224353;

void add(int& a,int b){
  a+=b;
  if(a>=mod) a-=mod;
}

int multi(int a, int b) {
	return (ll) a * b % mod;
}

int f(vector<int> const& a, int l) {
	int res = 0;
	int p = 1;
	for (int i = 0; i < max(int(a.size()), l); ++i) {
		if (i < l) {
			p = multi(p, 10);
		}
		if (i < a.size()) {
			add(res, multi(a[i], p));
			p = multi(p, 10);
		}
	}
	return res;
}

int f(int l, vector<int> const& b) {
	int res = 0;
	int p = 1;
	for (int i = 0; i<max(l,int(b.size())); ++i) {
		if (i < b.size()) {
			add(res, multi(b[i], p));
			p = multi(p, 10);
		}
		if (i < l) {
			p = multi(p, 10);
		}
	}
	return res;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr;
  vector<int> of_len(MAXL);
  for(int i=0;i<n;i++){
    int tmp,l=0;
    cin>>tmp;
    arr.push_back(tmp);
    while(tmp>0){
      l++;
      tmp/=10;
    }
    of_len[l]++;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    vector<int>digits;
    int tmp=arr[i];
    while(tmp){
      digits.push_back(tmp%10);
      tmp/=10;
    }
    for(int j=1;j<MAXL;j++){
      int sum=f(digits,j);
      add(ans,multi(sum,of_len[j]));
      sum=f(j,digits);
      add(ans,multi(sum,of_len[j]));
    }
  }
  cout<<ans<<endl;
}
