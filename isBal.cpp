#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  string val;
  node *left = NULL;
  node *right = NULL;
};

node *build(){
  string doExist, val;
  cin>>doExist;
  if(doExist == "false"){
    return NULL;
  }
  cin>>val;
  node *newNode = new node;
  newNode->val = val;

  newNode->left = build();
  newNode->right = build();
  return newNode;
}

int isBal(node *root){
  if(root == NULL){
    return 0;
  }

  int leftH = isBal(root->left);
  int rightH = isBal(root->right);

  if(leftH == -1 || rightH == -1 || abs(leftH-rightH) > 1){
    return -1;
  }

  return max(leftH, rightH)+1;
}

int main(){
  node *root1 = new node;
   string val;
  cin>>val;
  root1->val = val;
  root1->left = build();
  root1->right = build();

  if(isBal(root1) == -1){
    cout<<"false"<<endl;
  }else{
    cout<<"true"<<endl;
  }
}