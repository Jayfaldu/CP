#include<bits/stdc++.h>
#define syn ios_base::sync_with_stdio(false)
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pii>
#define vpl vector<pll>

using namespace std;
int a[10];

int main(){
  syn;
 int n;
 scanf("%d",&n);
 int left=0;
 int right=9;
 getchar();
 for(int i=0;i<n;i++){
   char tmp;
   scanf("%c",&tmp);
   if(tmp=='L'){
     for(int i=0;i<10;i++){
       if(!a[i]){a[i]=1;break;}
     }
   }
   else if(tmp=='R'){
     for(int i=9;i>=0;i--){
       if(!a[i]) {a[i]=1;break;}
     }
   }
   else{
     a[tmp-'0']=0;
   }
 }
 for(int i=0;i<10;i++) printf("%d",a[i]);
 printf("\n");
 return 0;
}
