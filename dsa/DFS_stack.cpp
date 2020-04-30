
#include<vector>
#include<stack>
#include<cstring>
#include<iostream>
using namespace std;

void DFS_stack(vector<vector<int>> adj,int visit[],int s){
  stack<int> S;
  S.push(s);

  while(!S.empty()){
       int u=S.top();
       S.pop();
       if(visit[u]==0){
         visit[u]=1;
         cout<<u<<" ";
       }

     vector<int>::iterator itr=adj[u].begin();
       while(itr!=adj[u].end()){
         int d=*itr;
          if(visit[d]==0)
            S.push(d);
        *itr++;
       }
  }
}

int main(){
       int v;
       cin>>v;
       vector<vector<int>> adj(v);
       adj[0].push_back(1);
       adj[0].push_back(2);
       adj[1].push_back(3);
       adj[1].push_back(2);
       adj[2].push_back(4);
       adj[4].push_back(3);
       adj[4].push_back(1);
       int visit[v];
       memset(visit,0,v*sizeof(visit[0]));
       for (int i = 0; i < adj.size(); i++) {
         cout<<i;
         for (int j = 0; j < adj[i].size(); j++)
             cout <<"->"<< adj[i][j];
       cout << endl;
       }
       DFS_stack(adj,visit,0);
}
