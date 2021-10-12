#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* left;
  node* right;
};

int findHeight(node *root){
  if(root == NULL){
    return 0;
  }
  return max(findHeight(root->left), findHeight(root->right))+1;
}

int findDiameter(node* root){
  if(root == NULL){
    return 0;
  }
  //so there are three cases first is when diameter passes through root in this case we need max height of left subtree
  //and max height of right subtree
  //other two cases are diameter might lie in left subtree and diameter might lie in right subtree 
  int h1 = findHeight(root->left);
  int h2 = findHeight(root->right);
  int d1 = findDiameter(root->left);
  int d2 = findDiameter(root->right);
  return max(d1, max(d2, 1+h1+h2));
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
  cout<<findDiameter(root);
}