/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // If any subtree is unbalanced or the difference in depths is greater than 1, return -1 to indicate unbalance.
        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        
        // Return the maximum depth of the current subtree plus 1.
        return max(leftDepth, rightDepth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
};
