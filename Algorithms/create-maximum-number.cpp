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
		vector<int> result;
		maxNumber(k, result, 0, nums1, 0, nums2);
		return result;
	}
private:
	void maxNumber(size_t k, vector<int>& result, size_t idx1, vector<int>& nums1, size_t idx2, vector<int>& nums2) {
		if (k <= 0) {
			return;
		}
		if (k == 1) {
			if (idx1 >= nums1.size() && idx2 >= nums2.size()) {
				return;
			}
			if (idx1 == nums1.size()) {
				result.push_back(*max_element(next(begin(nums2), idx2), end(nums2)));
				return;
			}
			if (idx2 == nums2.size()) {
				result.push_back(*max_element(next(begin(nums1), idx1), end(nums1)));
				return;
			}
			result.push_back(max(*max_element(next(begin(nums1), idx1), end(nums1)), *max_element(next(begin(nums2), idx2), end(nums2))));
			return;
		}
		if (idx1 + idx2 + k == nums1.size() + nums2.size()) {
			if (idx1 >= nums1.size()) {
				result.insert(end(result), next(begin(nums2), idx2), end(nums2));
				return;
			}
			if (idx2 >= nums2.size()) {
				result.insert(end(result), next(begin(nums1), idx1), end(nums1));
				return;
			}
			if (nums1.at(idx1) < nums2.at(idx2)) {
				result.push_back(nums2.at(idx2));
				maxNumber(k - 1, result, idx1, nums1, idx2 + 1, nums2);
				return;
			}
			if (nums1.at(idx1) > nums2.at(idx2)) {
				result.push_back(nums1.at(idx1));
				maxNumber(k - 1, result, idx1 + 1, nums1, idx2, nums2);
				return;
			}
			if (nums1.at(idx1) == nums2.at(idx2)) {
				result.push_back(nums1.at(idx1));
				vector<int> result1(result);
				vector<int> result2(result);
				maxNumber(k - 1, result1, idx1 + 1, nums1, idx2, nums2);
				maxNumber(k - 1, result2, idx1, nums1, idx2 + 1, nums2);
				// cout << "\nresult1 =\t";
				// for (const auto &k : result1) {
				// 	cout << k << '\t';
				// }
				// cout << "\nresult2 =\t";
				// for (const auto &k : result2) {
				// 	cout << k << '\t';
				// }
				// cout << '\n';
				result = result1.size() == result2.size() ? max(result1, result2) : result1.size() < result2.size() ? result2 : result1;
				// cout << '\n';
				return;
			}
			return;
		}
		if (idx1 + idx2 + k < nums1.size() + nums2.size()) {
			if (idx1 >= nums1.size()) {
				vector<int>::iterator jt = max_element(next(begin(nums2), idx2), prev(end(nums2), k + idx1 - nums1.size() - 1));
				result.push_back(*jt);
				maxNumber(k - 1, result, idx1, nums1, distance(begin(nums2), jt) + 1, nums2);
				return;
			}
			if (idx2 >= nums2.size()) {
				vector<int>::iterator it = max_element(next(begin(nums1), idx1), prev(end(nums1), k + idx2 - nums2.size() - 1));
				result.push_back(*it);
				maxNumber(k - 1, result, distance(begin(nums1), it) + 1, nums1, idx2, nums2);
				return;
			}
			vector<int>::iterator it = nums2.size() >= idx2 + k ? max_element(next(begin(nums1), idx1), end(nums1)) : max_element(next(begin(nums1), idx1), prev(end(nums1), k + idx2 - nums2.size() - 1));
			vector<int>::iterator jt = nums1.size() >= idx1 + k ? max_element(next(begin(nums2), idx2), end(nums2)) : max_element(next(begin(nums2), idx2), prev(end(nums2), k + idx1 - nums1.size() - 1));
			if (*it < *jt) {
				result.push_back(*jt);
				maxNumber(k - 1, result, idx1, nums1, distance(begin(nums2), jt) + 1, nums2);
				return;
			}
			if (*it > *jt) {
				result.push_back(*it);
				maxNumber(k - 1, result, distance(begin(nums1), it) + 1, nums1, idx2, nums2);
				return;
			}
			if (*it == *jt) {
				result.push_back(*it);
				vector<int> result1(result);
				vector<int> result2(result);
				maxNumber(k - 1, result1, distance(begin(nums1), it) + 1, nums1, idx2, nums2);
				maxNumber(k - 1, result2, idx1, nums1, distance(begin(nums2), jt) + 1, nums2);
				result = result1.size() == result2.size() ? max(result1, result2) : result1.size() < result2.size() ? result2 : result1;
				return;
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

	nums1 = {8, 9, 7, 3, 5, 9, 1, 0, 8, 5, 3, 0, 9, 2, 7, 4, 8, 9, 8, 1, 0, 2, 0, 2, 7, 2, 3, 5, 4, 7, 4, 1, 4, 0, 1, 4, 2, 1, 3, 1, 5, 3, 9, 3, 9, 0, 1, 7, 0, 6, 1, 8, 5, 6, 6, 5, 0, 4, 7, 2, 9, 2, 2, 7, 6, 2, 9, 2, 3, 5, 7, 4, 7, 0, 1, 8, 3, 6, 6, 3, 0, 8, 5, 3, 0, 3, 7, 3, 0, 9, 8, 5, 1, 9, 5, 0, 7, 9, 6, 8, 5, 1, 9, 6, 5, 8, 2, 3, 7, 1, 0, 1, 4, 3, 4, 4, 2, 4, 0, 8, 4, 6, 5, 5, 7, 6, 9, 0, 8, 4, 6, 1, 6, 7, 2, 0, 1, 1, 8, 2, 6, 4, 0, 5, 5, 2, 6, 1, 6, 4, 7, 1, 7, 2, 2, 9, 8, 9, 1, 0, 5, 5, 9, 7, 7, 8, 8, 3, 3, 8, 9, 3, 7, 5, 3, 6, 1, 0, 1, 0, 9, 3, 7, 8, 4, 0, 3, 5, 8, 1, 0, 5, 7, 2, 8, 4, 9, 5, 6, 8, 1, 1, 8, 7, 3, 2, 3, 4, 8, 7, 9, 9, 7, 8, 5, 2, 2, 7, 1, 9, 1, 5, 5, 1, 3, 5, 9, 0, 5, 2, 9, 4, 2, 8, 7, 3, 9, 4, 7, 4, 8, 7, 5, 0, 9, 9, 7, 9, 3, 8, 0, 9, 5, 3, 0, 0, 3, 0, 4, 9, 0, 9, 1, 6, 0, 2, 0, 5, 2, 2, 6, 0, 0, 9, 6, 3, 4, 1, 2, 0, 8, 3, 6, 6, 9, 0, 2, 1, 6, 9, 2, 4, 9, 0, 8, 3, 9, 0, 5, 4, 5, 4, 6, 1, 2, 5, 2, 2, 1, 7, 3, 8, 1, 1, 6, 8, 8, 1, 8, 5, 6, 1, 3, 0, 1, 3, 5, 6, 5, 0, 6, 4, 2, 8, 6, 0, 3, 7, 9, 5, 5, 9, 8, 0, 4, 8, 6, 0, 8, 6, 6, 1, 6, 2, 7, 1, 0, 2, 2, 4, 0, 0, 0, 4, 6, 5, 5, 4, 0, 1, 5, 8, 3, 2, 0, 9, 7, 6, 2, 6, 9, 9, 9, 7, 1, 4, 6, 2, 8, 2, 5, 3, 4, 5, 2, 4, 4, 4, 7, 2, 2, 5, 3, 2, 8, 2, 2, 4, 9, 8, 0, 9, 8, 7, 6, 2, 6, 7, 5, 4, 7, 5, 1, 0, 5, 7, 8, 7, 7, 8, 9, 7, 0, 3, 7, 7, 4, 7, 2, 0, 4, 1, 1, 9, 1, 7, 5, 0, 5, 6, 6, 1, 0, 6, 9, 4, 2, 8, 0, 5, 1, 9, 8, 4, 0, 3, 1, 2, 4, 2, 1, 8, 9, 5, 9, 6, 5, 3, 1, 8, 9, 0, 9, 8, 3, 0, 9, 4, 1, 1, 6, 0, 5, 9, 0, 8, 3, 7, 8, 5};
	nums2 = {7, 8, 4, 1, 9, 4, 2, 6, 5, 2, 1, 2, 8, 9, 3, 9, 9, 5, 4, 4, 2, 9, 2, 0, 5, 9, 4, 2, 1, 7, 2, 5, 1, 2, 0, 0, 5, 3, 1, 1, 7, 2, 3, 3, 2, 8, 2, 0, 1, 4, 5, 1, 0, 0, 7, 7, 9, 6, 3, 8, 0, 1, 5, 8, 3, 2, 3, 6, 4, 2, 6, 3, 6, 7, 6, 6, 9, 5, 4, 3, 2, 7, 6, 3, 1, 8, 7, 5, 7, 8, 1, 6, 0, 7, 3, 0, 4, 4, 4, 9, 6, 3, 1, 0, 3, 7, 3, 6, 1, 0, 0, 2, 5, 7, 2, 9, 6, 6, 2, 6, 8, 1, 9, 7, 8, 8, 9, 5, 1, 1, 4, 2, 0, 1, 3, 6, 7, 8, 7, 0, 5, 6, 0, 1, 7, 9, 6, 4, 8, 6, 7, 0, 2, 3, 2, 7, 6, 0, 5, 0, 9, 0, 3, 3, 8, 5, 0, 9, 3, 8, 0, 1, 3, 1, 8, 1, 8, 1, 1, 7, 5, 7, 4, 1, 0, 0, 0, 8, 9, 5, 7, 8, 9, 2, 8, 3, 0, 3, 4, 9, 8, 1, 7, 2, 3, 8, 3, 5, 3, 1, 4, 7, 7, 5, 4, 9, 2, 6, 2, 6, 4, 0, 0, 2, 8, 3, 3, 0, 9, 1, 6, 8, 3, 1, 7, 0, 7, 1, 5, 8, 3, 2, 5, 1, 1, 0, 3, 1, 4, 6, 3, 6, 2, 8, 6, 7, 2, 9, 5, 9, 1, 6, 0, 5, 4, 8, 6, 6, 9, 4, 0, 5, 8, 7, 0, 8, 9, 7, 3, 9, 0, 1, 0, 6, 2, 7, 3, 3, 2, 3, 3, 6, 3, 0, 8, 0, 0, 5, 2, 1, 0, 7, 5, 0, 3, 2, 6, 0, 5, 4, 9, 6, 7, 1, 0, 4, 0, 9, 6, 8, 3, 1, 2, 5, 0, 1, 0, 6, 8, 6, 6, 8, 8, 2, 4, 5, 0, 0, 8, 0, 5, 6, 2, 2, 5, 6, 3, 7, 7, 8, 4, 8, 4, 8, 9, 1, 6, 8, 9, 9, 0, 4, 0, 5, 5, 4, 9, 6, 7, 7, 9, 0, 5, 0, 9, 2, 5, 2, 9, 8, 9, 7, 6, 8, 6, 9, 2, 9, 1, 6, 0, 2, 7, 4, 4, 5, 3, 4, 5, 5, 5, 0, 8, 1, 3, 8, 3, 0, 8, 5, 7, 6, 8, 7, 8, 9, 7, 0, 8, 4, 0, 7, 0, 9, 5, 8, 2, 0, 8, 7, 0, 3, 1, 8, 1, 7, 1, 6, 9, 7, 9, 7, 2, 6, 3, 0, 5, 3, 6, 0, 5, 9, 3, 9, 1, 1, 0, 0, 8, 1, 4, 3, 0, 4, 3, 7, 7, 7, 4, 6, 4, 0, 0, 5, 7, 3, 2, 8, 5, 1, 4, 5, 8, 5, 6, 7, 5, 7, 3, 3, 9, 6, 8, 1, 5, 1, 1, 1, 0, 3};
	k = 500;
	answer = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 5, 3, 6, 4, 2, 6, 3, 6, 7, 6, 6, 9, 5, 4, 3, 2, 7, 6, 3, 1, 8, 7, 5, 7, 8, 1, 6, 0, 7, 3, 0, 4, 4, 4, 9, 6, 3, 1, 0, 3, 7, 3, 6, 1, 0, 0, 2, 5, 7, 2, 9, 6, 6, 2, 6, 8, 1, 9, 7, 8, 8, 9, 5, 1, 1, 4, 2, 0, 1, 3, 6, 7, 8, 7, 0, 5, 6, 0, 1, 7, 9, 6, 4, 8, 6, 7, 0, 2, 3, 2, 7, 6, 0, 5, 0, 9, 0, 3, 3, 8, 5, 0, 9, 3, 8, 0, 1, 3, 1, 8, 1, 8, 1, 1, 7, 5, 7, 4, 1, 0, 0, 0, 8, 9, 5, 7, 8, 9, 2, 8, 3, 0, 3, 4, 9, 8, 1, 7, 2, 3, 8, 3, 5, 3, 1, 4, 7, 7, 5, 4, 9, 2, 6, 2, 6, 4, 0, 0, 2, 8, 3, 3, 0, 9, 1, 6, 8, 3, 1, 7, 0, 7, 1, 5, 8, 3, 2, 5, 1, 1, 0, 3, 1, 4, 6, 3, 6, 2, 8, 6, 7, 2, 9, 5, 9, 1, 6, 0, 5, 4, 8, 6, 6, 9, 4, 0, 5, 8, 7, 0, 8, 9, 7, 3, 9, 0, 1, 0, 6, 2, 7, 3, 3, 2, 3, 3, 6, 3, 0, 8, 0, 0, 5, 2, 1, 0, 7, 5, 0, 3, 2, 6, 0, 5, 4, 9, 6, 7, 1, 0, 4, 0, 9, 6, 8, 3, 1, 2, 5, 0, 1, 0, 6, 8, 6, 6, 8, 8, 2, 4, 5, 0, 0, 8, 0, 5, 6, 2, 2, 5, 6, 3, 7, 7, 8, 4, 8, 4, 8, 9, 1, 6, 8, 9, 9, 0, 4, 0, 5, 5, 4, 9, 6, 7, 7, 9, 0, 5, 0, 9, 2, 5, 2, 9, 8, 9, 7, 6, 8, 6, 9, 2, 9, 1, 6, 0, 2, 7, 4, 4, 5, 3, 4, 5, 5, 5, 0, 8, 1, 3, 8, 3, 0, 8, 5, 7, 6, 8, 7, 8, 9, 7, 0, 8, 4, 0, 7, 0, 9, 5, 8, 2, 0, 8, 7, 0, 3, 1, 8, 1, 7, 1, 6, 9, 7, 9, 7, 2, 6, 3, 0, 5, 3, 6, 0, 5, 9, 3, 9, 1, 1, 0, 0, 8, 1, 4, 3, 0, 4, 3, 7, 7, 7, 4, 6, 4, 0, 0, 5, 7, 3, 2, 8, 5, 1, 4, 5, 8, 5, 6, 7, 5, 7, 3, 3, 9, 6, 8, 1, 5, 1, 1, 1, 0, 3};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {2, 5, 6, 4, 4, 0};
	nums2 = {7, 3, 8, 0, 6, 5, 7, 6, 2};
	k = 15;
	answer = {7, 3, 8, 2, 5, 6, 4, 4, 0, 6, 5, 7, 6, 2, 0};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {2, 5, 6, 4, 4, 0};
	nums2 = {7, 3, 8, 0, 6, 5, 7, 6, 2};
	k = 15;
	answer = {7, 3, 8, 2, 5, 6, 4, 4, 0, 6, 5, 7, 6, 2, 0};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {6, 6, 8};
	nums2 = {5, 0, 9};
	k = 3;
	answer = {9, 6, 8};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {8, 9};
	nums2 = {3, 9};
	k = 3;
	answer = {9, 8, 9};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

	nums1 = {};
	nums2 = {1};
	k = 1;
	answer = {1};
	result = solution.maxNumber(nums1, nums2, k);
	assert(answer == result);

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