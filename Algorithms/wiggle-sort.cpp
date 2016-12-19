// 280. Wiggle Sort
// https://leetcode.com/problems/wiggle-sort/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		const int n = nums.size();
		if (n < 2) return;
		for (int i = 1; i < n; i++) {
			if (i & 1) {
				if (nums[i - 1] <= nums[i]) continue;
				swap(nums[i - 1], nums[i]);
				continue;
			}
			if (nums[i - 1] <= nums[i]) {
				swap(nums[i - 1], nums[i]);
				continue;				
			}
		}
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	nums = {3, 5, 2, 1, 6, 4};
	solution.wiggleSort(nums);
	for (const auto &i : nums) cout << i << '\t';
	cout << '\n';
	cout << "\nPassed All\n";
	return 0;
}