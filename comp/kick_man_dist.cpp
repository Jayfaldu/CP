#include<bits/stdc++.h>

using namespace std;

bool shop[250][250];

struct data{
  int row;int tmp_row=(max_distance.row+tmp_distance.row)/2;
  int col;
  int distance;
};



int find_shop_distance(int rows,int cols){
  int tmp_row;
  int tmp_col;
  data max_distance=find_distance(rows,cols);
  shop[max_distance.row][max_distance.col]=1;
  while(1){
    data tmp_distance=find_distance(rows,cols);
    if((max_distance.row-tmp_distance.row)%2==0 || (max_distance.col-tmp_distance.col)%2==0){
      tmp_row=(max_distance.row+tmp_distance.row)/2;
      tmp_col=(max_distance.col+tmp_distance.col)/2;
    }
    else{

    }
    if(tmp_distance)
  }
}

int main(){
  int test_case;
  cin>>test_case;
  for(int k=0;k<test_case;k++){
    int rows,cols;
    cin>>rows>>cols;
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
        cin>>shop[i][j];
      }
    }
    max_distance=find_shop_distance(rows,cols)
  }


}
