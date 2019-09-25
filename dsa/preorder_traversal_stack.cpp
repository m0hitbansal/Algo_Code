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
 stack<node*>s1;
 s1.push(root);
 while(!s1.empty()){
  node *x=s1.top();
  s1.pop();
  if(x->right!=NULL)
  s1.push(x->right);
if(x->left!=NULL)
  s1.push(x->left);
  cout<<x->val<<" ";
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
  cout << "Preorder traversal: ";
  preorder(root);
  
  cout << endl;
  return 0;
}



