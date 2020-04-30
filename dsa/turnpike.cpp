#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,d;
vector<int>v;
vector<int>D[15];
void turnpike(int l,int r){
  if(check(l,r)){
    v[l]=
    l++;
    turnpike(l,r);
  }
  else if(check())
}
int main(){
  d=15;
  int x;
  n=(1+sqrt(1+(2*d)))/2;
  for(int i=0;i<d;i++){
    cin>>x;
    D[i][0]=x;
    D[i][1]=1;
  }
  v[0]=0;
  D[0][1]=0;
  D[0][14]=0;
  v[5]=D[14][0];
  int l=1,r=n-1;
  turnpike(l,r);
}
