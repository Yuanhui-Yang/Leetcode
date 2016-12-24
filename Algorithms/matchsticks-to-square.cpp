// 473. Matchsticks to Square
// https://leetcode.com/problems/matchsticks-to-square/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <bitset>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/72107/java-dfs-solution-with-explanation
class Solution {
public:
	bool makesquare(vector<int>& nums) {
		const int nums_size = nums.size();
		if (nums_size < 4) return false;
		const int nums_sum = accumulate(begin(nums), end(nums), 0);
		if (nums_sum % 4) return false;
		const int nums_sum_part = nums_sum / 4;
		sort(begin(nums), end(nums), greater<int>());
		if (nums.front() > nums_sum_part) return false;
		vector<int> buckets(4, 0);
		return helper(0, buckets, nums_sum_part, nums_size, nums);
	}
private:
	bool helper(const int index,
				vector<int>& buckets,
				const int nums_sum_part,
				const int nums_size,
				const vector<int>& nums) {
		if (index == nums_size) {
			return buckets[0] == nums_sum_part && buckets[1] == nums_sum_part && buckets[2] == nums_sum_part && buckets[3] == nums_sum_part;
		}
		for (int i = 0; i < 4; i++) {
			if (buckets[i] + nums[index] <= nums_sum_part) {
				buckets[i] += nums[index];
				if (helper(index + 1, buckets, nums_sum_part, nums_size, nums)) {
					return true;
				}
				buckets[i] -= nums[index];
			}
		}
		return false;
	}
};
// END: https://discuss.leetcode.com/topic/72107/java-dfs-solution-with-explanation
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	bool makesquare(vector<int>& nums) {
// 		const int nums_size = nums.size();
// 		if (nums_size < 4) return false;
// 		const int nums_sum = accumulate(begin(nums), end(nums), 0);
// 		if (nums_sum % 4) return false;
// 		const int nums_sum_part = nums_sum / 4;
// 		sort(begin(nums), end(nums));
// 		if (nums.back() > nums_sum_part) return false;
// 		bitset<15> visited;
// 		return helper(visited, 0, 0, nums_size, nums_sum_part, nums_sum_part, nums);
// 	}
// private:
// 	bool helper(const bitset<15> visited,
// 				const int depth,
// 				const int num_visited,
// 				const int nums_size,
// 				const int target,
// 				const int nums_sum_part,
// 				const vector<int>& nums) {
// 		if (target < 0) return false;
// 		if (depth == 3) {
// 			return num_visited < nums_size;
// 		}
// 		for (int i = 0; i < 15 && i < nums_size; i++) {
// 			if (!visited[i]) {
// 				if (nums[i] > target) return false;
// 				bitset<15> visited_next(visited);
// 				visited_next[i] = 1;
// 				if (nums[i] == target) {
// 					if (helper(visited_next, depth + 1, num_visited + 1, nums_size, nums_sum_part, nums_sum_part, nums)) {
// 						return true; 
// 					}
// 				}
// 				else {
// 					if (helper(visited_next, depth, num_visited + 1, nums_size, target - nums[i], nums_sum_part, nums)) {
// 						return true;
// 					}
// 				}
// 			}
// 		}
// 		return false;
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	vector<int> nums;

	nums = {1, 1, 2, 2, 2};
	assert(true == solution.makesquare(nums));

	nums = {3, 3, 3, 3, 4};
	assert(false == solution.makesquare(nums));
	
	nums = {3, 1, 3, 3, 10, 7, 10, 3, 6, 9, 10, 3, 7, 6, 7};
	assert(true == solution.makesquare(nums));

	nums = {9, 9, 3, 6, 9, 2, 1, 5, 9, 6, 7, 2, 6, 8, 10};
	assert(true == solution.makesquare(nums));

	nums = {5969561, 8742425, 2513572, 3352059, 9084275, 2194427, 1017540, 2324577, 6810719, 8936380, 7868365, 2755770, 9954463, 9912280, 4713511};
	assert(false == solution.makesquare(nums));

	nums = {7215807, 6967211, 5551998, 6632092, 2802439, 821366, 2465584, 9415257, 8663937, 3976802, 2850841, 803069, 2294462, 8242205, 9922998};
	assert(false == solution.makesquare(nums));

	cout << "\nPassed All\n";
	return 0;
}