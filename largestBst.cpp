#include<bits/stdc++.h>
using namespace std;

int preInd = 0;

class node{
  public:
  int val;
  node *left = NULL;
  node *right = NULL;
};

class info{
  public:
  bool isBst = true;
  int height = 0;
};

info findLargestBst(node *root, int min, int max){

  info newInfo;

  if(root == NULL){
     newInfo.height = 0;//1; poor analyzing low patience not using reason
     newInfo.isBst = true;
     return newInfo;
  }


  info leftInfo = findLargestBst(root->left, INT_MIN, root->val);
  info rightInfo = findLargestBst(root->right, root->val, INT_MAX);

//m = big mistake accessed left->val without knowing that it might be null
  if(leftInfo.isBst && rightInfo.isBst ){

    newInfo.height = 1 + (leftInfo.height + rightInfo.height);
    if(root->val > min && root->val < max){

      newInfo.isBst = true;
    }else{

      newInfo.isBst = false;
    }
  }else{

    newInfo.isBst = false;
    newInfo.height = (leftInfo.height > rightInfo.height?leftInfo.height:rightInfo.height);
  }
  return newInfo;
}

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

  m = n;//m = pure careless
  for(int i = 0;i < m;i++){
    int temp;
    cin>>temp;
    in.push_back(temp);
  }

  node *root = build(in, pre, 0, n-1);
  //printPre(root);
  info result = findLargestBst(root, INT_MIN, INT_MAX);

  cout<<result.height;
}