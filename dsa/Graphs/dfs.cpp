#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<int>visited;
vector<int>parent;
vector<int>d;
vector<int>f;
int t=0;
void dfs(int u){
  t++;
  d[u]=t;
  visited[u]=1;
  cout<<u<<endl;
    for(int i=0;i<v[u].size();i++){
      if(!visited[v[u][i]]){
        parent[v[u][i]]=u;
        dfs(v[u][i]);
      }
    }
    f[u]=++t;
}
int main(){
  int n;
  cout<<"enter number of vertex"<<endl;
  cin>>n;
  v.assign(n,vector<int>());
  visited.assign(n,0);
  parent.assign(n,INT_MAX);
  d.assign(n,0);
  f.assign(n,0);
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
      dfs(i);
      parent[i]=i;
    }
  }
  for(int i=0;i<n;i++){
    cout<<d[i]<<" "<<f[i]<<" "<<parent[i]<<endl;
  }
}
