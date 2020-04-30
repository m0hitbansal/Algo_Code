#include<iostream>
#include<climits>
using namespace std;
int main(){
  FILE *fp = fopen("test1.txt","r");
  int t;  fscanf(fp,"%d",&t);
  while(t--){
    int n,l;  fscanf(fp,"%d %d",&n,&l);
    int arr[n+5];
    for(int i=0;i<n;i++) fscanf(fp,"%d",&arr[i]);
  int min =INT_MIN, max=INT_MIN,i=0;

 for(int j=l;j<n;j++){
   if(arr[j]-arr[i]>max){
     max=arr[j]-arr[i];
   }
  if(arr[i]>arr[j-l+1]){
    i=j-l+1;
  }
 }
 cout<<" max differencer "<<max<<endl;
}
}
