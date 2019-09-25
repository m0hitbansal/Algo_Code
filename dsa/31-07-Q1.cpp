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
  int x;
  cin>>x;
  sort(arr,arr+n);
  int l=0,r=n-1,flag=1;
  while(l<=r){
    if((arr[l]+arr[r])==x){
      cout<<arr[l]<<" "<<arr[r];
      flag=0;
      break;
    }
    else if((arr[l]+arr[r])<x)
      l++;
    else
      r--;
  }
  if(flag)
  cout<<"not found";
}
