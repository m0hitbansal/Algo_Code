#include<iostream>
#include<string>
using namespace std;
int  main() {
  int t;
  cin>>t;
  while(t>0){
    string s1;
    cin>>s1;
    int l=s1.size();
    int p=0,q=0;
    for(int i=0;i<l;i++)
    {
      if(s1[i]=='0')
       p++;
       else
       q++;
    }

  if(p%2==0&&q%2==0&&l%2==0)
    cout<<"LOSE"<<endl;
  else if(p%2==0&&q%2!=0&&l%2!=0)
  cout<<"WIN"<<endl;
  else if(p%2!=0&&q%2==0&&l%2!=0)
  cout<<"LOSE"<<endl;
    else
    cout<<"WIN"<<endl;
    t--;
  }
  return 0;
}
