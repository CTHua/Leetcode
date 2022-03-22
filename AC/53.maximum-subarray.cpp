/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int length = nums.size();
        for(int i=1;i<length;i++)
        {
            nums[i] = max(nums[i]+nums[i-1],nums[i]);
            maximum = max(nums[i],maximum);
        }
        return maximum;
    }
};
// @lc code=end

