/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 */

// @lc code=start
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int size = nums.size();
        long long ans = 0;
        stack<int> s;
        for (int q = 0; q <= size; q++)
        {
            while (!s.empty() && (q == size || nums[s.top()] < nums[q]))
            {
                long long i = s.top();
                s.pop();
                long long p = s.empty() ? -1 : s.top();
                ans += nums[i] * (i - p) * (q - i);
            }
            s.push(q);
        }
        while(!s.empty())
            s.pop();
        for (int q = 0; q <= size; q++)
        {
            while (!s.empty() && (q == size || nums[s.top()] > nums[q]))
            {
                long long i = s.top();
                s.pop();
                long long p = s.empty() ? -1 : s.top();
                ans -= nums[i] * (i - p) * (q - i);
            }
            s.push(q);
        }
        return ans;
    }
};
// @lc code=end
