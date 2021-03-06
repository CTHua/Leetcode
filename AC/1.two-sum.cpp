/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                return vector<int>{hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end

