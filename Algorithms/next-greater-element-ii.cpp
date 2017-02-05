// 503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> result;
		vector<int> OPT(nums);
		OPT.insert(end(OPT), begin(nums), end(nums));
		for (size_t i = 0; i < nums.size(); i++) {
			size_t j = i + 1;
			while (j < OPT.size() && OPT[j] <= nums[i]) j++;
			if (j == OPT.size()) {
				result.push_back(-1);
				continue;
			}
			result.push_back(OPT[j]);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	vector<int> result;

	nums = {1, 2, 1};
	result = solution.nextGreaterElements(nums);
	assert(vector<int>({2, -1, 2}) == result);

	cout << "\nPassed All\n";
	return 0;
}