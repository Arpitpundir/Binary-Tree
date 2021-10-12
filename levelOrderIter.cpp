#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  node* left = NULL;
  node* right = NULL;
  int val;
};

void printLevelOrder(node* root){
  deque<node*> q;
  q.push_back(NULL);
  q.push_back(root);
  while(!q.empty()){
    node* top = q.front();
    q.pop_front();
    if(top == NULL && !q.empty()){
      q.push_back(NULL);
      cout<<endl;
    }else{
      if(top->left != NULL)//i will not insert null which are part of tree cause then queue will never be empty
      q.push_back(top->left);
      if(top->right != NULL)
      q.push_back(top->right);
      cout<<top->val<<" ";
    }
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