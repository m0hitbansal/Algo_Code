#include<iostream>
#include <cstdlib>
using namespace std;

int merge(int *arr,int l,int m,int h){
	int count=0;
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
						count=count+m-(l+i)+1;
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
		cout<<count<<endl;
		return count;
}
int  mergesort(int *arr,int l,int h){
   int c=0;
	if(l<h){
	int m=(h+l)/2;

  c+=mergesort(arr,l,m);
	c+=mergesort(arr,m+1,h);
	c+=merge(arr,l,m,h);

}
return c;
}

int main(){
  int n1;
  cin>>n1;
  int arr[n1];
  cout<<"enter array";
  for(int i=0;i<n1;i++){
  	cin>>arr[i];
  }
  int c=mergesort(arr,0,n1-1);
  /*for(int i=0;i<n1;i++){
  	cout<<arr[i]<<" " ;
  }*/
  cout <<c<<endl;
  return 0;
}
