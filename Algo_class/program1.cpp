#include <bits/stdc++.h>
using namespace std;
typedef struct point{
  int x;
  int y;
}point;
bool acompare(point lhs, point  rhs) { return lhs.x < rhs.x; }
int main(){
  int n;
  cin>>n;
  point p[n];
  for(int i=0;i<n;i++){
    cin>>p[i].x>>p[i].y;
  }
  int c=0;
  sort(p,(p+n),acompare);
  point p3;
  p3.x=p[0].x;
  p3.y=p[0].y;
  for(int i=1;i<n;i++){
    if(p[i].x>=p3.x&&p[i].y>=p3.y){
      c++;
    }
    if(p[i].y<=p3.y){
      p3.x=p[i].x;
      p3.y=p[i].y;

    }
  }
    cout<< c;
  /*for(int i=0;i<n;i++){
    cout<<p[i].x<<p[i].y;
    cout<<endl;
  }*/
}
