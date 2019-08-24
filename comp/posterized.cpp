// #include<bits/stdc++.h>
//
// using namespace std;
//
// struct groups{
//     int start;
//     int end;
//     bool operator<(const groups& t) const
//     {
//         return (this->start < t.end);
//     }
// };
//
// set<groups> record;
// int count=0;
//
//
//
// int find_key(int find_key,int k){
//   groups tmp;
//   tmp.start=-1;
//   tmp.end=257;
//   if(record.empty()){
//     tmp.start=find_key-k+1;
//     tmp.end=find_key;
//     record.insert(tmp);
//     //printf("hee\n");
//     return tmp.start;
//   }
//   else{
//     set<groups> ::iterator it;
//     for(it=record.begin();it!=record.end();it++){
//       if((find_key>(*it).end) && ((*it).end>tmp.start)){
//         tmp.start=(*it).end +1;
//       }
//       else if(find_key<(*it).start && ((*it).start<tmp.end)){
//         tmp.end=(*it).start -1;
//       }
//       else if (find_key>=(*it).start && find_key<=(*it).end){
//         tmp.end=(*it).end;
//         tmp.start=(*it).start;
//         //printf("hella\n");
//         return (*it).start;
//       }
//       if(tmp.end-tmp.start<k){
//         break;
//       }
//     }
//     if(tmp.end-tmp.start<k){
//       record.insert(tmp);
//       //printf("poo\n");
//       return tmp.start;
//     }
//     else{
//       if(find_key-k<=tmp.start){
//         tmp.end=tmp.start+k-1;
//         record.insert(tmp);
//         //printf("heaa\n");
//         return tmp.start;
//       }
//       else{
//         tmp.start=find_key-k+1;
//         tmp.end=find_key;
//         record.insert(tmp);
//         //printf("hekko\n");
//         return tmp.start;
//       }
//     }
//   }
// }
//
// int start_key(int find_key,int k){
//   groups tmp;
//   tmp.start=0;
//   tmp.end=256;
//   set<groups> ::iterator it;
//   if(record.empty()){
//     tmp.end=find_key;
//     //printf("%d %d\n",tmp.start,tmp.end);
//     record.insert(tmp);
//     //printf("baaa\n");
//     return 0;
//   }
//   else{
//     for(it=record.begin();it!=record.end();it++){
//       if(find_key>=(*it).start && find_key<=(*it).end){
//         return (*it).start;
//       }
//     }
//     for(it=record.begin();it!=record.end();it++){
//       if((*it).start==0){
//         record.erase(it);
//         tmp.start=0;
//         tmp.end=find_key;
//         record.insert(tmp);
//         return 0;
//       }
//     }
//   }
// }
//
// int main(){
//   int n;
//   int k;
//   set<groups> record;
//   scanf("%d %d",&n,&k);
//   int pixels[n];
//   for(int i=0;i<n;i++){
//     scanf("%d",&pixels[i]);
//   }
//   set<groups> ::iterator itf;
//   itf=record.begin();
//   for(int i=0;i<n;i++){
//     if(pixels[i]<k){
//       pixels[i]=start_key(pixels[i],k);
//     }
//     else{
//       pixels[i]=find_key(pixels[i],k);
//     }
//   }
//   for(int i=0;i<n;i++){
//     printf("%d ",pixels[i]);
//   }
// }


#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  int key[256];
  memset(key,-1,sizeof(key));
  for(int i=0;i<n;i++){
    int tmp;
    scanf("%d",&tmp);
    if(key[tmp]==-1){
      for(int j=max(0,tmp-k+1);j<=tmp;j++){
        if(key[j]==-1 || key[j]==j){  
          for(int k=j;k<=tmp;k++){
            key[k]=j;
          }
          break;
        }
      }
    }
    printf("%d ",key[tmp]);
  }
}
