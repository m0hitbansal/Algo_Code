#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  sort(arr,arr+n);
  int l=0,r=n-1,flag=1;
  for(int i=0;i<n;i++){
    flag=1;
    l=0;
    r=n-1;
  while(l<r){
    if((arr[l]+arr[r])==arr[i]){
      cout<<arr[l]<<" + "<<arr[r]<<"="<<arr[i]<<endl;
      flag=0;
      l++;
      r--;
    }
    else if((arr[l]+arr[r])<arr[i])
      l++;
    else
      r--;
  }
}
  if(flag)
  cout<<"not found";
}
