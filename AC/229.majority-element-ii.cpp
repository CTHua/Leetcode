/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int nDiv3 = n / 3;
        sort(nums.begin(), nums.end());
        if(n == 1)
            return nums;
        vector<int> result;
        int now = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if(nums[i] == now)
            {
                count++;
            }
            else
            {
                if(count > nDiv3)
                    result.push_back(now);
                now = nums[i];
                count = 1;
            }
        }
        if(now == nums[n-1] && count > nDiv3)
            result.push_back(now);
            
        return result;        
    }
};
// @lc code=end

