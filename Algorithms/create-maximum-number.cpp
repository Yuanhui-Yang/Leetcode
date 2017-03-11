// 321. Create Maximum Number
// https://leetcode.com/problems/create-maximum-number/

// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

// Example 1:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// return [9, 8, 6, 5, 3]

// Example 2:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// return [6, 7, 6, 0, 4]

// Example 3:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// return [9, 8, 9]

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // memset
#include <algorithm> // max; min; min_element; max_element; minmax_element; next_permutation; prev_permutation; nth_element; sort; swap; lower_bound; upper_bound; reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::string::npos
#include <list>
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

// BEGIN: https://discuss.leetcode.com/topic/32272/share-my-greedy-solution
// BEGIN: https://discuss.leetcode.com/topic/36805/c-16ms-fastest-beats-97
class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		if (k <= 0 or (nums1.empty() and nums2.empty()) or nums1.size() + nums2.size() < size_t(k)) {
			return {};
		}
		if (nums1.size() > nums2.size()) {
			return maxNumber(nums2, nums1, k);
		}
		if (nums1.empty()) {
			return maxArray(nums1, nums2, k);
		}
		vector<int> result;
		for (size_t i = 0; i <= k)
		return result;
	}
private:
	vector<int> merge(vector<int>& nums1, vector<int>& nums2) {

	}
private:
	vector<int> maxArray(vector<int>& nums, size_t k) {
		if (k == 0 or nums.empty() or nums.size() < k) {
			return {};
		}
		if (nums.size() == k) {
			return nums;
		}
		if (k == 1) {
			return {*max_element(begin(nums), end(nums))};
		}
		vector<int> result;
		for (size_t i = 0, j = nums.size() - k; j < nums.size(); i++, j++) {
			for (size_t l = i + 1; l <= j; l++) {
				if (nums.at(i) < nums.at(l)) {
					i = l;
				}
			}
			result.push_back(nums.at(i));
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/36805/c-16ms-fastest-beats-97
// END: https://discuss.leetcode.com/topic/32272/share-my-greedy-solution

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
// 		vector<int> result;
// 		maxNumber(k, result, begin(nums1), end(nums1), begin(nums2), end(nums2));
// 		return result;
// 	}
// private:
// 	void maxNumber(long long k, vector<int>& result, vector<int>::iterator begin1, vector<int>::iterator end1, vector<int>::iterator begin2, vector<int>::iterator end2) {
// 		if (k <= 0 or (begin1 == end1 and begin2 == end2) or (distance(begin1, end1) + distance(begin2, end2) < k)) {
// 			return;
// 		}
// 		if (begin1 == end1) {
// 			vector<int>::iterator it = max_element(begin2, prev(end2, k - 1));
// 			result.push_back(*it);
// 			maxNumber(k - 1, result, begin1, end1, next(it), end2);
// 			return;
// 		}
// 		if (begin2 == end2) {
// 			vector<int>::iterator it = max_element(begin1, prev(end1, k - 1));
// 			result.push_back(*it);
// 			maxNumber(k - 1, result, next(it), end1, begin2, end2);
// 			return;
// 		}
// 		vector<int>::iterator it = distance(begin2, end2) >= k ? max_element(begin1, end1) : max_element(begin1, prev(end1, k - distance(begin2, end2) - 1));
// 		vector<int>::iterator jt = distance(begin1, end1) >= k ? max_element(begin2, end2) : max_element(begin2, prev(end2, k - distance(begin1, end1) - 1));
// 		if (*it < *jt) {
// 			result.push_back(*jt);
// 			maxNumber(k - 1, result, begin1, end1, next(jt), end2);
// 			return;
// 		}
// 		if (*it > *jt) {
// 			result.push_back(*it);
// 			maxNumber(k - 1, result, next(it), end1, begin2, end2);
// 			return;
// 		}
// 		if (*it == *jt) {
// 			result.push_back(*it);
// 			vector<int> result1(result);
// 			vector<int> result2(result);
// 			maxNumber(k - 1, result1, next(it), end1, begin2, end2);
// 			maxNumber(k - 1, result2, begin1, end1, next(jt), end2);
// 			result = result1.size() == result2.size() ? max(result1, result2) : result1.size() < result2.size() ? result2 : result1;
// 			return;
// 		}
// 	}
// };
// END: Time Limit Exceeded

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