/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    vector<int> arr;
    void inorder(TreeNode* root) {
        if(root->left!=nullptr)
            inorder(root->left);
        arr.push_back(root->val);
        if(root->right!=nullptr)
            inorder(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        vector<int> ordered = arr;
        sort(ordered.begin(),ordered.end());
        int size = arr.size();
        for(int i=0;i<size;i++)
        {
            if(arr[i]!=ordered[i])
                return false;
            if(i<size-1&&arr[i+1]<=arr[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

