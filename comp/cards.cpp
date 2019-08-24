#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  int a[n],b[n];
  int min,min_index;
  min=3000000;
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  for(int i=0;i<n;i++) {
    scanf("%d",&b[i]);
    if(b[i]<min && b[i]>0 && (i+2-b[i]>0)) min=b[i],min_index=i;
  }
  if(min>n){
     printf("%d\n",n);
     return 0;
   }
  int moves=0;//min_index+1-b[min_index]+1;
  int tmp=0;
  int flag=0;
  for(int j=min_index+1;j<n;j++){
    if(b[j]==0) {
      flag=1;
      continue;
    }
    if(j-min_index>b[j]-min) tmp=max((j-min_index-b[j]+min),tmp);
  }
  // printf("%d %d \n",tmp,min);
  if(tmp==0 && min==1 && flag==0){
    // printf("Hello");s
    int last=b[n-1];
    int tmp_flag=0;
    for(int i=0;i<min_index;i++){
      if(i+2>b[i]-last&&b[i]>0) tmp_flag=1;
    }
    int z=0;
    for(int i=min_index+1;i<n;i++){
      if(b[i]!=b[i-1]+1) z=1;
    }
    if(tmp_flag==1 || z==1) printf("%d\n",min_index+1+n);
    else printf("%d\n",min_index);
  }
  else printf("%d\n",min_index+2-b[min_index]+tmp+n);
}
