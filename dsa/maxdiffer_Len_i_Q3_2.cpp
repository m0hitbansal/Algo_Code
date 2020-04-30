#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
using namespace std;

int main(){

  FILE *fp = fopen("test1.txt","r");
  int t;  fscanf(fp,"%d",&t);
  while(t--){
    int n,l;  fscanf(fp,"%d %d",&n,&l);
    int arr[n+5];
    for(int i=0;i<n;i++) fscanf(fp,"%d",&arr[i]);
    int maxDiff = INT_MIN;
    for(int i=0;i<=n-l;i++){
      for(int j=l+i;j<n;j++){
        maxDiff=max(arr[j]-arr[i],maxDiff);
      }
    }
    cout << "Maximum difference is " << maxDiff << endl;
  }
  return 0;
}
