#include<bits/stdc++.h>

struct data{
  int freq;
  int index;
};

int main(){
  int test;
  scanf("%d",&test);

  for(int i=0;i<test;i++){
    int n,q;
    scanf("%d %d",&n,&q);
    data north,east;
    north.freq=0,north.index=q+1;
    east.freq=0,east.index=q+1;
    int north_mem[q+1];
    int east_mem[q+1];
    memset(north_mem,0,sizeof(north_mem));
    memset(east_mem,0,sizeof(east_mem));

    while(n>0){
      int x,y;
      char dir;
      scanf("%d %d %c",&x,&y,&dir);
      if(dir=='N'){
        for(int j=y+1;j<=q;j++)
        north_mem[j]++;
      }
      else if(dir=='S'){
        for(int j=y-1;j>=0;j--)
        north_mem[j]++;
      }
      else if(dir=='E'){
        for(int j=x+1;j<=q;j++)
        east_mem[j]++;
      }
      else{
        for(int j=x-1;j>=0;j--)
        east_mem[j]++;
      }
      n--;
    }
    north.freq=north_mem[0],north.index=0;
    east.freq=east_mem[0],east.index=0;
    // for(int j=0;j<=q;j++)printf("%d  ",north_mem[j]);
    // printf("\n");
    // for(int j=0;j<=q;j++)printf("%d  ",east_mem[j]);
    // printf("\n");
    for(int j=1;j<=q;j++){
      if(north_mem[j]>north.freq){
        north.freq=north_mem[j];
        north.index=j;
      }
      if(east_mem[j]>east.freq){
        east.freq=east_mem[j];
        east.index=j;
      }
    }
    printf("Case #%d: %d %d\n",i+1,east.index,north.index);
  }

  return 0;
}
