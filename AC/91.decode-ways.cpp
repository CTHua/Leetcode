/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    map<string, int> solution;
    int numDecodings(string s) {
        int length = s.length();
        if(s == "")
            return 1;
        if(s[0]=='0')
            return 0;
        if(length == 1)
            return 1;
        if(solution.find(s)!=solution.end())
            return solution[s];
        if (stoi(s.substr(0, 2)) <= 26)
        {
            string left1 = s.substr(1);
            string left2 = s.substr(2);
            if(solution.find(left1)==solution.end())
                solution.insert(make_pair(left1,numDecodings(left1)));
            if(solution.find(left2)==solution.end())
                solution.insert(make_pair(left2,numDecodings(left2)));
            return solution[left1]+solution[left2];
        }
        else
        {
            string left1 = s.substr(1);
            if(solution.find(left1)==solution.end())
                solution.insert(make_pair(left1,numDecodings(left1)));
            return solution[left1];
        }
    }
};
// @lc code=end

