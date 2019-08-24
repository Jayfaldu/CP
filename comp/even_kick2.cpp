#include<stdio.h>
#include<math.h>

// int beautiful_num(long long int k){
//   int digits[17];
//   int j=0;
//   while(k>0){
//     digits[j++]=k%10;
//     k=k/10;
//   }
//   j--;
//   int f=0;
//   while(f==0 && j>=0){
//     if(digits[j--]%2!=0){
//         f=1;
//     }
//   }
//   return f;
// }


int main(){
  int n;
  scanf("%d",&n);
  //printf("%d           ",n);
  for(int i=0;i<n;i++){
    long long int k;
    scanf("%lld",&k);
    int digits[17];
    int length;
    int j=0;
    while(k>0){
      digits[j++]=k%10;
      length++;
      k=k/10;
    }
    j--;
    int f=0;
    while(f==0 && j>=0){
      if(digits[j--]%2!=0){
          f=1;
      }
    }
    if(f==0){
      printf("case #%d: %d\n",i+1,0);
    }
    else{
      j++;
      if(digits[j]==9){
        if(j+1==length || (digits[j+1]==8 && j+1<length)){
          long long int ans_low=(digits[j]-1)*(pow(10,j));
          for(int l=0;l<j;l++){
            ans_low+=8*pow(10,l);
          }
          long long int num=digits[j--]*pow(10,j+1);
          while(j>=0){
            num+=digits[j--]*pow(10,j+1);
          }
          printf("case #%d: %lld\n",i+1,num-ans_low);
          continue;
        }
        else{
          long long int ans_upr=(digits[j+1]+2)*pow(10,j+1);
          long long int ans_low=(digits[j]-1)*(pow(10,j));
          for(int l=0;l<j;l++){
            ans_low+=8*pow(10,l);
          }
          long long int num=digits[j--]*pow(10,j+1);
          while(j>=0){
            num+=digits[j--]*pow(10,j+1);
          }
          long long int mid=(ans_upr+ans_low)/2;
          if(num>mid){
            printf("case #%d: %lld\n",i+1,ans_upr-num);
          }
          else{
            printf("case #%d: %lld\n",i+1,num-ans_low);
          }
          continue;
        }
      }
      //printf("%d  ",j);
      long long int ans_upr=(digits[j]+1)*(pow(10,j));
      //printf("upr-%lld  ",ans_upr);
      long long int ans_low=(digits[j]-1)*(pow(10,j));
      for(int l=0;l<j;l++){
        ans_low+=8*pow(10,l);
      }
      //printf("low-%lld  ",ans_low);
      long long int mid=(ans_upr+ans_low)/2;
      long long int num=digits[j--]*pow(10,j+1);
      while(j>=0){
        num+=digits[j--]*pow(10,j+1);
      }
      if(num>mid){
        printf("case #%d: %lld\n",i+1,ans_upr-num);
      }
      else{
        printf("case #%d: %lld\n",i+1,num-ans_low);
      }
    }
  }
}
