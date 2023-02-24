class Solution {
public:
/*
* in inorder traversal whenever we reach a node we will now how many nodes are smaller than it
* we can use this information to find kth smallest element
*/
    pair<bool, int> kthSmallestRecur(TreeNode *root, int k, int smallerNode){

        if(root == NULL) return make_pair(false,0);
        pair<bool, int> leftTreeRes = kthSmallestRecur(root->left, k, smallerNode);
        if(leftTreeRes.first){
            return leftTreeRes;
        }else if(leftTreeRes.second+smallerNode+1 == k){
            return make_pair(true, root->val);
        }
        pair<bool, int> rightTreeRes = kthSmallestRecur(root->right, k, leftTreeRes.second+1+smallerNode);
        if(rightTreeRes.first){
            return rightTreeRes;
        }
        return make_pair(false, leftTreeRes.second+1+rightTreeRes.second);
    }
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestRecur(root, k, 0).second;
    }
};