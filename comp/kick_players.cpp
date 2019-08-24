#include<stdio.h>
#include<algorithm>

#define ll long long int

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int p,k;
    scanf("%d %d",&p,&k);
    int skill[p];
    for(int j=0;j<p;j++){
      scanf("%d",&skill[j]);
    }
    sort(skill,skill+p);
    float std[p-k+1];
    ll sum=0;
    ll min_time;
    for(int j=0;j<k;j++){
      sum+=skill[j];
    }
    min_time=(skill[k-1]*k)-sum;
    for(int j=1;j<=p-k;j++){
      sum=sum+skill[j+k-1]-skill[j-1];
      min_time=min(min_time,(skill[j+k-1]*k - sum));
    }
    printf("Case #%d: %lld\n",i+1,min_time);
  }
}
