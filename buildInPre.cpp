#include<bits/stdc++.h>
using namespace std;

int preInd = 0;
class node{
  public:
  int val; 
  node *left = NULL;//m = pure caeless 
  node *right = NULL;//m = pure careless
};

int search(int st, int end, int val, vector<int> in){
  for(int i = st; i <= end;i++){
    if(in[i] == val){
      return i;
    }
  }
}

node *build(vector<int> in, vector<int> pre, int st, int end){

  //cout<<st<<" "<<end<<" "<<preInd<<endl;
  if(st > end){
    return NULL;
  }
  
  node* newNode = new node;
  newNode->val = pre[preInd++];//m = update code careless

  if(st == end){
    return newNode;
  }

  int inInd = search(st, end, newNode->val, in);

  newNode->left = build(in, pre, st, inInd-1);//m = conceptual careless mistake
  newNode->right = build(in, pre, inInd+1, end);

  return newNode;
}

void printPre(node *root){
  if(root == NULL){
    return;
  }

  //cout<<root->val<<endl;

  if(root->left != NULL){
    //cout<<"jkj"<<endl;
    cout<<root->left->val<<" => "<<root->val;
  }else{
    cout<<"END => "<<root->val;
  }

  if(root->right != NULL){
    cout<<" <= "<<root->right->val<<endl;
  }else{
    cout<<" <= End"<<endl;
  }

  printPre(root->left);
  printPre(root->right);
}

int main(){
  int n, m;
  vector<int> pre;
  vector<int> in;

  cin>>n;

  for(int i = 0;i < n;i++){
    int temp;
    cin>>temp;
    pre.push_back(temp);
  }

  cin>>m;//m = pure careless
  for(int i = 0;i < m;i++){
    int temp;
    cin>>temp;
    in.push_back(temp);
  }

  node *root = build(in, pre, 0, n-1);

  printPre(root);
}