#include<stdio.h>

struct f{
  int freq;
  int min;
};

int main(){
  int n;
  scanf("%d",&n);
  int c[n];
  f x[n];
  for(int i=0;i<n;i++){
    x[i].freq=0;
  };
  int max_dist=0;
  for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
    int tmp=c[i];
    if(x[tmp].freq==0){
      x[tmp].freq++;
      x[tmp].min=i;
    }
    else{
      if(i-x[tmp].min>max_dist){
        max_dist=i-x[tmp].min;
        printf("%d  ",i);
      }
      x[tmp].min=i;
    }
  }
  printf("%d\n",max_dist);
}
