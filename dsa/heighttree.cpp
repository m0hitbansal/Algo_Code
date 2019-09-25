#include<iostream>
#include <cstdlib>
using namespace std;

typedef struct node{
   int val;
   struct node *left, *right;
 }node;

 node* NewNode(int n){
   node* temp = (node*)malloc(sizeof(node));
   temp->val = n;
   temp->left = temp->right = NULL;
   return temp;
 }
 void inorder( node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

node * AddNode(node * root,int key){
  if(root==NULL){
    return NewNode(key);
  }
    if(key<=root->val){
      root->left=AddNode(root->left,key);
    }
    else {
      root->right=AddNode(root->right,key);
    }

  return root;
}
int height(node* root)
{
  if(root==NULL)
    return -1;
  else
    return 1+max(height(root->left),height(root->right));
}
int main(){
  int k;
  node* root=NULL;
  root = AddNode(root,10);
  AddNode(root,5);
  AddNode(root,14);
  AddNode(root,4);
  AddNode(root,7);
  AddNode(root,6);
  AddNode(root,12);
  AddNode(root,13);
  AddNode(root,17);
 // inorder(root);
  cout<<height(root);
  cout << endl;
  return 0;
}
