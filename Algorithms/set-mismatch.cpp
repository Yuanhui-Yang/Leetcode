// 645. Set Mismatch
// https://leetcode.com/problems/set-mismatch/

/*
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> result;
		int sz = nums.size();
		for (int i = 0; i < sz; ++i) {
			while (nums[i] != i + 1 and nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < sz; ++i) {
			if (nums[i] != i + 1) {
				result.push_back(nums[i]);
				result.push_back(i + 1);
				break;
			}
		}
		return result;
	}
};