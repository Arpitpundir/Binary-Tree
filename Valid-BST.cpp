class Solution {
public:
    bool inorder(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        
        return inorder(root->left, minNode, root) && inorder(root->right, root, maxNode);
}
    bool isValidBST(TreeNode* root) {
        return inorder(root, NULL, NULL);
    }
};