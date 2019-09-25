#include<iostream>
#include <cstdlib>
using namespace std;
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}
int partition(int *arr,int l,int h){
  int k=arr[h];
	int i=l-1;

  for(int j=l;j<h;j++){
    if(arr[j]<=k){
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[h]);
  return i+1;
}
void quicksort(int *arr,int l,int h){
	if(l<h){
	int p=partition(arr,l,h);
	quicksort(arr,l,p-1);
	quicksort(arr,p+1,h);
}
}

int main(){
  int n1;
  cin>>n1;
  int arr[n1];
  cout<<"enter array";
  for(int i=0;i<n1;i++){
  	cin>>arr[i];
  } 
  quicksort(arr,0,n1-1);
  for(int i=0;i<n1;i++){
  	cout<<arr[i]<<" " ;
  } 
  cout << endl;
  return 0;
}