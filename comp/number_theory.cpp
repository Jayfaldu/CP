#include<bits/stdc++.h>

using namespace std;

long long power(int x,int m){
  if(m==0) return 1;
  else if(m%2==0) return power(x*x,m/2);
  else return power(x*x,(m-1)/2)*x;
}

long long mod_exp(int x,int m,int n){
  if(m==0) return 1;
  else if(m%2)  return (x*mod_exp((x*x)%n,(m-1)/2,n))%n;
  else return mod_exp((x*x)%n,m/2,n);
}

int gcd(int a,int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

int d,x,y;
void extended_euclid(int a,int b){
  if(b==0) d=a,x=1,y=0;
  else{
    extended_euclid(b,a%b);
    int tmp =x;
    x=y;
    y=tmp-(a/b)*y;
  }
}

int mod_inverse(int a,int m){ // where a and n are coprime
  extended_euclid(a,m);
  return (x%m+m)%m;
}

int euler_totient(int n){ //to find the no. of relatively prime no. with n less than namespae {
  int result =n;
  for(int i=2;i*i<=n;i++){
    if(n%i==0) result -=result/i;
    while(n%i==0) n/i;
  }
  if(n>1) result -=result/n;
  return result;
}


vector<vector<int>> matrix_multipy(int a[3][3],int b[3][3]){
  vector<vector<int>> mul;
  for(int i=0;i<3;i++){
    mul.push_back({});
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      mul[i].push_back(0);
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        mul[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
  return mul;
}

// int** pow_matrix(int X[3][3],int n){
//   if(n==1) return X;
//   else if(n%2){
//     return matrix_multipy(pow(matrix_multipy(X,X),(n-1)/2)),X);
//   }
//   else return pow_matrix(matrix_multipy(X,X),n/2);
// }

main(){
  cout<<"hello";
}
