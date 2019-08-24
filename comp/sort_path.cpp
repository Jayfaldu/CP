#include <bits/stdc++.h>

using namespace std;
int n,adj[101][101],m,p[1000010],ans,x[1000010];
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>s;
       for(int j=1;j<=n;j++)
       {
           adj[i][j]=(s[j-1]-'0');
       }
   }
   cin>>m;
   for(int i=1;i<=m;i++)
   {
       cin>>p[i];
   }
   for(int i=2;i<m;i++)
   {
       if(!adj[p[i-1]][p[i+1]] && p[i-1]!=p[i+1])
       {
           ans++;
           x[i]=true;
           i++;
       }
   }
   cout<<m-ans<<endl;
   for(int i=1;i<=m;i++)
   {
       if(!x[i])
        cout<<p[i]<<" ";
   }



     return 0;
}
