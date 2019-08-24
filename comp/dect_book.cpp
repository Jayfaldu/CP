#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int a[n+1];
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  int count=0;
  for(int i=1;i<=n;i++){
    int tmp=a[i];
    int j=i;
    while(j!=tmp){
      if(tmp<a[++j]){
        tmp=a[j];
      }
    }
    i=j;
    count++;
  }
  printf("%d\n",count);
}
