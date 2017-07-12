// 228. Summary Ranges
// https://leetcode.com/problems/summary-ranges/

/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		for (int n = nums.size(), i = 0; i < n; ++i) {
			int a = nums[i], b = nums[i];
			while (i + 1 < n and nums[i + 1] == b + 1) {
				++i;
				++b;
			}
			if (a == b) {
				result.push_back(to_string(a));
			}
			else {
				result.push_back(to_string(a) + "->" + to_string(b));
			}
		}
		return result;
	}
};