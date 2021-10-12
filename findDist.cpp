#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
  node(int val){
    this->val = val;
  }
};

node *lca(node *root, int p, int q){
  if(root == NULL){
    return NULL;
  }
  if(root->val == p){
    return root;
  }
  if(root->val == q){
    return root;
  }
  node *left = lca(root->left, p, q);
  node *right = lca(root->right, p, q);
  if(left && right){
    return root;
  }
  if(left){
    return left;
  }
  return right;
}

int findLevel(node *root, int n, int level){
  if(root == NULL){
    return -1;
  }
  if(root->val == n){
    return level;
  }
  int leftAns = findLevel(root->left, n, level+1);
  if(leftAns != -1){
    return leftAns;
  }
  return findLevel(root->right, n, level+1);
}

int findDistance(node *root, int p, int q){
  node *Lca = lca(root, p, q);
  int d1 = findLevel(Lca, p, 0);
  int d2 = findLevel(Lca, q, 0);
  return d1+d2;
}

int main() 
{ 
    // Let us create binary tree given in 
    // the above example 
    node * root = new node(1); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5); 
    root->right->left = new node(6); 
    root->right->right = new node(7); 
    root->right->left->right = new node(8); 
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5); 
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6); 
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4); 
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4); 
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5); 
    return 0; 
} 
