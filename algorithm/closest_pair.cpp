#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct coord{
  int x;
  int y;
};


float distance(int x1,int x2,int y1,int y2){
  return (sqrt(pow(x1-x2,2)+pow(y1-y2,2)));
}

bool compare_x(coord s1,coord s2){
  return (s1.x<s2.x);
}

bool compare_y(coord s1,coord s2){
  return (s1.y<s2.y);
}

float closest_distance(coord sx[],int start,int end){
  int mid=(start+end)/2;
  if(end-start<2){
    return distance(sx[start].x,sx[end].x,sx[start].y,sx[end].y);
  }
  if(end>start){
    float r1=closest_distance(sx,start,mid);
    float r2=closest_distance(sx,mid+1,end);
    float rmin=(r1>r2)?(r2):(r1);
    coord sy[end-start+1];
    int k=0;
    for(int i=start;i<=end;i++){
      if(abs(sx[mid].x-sx[i].x)<=rmin){
        sy[k].x=sx[i].x;
        sy[k].y=sx[i].y;
        k++;
      }
    }
    sort(sy,sy + k,compare_y);
    for(int i=0;i<=6 && abs(sy[i].y-sy[i+1].y)<rmin;i++){
      float dist=distance(sy[i].x,sy[i+1].x,sy[i].y,sy[i+1].y);
      if(rmin>dist){
        rmin=dist;
      }
    }
    return rmin;
  }
}

int main(){
  printf("enter the number of coordinates:\n");
  int n;
  scanf("%d",&n);
  coord points[n];
  for(int i=0;i<n;i++){
    printf("x:");
    scanf("%d",&points[i].x);
    printf("y:");
    scanf("%d",&points[i].y);
  }
  sort(points,points + n,compare_x);
  printf("%f",closest_distance(points,0,n));
}
