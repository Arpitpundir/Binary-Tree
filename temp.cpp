#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

node* insertNode(node *&root, int val){
  if(root == NULL){
    root = new node;
    root->val = val;
    return root;
  }
  if(val <= root->val){
    root->left = insertNode(root->left, val);
    return;
  }
  root->right = insertNode(root->right, val);
  return;
}
void buildBst(node *&root){
  int n;
  cin>>n;
  while(n--){
	  int temp;
	  cin>>temp;
    insertNode(root, temp);
  }
}

node* deleteBst(node *&root, int val){

  if(root == NULL){
    return NULL;
  }

  else if(root->val == val){

    if(root->left == NULL && root->right == NULL){
      delete root;//m
      return NULL;
    }

    if(root->left != NULL && root->right == NULL){
      node *temp = root->left;
      delete root;
      return temp;
    }
    
    else if(root->left == NULL && root->right != NULL){
      node *temp = root->right;
      delete root;
      return temp;
    }

    node *temp = root->right;
    while(temp->left != NULL){
      temp = temp->left;
    }
    root->val = temp->val;
    root->right = deleteBst(root->right, temp->val);
    return root;
  }

  else if(val < root->val)
  root->left = deleteBst(root->left, val);

  else if(val > root->val)
  root->right = deleteBst(root->right, val);

  return root;
}

void preOrder(node *root){
  if(root == NULL){
    return;
  }
  cout<<root->val<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    node* root = NULL;
  buildBst(root);
  int m;
  cin>>m;
  while(m--){
	int temp;
  cin>>temp;
  deleteBst(root, temp);
  }
    preOrder(root);

  }
}