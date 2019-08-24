#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int size;
    scanf("%d",&size);
    getchar();
    char x[2*size - 2];
    gets(x);
    printf("Case #%d: ",i+1);
    for(int j=0;j<2*size - 2;j++){
      if(x[j]=='E'){
        printf("S");
      }
      else{
        printf("E");
      }
    }
    printf("\n");
  }
}
