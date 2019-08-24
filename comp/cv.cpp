// #include<stdio.h>
//
// int main(){
//   int test;
//   scanf("%d",&test);
//   while(test--){
//     int n;
//     scanf("%d",&n);
//     char a[n];
//     int cnt=0;
//     getchar();
//     scanf("%c",&a[0]);
//     for(int i=1;i<n;i++){
//       scanf("%c",&a[i]);
//     }
//     printf("%d\n",cnt);
//   }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    scanf("%d",&test);
    while(test--){
        string s;
        cin>>s;
        int len=s.size();
        int count[26];
        memset(count,0,sizeof(count));
        for(int i=0;i<len;i++){
            count[s[i]-'a']++;
        }
        int odd=0;
        for(int i=0;i<26;i++){
            if(count[i]%2==1) odd++;
        }

        if(s.size()%2==1 && (odd==3 ||odd=1)){
          cout<<"DPS"<<endl;
        }
        else if(s.size()%2==0&&odd==2){
            cout<<"DPS"<<endl;
        }
        else{
            cout<<"!DPS"<<endl;
        }
    }
	return 0;
}
