#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
int maxLevel = 0;

class node {
  public:
  int val;
  int hd;
  node *right;
  node *left;
  node(int val){
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

node* build(){

  int d;
cin>>d;

node*root = new node(d);
queue<node*> q;
q.push(root);

while(!q.empty()){

	node*f = q.front();
	q.pop();
	int c1,c2;
	cin>>c1>>c2;

	if(c1!=-1){
		f->left = new node(c1);
		q.push(f->left);
	}
	if(c2!=-1){
		f->right = new node(c2);
		q.push(f->right);
	}
}
return root;
}

void leftView(node *root, int level){
  if(root == NULL){
    return;
  }

  if(level > maxLevel){
    cout<<root->val<<" ";
    maxLevel = level;
  }

  leftView(root->left, level+1);
  leftView(root->right, level+1);

  return;
}

int main(){
  node *root = build();
  int l = ans.size();

  leftView(root, 1);
}

