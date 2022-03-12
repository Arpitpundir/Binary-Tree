class Solution {
public:
    TreeNode* lcaUtil(TreeNode* root, int n1,int n2,bool &b1, bool &b2){
        if(root==NULL)
            return NULL;
        if(root->val==n1){
            b1=true;
            return root;
        }
        if(root->val==n2){
            b2=true;
            return root;
        }
        TreeNode* leftAns=lcaUtil(root->left,n1,n2,b1,b2);
        TreeNode* rightAns=lcaUtil(root->right,n1,n2,b1,b2);
        if(leftAns&&rightAns)
            return root;
        return leftAns==NULL?rightAns:leftAns;
    }
    bool findNode(TreeNode* root, int val){
        if(root==NULL)
            return false;;
        if(root->val==val)
            return true;
        return findNode(root->left,val)||findNode(root->right,val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool b1=false,b2=false;
        TreeNode* lca=lcaUtil(root,p->val,q->val,b1,b2);
        if(b1&&b2)
            return lca;
        if(b1&&findNode(lca, q->val))
            return lca;
        if(b2&&findNode(lca,p->val))
            return lca;
        return NULL;
        
    }
};