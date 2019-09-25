#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int x=arr[0];
  int c=1;
  for(int i=1;i<n;i++){
    if(x==arr[i])
    c++;
    else if(c>0)
    c++;
    else{
      x=arr[i];
      c=1;
    }
  }
  c=0;
  for(int i=0;i<n;i++){
    if(x==arr[i])
    c++;
  }
  if(c>=(n/2+1)){
    cout<<"majority element is "<<x;
  }
  else
  cout<<"there is no majority  element";
  return 0;
}
