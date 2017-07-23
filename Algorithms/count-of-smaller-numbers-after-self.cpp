// 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		if (nums.empty()) {
			return {};
		}
		int sz = nums.size();
		vector<int> result(sz);
		pair<vector<int>::iterator, vector<int>::iterator> p = minmax_element(begin(nums), end(nums));
		int minVal = *(p.first), maxVal = *(p.second);
		vector<int> A(maxVal - minVal + 1, 0);
		for (int i = sz - 1; i >= 0; --i) {
			int upper = nums[i] - minVal, lower = nums[i] - minVal + 1;
			result[i] = f(A, upper);
			g(A, lower);
		}
		return result;
	}
private:
	int f(vector<int> & A, int upper) {
		int result = 0;
		while (upper >= 1) {
			result += A[upper];
			upper -= upper & (-upper);
		}
		return result;
	}
	void g(vector<int> & A, int lower) {
		int upper = A.size();
		while (lower <= upper) {
			++A[lower];
			lower += lower & (-lower);
		}
	}
};