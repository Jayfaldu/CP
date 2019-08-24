// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int test;
//   scanf("%d",&test);
//   for(int j=0;j<test;j++){
//     int n;
//     scanf("%d",&n);
//     char a[n];
//     scanf("%c%c",&a[0],&a[1]);
//     int i=2;
//     while(1){
//       scanf("%c",&a[i]);
//       if(a[i]=='P') break;
//     }
//     int cnt=0;
//     for(int j=2;j<i;j++){
//       if(a[j]=='A' &&(a[j-1]=='P'||a[j-2]=='P')&&(a[j+1]=='P'||a[j+2]=='P'))
//       cnt++;
//     }
//     int tmp_cnt;
//     for(int j=i+1;j<n-2;){
//       tmp_cnt=0;
//       scanf("%c",&a[j]);
//       while(a[j++]=='A' && j<n-2 ){
//       scanf("%d",&a[j])
//       tmp_cnt++;
//       }
//       if(tmp_cnt==1 || tmp_cnt==3) cnt+=1;
//       else if(tmp_cnt==2) cnt+=2;
//     }
//
//   }
// }

#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int test;
    scanf("%d",&test);
    while(test--){
        ll n;
        scanf("%lld",&n);
        char ans[100];
        int i=0;
        while(n>0){
            ans[i++]=(n%10)+'0';
            n/=10;
        }
        int sum=0;
        for(int j=0;j<i;j++) sum+=(ans[j]-'0');
        // printf("%d\n",sum);
        for(int j=i-1;j>=0;j--) printf("%c",ans[j]);
        printf("%d\n",(10-(sum%10)));
    }
	return 0;
}
