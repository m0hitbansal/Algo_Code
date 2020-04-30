#include<iostream>
#define max 300
using namespace std;
int multi(int *res,int i,int x){
  int c=0;
  for(int j=0;j<i;j++){
    int m=res[j]*x+c;
    res[j]=m%10;
    c=m/10;
  }
  while(c){
    res[i]=c%10;
    c=c/10;
    i++;
  }
  return i;
}
int main(){
  int N;
  cin>>N;
  while(N--){
   int a,f=1;;
    cin>>a;
    int res[max];
    int size=1;
    res[0]=1;
    for(int i=2;i<=a;i++){
    size= multi(res,size,i);
    }
    for(int i=size-1;i>=0;i--)
    cout<<res[i];
    cout<<endl;
  }
}
