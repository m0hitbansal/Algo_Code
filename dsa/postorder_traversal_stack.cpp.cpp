#include<iostream>
 #include <cstdlib>
#include<stack>
 using namespace std;

 typedef struct node{
   int val;
   struct node *left, *right;
 }node;

 node* AddNode(int n){
   node* temp = (node*)malloc(sizeof(node));
   temp->val = n;
   temp->left = temp->right = NULL;
   return temp;
 }

void preorder(node* root){
 stack<pair<node*,int>>s1;
 s1.push({root,0});
 while(!s1.empty()){
  pair<node *,int> x=s1.top();
  s1.pop();
  if(x.second==1){
    cout<<(x.first)->val<<" ";
  }
  else{
    x.second=1;
    s1.push(x);
    if((x.first)->right!=NULL)
      s1.push({(x.first)->right,0});
    
    if((x.first)->left!=NULL)
      s1.push({(x.first)->left,0});
}
 }
}


int main(){

  node* root;
  root = AddNode(10);
  root->left = AddNode(9);
  root->left->left = AddNode(7);
  root->left->right = AddNode(3);
  root->left->right->left = AddNode(17);
  root->right = AddNode(8);
  root->right->left = AddNode(5);
  cout << "Postorder traversal: ";
  preorder(root);
  
  cout << endl;
  return 0;
}



