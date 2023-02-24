class Solution {
public:
bool isIdentical(TreeNode *node1, TreeNode *node2){
    if(!node1 && !node2) return true;
    if(!node1 || !node2) return false;
    return node1->val == node2->val && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        bool ans1 = false, ans2 = false;
        /*
        * can not use isSubtree for checking node to be identical because for checking node to be identical we need to check
        * we can not send root->left with subtree
        */
        if(isIdentical(root, subRoot)) return true;
        ans2 = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        return ans2;
    }
}