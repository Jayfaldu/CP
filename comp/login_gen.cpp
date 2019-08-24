#include<bits/stdc++.h>

using namespace std;

void find_id(char first[],char last,char ans[]){
  char tmp=first[0];
  int count=0;
  int k=strlen(first);
  if(k>1){
    count=1;
    tmp=first[1];
  }
  for(int i=2;i<k;i++){
    if(first[i]<tmp){
      tmp=first[i];
      if(i>3){
        if(i!=k-1){
          count=i;
        }
      }
      else{
        count=i;
      }
    }
  }
  for(int j=0;j<=count;j++){
    ans[j]=first[j];
  }
  ans[count+1]=last;
  ans[count+2]='\0';
}

int main(){
  char first[11];
  char last[11];
  char ans[12];
  scanf("%s",first);
  scanf("%s",last);
  find_id(first,last[0],ans);
  printf("%s\n",ans);
}
