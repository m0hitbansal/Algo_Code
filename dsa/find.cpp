#include<iostream>
#include <cstdlib>
#include<cmath>
using namespace std;
int find1(int * arr,int i,int j,int r);
void swap1(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int median(int *arr,int i,int j){
  bool swapped;
  int n=j-i+1;
  for(int p=0;p<n-1;p++){
    swapped=false;
    for(int q=i;q<j-p;q++){
      if(arr[q]>arr[q+1]){
        swap1(&arr[q],&arr[q+1]);
        swapped=true;
      }
    }
    if(swapped==false)
     break;
  }
  return floor((i+j)/2);
}
int pivot(int * arr,int i,int j){
  if(j-i+1<5){
    return median(arr,i,j);
  }
  int p,l,m;
  for(int p=i;p<=j;p+=5){
    l=p+4;
    if(l>j)
     l=j;
     m=median(arr,p,l);
     int k=(i+floor(p-i)/5);
     swap1(&arr[m],&arr[k]);
  }
  int mid=(j-i)/10+i+1;
  return find1(arr,i,i+(floor((j-i)/5)),mid);
}

int partition(int *arr,int i,int j){
  int pi=arr[j];
  int l=i-1;
  for(int h=i;h<j;h++){
    if(arr[h]<=pi){
      l++;
      swap1(&arr[l],&arr[h]);
    }
  }
  swap1(&arr[l+1],&arr[j]);
  return l+1;
}
int find1(int * arr,int i,int j,int r){
  if(i!=j&&r>0){
    int pi=pivot(arr,i,j);
    swap1(&arr[j],&arr[pi]);
    int k=partition(arr,i,j);
    if(r==j-k+1)
     return k;
    else if(r<j-k+1)
      return find1(arr,k+1,j,r);
    else
       return find1(arr,i,k-1,r-(j-k+1));
  }
  return i;
}
int main(){
  int n,r;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cin>>r;
  int x=find1(arr,0,n-1,r);
  cout<<r<<" rank of element is "<<arr[x];
  return 0;
}
