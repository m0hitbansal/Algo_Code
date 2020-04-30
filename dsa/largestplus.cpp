#include<bits/stdc++.h>
using namespace std;
int findLargestPlus(vector<int>mat[],int n,int m) 
{ 
    int arr[n][m]; 
      for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < m; j++) 
        {
        	arr[i][j]=0; 
        }
     }   
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < m; j++) 
        {  
        	if(i-1>=0&&j-1>=0){
        		if(mat[i][j]==1)
        			arr[i][j]+=arr[i-1][j-1];
        		else
        			arr[i][j]+=0;
        	}
        	else
        		arr[i][j]+=mat[i][j];
        } 
    } 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < m; j++) 
        {  
        	if(i-1>=0&&j+1<m){
        		if(mat[i][j]==1)
        			arr[i][j]+=arr[i-1][j+1];
        		else
        			arr[i][j]+=0;
        	}
        	else
        		arr[i][j]+=mat[i][j];
        } 
    }   
    for (int i =n-1; i>=0; i--) 
    { 
        for (int j = m-1; j>=0; j--) 
        {  
        	if(i+1<n&&j+1<m){
        		if(mat[i][j]==1)
        			arr[i][j]+=arr[i+1][j+1];
        		else
        			arr[i][j]+=0;
        	}
        	else
        		arr[i][j]+=mat[i][j];
        } 
    }
    for (int i = n-1; i >=0; i--) 
    { 
        for (int j = m-1; j>=0; j--) 
        {  
        	if(i+1<n&&j-1>=0){
        		if(mat[i][j]==1)
        			arr[i][j]+=arr[i+1][j-1];
        		else
        			arr[i][j]+=0;
        	}
        	else
        		arr[i][j]+=mat[i][j];
        } 
    }
    int N = 0; 
  
    // compute longest + 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < m; j++) 
        {     
  
            // largest + would be formed by a cell that 
            // has maximum value 
            if(arr[i][j]> N) 
                N =arr[i][j]; 
        } 
    } 
  
    // 4 directions of length n - 1 and 1 for middle cell 
    if (N) 
       return N-3; 
  
    // matrix contains all 0's 
    return 0; 
} 
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>v[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a;
			cin>>a;
			v[i].push_back(a);
		}
	}
	cout<<findLargestPlus(v,n,m);
}