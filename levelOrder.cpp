#include<bits/stdc++.h>
using namespace std;

//algo for printing level order

class node{
  public:
  node* left = NULL;//important
  node* right = NULL;
  int val;
};

int findHeight(node* root){
  if(root == NULL){
    return 0;
  }
  return max(findHeight(root->left), findHeight(root->right))+1;
}

void printThisLevel(node* root, int level){
  if(root == NULL)//important as it is not necessary that all nodes are present on a given level
  return;
  if(level == 1){
    //means this node is a part of level which we want to print so we will print this
    cout<<root->val<<" ";
    return;
  }
  //if i come here it means i am not on level which i want so i should go down 
  printThisLevel(root->left, level-1);
  printThisLevel(root->right, level-1);
}
//this function would be used to call for every level and for every level we have to sart from root
void printLevelOrder(node* root){
  int h = findHeight(root);
  cout<<h<<endl;
  for(int i = 1;i <= h;i++){
    printThisLevel(root, i);
    cout<<endl;
  }
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
  printLevelOrder(root);
}