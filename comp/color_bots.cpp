#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct bots{
  char a;
  int visited;
  int index;
};

bool compare(bots b1,bots b2){
  return (b1.a>b2.a);
}

int main(){
  int n;
  vector<pair<int,int>> ans;
  scanf("%d",&n);
  getchar();
  bots b1[n];
  bots b2[n];
  for(int i=0;i<n;i++){
    scanf("%c",&b1[i].a);
    b1[i].visited=0;
    b1[i].index=i+1;
  }
  getchar();
  for(int i=0;i<n;i++){
    scanf("%c",&b2[i].a);
    b2[i].visited=0;
    b2[i].index=i+1;
  }
  int count=0;
  sort(b1,b1+n,compare);
  sort(b2,b2+n,compare);
  int j=0;
  int i=0;
  int flag=0;
  for(;i<n;i++){
    for(;j<n;j++){
      if(b2[j].a<b1[i].a){
        break;
      }
      if(b1[i].a==b2[j].a){
        ans.push_back(make_pair(b1[i].index,b2[j].index));
        b1[i].visited=1;
        b2[j].visited=1;
        i++;
        count++;
      }
      if(b2[j].a=='?' || b1[i].a=='?'){
        flag=1;
      //  printf("hee");
        break;
      }
    }
    if(flag==1 || j==n){
      break;
    }
  }
  if(flag!=1){
    //printf("%d\n",i);
    while(b1[i].a!='?' && i<n){
      i++;
    }
    //printf("%c",b1[i].a);
    //printf("hello");
  }
  if(b1[i].a=='?'){
    //printf("gandu");
    int z=0;
    for(;z<n && i<n;z++){
      if(b2[z].visited==0 && b1[i].visited==0){
        b2[z].visited=1;
        b1[i].visited=1;
        ans.push_back(make_pair(b1[i].index,b2[z].index));
        i++;
        count++;
      }
    }
    while(b2[z].a!='?' && z<n){
      z++;
    }
    for(int k=0;k<n && z<n;k++){
      if(b1[k].visited==0 && b2[z].visited==0){
        b1[k].visited=1;
        b2[z].visited=1;
        ans.push_back((make_pair(b1[k].index,b2[z].index)));
        z++;
        count++;
      }
    }
  }
  else if(b2[j].a=='?'){
    //printf("hellos\n");
    int z=0;
    for(;z<n && j<n;z++){
      if(b1[z].visited==0 && b2[j].visited==0){
        b1[z].visited=1;
        b2[j].visited=1;
        ans.push_back(make_pair(b1[z].index,b2[j].index));
        j++;
        //printf("hee");
        count++;
      }
    }
    while(b1[z].a!='?' && z<n){
      z++;
    }
    for(int k=0;k<n && z<n;k++){
      if(b2[k].visited==0 && b1[z].visited==0){
        b2[k].visited=1;
        b1[z].visited=1;
        ans.push_back((make_pair(b1[z].index,b2[k].index)));
        z++;
        printf("hl");
        count++;
      }
    }
  }
  printf("%d\n",count);
  for(int i=0;i<count;i++){
    printf("%d %d\n",ans[i].first,ans[i].second);
  }
}
