#include<bits/stdc++.h>

using namespace std;


int decimal(int x,int num){
  int i=0;
  int dec_num=0;
  int rem;
  while(num!=0){
    rem=num%10;
    num/=10;
    dec_num+=rem*pow(x,i++);
  }
  return dec_num;
}

void to_y(int y,int num){
  int a[10],i=0;

  while(num>0){
    a[i]=num%y;
    num/=y;
    i++;
  }
  for(int j=i-1;j>=0;j--) cout<<a[j];
  cout<<endl;
}

int main(){
  int x;
  int num1,num2;
  scanf("%d%d%d",&x,&num1,&num2);
  printf("+:1\n-:2\n*:3\n/-4\n0-exit\n");
  while(1){
    int i;
    scanf("%d",&i);
    switch(i){
      case 1:
        {int ans=decimal(x,num1)+decimal(x,num2);
        to_y(x,ans);
        break;
        }
      case 2:
        {int ans=decimal(x,num1)-decimal(x,num2);
        if(ans<0){
          cout<<"-";
          to_y(x,-1*ans);
        }
        else to_y(x,ans);
        break;
        }
      case 3:
        {int ans=decimal(x,num1)*decimal(x,num2);
        to_y(x,ans);
        break;}
      case 4:
        {int ans=decimal(x,num1)/decimal(x,num2);
        if(ans>0) to_y(x,ans);
        cout<<"0\n";
        break;}
      case 0:
        return 0;
    }
  }
}
