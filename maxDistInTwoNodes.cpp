#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

  int globalMax = -10000;
  int findMaxDist(node* root){
    if(root == NULL){
      return 0;
    }
    int ls = findMaxDist(root->left);
    int rs = findMaxDist(root->right);
    int cand1 = ls+root->val;
    int cand2 = rs+root->val;
    int cand3 = ls+rs+root->val;
    int cand4 = root->val;
    globalMax = max(cand1, max(cand2, max(cand3, max(cand4, globalMax))));
    cout<<cand1<<" "<<cand2<<" "<<cand3<<" "<<cand4<<" "<<globalMax<<endl;

    return max(ls, max(rs, 0))+root->val; 
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
  findMaxDist(root);
  cout<<globalMax;
}