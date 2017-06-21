// 398. Random Pick Index
// https://leetcode.com/problems/random-pick-index/

/*
Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution(vector<int> nums) {
		this->nums.clear();
		this->nums = nums;
	}

	int pick(int target) {
		int result = -1;
		for (int n = nums.size(), i = 0, cnt = 0; i < n; ++i) {
			if (nums[i] == target) {
				if (rand() % (++cnt) == 0) {
					result = i;
				}
			}
		}
		return result;
	}
private:
	vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main(void) {
	vector<int> nums, results;
	Solution solution(nums);
	int result, target;

	nums = {1, 2, 3, 3, 3};
	solution = Solution(nums);
	target = 3;
	result = solution.pick(target);
	results.push_back(result);
	result = solution.pick(target);
	results.push_back(result);
	result = solution.pick(target);
	results.push_back(result);

	cout << "\nPassed All\n";
	return 0;
}