#include<iostream>
#include<stack>
#include<string>
using namespace std;
char check(char c){
  if(c=='1')
   return '+';
   if(c=='2')
    return '-';

    if(c=='3')
     return '*';

     if(c=='4')
      return '/';
      if(c=='5')
       return '^';
return c;
}
int main(){
int N;
cin>>N;
while(N--){
string s;
cin>>s;
stack<char>s1;
for(int i=0;i<s.size();i++){
  if(s[i]=='(')
   s1.push(s[i]);
  else if(s[i]==')'){
     while(s1.top()!='('){
       cout<<check(s1.top());
       s1.pop();
     }
     s1.pop();
   }
   else if(s[i]=='+'){
     while('1'<s1.top()){

       cout<<check(s1.top());
       s1.pop();
     }
     s1.push('1');
   }
   else if(s[i]=='-'){
     while('2'<s1.top()){
       cout<<check(s1.top());
       s1.pop();
     }
     s1.push('2');
   }
   else if(s[i]=='*'){
     while('3'<s1.top()){
       cout<<check(s1.top());
       s1.pop();
     }
     s1.push('3');
   }
   else if(s[i]=='/'){
     while('4'<s1.top()){
       cout<<check(s1.top());
       s1.pop();
     }
     s1.push('4');
   }
   else if(s[i]=='^'){
     while('5'<s1.top()){
       cout<<check(s1.top());
       s1.pop();
     }
     s1.push('5');
   }
   else
   cout<<s[i];
}
cout<<endl;
}
}
