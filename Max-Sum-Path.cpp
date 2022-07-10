class Solution {
public:
    int maxSum;
    int solve(TreeNode *root){
        if(!root) return 0;
        
        int leftContr = max(0,solve(root->left));
        int rightContr = max(0,solve(root->right));
        
        int currMaxPathSum = leftContr+rightContr+root->val;
        maxSum = max(maxSum,currMaxPathSum);
        return root->val+max(leftContr,rightContr);
    }
    int maxPathSum(TreeNode* root) {        
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};