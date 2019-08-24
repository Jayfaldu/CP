#include<bits/stdc++.h>
using namespace std;
#define syn ios_base::sync_with_stdio(false)


int main(){
  syn;
  string s;
  cin>>s;
  int tab=0;
  for(int i=0;i<s.size();){
    while(s[i]!='>' && s[i]!='/') i++;
    if(s[i]=='>'){
      for(int i=0;i<tab;i++) cout<<" ";
      cout<<s[i-2]<<s[i-1]<<s[i]<<"\n";
      i++;
      tab+=2;

    }
    if(s[i]=='/'){
      tab-=2;
      for(int j=0;j<tab;j++) cout<<" ";
      cout<<s[i-1];
      while(s[i]!='>') cout<<s[i++];
      cout<<">\n";
      i++;
    }

  }
}
