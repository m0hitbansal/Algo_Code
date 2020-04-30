#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
	int n;
	cout<<"size of array:";
	cin>>n;
	int arr[n],R[n];
	for(int i =0;i<n;i++){
      cin>>arr[i];
	}
	stack<int> s1;
	s1.push(0);
	for(int i=1;i<n;i++){
           while(!s1.empty()&& arr[s1.top()]<arr[i]){
           	R[s1.top()]=i;
           	s1.pop();
           }
           s1.push(i);

	}
	while(!s1.empty()){
          R[s1.top()]=n;
          s1.pop();
	}
	for(int i =0;i<n;i++){
      cout<<R[i]<<" " ;
	}
}