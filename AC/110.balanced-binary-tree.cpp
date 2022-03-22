/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
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
    int getTreeHeight(TreeNode* root, int depth) { 
        if (root == nullptr)
            return depth;
        return max(getTreeHeight(root->left,depth+1), getTreeHeight(root->right,depth+1));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        else
        {
            int heightL = getTreeHeight(root->left,0);
            int heightR = getTreeHeight(root->right,0);
            int diff = heightL - heightR;
            diff = diff < 0 ? diff*-1 : diff;
            return diff <= 1&&isBalanced(root->left)&&isBalanced(root->right);

        }
    }
};
// @lc code=end

