// 506. Relative Ranks
// https://leetcode.com/problems/relative-ranks/

/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		int sz = nums.size();
		vector<string> result(sz);
		vector<array<int, 2>> A(sz);
		for (int i = 0; i < sz; ++i) {
			A[i][0] = nums[i];
			A[i][1] = i;
		}
		sort(begin(A), end(A), greater<array<int, 2>>());
		for (int i = 0; i < sz; ++i) {
			if (i == 0) {
				result[A[i][1]] = "Gold Medal";
			}
			else if (i == 1) {
				result[A[i][1]] = "Silver Medal";
			}
			else if (i == 2) {
				result[A[i][1]] = "Bronze Medal";
			}
			else {
				result[A[i][1]] = to_string(i + 1);
			}
		}
		return result;
	}
};