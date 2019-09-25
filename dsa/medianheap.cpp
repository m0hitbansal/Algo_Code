#include<iostream>
#include<vector>
using namespace std;
vector<int>h1;
vector<int>h;
void swap1(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
class maxheap{
public:

  int top(){
        int max = -1;
        if( h.size() >= 0 ){
            max = h[0];
        }
       return max;
    }
    void heapify(int i){
      int p=(i-1)/2;
      while(p>=0){
        if(h[p]<h[i]){
          swap1(&h[p],&h[i]);
          i=p;
          p=(i-1)/2;
        }
        else
        break;
      }
    }
    void insertkey(int i){

      h.push_back(i);
      int j=h.size()-1;
      if(j!=0)
      heapify(j);
    }
    void topdownheapify(int i){
      int l=2*i+1;
      int r=2*i+2;
      int max=i;
      int size=h.size();
      while(r<size){
        if(h[l]>=h[r])
        max=l;
        else
        max=r;
        if(h[max]>h[i]){
          swap1(&h[max],&h[i]);
          i=max;
          l=2*i+1;
          r=2*i+2;
        }
      }
      if(l==size-1&&h[l]<h[i])
      swap1(&h[l],&h[i]);
    }
    int deleteTop(){
      int j=h.size();
      if(j==1)
      return h[0];
      int root=h[0];
      swap1(&h[0],&h[j-1]);
      h.pop_back();
      topdownheapify(0);
      return root;
    }
    int len(){
      return h.size();
    }
};
class minheap{
public:

  int len(){
    return h1.size();
  }
  int top(){
        int min = -1;
        if( h1.size() >= 0 ){
            min = h1[0];
        }
       return min;
    }
    void heapify(int i){
      int p=(i-1)/2;
      while(p>=0){
        if(h1[p]>h1[i]){
          swap1(&h1[p],&h1[i]);
          i=p;
          p=(i-1)/2;
        }
        else
        break;
      }
    }
    void insertkey(int i){

      h1.push_back(i);
      int j=h1.size()-1;
      if(j!=0)
      heapify(j);
    }
    void topdownheapify(int i){
      int l=2*i+1;
      int r=2*i+2;
      int min=i;
      int size=h1.size();
      while(r<size){
        if(h1[l]<=h1[r])
        min=l;
        else
        min=r;
        if(h1[min]<h1[i]){
          swap1(&h1[min],&h1[i]);
          i=min;
          l=2*i+1;
          r=2*i+2;
        }
      }
      if(l==size-1&&h1[l]<h1[i])
      swap1(&h1[l],&h1[i]);
    }
    int deleteTop(){
      int j=h1.size();
      if(j==1)
      return h1[0];
      int root=h1[0];
      swap1(&h1[0],&h1[j-1]);
      h1.pop_back();
      topdownheapify(0);
      return root;
    }
};
void add(minheap &r,maxheap &l,int val){
  int left=l.len();
  int right=r.len();
  if(left==0)
  l.insertkey(val);
  else{
  if(left==right){
    if(val<=l.top())
      l.insertkey(val);
    else{
      l.insertkey(r.deleteTop());
      r.insertkey(val);
    }
  }
  else if(left>right){
    if(val<=l.top()){
      r.insertkey(l.deleteTop());
      l.insertkey(val);
    }
    else
    r.insertkey(val);
  }
  else{
    if(val<=l.top()){
      l.insertkey(val);
    }
    else
    l.insertkey(r.deleteTop());
    r.insertkey(val);

  }
}
}
int getmedian(maxheap &l){
  return l.top();
}
int main(){
  int m;
  minheap *mini;
  maxheap *maxi;
  int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
  for(int i = 0; i < 12; i++)
    {
        add(*mini,*maxi,A[i]);

        m = getmedian(*maxi);
        cout << m << endl;
    }
}
