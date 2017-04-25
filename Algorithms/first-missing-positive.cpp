// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
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

// BEGIN: Time Complexity O(n) Space Complexity O(1)
// BEGIN: http://www.cnblogs.com/yuzhangcmu/p/4200096.html
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0, n = nums.size(); i < n; i++) {
			while (nums.at(i) >= 1 and nums.at(i) <= n and nums.at(i) != nums.at(nums.at(i) - 1)) {
				swap(nums.at(i), nums.at(nums.at(i) - 1));
			}
		}
		for (int i = 0, n = nums.size(); i < n; i++) {
			if (nums.at(i) != i + 1) {
				return i + 1;
			}
		}
		return nums.size() + 1;
	}
};
// END: http://www.cnblogs.com/yuzhangcmu/p/4200096.html
// END: Time Complexity O(n) Space Complexity O(1)

int main(void) {
	Solution solution;
	vector<int> nums;
	int result = 0, answer = 0;

	nums = {1};
	answer = 2;
	result = solution.firstMissingPositive(nums);
	assert(answer == result);

	nums = {};
	answer = 1;
	result = solution.firstMissingPositive(nums);
	assert(answer == result);

	nums = {1, 2, 0};
	answer = 3;
	result = solution.firstMissingPositive(nums);
	assert(answer == result);

	nums = {3, 4, -1, 1};
	answer = 2;
	result = solution.firstMissingPositive(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}