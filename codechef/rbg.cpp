#include<iostream>
#include<string>
using namespace std;

int lcp(string s,int l,int p,int e){
  int count=0;
  int m=p;
  while((l<p)&&(m<e)&&(s[l]==s[m])){
  //  cout<<s[l];
    l++;
    m++;
    count++;
  }
  
  return count;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  int q;
  cin>>q;
  for(int i=1;i<=q;i++){
    int p;
    cin>>p;
    int c=lcp(s,0,p,s.size());
    cout<<c<<endl;
  }
}
