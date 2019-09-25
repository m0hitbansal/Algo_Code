#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main(){
  int n,l;
  cin>>n>>l;
  vector<int>v;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int max=INT_MIN,i=0;
  v.push_back(0);
  int r=0,a=0;
 for(int j=1;j<n;j++){
   if(j-l>i){
     a++;
     i=v[a];
   }
   if(arr[j]-arr[i]>max){
     max=arr[j]-arr[i];
   }
   r=v.size()-1;
  while(r>=i&&arr[v[r]]>arr[j]){
    v.pop_back();
    r--;
  }
  v.push_back(j);
 }
 cout<<" max differencer "<<max;
}
