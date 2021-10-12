#include<bits/stdc++.h>
using namespace std;

class node{
  int val;
  node *left = NULL;
  node *right = NULL;
};

class custom{
  bool hasP = false;
  bool hasQ = false;
  node* ans = NULL
};

custom* helper(node *root, node *p, node *q){
  if(root == NULL){
    return NULL;
  }
  custom *leftAns = helper(root->left, p, q);
  if(leftAns != NULL && leftAns->ans != NULL){
    return leftAns;
  }

  custom *rightAns = helper(root->right, p, q);
  if(rightAns != NULL && rightAns->right != NULL){
    return rightAns;
  }

  custom *result = new custom;
  if(leftAns != NULL && rightAns != NULL){
    //we have found one key on one side and one key on another side
    result = new custom;
    result->ans = root;
    result->hasP = true;
    result->hasQ = true;
    return result;
  }

  if(root->val = p->val){
    result->hasP = true;
    if(leftAns != NULL || rightAns != NULL){
      result->ans = root;
      result->hasQ = true;
      return result;
    }
    return result;
  }

  if(root->val = q->val){
    result->hasQ = true;
    if(leftAns != NULL || rightAns != NULL){
      result->ans = root;
      result->hasP = true;
      return result;
    }
    return result;
  }

  if(leftAns){
    return leftAns
  }

  if(rightAns){
    return rightAns;
  }

  return NULL;
}

node* lcs(node* root, node *p, node *q){
  custom *temp = helper(root, p, q);
  if(temp->ans == NULL){
    return NULL;
  }return temp-ans;

}