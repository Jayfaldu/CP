#include<stdio.h>
#include<math.h>


int answer(int s[],int n,int m){

  int ans[n+1][m];

  for(int i=0;i<m;i++){
    ans[0][i]=1;
  }

  for(int i=1;i<=n;i++){
    for(int j=0;j<m;j++){
      int x=0;
      int y=0;

      if(j-1>=0){
        x+=ans[i][j-1];
      }
      if(i-s[j]>=0){
        y+=ans[i-s[j]][j];
      }
      ans[i][j]=x+y;
    }
  }

  return ans[n][m-1];
}



int main(){
  printf("Enter the number of which you want to find the change");
  int n;
  scanf("%d",&n);
  printf("Enter the number of coins available");
  int m;
  scanf("%d",&m);
  printf("enter the values of coins");
  int s[m];
  int exist[n+1];
  for(int i=0;i<=n;i++){
    exist[i]=0;
  }
  for(int i=0;i<m;i++){
    scanf("%d",&s[i]);
    exist[s[i]]=1;
  }
  int ans[n+1];
  printf("ans-%d\n",answer(s,n,m));
  // for(int i=0;i<=n;i++){
  //   printf("%d\n",ans[i]);
  // }
  // printf("existance\n");
  // for(int i=0;i<=n;i++){
  //   printf("%d\n",exist[i]);
  // }
  return 0;
}
