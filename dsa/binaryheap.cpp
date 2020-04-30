#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> h;
void swap1(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void insertkey(int i){
  h.push_back(i);
  int j=h.size()-1;
  if(j!=0){
  int p=(j-1)/2;
  while(p>=0){
    if(h[p]>h[j]){
     swap1(&h[p],&h[j]);
     j=p;
     p=(j-1)/2;
   }
   else
   break;
  }
}
}
void decreasekey(int i,int val){
  h[i]=val;
  int p=(i-1)/2;
  while(p>=0){
    if(h[p]>h[i]){
      swap1(&h[p],&h[i]);
      i=p;
      p=(i-1)/2;
    }
    else
    break;
  }
}
void topdownheapify(int i){
  int l=2*i+1;
  int r=2*i+2;
  int min=i;
  int size=h.size();
  while(r<size){
    if(h[l]<=h[r])
    min=l;
    else
    min=r;
    if(h[min]<h[i]){
      swap1(&h[min],&h[i]);
      i=min;
      l=2*i+1;
      r=2*i+2;
    }
  }
  if(l==size-1&&h[l]<h[i])
  swap1(&h[l],&h[i]);
}
int extractmin(){

  int j=h.size();
  if(j==1)
  return h[0];
  int root=h[0];
  swap1(&h[0],&h[j-1]);

  h.pop_back();
  topdownheapify(0);
  return root;
}
void delet(int i){
  decreasekey(i,INT_MIN);
  extractmin();
}
void printheap(){
  for(int i=0;i<h.size();i++)
  cout<<h[i];
  cout<<endl;
}
int main(){

  insertkey(3);
  insertkey(5);
  insertkey(10);
  insertkey(7);
  insertkey(8);
  insertkey(9);
  printheap();
cout<<"minimun element is:"<<extractmin()<<endl;
  delet(2);
printheap();
  decreasekey(0,1);
printheap();
  cout<<"minimun element is:"<<extractmin()<<endl;
}
