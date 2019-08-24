#include<stdio.h>
#include<string.h>

// int sq[5*10006][5*10006];

int main(){
  int test;
  scanf("%d",&test);
  for(int i=1;i<=test;i++){
    memset(sq,0,sizeof(sq));
    int n,r,c,sr,sc;
    scanf("%d%d%d%d%d",&n,&r,&c,&sr,&sc);
    sq[sr][sc]=1;
    char a[5*10004];
    scanf("%s",a);
    for(int i=0;i<n;i++){
      if(a[i]=='E'){
        while(sq[++sr][sc]!=0);
        sq[sr][sc]=1;
      }
      else if(a[i]=='W'){
        while(sq[--sr][sc]!=0);
        sq[sr][sc]=1;
      }
      else if(a[i]=='S'){
        while(sq[sr][++sc]!=0);
        sq[sr][sc]=1;
      }
      else if(a[i]=='N'){
        while(sq[sr][--sc]!=0);
        sq[sr][sc]=1;
      }
    }
    printf("Case #%d: %d %d",i,sr,sc);
  }
}
