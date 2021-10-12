#for finding diameter we would use bottom up traversal i.e we would return hight and diameter of
#every node in this way we would not have to find the diameter and height seperatel of right and
#left subtree

class Node:
    def __init__(self, key):
        self.key = key
        self.right = None
        self.left = None
        
def fastDiameter(node):
    if(node == None):
        return [0, 0]
    left = fastDiameter(node.left)
    right = fastDiameter(node.right)
    return [1+max(left[0], right[0]), max(1+left[0]+right[0], left[1], right[1])]

root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 
print(fastDiameter(root))
    