#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int a=0,b=1023;
  for(int i=0;i<n;i++){
    // printf("%d ",i);
    char x;
    int tmp;
    getchar();
    scanf("%c %d",&x,&tmp);
    // printf("%c %d he  \n",x,tmp);
    if(x=='|') a|=tmp,b|=tmp;
    else if(x=='&') a&=tmp,b&=tmp;
    else a^=tmp,b^=tmp;
  }
  printf("2\n& %d\n^ %d",a^b,a);
}
