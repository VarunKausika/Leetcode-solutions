# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # Iterative approach
        inorder = []
        stack = [root]
        
        if not root:
            return inorder
        
        while stack:
            node = stack.pop()
            if node.left and node.left not in inorder:
                stack.append(node)
                stack.append(node.left)
            else:
                inorder.append(node)
                if node.right:
                    stack.append(node.right)
                    
        inorder = [x.val for x in inorder]
        
        return inorder
            
                
                