#include<iostream>
using namespace std;
typedef struct box{
  int e;
  int count=0;
}box;
int main(){
  int n,k;
  cin>>n;
  cin>>k;
  int arr[n];
  box b[k-1];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n;i++){
    int j;
    for(j=0;j<k-1;j++){
      if(b[j].count==0){
        b[j].e=arr[i];
        b[j].count++;
        break;
      }
      else if(b[j].e==arr[i]){
        b[j].count++;
        break;
      }
    }
     if(j==k-1){
       for(int l=0;l<k-1;l++){
         b[l].count--;
       }
     }
  }
for (int i=0; i<k-1; i++){
    int c = 0;
    for (int j=0; j<n; j++)
        if (arr[j] == b[i].e)
            c++;
    if (c > n/k)
     cout << "Number:" <<b[i].e<< endl;
    }
  return 0;
}
