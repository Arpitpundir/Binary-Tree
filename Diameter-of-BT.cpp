class Solution {
public:
    int findDiameter( TreeNode* root, int &diameter){
      if(root==NULL)
      return 0;
      int leftHeight=findDiameter(root->left,diameter);
      int rightHeight=findDiameter(root->right,diameter);
      diameter=max(diameter,leftHeight+rightHeight);
      return 1+max(leftHeight,rightHeight);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        findDiameter(root,diameter);
        return diameter;
    }
};