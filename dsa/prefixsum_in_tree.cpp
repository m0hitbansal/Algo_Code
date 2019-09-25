#include <bits/stdc++.h>
using namespace std;
typedef struct node{
  int key;
  struct node * left;
  struct node *right;
  int sum;
  int height;
}node;
node * newnode(int val){
  node *temp=(node*)malloc(sizeof(node));
  temp->key=val;
  temp->left=NULL;
  temp->right=NULL;
  temp->height=1;
  temp->sum=val;
  return temp;
}
void preOrder(node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int heigh(node *N){
    if (N == NULL)
        return 0;
    return N->height;
}
int SUM(node *N){
    if (N == NULL)
        return 0;
    return N->sum;
}
int getDiff(node *N){
    if (N == NULL)
        return 0;
    return heigh(N->left) - heigh(N->right);
}
node* zigzigleft(node* z){
  node *y=z->left;
  node *t3=y->right;
//  y->parent=z->parent;
  z->left=t3;
  y->right=z;
//  z->parent=y;
//  t3->parent=z;
z->height=max(heigh(z->right),heigh(z->left))+1;
y->height=max(heigh(y->right),heigh(y->left))+1;
z->sum=SUM(z->left)+SUM(z->right)+z->key;
y->sum=SUM(y->left)+SUM(y->right)+y->key;
return y;
}
node* zigzigright(node* z){
  node *y=z->right;
  node *t3=y->left;
//  y->parent=z->parent;
  z->right=t3;
  y->left=z;
  //z->parent=y;
//  t3->parent=z;
z->height=max(heigh(z->right),heigh(z->left))+1;
y->height=max(heigh(y->right),heigh(y->left))+1;
z->sum=SUM(z->left)+SUM(z->right)+z->key;
y->sum=SUM(y->left)+SUM(y->right)+ y->key;
return y;
}
node* zigzagleft(node* z){
  node *y=z->left;
  node *x=y->right;
  node * t1=x->left;
  node* t2=x->right;
//  x->parent=z->parent;
  z->left=t2;
//  t2->parent=z;
  x->right=z;
//  z->parent=x;
  x->left=y;
//  y->parent=x;
  y->right=t1;
  //t1->parent=y;
  z->height=max(heigh(z->right),heigh(z->left))+1;
  y->height=max(heigh(y->right),heigh(y->left))+1;
  x->height=max(heigh(x->right),heigh(x->left))+1;
  z->sum=SUM(z->left)+SUM(z->right)+z->key;
  y->sum=SUM(y->left)+SUM(y->right)+y->key;
  x->sum=SUM(x->left)+SUM(x->right)+x->key;
  return x;
}
node* zigzagright(node* z){
  node *y=z->right;
  node *x=y->left;
  node * t1=x->left;
  node* t2=x->right;
//  x->parent=z->parent;
  z->right=t1;
//  t1->parent=z;
  x->right=y;
//  y->parent=x;
  x->left=z;
//  z->parent=x;
  y->left=t2;
//  t2->parent=y;
z->height=max(heigh(z->right),heigh(z->left))+1;
y->height=max(heigh(y->right),heigh(y->left))+1;
x->height=max(heigh(x->right),heigh(x->left))+1;
z->sum=SUM(z->left)+SUM(z->right)+z->key;
y->sum=SUM(y->left)+SUM(y->right)+y->key;
x->sum=SUM(x->left)+SUM(x->right)+x->key;
  return x;
}
node * insert(node * root ,int val){
  if(root==NULL){
  //  root->parent=NULL;
    return(newnode(val));
  }
  if(val<root->key){
    root->left=insert(root->left,val);
  //  root->left->parent=root;
  }
  else {
    root->right=insert(root->right,val);
    //root->right->parent=root;
  }
  root->height=max(heigh(root->left),heigh(root->right))+1;
  root->sum=SUM(root->left)+SUM(root->right)+root->key;
  int diff=getDiff(root);
  if(diff>1&&val<root->left->key){
    return zigzigleft(root);
  }
  if(diff>1&&val>root->left->key){
    return zigzagleft(root);
  }
 if(diff<-1&&val>root->right->key){

    return zigzigright(root);
  }
 if(diff<-1&&val<root->right->key){
    return zigzagright(root);
  }
  return root;
}
node* successor(node* n1){
  node * temp=n1;
  while(temp && temp->left!=NULL){
    temp=temp->left;
  }
  return temp;
}
node * deleteNode(node* root,int val){
  if(root==NULL)
  return root;
  if(val<root->key){
    root->left = deleteNode(root->left, val);
  }
  else if(val>root->key){
    root->right = deleteNode(root->right, val);
  }
  else{
    if(root->left==NULL||root->right==NULL){
      node *temp=(root->left)?root->left:root->right;
      if(temp==NULL){
        temp=root;
        root=NULL;
      }
      else
      *root=*temp;
     free(temp);
    }
    else{
      node * temp=successor(root->right);
      root->key=temp->key;
      root->right=deleteNode(root->right,temp->key);
    }
  }
  if (root == NULL)
   return root;  
  root->height=max(heigh(root->left),heigh(root->right))+1;
  root->sum=SUM(root->left)+SUM(root->right)+root->key;
  int diff=getDiff(root);
  if(diff>1&&getDiff(root->left)>=0){
    return zigzigleft(root);
  }
  if(diff>1&&getDiff(root->left)<0){
    return zigzagleft(root);
  }
 if(diff<-1&&getDiff(root->right)<=0){

    return zigzigright(root);
  }
 if(diff<-1&&getDiff(root->right)>0){
    return zigzagright(root);
  }
  return root;
}
int prefixsum(node* root,int x){
  int sum=0;
  while(root!=NULL){
    if(root->key==x){
      sum+=SUM(root->left);
      return sum;
    }
    else if(root->key>x){
      root=root->left;
    }
    else{
      sum+=SUM(root->left)+root->key;
      root=root->right;
    }
  }
  return 0;
}

int main(){
  node *root = NULL;
  root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    root=deleteNode(root,9);
    preOrder(root);
    cout<<endl;
    int pre=prefixsum(root,5);
    if(pre)
    cout<<"prefix sum is:"<<pre<<endl;
    else
    cout<<"element not present";
  }
