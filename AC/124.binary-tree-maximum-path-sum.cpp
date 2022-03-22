/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maximum = -2147483648;
    int dfs(TreeNode* root) {
        if(root==nullptr) return 0;
        int sumLeft = dfs(root->left);
        int sumRight = dfs(root->right);
        int res = root->val+max(max(sumLeft,sumRight), 0);
        maximum = max(maximum, max(res,root->val+sumLeft+sumRight));
        return res;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maximum;
    }
};
// @lc code=end

