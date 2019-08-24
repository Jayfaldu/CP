#include<stdio.h>

int main(){
  int test;
  scanf("%d",&test);
  getchar();
  for(int i=0;i<test;i++){
    char s[99];
    int j=0;
    char c=getchar();
    while(c!='\n'){
      s[j++]=c;
      c=getchar();
    }
    char s1[99];
    char s2[99];
    //printf("%c    \n",s[0]);
    for(int k=0;k<j;k++){
      if(s[k]=='4'){
        s1[k]=s[k]-1;
      }
      else{
        s1[k]=s[k];
      }
      s2[k]=s[k]-s1[k]+'0';
    }
    //printf("%c    he\n",s2[0]);
    s1[j]='\0';
    s2[j]='\0';
    printf("Case #%d: ",i+1);
    for(int k=0;k<j;k++){
      printf("%c",s1[k]);
    }
    printf(" ");
    int k=0;
    while(s2[k]=='0'){
      k++;
    }
    while(k<j){
      printf("%c",s2[k++]);
    }
    printf("\n");
  }
}
