// 163. Missing Ranges
// https://leetcode.com/problems/missing-ranges/

/*
Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long a = lower, b;
        --a;
        for (int sz = nums.size(), i = 0; i <= sz; ++i) {
            b = i < sz ? nums[i] : (long)upper + 1;
            if (a + 2 == b) {
                string t = to_string(a + 1);
                result.push_back(t);
            }
            else if (a + 2 < b) {
                string t = to_string(a + 1) + "->" + to_string(b - 1);
                result.push_back(t);
            }
            a = b;
        }
        return result;
    }
};
