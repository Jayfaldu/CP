#include<stdio.h>
#include<math.h>

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;n++){
    long long int k;
    scanf("%lld",&k);
    int digits[17];
    int j=0;
    while(k>0){
      digits[j++]=k%10;
      k=k/10;
    }
    j--;
    int f=0;
    while(f==0 && j>=0){
        if(digits[j--]%2!=0){
          f=1;
        }
    }
    j++;
    long long int ans_upr=(digits[j])*(pow(10,j+1));
    long long int ans_low=(digits[j])*(pow(10,j+1));
    for(int l=1;l<=j;l++){
      ans_low+=8*pow(10,l);
    }
    long long int mid=(ans_upr+ans_low)/2;
    long long int num=digits[j--]*pow(10,j+1);
    while(j>=0){
      num+=digits[j--]*pow(10,j+1);
    }
    if(num>mid){
      print("%lld\n",ans_upr-num);
    }
    else{
      print("%lld\n",num-ans_low);
    }
  }
}
