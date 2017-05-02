// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close; 
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() and nums2.empty()) {
			return 0;
		}
		size_t l = nums1.size() + nums2.size();
		return l % 2 ? kthElement(nums1, nums2, l / 2) : 0.5 * kthElement(nums1, nums2, l / 2 - 1) + 0.5 * kthElement(nums1, nums2, l / 2);
	}
private:
	int kthElement(vector<int>& nums1, vector<int>& nums2, size_t k) {
		if (nums1.size() < nums2.size()) {
			return kthElement(nums2, nums1, k);
		}
		if (nums2.empty()) {
			return nums1.at(k);
		}
		
	}
};

// class Solution {
// public:
// 	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// 		if (nums1.empty() and nums2.empty()) {
// 			return 0;
// 		}
// 		size_t l = nums1.size() + nums2.size();
// 		return l % 2 ? kthElement(0, nums1, 0, nums2, l / 2) : 0.5 * kthElement(0, nums1, 0, nums2, l / 2 - 1) + 0.5 * kthElement(0, nums1, 0, nums2, l / 2);
// 	}
// private:
// 	int kthElement(size_t b1, vector<int>& nums1, size_t b2, vector<int>& nums2, size_t k) {
// 		if (nums2.size() <= b2) {
// 			return nums1.at(b1 + k);
// 		}
// 		if (nums2.size() == b2 + 1) {
// 			size_t d = distance(next(begin(nums1), b1), lower_bound(next(begin(nums1), b1), end(nums1), nums2.back()));
// 			return d == k ? nums2.back() : nums1.at(b1 + k - (d < k));
// 		}
// 		if (nums1.size() + b2 < nums2.size() + b1) {
// 			return kthElement(b2, nums2, b1, nums1, k);
// 		}
// 		if (k == 0) {
// 			return min(nums1.at(b1), nums2.at(b2));
// 		}
// 		if (k == 1) {
// 			return min(max(nums1.at(b1), nums2.at(b2)), min(nums1.at(b1 + 1), nums2.at(b2 + 1)));
// 		}
// 		size_t i = min(b1 + k / 2, nums1.size() - 1), j = min(b2 + k / 2, nums2.size() - 1);
// 		return nums1.at(i) < nums2.at(j) ? kthElement(i, nums1, b2, nums2, k + b1 - i) : kthElement(b1, nums1, j, nums2, k + b2 - j);
// 	}
// };

// BEGIN: Time Complexity O(n) Space Complexity O(n)
// class Solution {
// public:
// 	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// 		if (nums1.empty() and nums2.empty()) {
// 			return 0.0;
// 		}
// 		vector<int> result;
// 		result.insert(end(result), begin(nums1), end(nums1));
// 		result.insert(end(result), begin(nums2), end(nums2));
// 		inplace_merge(begin(result), next(begin(result), nums1.size()), end(result));
// 		if (result.size() % 2) {
// 			return result.at(result.size() / 2);
// 		}
// 		return 0.5 * result.at(result.size() / 2 - 1) + 0.5 * result.at(result.size() / 2);
// 	}
// };
// END: Time Complexity O(n) Space Complexity O(n)

int main(void) {
	Solution solution;
	vector<int> nums1, nums2;
	double result = 0, answer = 0;

	nums1 = {1, 5};
	nums2 = {2, 3, 4, 6, 7, 8, 9, 10};
	answer = 5.5;
	result = solution.findMedianSortedArrays(nums1, nums2); 
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 2};
	nums2 = {3, 4, 5, 6, 7, 8};
	answer = 4.5;
	result = solution.findMedianSortedArrays(nums1, nums2); 
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 2, 6};
	nums2 = {3, 4, 5};
	answer = 3.5;
	result = solution.findMedianSortedArrays(nums1, nums2); 
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 4};
	nums2 = {2, 3, 5, 6};
	answer = 3.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1};
	nums2 = {2, 3, 4};
	answer = 2.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 3};
	nums2 = {2};
	answer = 2;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 2};
	nums2 = {3, 4};
	answer = 2.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	cout << "\nPassed All\n";
	return 0;
}