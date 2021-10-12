def sumReplacement(node):
    if(node == None):
        return 0
    node.key = node.key+sumReplacement(node.left)+sumReplacement(node.right)
    return node.key
def postOrder(node):
    if node == None:
        return
    postOrder(node.left)
    postOrder(node.right)
    print(node.key)

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
    
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 
sumReplacement(root)
postOrder(root)
