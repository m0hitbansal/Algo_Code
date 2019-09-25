#include <bits/stdc++.h>
using namespace std;
typedef struct node{
  int key;
  struct node * left;
  struct node *right;
  int min,max,mingap,maxgap;
  int height;
}node;
node * newnode(int val){
  node *temp=(node*)malloc(sizeof(node));
  temp->key=val;
  temp->left=NULL;
  temp->right=NULL;
  temp->height=1;
  temp->min=temp->max=val;
  temp->mingap=INT_MAX;
  temp->maxgap=INT_MIN;
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

int getDiff(node *N){
    if (N == NULL)
        return 0;
    return heigh(N->left) - heigh(N->right);
}
node * setMinMax(node * N){
  if(N->right)
  N->max=N->right->max;
  else
  N->max=N->key;
  if(N->left)
  N->min=N->left->min;
  else
  N->min=N->key;
  return N;
}

node* setMinMaxGap(node* N){
  int a =INT_MAX, b =INT_MAX, c =INT_MAX,d = INT_MAX;
        if(N->left != NULL) {
            a = N->left->mingap;
            c = N->key - N->left->max;
        }

        if(N->right != NULL) {
            b = N->right->mingap;
            d = N->right->min - N->key;
        }

        N->mingap = min(a,min(b,min(c,d)));
        N->maxgap=N->max-N->min;
        return N;
}
node* zigzigleft(node* z){
  node *y=z->left;
  node *t3=y->right;
  z->left=t3;
  y->right=z;
  z->height=max(heigh(z->right),heigh(z->left))+1;
  y->height=max(heigh(y->right),heigh(y->left))+1;
  z=setMinMax(z);  y=setMinMax(y);
  z=setMinMaxGap(z);y=setMinMaxGap(y);
  return y;
}
node* zigzigright(node* z){
  node *y=z->right;
  node *t3=y->left;
  z->right=t3;
  y->left=z;
  z->height=max(heigh(z->right),heigh(z->left))+1;
  y->height=max(heigh(y->right),heigh(y->left))+1;
  z=setMinMax(z);  y=setMinMax(y);
  z=setMinMaxGap(z);y=setMinMaxGap(y);
  return y;
}
node* zigzagleft(node* z){
  node *y=z->left;
  node *x=y->right;
  node * t1=x->left;
  node* t2=x->right;
  z->left=t2;
  x->right=z;
  x->left=y;
  y->right=t1;
  z->height=max(heigh(z->right),heigh(z->left))+1;
  y->height=max(heigh(y->right),heigh(y->left))+1;
  x->height=max(heigh(x->right),heigh(x->left))+1;
  z=setMinMax(z);  y=setMinMax(y);  x=setMinMax(x);
  z=setMinMaxGap(z);y=setMinMaxGap(y);x=setMinMaxGap(x);
  return x;
}
node* zigzagright(node* z){
  node *y=z->right;
  node *x=y->left;
  node * t1=x->left;
  node* t2=x->right;
  z->right=t1;
  x->right=y;
  x->left=z;
  y->left=t2;
  z->height=max(heigh(z->right),heigh(z->left))+1;
  y->height=max(heigh(y->right),heigh(y->left))+1;
  x->height=max(heigh(x->right),heigh(x->left))+1;
  z=setMinMax(z);  y=setMinMax(y);  x=setMinMax(x);
  z=setMinMaxGap(z);y=setMinMaxGap(y);x=setMinMaxGap(x);
  return x;
}
node * insert(node * root ,int val){
  if(root==NULL)
    return(newnode(val));
  if(val<root->key)
    root->left=insert(root->left,val);
  else
    root->right=insert(root->right,val);

  root->height=max(heigh(root->left),heigh(root->right))+1;
  root=setMinMax(root);
  root=setMinMaxGap(root);
  int diff=getDiff(root);
  if(diff>1&&val<root->left->key)
    return zigzigleft(root);
  if(diff>1&&val>root->left->key)
    return zigzagleft(root);
 if(diff<-1&&val>root->right->key)
    return zigzigright(root);
 if(diff<-1&&val<root->right->key)
    return zigzagright(root);
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

  root=setMinMax(root);
  root=setMinMaxGap(root);
  int diff=getDiff(root);
  if(diff>1&&getDiff(root->left)>=0)
    return zigzigleft(root);
  if(diff>1&&getDiff(root->left)<0)
    return zigzagleft(root);
 if(diff<-1&&getDiff(root->right)<=0)
    return zigzigright(root);
 if(diff<-1&&getDiff(root->right)>0)
    return zigzagright(root);
 return root;
}

int main(){
  node *root = NULL;
  root = insert(root, 59);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 61);
    root = insert(root, 18);
    root = insert(root, -2);
    root = insert(root, 30);
    root = insert(root, 2);
    root=deleteNode(root,61);
    preOrder(root);
    cout<<endl;
    cout<<"minimumgap= "<<root->mingap<<endl;
    cout<<"maximumgap= "<<root->maxgap<<endl;
  }
