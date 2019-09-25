#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
 string s1;
 cin>>s1;
 long long int num=0,right;
 for(int i=0;i<=s1.length()-1;i++){
   num=num*2+(s1[i]-'0');
 }
 int c=0;
right=1;
 while(right<num){
   right*=4;
   c++;
 }
 cout<<c;
}
