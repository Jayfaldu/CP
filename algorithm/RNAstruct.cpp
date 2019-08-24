#include<stdio.h>
#include<algorithm>

using namespace std;
int ans[1000][1000];

int maximum(int x,int y,int z){
  if(x>y){
    return max(x,z);
  }
  else{
    return max(y,z);
  }
}

void max_struct(char a[],int n){
  for(int k=5;k<=n;k++){
    for(int i=1;i<=n-k;i++){
      int j=i+k;
      ans[i][j]=0;
      if(a[j]=='A'){
        for(int l=i;l<=j-5;l++){
          if(a[l]=='U'){
            ans[i][j]=maximum(ans[i][j-1],ans[i][l-1]+ans[l+1][j-1]+1,ans[i][j]);
          }
        }
      }
      if(a[j]=='U'){
        for(int l=i;l<=j-5;l++){
          if(a[l]=='A'){
            ans[i][j]=maximum(ans[i][j-1],ans[i][l-1]+ans[l+1][j-1]+1,ans[i][j]);
          }
        }
      }
      if(a[j]=='C'){
        for(int l=i;l<=j-5;l++){
          if(a[l]=='G'){
            ans[i][j]=maximum(ans[i][j-1],ans[i][l-1]+ans[l+1][j-1]+1,ans[i][j]);
          }
        }
      }
      if(a[j]=='G'){
        for(int l=i;l<=j-5;l++){
          if(a[l]=='C'){
            ans[i][j]=maximum(ans[i][j-1],ans[i][l-1]+ans[l+1][j-1]+1,ans[i][j]);
          }
        }
      }
    }
  }
}

int main(){
  int n;
  printf("Enter the length of DNA structure:");
  scanf("%d",&n);
  getchar();
  char a[n+1];
  for(int i=1;i<=n;i++){
    scanf("%c",&a[i]);
  }
  max_struct(a,n);
  printf("%d\n",ans[1][n]);
  return 0;
}
