// 480. Sliding Window Median
// https://leetcode.com/problems/sliding-window-median/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> result;
		multiset<int> rbtree;
		for (size_t i = 0; i < nums.size(); i++) {
			if (rbtree.size() + 1 < size_t(k)) {
				rbtree.insert(nums[i]);
				continue;
			}
			if (rbtree.size() + 1 == size_t(k)) {
				rbtree.insert(nums[i]);
				if (k & 1) {
					double median = double(*next(begin(rbtree), k >> 1));
					result.push_back(median);
					rbtree.erase(rbtree.lower_bound(nums[i + 1 - k]));
					continue;
				}
				else {
					double medianLeft = double(*next(begin(rbtree), (k >> 1) - 1));
					double medianRight = double(*next(begin(rbtree), k >> 1));
					double median = medianLeft / 2.0 + medianRight / 2.0;
					result.push_back(median);
					rbtree.erase(rbtree.lower_bound(nums[i + 1 - k]));
					continue;					
				}
				continue;
			}
			continue;
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<double> result;
	vector<int> nums;
	nums = {1, 3, -1, -3, 5, 3, 6, 7};
	result = solution.medianSlidingWindow(nums, 3);
	assert(vector<double>({1.0, -1.0, -1.0, 3.0, 5.0, 6.0}) == result);
	cout << "\nPassed All\n";
	return 0;
}