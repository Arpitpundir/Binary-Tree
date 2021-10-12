# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return buildTreeRec(0, len(inorder)-1, preorder, inorder)
        
def buildTreeRec(st, end, pre, inord):
    #print(st, end)
    if(st > end):
        return None
    curr = TreeNode(pre.pop(0))
    currInd = Search(curr.val, inord)
    #print(Solution.preIndex, st, end, currInd, curr.val)

    if(st == end):
        return curr
    curr.left = buildTreeRec(st, currInd-1, pre, inord)
    curr.right = buildTreeRec(currInd+1, end, pre, inord)
    return curr


def Search(val, a):
    for i in range(len(a)):
        if(a[i] == val):
            return i
        
#small recuursive soln

def buildTree(self, preorder, inorder):
    if inorder:
        ind = inorder.index(preorder.pop(0))
        root = TreeNode(inorder[ind])
        root.left = self.buildTree(preorder, inorder[0:ind])
        root.right = self.buildTree(preorder, inorder[ind+1:])
        return root