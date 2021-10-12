#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

void printPreorder(node *root){
  if(root == NULL){
    return;
  }
  cout<<root->val<<" ";
  printPreorder(root->left);
  printPreorder(root->right);
  return;
}

node* build(vector<int> a, int st, int end){
  node *newNode = new node;
  if(st > end){
    return NULL;
  }
  if(st == end){
    newNode->val = a[st];
    return newNode;
  }

  int mid = (st+end)/2;
  newNode->val = a[mid];

  newNode->left = build(a, st, mid-1);
  newNode->right = build(a, mid+1, end);

  return newNode;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    
    vector<int> a;
    
    for(int i = 0;i < n;i++){
      int temp;
      cin>>temp;
      a.push_back(temp);
    }

    node *root = build(a, 0, n-1);
    printPreorder(root);
    cout<<endl;
  }
}