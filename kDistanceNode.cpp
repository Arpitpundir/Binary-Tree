#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* left;
    node* right;
};
int preIndex = 0;

int search(vector<int> in, int st, int end, int val){
  for(int i = st; i <= end;i++){
    if(in[i] == val){
      return i;
    }
  }
}

node* build(vector<int> pre, vector<int> in, int st, int end){
    if(st > end){
        return NULL;
    }
    node* newNode = new node;
    newNode->val = pre[preIndex++];
    int inIndex = search(in, st, end, newNode->val);
    newNode->left = build(pre, in, st, inIndex-1);
    newNode->right = build(pre, in, inIndex+1, end);
    return newNode;
}

void kthNodeDown(node *root, int k, vector<int> &ans) 
{ 
    if (root == NULL || k < 0)  
    return; 
    if (k==0) { 
        ans.push_back(root->val);
        return; 
    } 
    kthNodeDown(root->left, k-1, ans); 
    kthNodeDown(root->right, k-1, ans); 
} 
   
int kthNode(node* root, int target , int k, vector<int> &ans){ 
    if (root == NULL) return -1; 

    if (root->val == target){ 
        kthNodeDown(root, k, ans); 
        return 0; 
    }   

    int dl = kthNode(root->left, target, k, ans);   
    if (dl != -1){
         if (dl + 1 == k)
         ans.push_back(root->val);   
         else
            kthNodeDown(root->right, k-dl-2, ans); 
         return 1 + dl; 
    } 
   
    int dr = kthNode(root->right, target, k, ans); 
    if (dr != -1) { 
         if (dr + 1 == k) 
         ans.push_back(root->val);        
         else
            kthNodeDown(root->left, k-dr-2, ans); 
         return 1 + dr; 
    } 
  
    return -1; 
}  

void printInorder(node* root){
  if(root == NULL){
    cout<<"-1"<<" ";
    return;
  }
  printInorder(root->left);
  cout<<root->val<<" ";
  printInorder(root->right);
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

  node *root = build(pre, in, 0, n-1);

  //printPre(root);

  int t;
  cin>>t;
  while(t--){
    int target;
    cin>>target;
    int dist;
    cin>>dist;
    vector<int> ans;
   kthNode(root,target, dist, ans);
    int l = ans.size();
    ans.sort(ans.begin(), ans.end());//m = not enough patience for reading question properly

    if(l == 0){//m = not enough patience for reading question properly
      cout<<"0"<<endl;
    }else{
      for(int i = 0;i < l;i++){
        cout<<ans[i]<<" ";
      }
    }
    cout<<endl;
  }
}