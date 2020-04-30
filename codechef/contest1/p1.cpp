#include<iostream>
using namespace std;
int  main() {
  int t;
  cin>>t;
  while(t>0){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int max=0;
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    for(int i=0;i<n;i++){
      cin>>b[i];
    }
    for(int i=0;i<n;i++){
      int x;
      x=a[i]*20-b[i]*10;
      if(x<0){
        x=0;
      }
      if(max<=x)
      max=x;
    }
    cout<<max<<endl;
    t--;
  }
  return 0;
}
