#include <bits/stdc++.h>
using namespace std;
typedef struct node{
  int key;
  struct node * left;
  struct node *right;
  int height;
  int max;
  int imax;
  int val;
}node;
node * newnode(int index,int val){
  node *temp=(node*)malloc(sizeof(node));
  temp->key=index;
  temp->val=val;
  temp->left=NULL;
  temp->right=NULL;
  temp->height=1;
  temp->max=val;
  temp->imax=index;
  return temp;
}
void preOrder(node *root)
{
    if(root != NULL)
    {
        cout << root->key<<" "<<root->max<<" "<<root->imax << "------";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int heigh(node *N){
    if (N == NULL)
        return 0;
    return N->height;
}
node* maxi(node * root1,node * root2){
  return (root1->max<root2->max)?root2:root1;
}
node * insert(node * root,int *arr,int i,int j){
  int m=(i+j)/2;
  root=newnode(m,arr[m]);
  if(m-1>=i){
    root->left=insert(root->left,arr,i,m-1);
  }
  if(m+1<=j){
    root->right=insert(root->right,arr,m+1,j);
  }
  node * temp=NULL;
  if(root->left!=NULL&&root->right!=NULL){
     temp=maxi(root->left,root->right);
    temp=maxi(root,temp);
    root->max=temp->max;
    root->imax=temp->imax;
  }
  else if(root->left){
    temp=maxi(root,root->left);
    root->max=temp->max;
    root->imax=temp->imax;
  }
  else if(root->right){
    temp=maxi(root,root->right);
    root->max=temp->max;
    root->imax=temp->imax;
  }
  return root;
}
node * update(node * root,int index,int val){
  if(root==NULL)
  return root;
  if(root->key==index){
    root->val=val;
    root->max=val;
  }
  else if(root->key>index)
    root->left=update(root->left,index,val);
  else
    root->right=update(root->right,index,val);
    node * temp=NULL;
    if(root->left!=NULL&&root->right!=NULL){
       temp=maxi(root->left,root->right);
      temp=maxi(root,temp);
      root->max=temp->max;
      root->imax=temp->imax;
    }
    else if(root->left){
      temp=maxi(root,root->left);
      root->max=temp->max;
      root->imax=temp->imax;
    }
    else if(root->right){
      temp=maxi(root,root->right);
      root->max=temp->max;
      root->imax=temp->imax;
    }
    return root;
}
inr findnearmax(node * root,int* arr,int i){
  int index=root->imax;
  if(root->key==i){
    if(root->max>arr[i]&&root->imax>i){
      index=root->imax;
      if(root->right)
        index=min(index,findnearmax(root->right,arr,i))
    }
    else{

    }
  }
}
int  main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  node *root=NULL;
  root=insert(root,arr,0,n-1);
  preOrder(root);
  cout<<endl<<endl;
  root=update(root,4,100);
  preOrder(root);
  return 0;
}
