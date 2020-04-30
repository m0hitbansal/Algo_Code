#include<iostream>
#include <cstdlib>
using namespace std;
void merge(int *arr,int l,int m,int h){
	int n1=m-l+1;
	int n2=h-m;
	int a1[n1];
	int a2[n2];
	for(int i=0;i<n1;i++){
	a1[i]=arr[l+i];
	}
	for(int i=0;i<n2;i++){
	a2[i]=arr[m+1+i];
	}
	int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) 
    { 
        if (a1[i] <= a2[j]) 
        { 
            arr[k] = a1[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = a2[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = a1[i]; 
        i++; 
        k++; 
    } 
  while (j < n2) 
    { 
        arr[k] = a2[j]; 
        j++; 
        k++; 
    }
}
void mergesort(int *arr,int l,int h){
	if(l<h){
	int m=(h+l)/2;
	mergesort(arr,l,m);
	mergesort(arr,m+1,h);
	merge(arr,l,m,h);
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
  mergesort(arr,0,n1-1);
  for(int i=0;i<n1;i++){
  	cout<<arr[i]<<" " ;
  } 
  cout << endl;
  return 0;
}