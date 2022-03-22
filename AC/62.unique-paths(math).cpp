/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int combine(int m, int n)
    {
        double res = 1, div = 1;
        for (int i = 1; i <= n; i++)
            res*=m--,div*=i;
        return res/div;
    }
    int uniquePaths(int m, int n) {
       return combine(m+n-2,min(m,n)-1);
    }
};
// @lc code=end

