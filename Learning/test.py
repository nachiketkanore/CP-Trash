class TreeNode:
    def __init__(self, data, left = None, right = None):
        self.val = data
        self.left = left
        self.right = right
class Solution:
    def solve(self, root):
        def dfs(node):
            if not node:
                return 0, float("-inf")
            left_0, left_1 = dfs(node.left)
            right_0, right_1 = dfs(node.right)
            if node.val & 1:
                self.ans = max(self.ans, left_1 + right_0 + 1, left_0 + right_1 + 1)
                return max(left_1 + 1, right_1 + 1, 0), max(left_0 + 1, right_0 + 1)
            else:
                self.ans = max(self.ans, left_0 + right_0 + 1, left_1 + right_1 + 1)
                return max(left_0 + 1, right_0 + 1, 0), max(left_1 + 1, right_1 + 1)
    self.ans = 0
    dfs(root)
    return self.ans

