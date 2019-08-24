#include<iostream>
#include<vector>

using namespace std;

bool find_sum(int set[],int sum,int n){

  bool subset_sum[n+1][sum+1];
  for(int i=0;i<=n;i++){
    subset_sum[i][0]=true;
  }
  for(int i=1;i<=sum;i++){
    subset_sum[0][i]=false;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
      if(j==set[i-1]){
        subset_sum[i][j]=true;
      }
      else{
        subset_sum[i][j]=(subset_sum[i-1][j] || subset_sum[i-1][j-(set[i-1]%j)]);
      }
    }
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=sum;j++){
      cout<<subset_sum[i][j];
    }
    cout<<endl;
  }

  return subset_sum[n][sum];

}

int main(){

  cout<<"Enter the size of the set:";
  int n;
  cin>>n;
  cout<<"Enter the set elements:";
  int set[n];
  for(int i=0;i<n;i++){
    cin>>set[i];
  }
  cout<<"Enter the sum:";
  int sum;
  cin>>sum;
  cout<<find_sum(set,sum,n)<<endl;

  return 0;
}
