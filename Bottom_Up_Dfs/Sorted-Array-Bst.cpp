class Solution {
public:
    TreeNode* buildBstRecursive(int st, int end, vector<int>& nums){
        if(st == end) return new TreeNode(nums[st]);
        int mid = st+(end-st)/2;
        TreeNode* rightTree = this->buildBstRecursive(mid+1, end, nums);
        TreeNode* currNode = new TreeNode(nums[mid]);
        currNode->right = rightTree;
        if(st == mid) return currNode;
        currNode->left = this->buildBstRecursive(st, mid-1, nums);
        return currNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return this->buildBstRecursive(0, nums.size()-1, nums);
    }
};