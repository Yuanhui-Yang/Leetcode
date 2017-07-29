// 494. Target Sum
// https://leetcode.com/problems/target-sum/

/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = accumulate(begin(nums), end(nums), 0);
		if (S < -sum or sum < S) {
			return 0;
		}
		int sz = nums.size();
		vector<vector<int>> A(sz, vector<int>(2001, -1));
		return f(A, nums, 0, sz, 0, S);
	}
private:
	int f(vector<vector<int>> & A, vector<int>& nums, int index, int sz, int curr, int S) {
		if (index == sz) {
			return curr == S;
		}
		if (A[index][curr + 1000] >= 0) {
			return A[index][curr + 1000];
		}
		return A[index][curr + 1000] = f(A, nums, index + 1, sz, curr - nums[index], S) + f(A, nums, index + 1, sz, curr + nums[index], S);
	}
};

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		return f(nums, 0, nums.size(), S);
	}
private:
	int f(vector<int>& nums, int index, int sz, int S) {
		if (index == sz) {
			return S == 0;
		}
		return f(nums, index + 1, sz, S - nums[index]) + f(nums, index + 1, sz, S + nums[index]);
	}
};