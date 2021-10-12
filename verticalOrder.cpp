#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node* left;
  node* right;
  node(int val){
    this->val = val;
    this->right = NULL;
    this->left = NULL;
  }
};

void verticalOrderPrint(node* root, int d, map<int, vector<int> > &m){
  if(root == NULL)
  return;

  m[d].push_back(root->val);
  verticalOrderPrint(root->left, d-1, m);
  verticalOrderPrint(root->right, d+1, m);
  return;
}

int main(){
  node *root = new node(1); 
    root->left = new node(2);

    root->right = new node(3);

    root->left->left = new node(4); 

    root->left->right = new node(5);

    root->right->left = new node(6);

    root->right->right = new node(7);

    root->right->left->right = new node(8); 

    map<int, vector<int> > m;
    verticalOrderPrint(root, 0, m);

    map<int, vector<int> >::iterator i;
    for(i = m.begin(); i != m.end(); i++){
      int l = i->second.size();
      cout<<i->first<<": ";
      for(int j = 0;j < l; j++){
        cout<<i->second[j]<<" ";
      }
      cout<<endl;
    }
}