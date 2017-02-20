// 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include <iostream>
#include <cassert>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

// BEGIN: https://discuss.leetcode.com/topic/31288/c-o-nlogn-time-o-n-space-mergesort-solution-with-detail-explanation
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		if (nums.empty()) {
			return {};
		}
		vector<int> result(nums.size(), 0);
		vector<pair<int, size_t>> numsIdxs;
		for (size_t i = 0; i < nums.size(); i++) {
			numsIdxs.push_back(make_pair(nums[i], i));
		}
		countSmaller(begin(numsIdxs), end(numsIdxs), result);
		return result;
	}
private:
	void countSmaller(vector<pair<int, size_t>>::iterator begin,
		vector<pair<int, size_t>>::iterator end,
		vector<int>& result) {
		if (distance(begin, end) <= 1) {
			return;
		}
		vector<pair<int, size_t>>::iterator mid =  next(begin, distance(begin, end) / 2);
		countSmaller(begin, mid, result);
		countSmaller(mid, end, result);
		for (vector<pair<int, size_t>>::iterator it = begin; it != mid; it++) {
			result[it->second] += distance(mid, lower_bound(mid, end, *it));
		}
		inplace_merge(begin, mid, end);
	}
};
// END: https://discuss.leetcode.com/topic/31288/c-o-nlogn-time-o-n-space-mergesort-solution-with-detail-explanation

// BEGIN: https://discuss.leetcode.com/topic/39656/short-java-binary-index-tree-beat-97-33-with-detailed-explanation
// class Solution {
// public:
// 	vector<int> countSmaller(vector<int>& nums) {
// 		vector<int> result;
// 		if (nums.empty()) return result;
// 		pair<vector<int>::iterator, vector<int>::iterator> MinMaxItr = minmax_element(begin(nums), end(nums));
// 		int minVal = *(MinMaxItr.first);
// 		for (auto &i : nums) i += 1 - minVal;
// 		vector<int> tree(*(MinMaxItr.second) + 1, 0);
// 		for (int i = nums.size() - 1; i >= 0; i--) {
// 			result.push_back(this->read(nums[i] - 1, tree));
// 			this->update(nums[i], tree);
// 		}
// 		reverse(begin(result), end(result));
// 		return result;
// 	}
// private:
// 	int read(int i, vector<int>& tree) {
// 		int result = 0;
// 		while (i) {
// 			result += tree[i];
// 			i -= i & (-i);
// 		}
// 		return result;
// 	}
// 	void update(int i, vector<int>& tree) {
// 		while (i < (int)tree.size()) {
// 			tree[i]++;
// 			i += i & (-i);
// 		}
// 	}
// };
// END: https://discuss.leetcode.com/topic/39656/short-java-binary-index-tree-beat-97-33-with-detailed-explanation

// BEGIN: https://discuss.leetcode.com/topic/36736/c-14-line-solution
// class Solution {
// public:
// 	vector<int> countSmaller(vector<int>& nums) {
// 		vector<int> result(nums.size(), 0), x;
// 		for (int i = nums.size() - 1; i >= 0; i--) {
// 			vector<int>::iterator it = lower_bound(begin(x), end(x), nums[i]);
// 			result[i] = it - begin(x);
// 			x.insert(it, nums[i]);
// 		}
// 		return result;
// 	}
// };
// END: https://discuss.leetcode.com/topic/36736/c-14-line-solution

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<int> countSmaller(vector<int>& nums) {
// 		vector<int> result(nums.size(), 0);
// 		for (size_t i = 0; i < nums.size(); i++)
// 			for (size_t j = i + 1; j < nums.size(); j++)
// 				if (nums[j] < nums[i])
// 					result[i]++;
// 		return result;
// 	}
// };
// END: Time Limit Exceeded

int main(void) {
	Solution solution;
	vector<int> nums;
	vector<int> result;
	vector<int> answer;

	nums = {5, 2, 6, 1};
	result = solution.countSmaller(nums);
	answer = {2, 1, 1, 0};
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}