class Solution {
public:
    int postIndex;
    int search(vector<int> arr, int val, int st, int end){
        for(int i=st;i<=end;i++){
            if(arr[i]==val) return i;
        }
        return 0;
    }
    TreeNode* buildTreeRec(vector<int> post, vector<int> in, int st, int end){
        if(st>end) return NULL;
        TreeNode *currNode=new TreeNode(post[postIndex--]);
        if(st == end){
            return currNode;
        }
        int currInIndex = search(in, currNode->val, st, end);
        
        currNode->right = buildTreeRec(post,in,currInIndex+1, end);
        currNode->left = buildTreeRec(post,in,st,currInIndex-1);
        return currNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = inorder.size()-1;  
        return buildTreeRec(postorder,inorder,0,inorder.size()-1);
    }
};