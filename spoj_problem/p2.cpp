#include<iostream>
using namespace std;
bool prime(long long int n) {
    if (n == 1)
        return false;
    long long int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
          return false;
        }
        i += 1;
    }
  return true;
}
int main(){
int x;
cin>>x;
while(x>0){
long long int a,b;
cin>>a>>b;
for(long long int j=a;j<=b;j++){
if(prime(j))
cout<<j<<"\n";
}
cout<<endl;
x--;
}
}
