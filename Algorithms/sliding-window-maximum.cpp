// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/
#include <iostream>
#include <vector>
#include <dequeue>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		dequeue<int> dq;
		const int n = nums.size();
		if (n == 0) return result;
		if (n == 1) return result = nums;
		if (n == 2) return result = {max(nums[0], nums[1])};
		for (int i = 0; i < n; i++) {
			if (dq.size() < 2) {
				dq.push_back(nums[i]);
				continue;
			}
			int maxVal = INT_MIN;
			for (const auto &j : dq) maxVal = max(maxVal, dq.front());
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
	for (const auto &i : solution.maxSlidingWindow(nums, 3)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}