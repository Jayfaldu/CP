#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(pair<ll,ll> p1,pair<ll,ll> p2){
     if(p1.second!=p2.second)
    return p1.second>p2.second;
    return p1.first>p2.first;
}
int main(){
    ll n,k,a,b;
    cin>>n>>k;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),compare);
    ll sum=0,ans=-1;
    priority_queue<ll,vector<ll>,greater<ll>>p;
    for(ll i=0;i<n;i++){
        sum+=v[i].first;
        p.push(v[i].first);
        while(p.size()>k){
            sum=sum-p.top();
            cout<<p.top()<<endl;
            p.pop();
        }
        ans=max(ans,sum*v[i].second);
    }
    cout<<ans<<endl;
}
