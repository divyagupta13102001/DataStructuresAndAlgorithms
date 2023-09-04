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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }

private:
    int calculateDiameter(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }

        // Calculate the depths of the left and right subtrees
        int leftDepth = calculateDiameter(root->left, diameter);
        int rightDepth = calculateDiameter(root->right, diameter);

        // Update the diameter if a longer path is found
        diameter = max(diameter, leftDepth + rightDepth);

        // Return the maximum depth of the current subtree plus 1
        return max(leftDepth, rightDepth) + 1;
    }
};
