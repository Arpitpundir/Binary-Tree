class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode *left = root->left, *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};