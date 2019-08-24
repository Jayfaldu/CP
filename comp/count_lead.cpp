#include<bits/stdc++.h>

using namespace std;

// int find_len(string str,int len){
//   char x[len];
//   int count=0;
//   x[count++]=str[0];
//   for(int i=1;i<len;i++){
//     int flag=0;
//     char tmp = str[i];
//     for(int j=0;j<count;j++){
//       if(tmp==x[j] || tmp==' '){
//         flag=1;
//       }
//     }
//     if(flag==0){
//       x[count++]=str[i];
//     }
//   }
//   return count;
// }

int find_len(string str,int len){
  set<char> tmp;
  for(int i=0;i<len;i++){
    if(str[i]!=' '){
      tmp.insert(str[i]);
    }
  }
  return tmp.size();
}

int compare(string str1,string str2,int len){
  for(int i=0;i<len;i++){
    if(str1[i]!=str2[i]){
      return str1[i]-str2[i];
    }
  }
}


int main(){
  int n;
  cin>>n;
   for(int i=0;i<n;i++){
    int k;
    cin>>k;
    getchar();
    string leader;
    getline(cin,leader);
    int len=find_len(leader,leader.length());
    for(int i=1;i<k;i++){
      string tmp;
      getline(cin,tmp);
      int tmp_len=find_len(tmp,tmp.length());
      if(tmp_len>len){
          leader=tmp;
          len=tmp_len;
      }
      else if(tmp_len==len){
        if(compare(tmp,leader,len)<0){
          leader=tmp;
          len=tmp_len;
        }
      }
    }
    cout<<"Case #"<<i+1<<": "<<leader<<endl;
  }
}
