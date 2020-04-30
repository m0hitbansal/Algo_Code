#include<iostream>
using namespace std;
int reverse(int i){
  int sum=0;
while(i>0){
sum=sum*10+i%10;
i=i/10;
}
return sum;
}
int main(){
int N;
cin>>N;
while(N--){
int a,b;
cin>>a>>b;
a=reverse(a);
//cout<<a;
b=reverse(b);
//cout<<b;
cout<<reverse(a+b)<<endl;
}
}
