#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

void insertNode(node *&root, int val){
  if(root == NULL){
    root = new node;
    root->val = val;
    return;
  }
  if(val < root->val){
    insertNode(root->left, val);
    return;
  }
  insertNode(root->right, val);
  return;
}
void buildBst(node *&root){
  int temp;
  cin>>temp;
  while(temp != -1){
    insertNode(root, temp);
    cin>>temp;
  }
}

bool isBst(node *root, int min, int max){
  if(root == NULL){
    return true;
  }
  if(root->val > min && root->val < max && isBst(root->left, min, root->val) && isBst(root->right, root->val, max)){
    return true;
  }
  return false;
}

void inOrderPrint(node *root){
  if(root == NULL){
    return;
  }
  inOrderPrint(root->left);
  cout<<root->val<<" ";
  inOrderPrint(root->right);
}

int main(){
  node* root = NULL;
  buildBst(root);
  inOrderPrint(root);
  if(isBst(root, -1, 10000)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  root = new node;
  root->val = 1;
  root->left = new node;
  root->left->val = 2;
  root->right = new node;
  root->right->val = 3;
  root->left->left = new node;
  root->left->left->val = 4;
  root->left->right = new node;
  root->left->right->val = 5; 
  if(isBst(root, -1, 10000)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}