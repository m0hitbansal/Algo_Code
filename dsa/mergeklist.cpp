#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int len=0;
vector<int>res;
void mergelist(vector<int>v[],int k){
  int m[k];

  priority_queue <pi, vector<pi>, greater<pi> > heap;
  for(int i=0;i<k;i++){
    heap.push(make_pair(v[i][0],i));
    m[i]=1;
  }
  int index;
  for(int j=0;j<9;j++){
      pair<int ,int>top=heap.top();
      heap.pop();
      index=top.second;
      res.push_back(top.first);
      
      if(m[index]<v[index].size())
    heap.push(make_pair(v[index][m[index]],index));
    m[index]++;
  }

}
int main(){
  int k=3,val,n;
  //cin>>k;
  vector<int>v[3]={ { 5, 13, 20 },
                               { 4, 6,15 },
                               { 1, 18, 29 } };

  /*for(int i=0;i<k;i++){

    cout<<"enter the number of element in list "<<i+1<<endl;
    cin>>n;
    len+=n;
    for(int j=0;j<n;j++){
      cin>>val;
      v[i].push_back(val);
    }
  }*/
  mergelist(v,k);

  for(int i=0;i<res.size();i++)
  cout<<res[i]<<" ";
}
