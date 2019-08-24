#include<stdio.h>
#include<stack>
#include<algorithm>

using namespace std;

struct index{
  int width;
  int index;
};

bool compare(index s1,index s2){
  return (s1.width < s2.width);
}

int main(){

  int n;
  scanf("%d",&n);
  index size[n];
  for(int i=0;i<n;i++){
    scanf("%d",&size[i].width);
    size[i].index=i+1;
  }
  sort(size,size+n,compare);
  int count=0;
  int ans[2*n];
  // for(int i=0;i<n;i++){
  //   printf("%d  %d\n",size[i].width,size[i].index);
  // }
  getchar();
  stack<int> fill;
  for(int i=0;i<2*n;i++){
    char x;
    scanf("%c",&x);
    if(x=='0'){
      ans[i]=size[count++].index;
      fill.push(ans[i]);
    }
    else{
      ans[i]=fill.top();
      fill.pop();
    }
  }
  for(int i=0;i<2*n;i++){
    printf("%d ",ans[i]);
  }
  return 0;
}
