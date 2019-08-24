#include<bits/stdc++.h>

using namespace std;
int data[200001],freq[200001],s1[200001],s2[200001];

int main(){
  int n;
  memset(freq,0,sizeof(freq));
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  int count1=0;
  int count2=0;
  int flag=0;
  for(int i=0;i<n;i++){
    if(freq[data[i]]==0){
      freq[data[i]]+=1;
      s1[count1++]=data[i];
    }
    else if(freq[data[i]]==1){
      freq[data[i]]+=1;
      s2[count2++]=data[i];
    }
    else{
      flag=1;
      break;
    }
  }
  if(flag==1){
    printf("NO\n");
  }
  else{
    printf("Yes\n");
    printf("%d\n",count2);
    sort(s2,s2+count2);
    for(int i=0;i<count2;i++){
      printf("%d ",s2[i]);
    }
    printf("\n");
    printf("%d\n",count1);
    sort(s1,s1+count1);
    for(int i=count1-1;i>=0;i--){
      printf("%d ",s1[i]);
    }
    printf("\n");
  }
}
