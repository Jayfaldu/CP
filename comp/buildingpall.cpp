#include<bits/stdc++.h>
using namespace std;

int main(){
  int test;
  scanf("%d",&test);
  for(int i=0;i<test;i++){
    int length,querry,count=0;
    scanf("%d%d",&length,&querry);
    getchar();
    char str[length];
    for(int j=0;j<length;j++){
      scanf("%c",&str[j]);
    }
    puts(str);
    vector< vector<int> > freq;
    for(int i=0;i<26;i++){
      freq.push_back({});
    }
    printf("hello");
    for(int j=0;j<length;j++){
      freq[str[j]-'A'].push_back(j);
    }
    for(int j=0;j<querry;j++){
      int l,r;
      printf("hee");
      scanf("%d %d",&l,&r);
      int a[26];
      printf(" %d %d \n",l,r);
      memset(a,0,sizeof(a));
      for(int k=l-1;k<r;k++){
        printf("helo");
        int tmp=str[k]-'A';
        if(a[tmp]==0){
          int tmp_count=0;
          vector<int>::iterator it;
          for(it=freq[tmp].begin();it!=freq[tmp].end();it++){
            if(*it>=l-1){
              tmp_count++;
            }
            else if(*it>=r){
              break;
            }
          }
          if(tmp_count%2==0){
            a[tmp]=2;
          }
          else{
            a[tmp]=1;
          }
        }
        int flag=1;
        for(int z=0;z<26;z++){
          if(a[z]==1){
            z++;
            while(z<26){
              if(a[z]==1){
                flag=0;
                z++;
              }
            }
          }
        }
        if(flag==1){
          count++;
        }
      }
    }
    printf("Case #%d: %d",i+1,count);
  }
}
