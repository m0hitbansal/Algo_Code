#include<iostream>
using namespace std;
int  main() {
  int t;
  cin>>t;
  while(t>0){
    long long int n,k,flag=1;
    cin>>n>>k;
    long long int l=n/k;
    long long int b[k]={0};
    long long int i=0;
  /*  while(n>0){
      b[i]+=k;
      i=(i+1)%k;
      n=n-k;
    }*/
    int m=l/k;
    if(l==(m*k))
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
    t--;
  }
  return 0;
}
