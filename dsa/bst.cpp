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
node * search(node* root,int key){
  if(root==NULL)
    return root;
  else if(root->val==key)
    return root;
  else if(key<=root->val)
    return search(root->left,key);
  else 
   return search(root->right,key);
}
node* successor(node* n1){
  node * temp=n1;
  while(temp && temp->left!=NULL){
    temp=temp->left;
  }
  return temp;
}
node* delet(node* root,int key){
  if(root==NULL)
    return root;
  if (key < root->val) 
    root->left = delet(root->left, key); 
  else if (key > root->val) 
    root->right = delet(root->right, key); 
  else{
     if(root->left==NULL){
      node * temp=root->right;
      free(root);
      return temp;
     }
     else if(root->right==NULL){
      node *temp=root->left;
      free(root);
      return temp;
     }
     node * temp=successor(root->right);
     root->val=temp->val;
     root->right=delet(root->right,temp->val);
  }
  return root;
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
  inorder(root);
  cout<<"enter search element ";
  cin>>k;
  cout<<"key present in tree:"<<search(root,k)->val;
  root=delet(root,10);
  inorder(root);
  cout << endl;
  return 0;
}