#include<iostream>
using namespace std;
int main(){
long int i=11122334;
//cout<<i<<endl;
int x;
int next;
long int sum=0;
long int  t=1;
while(i>0){
  x=i%10;
  i/=10;
  next =i%10;
  if(next!=x){
    sum+=x*t;
  }
  t*=10;
}
//sum+=x*t;
cout<<sum;
}
