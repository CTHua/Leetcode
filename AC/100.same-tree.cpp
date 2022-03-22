/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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

    string dfs(TreeNode *root){
        if(root->left == nullptr && root->right == nullptr)
            return to_string(root->val);
        else
        {
            string result = to_string(root->val)+", ";
            if(root->left!=nullptr)
                result += dfs(root->left)+", ";
            else
                result += "null, ";
            if(root->right!=nullptr)
                result += dfs(root->right)+", ";
            else
                result += "null, ";
            return result;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)
            return true;
        if(p==nullptr)
            return false;
        if(q==nullptr)
            return false;
        string t1 = dfs(p);
        cout<<t1<<endl;
        string t2 = dfs(q);
        cout<<t2<<endl;
        return t1 == t2;
    }
};
// @lc code=end

