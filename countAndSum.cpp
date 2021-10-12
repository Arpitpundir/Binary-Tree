#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

int findSum(node *root){
  if(root == NULL){
    return 0;
  }
  return findSum(root->left)+findSum(root->right)+root->val;
}

int findCount(node* root){
  if(root == NULL){
    return 0;
  }
  return findCount(root->left)+findCount(root->right)+1;
}

int main(){
  node *root = new node;
  root->val = 1;
  root->left = new node;
  root->left->val = 2;
  root->right = new node;
  root->right->val = 3;
  root->left->left = new node;
  root->left->left->val = 4;
  root->left->right = new node;
  root->left->right->val = 5; 
  cout<<findCount(root)<<endl;
  cout<<findSum(root)<<endl;
}