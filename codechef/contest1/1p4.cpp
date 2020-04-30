#include<bits/stdc++.h>

#include<vector>
#include<map>
using namespace std;
int  main() {
  int t;
  cin>>t;
  while(t>0){
    int n;
    cin>>n;
    vector<int> lis[n+1];
    int val,p,q;

    unordered_map<int,int>m;
    unordered_map<int,int>res;
    vector<int> b;
    for(int i=1;i<=n;i++){
      cin>>val;
     p=i-val;
      if(p<=0)
      p=1;
       q=i+val;
      if(q>n)
      q=n;
      lis[p].push_back(i);
      lis[q].push_back(i);
    }
    for(int i=0;i<n;i++){
      cin>>val;
      b.push_back(val);
    }
    int count=0;
    for(int i=1;i<=q;i++){
      int min=0;
      int j=0;
      while(j<lis[i].size()){
        if(m[lis[i][j]]==0){
          m[lis[i][j]]=1;
          count++;
        }
        else{
          min++;
        }
        j++;
      }
     res[count]++;
     count=count-min;
    }
    int f=0;
    for(int j=0;j<n;j++){
      if(res[b[j]]>0)
        res[b[j]]--;
      else{
        f=1;
        break;
      }
    }
    if(f==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    t--;
  }
  return 0;
}
