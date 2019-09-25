#include<iostream>
#include<cmath>
using namespace std;
int main(){
 int n,l,r;
 cin>>n>>l>>r;
 int min=0,max=0;
  int num=0,c=l,d=1;
 for(int i=0;i<n;i++){
  if(c>0){
  min+=pow(2,i);
  c--;
}
else
 min+=1;
}
int s=pow(2,r-1);
for(int i=0;i<n;i++){
 if(d<=r){
 max+=pow(2,i);
 d++;
}
 else
 max+=s;
}
cout<<min<<" "<<max;
}
