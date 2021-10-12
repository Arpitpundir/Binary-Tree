#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

node *head = NULL;
node *tail = NULL;

void bt2LL(node* root){
  cout<<"jkl";
  if(root == NULL){
    cout<<"kl";
        return;
  }
  cout<<root->val<<" "<<root->left<<endl;
  bt2LL(root->left);
  if(tail == NULL){
    head = root;//this code will execute only once 
  }else{
    tail->right = root;
    root->left = tail;
  }
  tail = root;//in either case tail is going to be root whether left part is null or not
  //by now we have prepared left ll now we will go to right part and connect head of right ll to the tail
  //that we have build by now
  if(root->right != NULL)
  bt2LL(root->right);
  cout<<root->left->val<<"-"<<root->val<<"-"<<root->right->val<<endl;
  return;
}

void printLL(node *head){
  node *temp = head;
  while(temp->right != NULL){
    cout<<temp->val<<" ";
    temp = temp->right;
  }
}

int main() 
{ 
    // Let us create binary tree given in 
    // the above example 
    node *root = new node;
    root->val = 1;
    cout<<root->left;
    root->left = new node;
    root->left->val = 2;
    root->right = new node;
    root->right->val = 3;
    root->left->left = new node;
    root->left->left->val = 4;
    root->left->right = new node;
    root->left->right->val = 5; 
    bt2LL(root);
    tail->right = NULL;
    printLL(head);
    return 0; 
} 
