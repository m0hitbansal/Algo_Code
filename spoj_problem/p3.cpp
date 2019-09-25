#include<iostream>
#include<string>
#define mod 11
using namespace std;
int rabin_karp(string s1,string s2,int base){
	int n1=s1.length();
	int n2=s2.length();
	int c = 1,txt1 = 0, txt2 = 0, ans = 0;
  for(int i=0;i<n2;i++){
    c = (c*base)%mod;
    txt1 = ((base*txt1+(s1[i]-'0')))%mod;
    txt2 = ((base*txt2+(s2[i]-'0')))%mod;
  }
  int l=n2,k;
  c=c/base;
  for(int j=n2;j<n1;j++){
   if(txt1==txt2){
     for ( k = 0; k < l; k++)
             {
                 if (s1[j-l+k] != s2[k])
                     break;
             }
             if (k == l)
               return 1;
   }
   txt1=((txt1-(s1[j-l]-'0')*c)*base+(s1[n2]-'0'))%mod;
  }
return 0;
}
int main(){
int x=24;
while(x>0){
string a,b;
cin>>a>>b;
int l=rabin_karp(a,b,2);
cout<<l<<endl;
}
x--;
}
