#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  string val;
  node *left = NULL;
  node *right = NULL;
};

void printInorder(node *root){
  if(root == NULL){
    cout<<"-1"<<" ";
    return;
  }
  printInorder(root->left);
  cout<<root->val<<" ";
  printInorder(root->right);
  return;
}
node *build(){
  string doExist, val;
  cin>>doExist;
  //cout<<doExist<<endl;
  if(doExist == "false"){
    return NULL;
  }
  cin>>val;
  //cout<<val<<endl;
  node *newNode = new node;
  newNode->val = val;

  newNode->left = build();
  newNode->right = build();
//printInorder(newNode);
//cout<<endl;
  return newNode;

}

bool isSame(node *root1, node *root2){
  if(root1 == NULL && root2 == NULL){
    return true;
  }

  if(root1 == NULL){
    return false;
  }

  if(root2 == NULL){
    return false;
  }

  return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

int main(){
  node *root1 = new node;
   string val;
  cin>>val;
  root1->val = val;
  //cout<<root1->val<<endl;
  root1->left = build();
  root1->right = build();
//printInorder(root1);
  node *root2 = new node;
  cin>>val;

  root2->val = val;
  root2->left = build();
  root2->right = build();
//printInorder(root2);
  if(isSame(root1, root2)){
    cout<<"true"<<endl;
  }else{
    cout<<"false"<<endl;
  }
}