#include<bits/stdc++.h>
using namespace std;

class node{
  int val;
  node *left = NULL;
  node *right = NULL;
};

node* findLcaUtil(node *root, bool &isFound1, bool &isFound2, int n1, int n2){
  if(!root) return NULL;

  if(root->val == n1){
    isFound1 = true;
    return root;
  }

  if(root->val == n2){
    isFound2 = true;
    return root;
  }

  node *leftSubtreeAns = findLcaUtil(root->left, isFound1, isFound2, n1,n2);
  node *rightSubtreeAns = findLcaUtil(root->right, isFound2, isFound2,n1,n2);

  if(leftSubtreeAns&&rightSubtreeAns) return root;
  if(leftSubtreeAns){
    return leftSubtreeAns;
  }
  if(rightSubtreeAns){
    return rightSubtreeAns;
  }

  return NULL;
}

bool find(node *root, int val){
  if(!root) return false;
  if(root->val == val) return true;
  return find(root->left,val)||find(root->right, val);
}

int main(){
  bool isFound1=false, isFound2 = false;

  node *lca = findLcaUtil(root,isFound1,isFound2,val1,val2);
  if(isFound1 && isFound2) return lca;
  else if(isfound1){
    if(findLcaUtil(lca, val2)){
      return lca;
    }else{
      return NULL;
    }
  }else{
    if(findLcaUtil(lca, val1)){
      return lca;
    }else{
      return NULL;
    }
  }
}