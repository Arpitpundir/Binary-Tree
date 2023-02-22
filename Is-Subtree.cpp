class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        bool ans1 = false, ans2 = false;
        if(root->val == subRoot->val){
            ans1 = (isSubtree(root->left, subRoot->left)&&isSubtree(root->right, subRoot->right));
        }
        ans2 = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        return ans1||ans2;
    }
};