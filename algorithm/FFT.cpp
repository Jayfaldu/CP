#include<iostream>
#include<complex>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const double value=M_PI*2;

 vector<complex<double>> FFT(int a[],int n,complex<double> omegan){
  if(n==1){
    printf("HELP\n");
    vector<complex<double>> tmp;
    complex<double> idk (a[0],0);
    tmp.push_back(idk);
    return tmp;
  }
  else{
    printf("IN\n");
    int m=n/2;
    int a_even[m];
    int a_odd[m];
    printf("ROLL\n");
    for(int i=0;i<n;){
      static int j=0;
      a_even[j++]=a[i];
      i=i+2;
    }
    for(int i=1;i<n;){
      static int k=0;
      a_odd[k++]=a[i];
      i=i+2;
    }
    complex<double> x (1,0);
    vector< complex<double> >y_even=FFT(a_even,n/2,pow(omegan,2));
    vector< complex<double> >y_odd=FFT(a_odd,n/2,pow(omegan,2));
    vector<complex<double>> answer;
    complex<double> timepass (0,0);
    for(int j=0;j<n;j++){
      answer.push_back(timepass);
    }
    for(int j=0;j<n/2;j++){
        answer[j]=y_even[j]+x*y_odd[j];
        answer[j+n/2]=y_even[j]-x*y_odd[j];
        x=x*omegan;
    }
    printf("CANT\n");
    return answer;
  }
}

 vector<complex<double>> reverse_FFT(vector<complex<double>> a,int n,complex<double> omegan){
 complex<double> timepass (0,0);
 if(n==1){
   vector<complex<double>> tmp;
   tmp.push_back(a[0]);
   return tmp;
 }
 else{
   int m=n/2;
   vector<complex<double>> a_even;
   vector<complex<double>> a_odd;
   for(int i=0;i<m;i++){
     a_even.push_back(timepass);
     a_odd.push_back(timepass);
   }
   for(int i=0;i<n;){
     static int j=0;
     a_even[j++]=a[i];
     i=i+2;
   }
   for(int i=1;i<n;){
     static int k=0;
     a_odd[k++]=a[i];
     i=i+2;
   }
   complex<double> x (1,0);
   vector< complex<double> >y_even=reverse_FFT(a_even,n/2,pow(omegan,2));
   vector< complex<double> >y_odd=reverse_FFT(a_odd,n/2,pow(omegan,2));
   vector<complex<double>> answer;

   for(int j=0;j<n;j++){
     answer.push_back(timepass);
   }
   for(int j=0;j<n/2;j++){
       answer[j]=y_even[j]+x*y_odd[j];
       answer[j+n/2]=y_even[j]-x*y_odd[j];
       x=x*omegan;
   }
   return answer;
 }
}


int main(){
  printf("enter the degree of polynomial:");
  int n;
  scanf("%d",&n);
  printf("enter the coeffeicent of 1st polynomial:");
  int a[n+1];
  int b[n+1];
  for(int i=0;i<=n;i++){
    scanf("%d",&a[i]);
  }
  printf("enter the second polynomial:");
  for(int i=0;i<=n;i++){
    scanf("%d",&b[i]);
  }
  complex<double> omega (cos(M_PI/(n+1)),sin(M_PI/(n+1)));
  vector<complex<double>> y1;
  vector<complex<double>> y2;
  printf("HELLO\n");
  vector<complex<double>> y;
  cout<<omega<<endl;
  y1=FFT(a,2*(n+1),omega);
  printf("DEEP\n");
  for(int i=0;i<2*n+2;i++){
    cout<<y1[i]<<endl;
  }
  y2=FFT(b,2*(n+1),omega);
  complex<double> timepass (0,0);
  for(int i=0;i<2*n+2;i++){
    y.push_back(timepass);
  }
  for(int i=0;i<2*n+2;i++){
    y[i]=y1[i]*y2[i];
  }
  complex<double> com_omega (cos(M_PI/(n+1)),-sin(M_PI/(n+1)));
  vector<complex<double>> x;
  x=reverse_FFT(y,2*(n+1),com_omega);
  for(int i=0;i<2*n+2;i++){
    printf("%lf",real(x[i]));
  }
  return 0;
}
