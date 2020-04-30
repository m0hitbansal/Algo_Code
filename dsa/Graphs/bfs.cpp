#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<int>visited;
void bfs(int u){
  queue<int>q;
  q.push(u);
  visited[u]=1;
  while(!q.empty()){
    int f=q.front();
    q.pop();
    cout<<endl<<f;
    for(int i=0;i<v[f].size();i++){
      if(!visited[v[f][i]]){
        q.push(v[f][i]);
        visited[v[f][i]]=1;
      }
    }
  }
}
int main(){
  int n;
  cout<<"enter number of vertex"<<endl;
  cin>>n;
  v.assign(n,vector<int>());
  visited.assign(n,0);
  v[0].push_back(1);
  v[0].push_back(2);
  v[1].push_back(0);
  v[1].push_back(4);
  v[1].push_back(3);
  v[2].push_back(0);
  v[2].push_back(4);
  v[4].push_back(5);
  v[4].push_back(2);
  v[4].push_back(1);
  v[3].push_back(5);
  v[3].push_back(1);
  v[5].push_back(4);
  v[5].push_back(3);
  int arr[n]={0};
 for(int i=0;i<n;i++){
    if(!visited[i]){
      bfs(4);
    }
  }
}
