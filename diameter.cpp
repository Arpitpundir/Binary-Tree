#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* left;
  node* right;
};

// int findHeight(node *root){
//   if(root == NULL){
//     return 0;
//   }
//   return max(findHeight(root->left), findHeight(root->right))+1;
// }

int findDiameter(node* root){
  if(root == NULL){
    return {0,0};
  }
  //so there are three cases first is when diameter passes through root in this case we need max height of left subtree
  //and max height of right subtree
  //other two cases are diameter might lie in left subtree and diameter might lie in right subtree 
  auto leftTreeData = findDiameter(root->left);
  auto rightTreeData = findDiameter(root->right);
  int h1 = leftTreeData.second;
  int h2 = rightTreeData.second;
  int d1 = leftTreeData.first;
  int d2 = rightTreeData.first;
  int currHeight = 1+max(h1,h2);
  int maxDiameter = max(1+h1+h2, max(d1,d2));
  return {maxDiameter, currHeight};
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