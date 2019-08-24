#include<bits/stdc++.h>

using namespace std;

vector <string> ss;
vector <char> ans;

bool find_resp(int n,int length,int z){
  vector<string> :: iterator it;
  set<char> tmp;
  for(it=ss.begin();it!=ss.end();it++){
    tmp.insert((*it)[z]);
    if(tmp.size()>2){
      return 0;
    }
  }

  char tmp1=*tmp.begin();
  char tmp2=*(tmp.begin())+1;
  cout<<*tmp.begin();
  cout<<*tmp.end()<<endl;
  if(tmp1=='P'){
    if(tmp2=='R'){
      cout<<"hello";
      ans.push_back('P');
      for(it=ss.begin();it!=ss.end();it++){
        if((*it)[z]=='R'){
          ss.erase(it);
        }
      }
      return 1;
    }
    else if(tmp2=='S'){
      cout<<"heeee";
      ans.push_back('S');
      for(it=ss.begin();it!=ss.end();it++){
        if((*it)[z]=='P'){
          ss.erase(it);
        }
      }
      return 1;
    }
    else{
      cout<<"hiiii";
      ans.push_back('S');
      ss.clear();
      return 1;
    }
  }
  if(tmp1=='R'){
    if(tmp2=='S'){
      cout<<"kaaaaa";
      ans.push_back('R');
      for(it=ss.begin();it!=ss.end();it++){
        if((*it)[z]=='S'){
          ss.erase(it);
        }
      }
      return 1;
    }
    else{
      cout<<"haaaaaa";
      ans.push_back('P');
      ss.clear();
      return 1;
    }
  }
  if(tmp1=='S'){
    cout<<"lol";
    ans.push_back('R');
    ss.clear();
    return 1;
  }
}


int main(){
  int test;
  cin>>test;
  for(int i=1;i<=test;i++){
    int n;
    cin>>n;
    getchar();
    for(int j=0;j<n;j++){
      string tmp;
      getline(cin,tmp);
      ss.push_back(tmp);
    }
    int flag=1;
    int length=ss[0].size();
    for(int j=0;j<length || !ss.empty();j++){
      int tmp=find_resp(n,length,j);
      if(tmp==0){
        flag=0;
        cout<<"hello"<<endl;
        break;
      }
    }
    if(flag==0){
      cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
    }
    else{
      cout<<"Case #"<<i<<": ";
      for(int j=0;j<ans.size();j++){
        cout<<ans[j];
      }
      cout<<endl;
    }
    ss.clear();
    ans.clear();
  }
}
