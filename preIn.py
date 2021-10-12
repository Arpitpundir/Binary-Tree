ind = 0
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        
def binSearch(a, s, e, key):
    while(s<=e):
        mid = int((s+e)/2)
        if(a[mid] == key):
            return mid
        else if(a[mid] > key):
            binSearch(a, s, mid-1, key)
        else:
            binSearch(a, mid+1, e, key)
            
    return -1
def build(inOrd, preOrd, start, end):
    #start in preorer would always be the roor node
    if(start > end):
        return None
    key = preOrd[ind]
    node = Node(key)
    tempInd = binSearch(preOrd, start, end, key)
    node.left = build(preOrd, inOrd,start, ind-1)
    node.right = build(preOrd, inOrd, ind+1, end)
    return node
    
def inorder(node):
    if(node == None):
        return
    inorder(node.left)
    print(node.key)
    inorder(node.right)
    
n = int(input())
preOrd = []
inOrd = []
for i in range(n):
    preOrd.append(int(input()))
    
for i in range(n):
    inOrd.append(int(input()))
    
node = build(inOrd, preOrd, 0, n-1)
inOrder(node)