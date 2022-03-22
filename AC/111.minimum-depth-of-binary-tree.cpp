/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minimum = 2147483647;
    void bfs(TreeNode *root, int depth)
    {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
        {
            minimum = min(minimum, depth);
            return;
        }
        else
        {
            bfs(root->left, depth + 1);
            bfs(root->right, depth + 1);
        }
    }
    int minDepth(TreeNode* root) 
    {
        if(root== nullptr)
            return 0;
        bfs(root, 1);    
        return minimum;
    }
};
// @lc code=end

