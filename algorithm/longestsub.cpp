#include<stdio.h>
#include<algorithm>



void LCS(int b[1000][1000],int c[1000][1000],char x[],char y[],int m,int n){
  for(int i=0;i<=m;i++){
    c[i][0]=0;
  }
  for(int i=0;i<=n;i++){
    c[0][i]=0;
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(x[i]==y[j]){
        c[i][j]=c[i-1][j-1]+1;
        b[i][j]=1;
      }
      else if(c[i-1][j]>c[i][j-1]){
      c[i][j]=c[i-1][j];
      b[i][j]=2;
      }
      else{
        c[i][j]=c[i][j-1];
        b[i][j]=3;
      }
    }
  }
}

int print_LCS(int b[1000][1000],char x[],int m,int n){
  if(m==0 || n==0){
    return 0;
  }
  if(b[m][n]==1){
    print_LCS(b,x,m-1,n-1);
    printf("%c",x[m]);
  }
  else if(b[m][n]==2){
    print_LCS(b,x,m-1,n);
  }
  else{
    print_LCS(b,x,m,n-1);
  }
}

int main(){
  printf("enter the length of first sequence:");
  int m;

  scanf("%d",&m);
  char x[m+1];
  getchar();
  for(int i=1;i<=m;i++){
    scanf("%c",&x[i]);
  }
  getchar();
  printf("enter the length of second sequence:");
  int n;
  scanf("%d",&n);
  getchar();

  char y[n+1];
  for(int i=1;i<=n;i++){
    scanf("%c",&y[i]);
  }
  int c[1000][1000];
  int b[1000][1000];
  LCS(b,c,x,y,m,n);
  printf("%d\n",c[m][n]);
  print_LCS(b,x,m,n);
  printf("\n");
}
