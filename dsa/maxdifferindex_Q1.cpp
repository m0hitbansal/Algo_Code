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
  int max=INT_MIN,maxi,min=INT_MAX,mini;
 for(int i=0;i<n;i++){
   if(arr[i]>max){
     max=arr[i];
     maxi=i;
   }
   else if(arr[i]<min){
     min=arr[i];
     mini=i;
   }
 }
 cout<<mini<<" "<<maxi<<" max differencer "<<(max-min);
}
