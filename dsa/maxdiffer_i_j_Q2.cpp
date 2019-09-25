#include<iostream>
#include<climits>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int max=INT_MIN,i=0;
 for(int j=1;j<n;j++){
   if(arr[j]-arr[i]>max){
     max=arr[j]-arr[i];
   }
  if(arr[i]>arr[j]){
    i=j;
   }
 }
 cout<<" max differencer "<<max;
}
