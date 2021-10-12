class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
def inorder(node):
    if(node == None):
        return
    inorder(node.left)
    print(node.key)
    inorder(node.right)
    
def buildTree(a, start, end):
    if(start > end):
        return None
    
    mid = int((start+end)/2)
    node = Node(a[mid])
    node.left = buildTree(a, start, mid-1)
    node.right = buildTree(a, mid+1, end)
    return node

n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

node = buildTree(a, 0, len(a) - 1)
inorder(node)