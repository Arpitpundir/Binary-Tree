//call recursively first on right subtree because we need rightmost node first
//use a global variable to store the max level that you have encountered 
#include<bits/stdc++.h>
using namespace std;

int max_level = 0;
class node{
  public:
  int val;
  node *right = NULL;
  node *left = NULL;
};

void rightView(node *root, int level, vector<node*> &ans){
  if(root == NULL){
    return;
  }
  if(level > max_level){
    max_level = level;
    ans.push_back(root);
  }
  //we are coming down also when level < max_level because there is a chance that down the tree child of these level
  //might become the rightmost 
  rightView(root->right, level+1, ans);
  rightView(root->left, level+1, ans);
  return;
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
  vector<node*> ans; 
  rightView(root, 1, ans);
  int l = ans.size();
  for(int i = 0;i < l;i++){
    cout<<ans[i]->val<<endl;
  }
}