/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
            return nums[0];
        if(size <= 2)
            return max(nums[0], nums[1]);
        int maximum = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) 
        {
            int local_maximum = 0;
            for(int j = 0; j < i-1; j++)
                local_maximum = max(local_maximum, nums[j]);
            nums[i] += local_maximum;
            maximum = max(maximum, nums[i]);
        }
        return maximum;
    }
};
// @lc code=end

