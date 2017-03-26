// 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/

/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
*/

#include <iostream> // std::cout; std::cin
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
	int singleNonDuplicate(vector<int>& nums) {
		size_t left = 0, right = nums.size() - 1;
		if (nums.at(left) != nums.at(left + 1)) {
			return nums.front();
		}
		if (nums.at(right - 1) != nums.at(right)) {
			return nums.back();
		}
		while (left + 1 < right) {
			size_t mid = left + (right - left) / 2;
			if (nums.at(mid - 1) != nums.at(mid) and nums.at(mid + 1) != nums.at(mid)) {
				return nums.at(mid);
			}
			if (mid % 2) {
				if (nums.at(mid - 1) == nums.at(mid)) {
					left = mid;
				}
				else {
					right = mid;
				}
			}
			else {
				if (nums.at(mid + 1) == nums.at(mid)) {
					left = mid;
				}
				else {
					right = mid;
				}
			}
		}
		if (nums.at(left - 1) != nums.at(left) and nums.at(left + 1) != nums.at(left)) {
			return nums.at(left);
		}
		return nums.at(right);
	}
};

// class Solution {
// public:
// 	int singleNonDuplicate(vector<int>& nums) {
// 		int result = 0;
// 		for (const auto &i : nums) {
// 			result ^= i;
// 		}
// 		return result;
// 	}
// };

int main(void) {
	Solution solution;
	vector<int> nums;
	int result = 0, answer = 0;

	nums = {0, 1, 1};
	answer = 0;
	result = solution.singleNonDuplicate(nums);
	assert(answer == result);

	nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
	answer = 2;
	result = solution.singleNonDuplicate(nums);
	assert(answer == result);

	nums = {3, 3, 7, 7, 10, 11, 11};
	answer = 10;
	result = solution.singleNonDuplicate(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}