// 324. Wiggle Sort II
// https://leetcode.com/problems/wiggle-sort-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: http://www.jiuzhang.com/solutions/wiggle-sort-ii/
// BEGIN: https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
// BEGIN: https://discuss.leetcode.com/topic/32920/o-n-time-o-1-space-solution-with-detail-explanations
// BEGIN: http://en.cppreference.com/w/cpp/algorithm/nth_element
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 2) {
			sort(begin(nums), end(nums));
			return;
		}
		nth_element(begin(nums), begin(nums) + n / 2, end(nums));
		int median = nums[n / 2];
		vector<int> result(n, median);
		for (int i = 0, j = 1; i < n; i++) {
			if (j < n && nums[i] > result[j]) {
				result[j] = nums[i];
				j += 2;
			}
		}
		for (int i = 0, j = (n & 1) ? (n - 1) : (n - 2); i < n; i++) {
			if (j >= 0 && nums[i] < result[j]) {
				result[j] = nums[i];
				j -= 2;
			}
		}
		nums = result;
	}
};
// END: http://en.cppreference.com/w/cpp/algorithm/nth_element
// END: https://discuss.leetcode.com/topic/32920/o-n-time-o-1-space-solution-with-detail-explanations
// END: https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
// END: http://www.jiuzhang.com/solutions/wiggle-sort-ii/
int main(void) {
	Solution solution;
	vector<int> nums;

	nums = {1, 5, 1, 1, 6, 4};
	solution.wiggleSort(nums);
	for (const auto &i : nums) cout << i << '\t';
	cout << '\n';
	
	nums = {1, 3, 2, 2, 3, 1};
	solution.wiggleSort(nums);
	for (const auto &i : nums) cout << i << '\t';
	cout << '\n';	
	
	cout << "\nPassed All\n";
	return 0;
}