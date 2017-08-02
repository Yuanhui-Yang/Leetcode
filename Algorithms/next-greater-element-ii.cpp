// 503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/

/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int sz = nums.size();
		vector<int> result(sz, -1);
		stack<int> stk;
		for (int i = 0; i < 2 * sz; ++i) {
			while (!stk.empty() and nums[stk.top() % sz] < nums[i % sz]) {
				result[stk.top() % sz] = nums[i % sz];
				stk.pop();
			}
			stk.push(i);
		}
		return result;
	}
};

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int sz = nums.size();
		vector<int> result(2 * sz, -1);
		nums.insert(end(nums), begin(nums), end(nums));
		stack<int> stk;
		for (int i = 0; i < 2 * sz; ++i) {
			while (!stk.empty() and nums[stk.top()] < nums[i]) {
				result[stk.top()] = nums[i];
				stk.pop();
			}
			stk.push(i);
		}
		while (result.size() > sz) {
			result.pop_back();
		}
		return result;
	}
};