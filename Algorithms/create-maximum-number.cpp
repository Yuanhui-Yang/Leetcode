// 321. Create Maximum Number
// https://leetcode.com/problems/create-maximum-number/
#include <iostream>
#include <cassert>
#include <cmath>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		if (k <= 0) {
			return {};
		}
		if (k == 1) {
			return {max(*max_element(begin(nums1), end(nums1)), *max_element(begin(nums2), end(nums2)))};
		}
		vector<int> result;
		maxNumber(k, result, 0, nums1, 0, nums2);
		return result;
	}
private:
	void maxNumber(size_t k, vector<int>& result,
		const size_t idx1, const vector<int>& nums1,
		const size_t idx2, const vector<int>& nums2) {
		if (k == 0) {
			return;
		}
		if (k == 1) {
			if (idx1 == nums1.size()) {
				result.push_back(*max_element(next(begin(nums2), idx2), end(nums2)));
				return;
			}
			if (idx2 == nums2.size()) {
				result.push_back(*max_element(next(begin(nums1), idx1), end(nums1)));
				return;
			}
			result.push_back(*max_element(next(begin(nums1), idx1), end(nums1)),
				*max_element(next(begin(nums2), idx2), end(nums2)));
			return;
		}
		if (idx1 + idx2 + k == nums1.size() + nums2.size()) {
			for (size_t i = idx1, j = idx2; i < nums1.size() || j < nums2.size(); ) {
				if (i >= nums1.size()) {
					result.push_back(nums2.at(j));
					j++;
					continue;
				}
				if (j >= nums2.size()) {
					result.push_back(nums1.at(i));
					i++;
					continue;
				}
				if (nums1.at(i) < nums2.at(j)) {
					result.push_back(nums2.at(j));
					j++;
				}
				else {
					result.push_back(nums1.at(i));
					i++;
				}
			}
			return;
		}
		if (idx1 + idx2 + k < nums1.size() + nums2.size()) {
			if (idx1 >= nums1.size()) {
				size_t i = idx2;
				for (size_t j = idx2; j + k < nums2.size() + 1; j++) {
					if (nums2.at(i) < nums2.at(j)) {
						i = j;
					}
				}
				result.push_back(nums2.at(i));
				maxNumber(k - 1, result, idx1, nums1, i + 1, nums2);
				return;
			}
			if (idx2 >= nums2.size()) {
				size_t i = idx1;
				for (size_t j = idx1; j + k < nums1.size() + 1; j++) {
					if (nums1.at(i) < nums1.at(j)) {
						i = j;
					}
				}
				result.push_back(nums1.at(i));
				maxNumber(k - 1, result, i + 1, nums1, idx2, nums2);
				return;
			}
			if (nums1.size() >= k + idx1) {
				size_t i = idx2;
				for (size_t j = )
			}
		}
	}
};
int main(void) {
	Solution solution;
	vector<int> nums1;
	vector<int> nums2;
	int k = 0;
	vector<int> result;
	vector<int> answer;

	nums1 = {3, 4, 6, 5};
	nums2 = {9, 1, 2, 5, 8, 3};
	k = 5;
	answer = {9, 8, 6, 5, 3};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {6, 7};
	nums2 = {6, 0, 4};
	k = 5;
	answer = {6, 7, 6, 0, 4};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {3, 9};
	nums2 = {8, 9};
	k = 3;
	answer = {9, 8, 9};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}