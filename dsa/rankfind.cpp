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
int findrank(int *arr,int l,int h,int r){
	if(l<=h){
  	int p=partition(arr,l,h);
    cout<<"*"<<p<<endl;
	  if(r==h-p+1){
      return p;
    }
    else  if(r<h-p+1){
      cout<<"c"<<endl;
      return findrank(arr,p+1,h,r);
    }
    else{
      cout<<"a"<<endl;
      return findrank(arr,l,p-1,r-(h-p+1));
    }
  }
}

int main(){
  int n1 = 6;
  int arr[n1]={10,2,1,4,5,6};
  int r=findrank(arr,0,n1-1,3);
  cout<<arr[r];
  cout << endl;
  return 0;
}
