#include<iostream>
using namespace std;
long long int check(long long int i,long long int n){

  long long int t=1,sum=0;
  int x;
  int next;
  while(i>0){
    x=i%10;
    i/=10;
    next =i%10;
    if(next!=x){
      sum+=x*t;
    }
    t*=10;
  }
  return sum;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    long long int nl,nr,l,r;
    long long int sum=0;
    cin>>nl>>l>>nr>>r;
    for(int i=l;i<=r;i++){

      sum+=check(i,nl);
      //cout<<sum<<endl;
    }
    cout<<sum<<endl;
  }
}
