#include<iostream>
#include<vector>
#define mod 11
using namespace std;
int match(string s1,string s2,int l,int start,vector<int>hash[],int txt2){
	int x=hash[txt2].size();
	int count=0;
	if(x>0){
		for(int i=0;i<x;i++){
             int j,p=hash[txt2][i];
             for(j=0;j<l;j++){
             	if(s2[start + j]!=s1[p+j])
                    break;
             }
             if(j==l){
             	count++;
             }
		}
	}
	return count;
}
int rabin_karp(string s1,string s2,int l,int base){
	int n1=s1.length();
	int n2=s2.length();
	int c = 1,txt1 = 0, txt2 = 0, ans = 0;

  vector<int> hash[mod]; 
  
  for(int i=0;i<l;i++){
    c = (c*base)%mod;
    txt1 = ((base*txt1+(s1[i]-'0')))%mod;
    txt2 = ((base*txt2+(s2[i]-'0')))%mod;
  }
  c=c/base;
  hash[txt1].push_back(0);
for(int i=l;i<n1;i++){
	 txt1 = (txt1-(c*(s1[i-l]-'0')))%mod;
    txt1 = (base*txt1 + (s1[i]-'0'))%mod;
    hash[txt1].push_back(i-l+1);
}
ans+=match(s1,s2,l,0,hash,txt2);
for(int i=l;i<n2;i++){
	txt2 = (txt2-(c*(s2[i-l]-'0')))%mod;
    txt2 = (base*txt2 + (s2[i]-'0'))%mod;
    ans+=match(s1,s2,l,i-l+1,hash,txt2);
}
return ans;
}
int main(){
	int val=rabin_karp("1011010","10110",3,2);
	cout<<"number of pattern "<<val;
	return 0;
}
