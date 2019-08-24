#include<stdio.h>
#include<math.h>

struct coord{
  int x;
  int y;
};

int main(){
  coord locat;
  coord flag;
  scanf("%d %d",&locat.x,&locat.y);
  scanf("%d %d",&flag.x,&flag.y);
  if(locat.x==flag.x){
    locat.x+=1;
  }
  else if(locat.y==flag.y){
    locat.y+=1;
  }
  int ans;
  //printf("%d %d\n",abs(flag.x-locat.x),abs(flag.y-locat.y));
  ans=(abs(flag.x-locat.x)+2+abs(flag.y-locat.y))*2;
  printf("%d\n",ans);
}
